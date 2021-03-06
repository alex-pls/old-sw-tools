//---------------------------------------------------------------------------
///// BackgroundCommThread.cpp
/////     purpose :  Opens a commport object and monitors it for bytes received on the port.
/////    copyright: Harold Howe, bcbdev.com 1999-2000.
/////    notice   : This file demonstrates how to use the commport class. It exists solely for educational purposes.
/////               You may copy and use comm.h and comm.cpp as you see fit in your projects, but this file may only
/////               be distributed along with the rest of this example project.
#include <vcl.h>
#pragma hdrstop

#include "BackgroundCommThread.h"
#include "main.h"
#include <exptintf.hpp>

#pragma package(smart_init)


//---------------------------------------------------------------------------
//  TBackgroundCommThread::TBackgroundCommThread (constructor)
//      purpose: Initialize stuff, like every constructor should
//      remarks: 1  TBackgroundCommThread maintains a commport object. This object
//                  is initialized here.
//               2  The thread is given a high priority. The idea is that we run frequently,
//                  but we only do minimal processing each time through.
__fastcall TBackgroundCommThread::TBackgroundCommThread()
    : TThread(true)
{
    // initialize to com1 at 115200
    m_CommPort.SetCommPort("COM1");
    m_CommPort.SetBaudRate(115200);

    Priority = tpHighest;
    FreeOnTerminate = false;  // Don't automatically delete ourselves when terminated.
}
//---------------------------------------------------------------------------

//---------------------------------------------------------------------------
//  TBackgroundCommThread::~TBackgroundCommThread (destructor)
//      purpose: Blank for now.
//      remarks:
__fastcall TBackgroundCommThread::~TBackgroundCommThread()
{
}
//---------------------------------------------------------------------------

//---------------------------------------------------------------------------
//  TBackgroundCommThread::Connect
//      purpose: Open the comm port and start looking for characters
//      remarks: 1  Characters are received and processed from a background thread.
//                  The thread is resumed, or started, when Connect is called.
//               2  When we connect, we send a \r. This will cause the terminal
//                  to send us its command prompt if it has one.
void TBackgroundCommThread::Connect()
{
    // clear the vector of characters received
    m_ReceivedChars.clear();

    try
    {
        m_CommPort.OpenCommPort();
        // calls to suspend and resume can be nested. We don't want that stinking nesting stuff.
        // call resume as many times as it takes to get the thread going again.
        while(Suspended)
            Resume();
        m_CommPort.WriteString("\r");
    }
    catch(ECommError &e)
    {
        if (e.Error == ECommError::OPEN_ERROR)
            ShowMessage("Error opening comm port. Port already in use?");
        else
            ShowMessage("Error opening comm port.");
    }
}
//---------------------------------------------------------------------------

//---------------------------------------------------------------------------
//  TBackgroundCommThread::Disconnect
//      purpose: Closes the comm port and suspends the thread.
//      remarks:
void TBackgroundCommThread::Disconnect()
{
    Suspend();
    m_CommPort.CloseCommPort();
}
//---------------------------------------------------------------------------

//---------------------------------------------------------------------------
//  TBackgroundCommThread::SetParameters
//      purpose: Gives clients of the thread class a way to set the baud rate and
//               port number of the comm port object.
//      remarks: 1 : If we are currently connected, we have to disconnect, change the
//                   port settings, and then re-connect. If characters are being received,
//                   this might mean that we drop some characters.
//               2 : Might want to first check if any of the paramaters have changed.
//                   If baud and port are the same as what the comm object is alread set
//                   to, then there is not much point disconnecting and re-connecting.
void TBackgroundCommThread::SetParameters(unsigned int baud, const std::string &port )
{
    bool bConnected = GetConnected();

    Disconnect();
    m_CommPort.SetBaudRate(baud);
    m_CommPort.SetCommPort(port);

    if(bConnected)
        Connect();
}
//---------------------------------------------------------------------------

//---------------------------------------------------------------------------
//  TBackgroundCommThread::WriteString
//      purpose: Gives clients a way to write a string out the port.
//      remarks:
void TBackgroundCommThread::WriteString(const AnsiString &str)
{
    m_CommPort.WriteString(str.c_str());
}
//---------------------------------------------------------------------------

//---------------------------------------------------------------------------
//  TBackgroundCommThread::SynchronizeNewBytes
//      purpose: Notifies the main form that new bytes have been received.
//      remarks: 1  New bytes are stuffed into the m_ReceivedChars vector. We don't want
//                  the mainform reading characters while the background thread is still
//                  stuffing characters into it. Instead, we want to synchronize the two
//                  threads. For this, we use the Synchronize features of TThread. While
//                  the main form is reading characters, the background thread promises
//                  that it won't stuff any more bytes into the vector
//               2  The sync function calls a member of the main form. This is somewhat of
//                  a design flaw. This thread class should not have intimate knowledge of
//                  its clients. Calling a member of the main form tightly couples this
//                  class to the main form class. This is a bad design practice. But this
//                  is educational software. What did you expect, to learn *good* coding practices?
void __fastcall TBackgroundCommThread::SynchronizeNewBytes(void)
{
    // If the app has been terminated, don't bother. The main form might not be alive anymore
    if(Application->Terminated)
        return;

    // Don't send the characters if we have been terminated.
    // This safeguard may be unecessary
    if(!Application->Terminated)
    {
        mainFrm->NewBytesReceived(m_ReceivedChars);
    }
}
//---------------------------------------------------------------------------


//---------------------------------------------------------------------------
//  TBackgroundCommThread::Execute
//      purpose: Monitor the comm port for data.
//      remarks: 1  This is the main function of this thread. Its the entire reason we use
//                  a background thread.
//               2  Execute starts when the Connect method is called.
void __fastcall TBackgroundCommThread::Execute()
{
    while (!Terminated)
    {
        // Find out how many bytes are available on the port.
        DWORD BytesAvailable = m_CommPort.BytesAvailable();
        DWORD BytesRead =0;

        if(BytesAvailable > 0)
        {
            // If bytes have been received, then create a buffer to
            // read the bytes into, and read the bytes from the port object.
            BYTE *buffer = new BYTE[BytesAvailable];
            BytesRead = m_CommPort.ReadBytes(buffer,BytesAvailable);

            // If bytes were read, then transfer those bytes over to the vector,
            // and call the sync method.
            if(BytesRead)
            {
                m_ReceivedChars.clear();
                // at 115k, each byte takes about 87 us. In 100ms, we could receive more than 1k of text
                // we want the vector to allocate its memory once, all in one chunk. For this, we call reserve.
                m_ReceivedChars.reserve(BytesRead);
                m_ReceivedChars.insert(m_ReceivedChars.begin(),&buffer[0], &buffer[BytesRead]);
                Synchronize(SynchronizeNewBytes);
            }

            delete []buffer;
        }

        // Sleep for a period of time, and then wake up and check the port again.
        Sleep(100);
    }
}
//---------------------------------------------------------------------------

