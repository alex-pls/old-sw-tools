//---------------------------------------------------------------------------
///// BackgroundCommThread.h
/////     purpose : Header file for the background thread.
/////    copyright: Harold Howe, bcbdev.com 1999-2000.
/////    notice   : This file demonstrates how to use the commport class. It exists solely for educational purposes.
/////               You may copy and use comm.h and comm.cpp as you see fit in your projects, but this file may only
/////               be distributed along with the rest of this example project.
#ifndef BackgroundCommThreadH
#define BackgroundCommThreadH
//---------------------------------------------------------------------------
#include <Classes.hpp>

#include "comm.h"
#include <vector>

#include <string>

//---------------------------------------------------------------------------
class TBackgroundCommThread : public TThread
{
protected:
    std::vector<BYTE> m_ReceivedChars;
    TCommPort m_CommPort;
    void __fastcall Execute();

    // Synchronized methods
    void __fastcall SynchronizeNewBytes(void);
public:
    __fastcall TBackgroundCommThread();
    virtual __fastcall ~TBackgroundCommThread();

    void Connect();
    void Disconnect();
    void SetParameters(unsigned int baud, const std::string &port);
    bool GetConnected()
    {
        return m_CommPort.GetConnected();
    }

    void WriteString(const AnsiString &str);
//    void WriteStringAndWaitForAck(const AnsiString &str);



    TCommPort& GetCommPort()
    {
        return m_CommPort;
    }

};
//---------------------------------------------------------------------------
#endif

