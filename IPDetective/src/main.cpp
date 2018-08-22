// IPDetective Project
//
// Status: Aborted
//
// by Alessandro Polo 2002
// eWorld Network :: www.ewgate.net
//------------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "about.h"      // About box form
#include "splash.h"     // Splash box form
#include "shortcuts.h"  // ShortCuts Win form
#include "terminal.h"   // Terminal Win form

#include <string>

#include <memory>       //for Serial Input Data
#include <mmsystem.h>   //for playing sounds on events

//#include <sstream>
#include <shellapi.h>
#include <windows.h>
//#include <shlobj.h>

#include <winsock2.h>
#include <nb30.h>
#include <shlguid.h>    // Clear IE History
#include <UrlHist.h>    // Clear IE History


#include "OSfunc.h"

#include "include\SerialPort\comm.h"          //serial IO
#include "include\SerialPort\BackgroundCommThread.h"
/////////#include "Services\SysInfos\SysInfo\SysInfo.h" //
//#include "LANfunc.h"


//______________________Services Static Classes & exported functions.
#include "Services\services.h"

#include "main.h"
#include <lmaccess.h>   // LISTING NT USERS
#include <lmapibuf.h>   // LISTING NT USERS

//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "cdiroutl"
#pragma link "SHDocVw_OCX"
#pragma resource "*.dfm"
using namespace std;
TmainFrm *mainFrm;


const int TextStreamCapacity   = 64*1024;
//==============================================================================


//---------------------------------------------------------------------------
__fastcall TmainFrm::TmainFrm(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------


//================================================== serial port
/*
static BOOL CALLBACK GetSerialPortList(LPVOID lpCallbackValue,LISTPORTS_PORTINFO* lpPortInfo)
{
       mainFrm->OSInfo_Memo->Lines->Add(AnsiString(lpPortInfo->lpPortName) + ":\t" + AnsiString(lpPortInfo->lpFriendlyName));
  return TRUE;
}
*/
//========================================================


void __fastcall TmainFrm::GetOSInfo_BtnClick(TObject *Sender)
{
        if (!LocalInfos_TreeView->Selected->SelectedIndex) return;

        if (OSReportClean_chk->Checked)
                OSInfo_Memo->Clear();
        else    OSInfo_Memo->Lines->Add("");

switch (LocalInfos_TreeView->Selected->SelectedIndex) {

  case 10:      // Computer
        {
        OSInfo_Memo->Lines->Add("________Loading Computer Infos");
        OSInfo_Memo->Lines->Add("");
        OSInfo_Memo->Lines->Add("");
        }
  case 11:     // Computer->Owner
        {
        OSInfo_Memo->Lines->Add("________Computer Owner Infos");
        OSInfo_Memo->Lines->Add("");
        AnsiString str;
        DWORD size = 255;
        str.SetLength(size +1);                  // 255 characters plus null term
        GetComputerName(str.c_str(), &size) ;    // call the API Get functions
        OSInfo_Memo->Lines->Add(" Computer Name:\t" + str);
        OSInfo_Memo->Lines->Add("");
        };
        if (LocalInfos_TreeView->Selected->SelectedIndex != 10) break;
  case 12:     // Computer->Operative System
        {
        OSInfo_Memo->Lines->Add("________Operative System Infos");
        OSInfo_Memo->Lines->Add("");
        OSInfo_Memo->Lines->Add("");
        };
        if (LocalInfos_TreeView->Selected->SelectedIndex != 10) break;
  case 13:     // Computer->DLLs Version
        {
        OSInfo_Memo->Lines->Add("________System DLLs Versions");
        OSInfo_Memo->Lines->Add("");
        DWORD version;
        OSInfo_Memo->Lines->Add(GetDLLVersion("lannfo.dll"));
        OSInfo_Memo->Lines->Add("Comctl32.dll\t" + String(HIWORD(version)) + "." + String(LOWORD(version)));
        version = GetDLLVersion("Shell32.dll");
        OSInfo_Memo->Lines->Add("Shell32.dll\t" + String(HIWORD(version)) + "." + String(LOWORD(version)));
        version = GetDLLVersion("Shlwapi.dll");
        OSInfo_Memo->Lines->Add("Shlwapi.dll\t" + String(HIWORD(version)) + "." + String(LOWORD(version)));
        OSInfo_Memo->Lines->Add("");
        };
        if (LocalInfos_TreeView->Selected->SelectedIndex != 10) break;
  case 14:     // Computer->DeskTop
        {
        OSInfo_Memo->Lines->Add("________Computer DekTop Infos");

        if(Screen->PixelsPerInch == 96) OSInfo_Memo->Lines->Add("Small fonts in use.");
        else if(Screen->PixelsPerInch == 120) OSInfo_Memo->Lines->Add("Large fonts in use.");
        else    {
            float Ratio = ((float)Screen->PixelsPerInch) / 96.0;
            Ratio *= 100.0;
            OSInfo_Memo->Lines->Add("Fonts are set to " + IntToStr((int)Ratio) + " %");
          };


        };
        break;

  case 20:     // HardWare
        {
        OSInfo_Memo->Lines->Add("________Computer Hardware Infos");
        OSInfo_Memo->Lines->Add("");
        OSInfo_Memo->Lines->Add("");
        };
  case 21:     // HardWare->CPU
        {
        OSInfo_Memo->Lines->Add("________Computer CPU");
        };
        if (LocalInfos_TreeView->Selected->SelectedIndex != 20) break;
  case 22:     // HardWare->Modem
        {
        OSInfo_Memo->Lines->Add("________Computer Modem");
        };
        if (LocalInfos_TreeView->Selected->SelectedIndex != 20) break;
  case 23:     // HardWare->Serial Ports
        {
        OSInfo_Memo->Lines->Add("________Serial Ports:");
//        ListPorts(GetSerialPortList,NULL);
        };
        break;



  case 30:     // InterNet
        {
        };
  case 31:     // InterNet->Settings
        {
        OSInfo_Memo->Lines->Add("________InterNet Settings");
        };
        if (LocalInfos_TreeView->Selected->SelectedIndex != 30) break;
  case 32:     // InterNet->Accounts
        {
        OSInfo_Memo->Lines->Add("________InterNet Accounts");
        };
        if (LocalInfos_TreeView->Selected->SelectedIndex != 30) break;
  case 33:     // InterNet->Mail Account
        {
        OSInfo_Memo->Lines->Add("________Mail Accounts");
        };
        break;

  case 40:     // NetWork
        {
        };
  case 41:     // NetWork->Info
        {
        OSInfo_Memo->Lines->Add("________NetWork Infos");
        };
        if (LocalInfos_TreeView->Selected->SelectedIndex != 40) break;
  case 42:     // NetWork->WinSock
        {
        OSInfo_Memo->Lines->Add("________WinSock Infos");
        };
        if (LocalInfos_TreeView->Selected->SelectedIndex != 40) break;
    };
}
//---------------------------------------------------------------------------





void __fastcall TmainFrm::Map_btnClick(TObject *Sender)
{
  // Show the Map Network Drive dialog.
  WNetConnectionDialog( NULL, RESOURCETYPE_DISK);
}
//---------------------------------------------------------------------------



void __fastcall TmainFrm::Ref_ListViewClick(TObject *Sender)
{
//  if FileExists(RFCFiles_Ed + Ref_ListView->Selected->Caption)
        ShellExecute(NULL, "open", (RFCFiles_Ed->Text + Ref_ListView->Selected->Caption).c_str(), "", "", SW_SHOWDEFAULT);
}
//---------------------------------------------------------------------------



void __fastcall TmainFrm::IPDetective1Click(TObject *Sender)
{
  Application->CreateForm(__classid(TAboutBox), &AboutBox);
  AboutBox->Show();
}
//---------------------------------------------------------------------------



void __fastcall TmainFrm::WinShortcuts_MnuClick(TObject *Sender)
{
if (WinShortcuts_Mnu->Checked)
        {
        ShortCutsFrm->Close();
                // close the form, it will be deleted on app exit.
        }
else    {
        Application->CreateForm(__classid(TShortCutsFrm), &ShortCutsFrm);
                // created the form, it will be deleted on app exit.
        ShortCutsFrm->ShortCutsListView->Items = ShortCutsListView->Items;
                // syncronise with main list
        ShortCutsFrm->Show();
                // shows the form
        }
  WinShortcuts_Mnu->Checked = !WinShortcuts_Mnu->Checked;
  WinShortcuts_Mnu2->Checked = !WinShortcuts_Mnu->Checked;
                // check / uncheck the menu items
}
//---------------------------------------------------------------------------


void __fastcall TmainFrm::WinTerminal_MnuClick(TObject *Sender)
{
if (WinTerminal_Mnu->Checked)
        {
        TerminalFrm->Close();
                // close the form, it will be deleted on app exit.
        }
else    {
                Application->CreateForm(__classid(TTerminalFrm), &TerminalFrm);
                // created the form, it will be deleted on app exit.

        TerminalFrm->TConsole_Memo->Lines = TConsole_Memo->Lines;
        TerminalFrm->TConsoleApp_Memo = TConsole_Memo;
        TerminalFrm->TConsoleApp_cmb = TConsole_cmb;
        TerminalFrm->CloseCall = WinTerminal_Mnu;

        TerminalFrm->TConsole_Memo->Font->Assign(TConsole_Memo->Font);
        TerminalFrm->TConsole_cmb->Font->Assign(TConsole_cmb->Font);
        TerminalFrm->TConsole_Memo->Font->Color = TConsole_Memo->Font->Color;
        TerminalFrm->TConsole_cmb->Font->Color = TConsole_cmb->Font->Color;


                // syncronise with main console
        TerminalFrm->Show();
                // shows the form
        }
  WinTerminal_Mnu->Checked = !WinTerminal_Mnu->Checked;
  WinTerminal_Mnu2->Checked = !WinTerminal_Mnu->Checked;

                // check / uncheck the menu items

}


//===============================================================
LRESULT IconDrawItem(LPDRAWITEMSTRUCT lpdi)
{
	HICON hIcon;

	hIcon = (HICON)LoadImage(g_hinst, MAKEINTRESOURCE(lpdi->CtlID), IMAGE_ICON,
		16, 16, 0);
	if (!hIcon)
		return(FALSE);

	DrawIconEx(lpdi->hDC, lpdi->rcItem.left, lpdi->rcItem.top, hIcon,
		16, 16, 0, NULL, DI_NORMAL);

	return(TRUE);
}

void __fastcall TmainFrm::DrawItem(TMessage& Msg)
{
     IconDrawItem((LPDRAWITEMSTRUCT)Msg.LParam);
     TForm::Dispatch(&Msg);
}
//---------------------------------------------------------------------------
void __fastcall TmainFrm::MyNotify(TMessage& Msg)
{
    POINT MousePos;

    switch(Msg.LParam)
    {
        case WM_RBUTTONUP:
            if (GetCursorPos(&MousePos))
            {
                Ticon_PopupMnu->PopupComponent = mainFrm;
                SetForegroundWindow(Handle);
                Ticon_PopupMnu->Popup(MousePos.x, MousePos.y);
            }
            else
                mainFrm->Show();
            break;
        case WM_LBUTTONUP:
                mainFrm->Show();        //open another popup menu with services
            break;
        default:
//                mainFrm->Show();
            break;
    }
    TForm::Dispatch(&Msg);
}

bool __fastcall TmainFrm::TrayMessage(DWORD dwMessage)
{
   NOTIFYICONDATA tnd;
   PSTR pszTip;

   pszTip = "IP Detective 2002";

   tnd.cbSize          = sizeof(NOTIFYICONDATA);
   tnd.hWnd            = Handle;
   tnd.uID             = IDC_MYICON;
   tnd.uFlags          = NIF_MESSAGE | NIF_ICON | NIF_TIP;
   tnd.uCallbackMessage	= MYWM_NOTIFY;

   if (dwMessage == NIM_MODIFY)
    {
        tnd.hIcon		= (HICON)Application->Icon->Handle;
        if (pszTip)
           lstrcpyn(tnd.szTip, pszTip, sizeof(tnd.szTip));
	    else
        tnd.szTip[0] = '\0';
    }
   else
    {
        tnd.hIcon = NULL;
        tnd.szTip[0] = '\0';
    }

   return (Shell_NotifyIcon(dwMessage, &tnd));
}

//===============================================================


//---------------------------------------------------------------------------


void __fastcall TmainFrm::TrayIcon_MnuClick(TObject *Sender)
{
        if(TrayIcon_Mnu->Checked)
                {
            	TrayMessage(NIM_DELETE);
                ShowWindow(Application->Handle, SW_SHOW);
                }
        else    {
            	TrayMessage(NIM_ADD);
                TrayMessage(NIM_MODIFY);
                ShowWindow(Application->Handle, SW_HIDE);
                };
TrayIcon_Mnu->Checked = !TrayIcon_Mnu->Checked;
}
//---------------------------------------------------------------------------

void __fastcall TmainFrm::Shutdown_MnuClick(TObject *Sender)
{
Application->Terminate();
}
//---------------------------------------------------------------------------

void __fastcall TmainFrm::WinActiveConn_MnuClick(TObject *Sender)
{
// BLA        
}
//---------------------------------------------------------------------------

void __fastcall TmainFrm::WinMain_MnuClick(TObject *Sender)
{
        if (WinMain_Mnu->Checked)
                {
                mainFrm->Hide();
                }
        else    {
                mainFrm->Show();
                };
WinMain_Mnu->Checked = !WinMain_Mnu->Checked;
}
//---------------------------------------------------------------------------

void __fastcall TmainFrm::FormClose(TObject *Sender, TCloseAction &Action)
{
 if (SaveonExit_chk->Checked)
        {
        Log_Memo->Lines->Add("Saving Application Data");
        WhoIsServers_lbx->Items->SaveToFile("data\\wislist.txt");

         if (KeepLog_chk->Checked)
                {
                Log_Memo->Lines->Add("");
                Log_Memo->Lines->Add("______________Session Closed.");
                Log_Memo->Lines->SaveToFile("data\\log.txt");
                };
        };
 Log_Memo->Lines->Add("UnLoading ICQ MAPI Service DLL (file: base.dll)");


 if (Tray_NotClose_chk->Checked)
    {
    if(!Application->Terminated)
    {
        ShowWindow(Application->Handle, SW_HIDE);
        Action = caNone;
    	TrayMessage(NIM_ADD);
        TrayMessage(NIM_MODIFY);
        mainFrm->Hide();
    }
    }
 else
    	TrayMessage(NIM_DELETE);

}
//---------------------------------------------------------------------------

void __fastcall TmainFrm::Button1Click(TObject *Sender)
{
    TMenuItem *Root = MainMenu->Items;

    // create a new menu item, set the owner to the form;
    TMenuItem *HelpItem = new TMenuItem(this);
    HelpItem->Caption = "&Help";
    Root->Add(HelpItem);

    // now add child items under the new Help item.
    TMenuItem *ContentsItem = new TMenuItem(this);
    TMenuItem *IndexItem    = new TMenuItem(this);
    TMenuItem *AboutItem    = new TMenuItem(this);
    ContentsItem ->Caption = "&Contents";
    IndexItem    ->Caption = "&Index";
    AboutItem    ->Caption = "&About";

    HelpItem->Add(ContentsItem);
    HelpItem->Add(IndexItem);
    HelpItem->Add(AboutItem);
        
}
//---------------------------------------------------------------------------

void __fastcall TmainFrm::SurfeWorldClick(TObject *Sender)
{
    // open a website.
    ShellExecute(Handle, "open", "http://www.ewgate.net", NULL,NULL,SW_SHOWDEFAULT);
}
//---------------------------------------------------------------------------

void __fastcall TmainFrm::SerialOpenSocket_BtnClick(TObject *Sender)
{
if (SerialOpenSocket_Btn->Caption == "Open Socket")
    {
    // Tell the vector to reserve some space. This will help reduce the need to allocate memory
    // when characters are received. Actually, it should completely eliminate it.
    m_TextStream.reserve(TextStreamCapacity);
    // create the comm port thread.
    m_CommThread = new TBackgroundCommThread();
    SerialStatus_Lb->Caption = "Socket Ready.";
    SerialOpenSocket_Btn->Caption = "Close Socket";
    }
else
    {
    // If the commport is running, terminate it and wait for it to finish.
        m_CommThread->Disconnect();
    if(!m_CommThread->Suspended)
    {
        m_CommThread->Terminate();
        m_CommThread->WaitFor();
    }
    delete m_CommThread;
    SerialStatus_Lb->Caption = "Socket Closed.";
    SerialOpenSocket_Btn->Caption == "Open Socket";
    };
}
//---------------------------------------------------------------------------

void __fastcall TmainFrm::SerialConnect_BtnClick(TObject *Sender)
{
if (SerialOpenSocket_Btn->Caption == "Open Socket")
        {
        ShowMessage("Open the Socket before connecting.");
        return;
        };
if (SerialConnect_Btn->Caption == "Connect")
    {
    bool bConnected = m_CommThread->GetConnected();
    if(!bConnected)
        {
            unsigned int nBaud = 57600;
            switch(SerialBaud_CBox->ItemIndex)
            {
                case 0:
                    nBaud =57600;
                    break;
                case 1:
                    nBaud =115200;
                    break;
            };
            m_CommThread->SetParameters(nBaud, SerialPort_CBox->Text.c_str());
            //    ShowMessage(IntToStr(m_CommThread->GetConnected()));
                m_CommThread->Connect();
                SerialStatus_Lb->Caption = "Connected.";
        };
    SerialOpenSocket_Btn->Caption == "Disconnect";
    }
else
    {
    m_CommThread->Disconnect();
    SerialStatus_Lb->Caption = "Disconnected.";
    SerialOpenSocket_Btn->Caption == "Connect";
    };
}
//---------------------------------------------------------------------------

void TmainFrm::NewBytesReceived(const std::vector<BYTE> &stream)
{
    // when new bytes arrive, append them to the existing text stream
    m_TextStream.insert(m_TextStream.end(), stream.begin(), stream.end());

    // The text stream may contain backspace characters, and the occasional \0.
    // We need to remove those. Call ParseForControlCharacters to handle that.
    if(m_TextStream.size() < 2)
        return;

    // search for backspace chars, \b. When found, erase the \b character, and its
    // preceeding character.
    // Note: there is some waste here. The code searches the entire text stream.
    //       It would be more efficient to only search the new text, since the
    //       old text was already parsed.
    std::vector<BYTE>::iterator iter= m_TextStream.begin() + 1;
    while(iter < m_TextStream.end())
    {
        // search for a \b. start at the current location, iter,
        // and search until the end
        iter = std::find(iter, m_TextStream.end(), '\b');
        if(iter != m_TextStream.end())
        {
            // if found, erase the characters at iter-1 and iter. iter contains the backspace,
            // and iter-1 contains the character to erase.
            int nPosition = iter - m_TextStream.begin();  // the search will resume at iter-begin(), save this position
            m_TextStream.erase(iter-1, iter +1);          // erase from iter-1 up to, but not including, iter + 1
            iter = m_TextStream.begin() + nPosition -1;   // reset iter so the search can continue
        }
    }

    // search for \0's. I found that if the text stream contains a \0 in the middle, the memo
    // control does not display anything after that \0. Under normal circumstances, we should not
    // receive any of these in the text stream. However, I did see them when the user unplugs the
    // rs-232 cable in middle of a transfer The port would receive a sprurios \0. This code removes them
    iter =  m_TextStream.begin();
    while(iter < m_TextStream.end())
    {
        iter = std::find(iter, m_TextStream.end(), '\0');
        if(iter != m_TextStream.end())
        {
            m_TextStream.erase(iter, iter+1);
            --iter;  // resume search at prior location.
        }
    }

    // copy the text stream into the memo.
    // Memo controls cannot work directly with vectors, but they can work with streams.
    // This routine creates a memory stream, and copies the text stream over to the memory
    // stream. Then it passes the memory stream to the memo or rich edit control. This is
    // extremely wasteful. For every character the user enters, we allocate a big chunk of
    // memory, perform a big copy, load the memory, and deallocate.
    //
    // The problem is that you can't spoon feed individual characters to a memo control.
    // This could be improved by:
    // 1- creating a custom control that can deal with iterators or individual chars
    // 2- using memory streams instead of std::vectors. vectors are used because they
    //    work with the standard algorithms, but we could also use the algorithms on the
    //    raw memory in the memory stream. But memory streams do not provide nice insert
    //    and erase methods.
    // 3- don't use a memo control. handle the painting directly. This is what hyper term does.
    //
    // since this is just a demo program, and because the performance seemed to be acceptable, I
    // just left the inefficient algorithm in place.

    // If the text stream exceeds 32k, then get rid of the first 1k.
    if(m_TextStream.size() > 32 * 1024)
    {
        int BytesToErase = m_TextStream.size() - 32 * 1024 + 1024; // erase an extra 1k so we are not erasing stuff after each key stroke.
        m_TextStream.erase(m_TextStream.begin(), m_TextStream.begin() + BytesToErase);
    }

    // create a TMemoryStream object, and copy the text bytes over to it.
    // then load the memorystrem into the memo control.
    // Note: beginupdate and endupdate help reduce flicker.
    std::auto_ptr<TMemoryStream> SPstream(new TMemoryStream);
    SPstream->Write(m_TextStream.begin(), m_TextStream.size());
    SPstream->Seek(0,soFromBeginning);
    SerialDataIn_REd->Lines->BeginUpdate();
    SerialDataIn_REd->Lines->LoadFromStream(SPstream.get());

    // These two lines are important. We want the cursor to be at the last key received.
    // SelStart determines the cursor location. Set it to the last char. Then, tell the memo
    // to scroll the caret so it is visible.
    SerialDataIn_REd->SelStart = SerialDataIn_REd->Text.Length();
    SendMessage(SerialDataIn_REd->Handle, EM_SCROLLCARET,0,0);
    SerialDataIn_REd->Lines->EndUpdate();
}

void __fastcall TmainFrm::SerialSend_BtnClick(TObject *Sender)
{
//    if (m_CommThread->GetConnected())
      if (SerialStatus_Lb->Caption == "Connected.")
        {
        AnsiString strRet('\r');
        m_CommThread->WriteString(SerialOutData_REd->Text);
    // when they press return, only send \r out the port
        m_CommThread->WriteString(strRet);
        };
}
//---------------------------------------------------------------------------


//---------------------------------------------------------------------------

void __fastcall TmainFrm::Ref_ListViewSelectItem(TObject *Sender,
      TListItem *Item, bool Selected)
{
        if (FileExists(Item->Caption))
            ShellExecute(NULL, "open", (Item->Caption).c_str(), "", "", SW_SHOWDEFAULT);

}
//---------------------------------------------------------------------------


void __fastcall TmainFrm::WndProc(Messages::TMessage &Message)
{
    if( (Message.Msg    == WM_SYSCOMMAND) &&
        (Message.WParam == SC_SCREENSAVE) &&
        (DisableScreenSaver_chk->Checked) )
    {
        ShowMessage("ScreenSaver Disabled.");
        Message.Result = true;
    }
    else
        TForm::WndProc(Message);
}

void __fastcall TmainFrm::PingConnect_BtnClick(TObject *Sender)
{
//PlaySound("type.wav",   NULL, SND_FILENAME | SND_ASYNC |SND_NOSTOP);
//PlaySound("SystemStart",NULL, SND_ALIAS    | SND_ASYNC |SND_NOSTOP);

if (!Pinger_Memo->Visible) PingAdvanced_slbClick(Sender);       // shows the report

if (Ping.Load())
        {
        Log_Memo->Lines->Add("");
        Log_Memo->Lines->Add("LamePinging " + PingTargetIP_txt->Text + " (check own log for details)");

                                (FARPROC) lpfn_Ping_Lame = GetProcAddress (Ping.GetIstance(), "LamePing");
                                 if (lpfn_Ping_Lame != NULL)
        {
        if (!PingLoop_opt->Checked)
                (lpfn_Ping_Lame)(PingTargetIP_txt->Text, PingN_txt->Text.ToInt(), PingPsize_txt->Text.ToInt(), Pinger_Memo);
//        else
//                (lpfn_Ping_Lame)(PingTargetIP_txt->Text, 1, PingPsize_txt->Text.ToInt() , Pinger_Memo));
        }
                                 else
                                        {
                                        Pinger_Memo->Lines->Add("ERROR|\tService Function (LamePing) NOT Found.");
                                        return;
                                        };
        };

}
//---------------------------------------------------------------------------

void __fastcall TmainFrm::CaptureScreen_BtnClick(TObject *Sender)
{
if (CaptureFullScreen_opt->Checked)
  {
  // First, get an HDC for the entire screen with the API GetDC function.
  // Then create a Canvas based on the DC.
  HDC dc = GetDC(0);
  Graphics::TCanvas *ScreenCanvas = new Graphics::TCanvas;
  ScreenCanvas->Handle = dc;

  // Resize the TImage control to match the size of the screen.
  // Then copy from the screen Canvas to the TImage Canvas.
  CaptureShot_Img->Picture->Bitmap->Width = Screen->Width;
  CaptureShot_Img->Picture->Bitmap->Height= Screen->Height;
  TRect rect = Rect(0,0,Screen->Width, Screen->Height);
  CaptureShot_Img->Picture->Bitmap->Canvas->CopyRect(rect, ScreenCanvas, rect);

  // cleanup
  delete ScreenCanvas;
  ReleaseDC(NULL,dc);
  }
else
  {
// The BCB IDE window has the window class "TAppBuilder"
  HWND BCBHandle = FindWindow(CaptureWindow_Ed->Text.c_str() ,NULL);
  if(BCBHandle)
  {
    // Create a TCanvas for the BCB IDE window. GetWindowDC returns a DC for the
    // whole window, including the menu, title bar and border.
    HDC dc = GetWindowDC(BCBHandle);
    Graphics::TCanvas *ScreenCanvas = new Graphics::TCanvas;
    ScreenCanvas->Handle = dc;

    // need to create a TRect that is the same width and height as the ClipRect
    // of the Canvas, but whose left and top members are zero.
    TRect rect = ScreenCanvas->ClipRect;
    rect.Right  = rect.Right  - rect.Left;
    rect.Bottom = rect.Bottom - rect.Top;
    rect.Top = 0;
    rect.Left = 0;

    // resize the bitmap of the Image, and then copy the contents of the
    // BCB ide canvas to the bitmap's canvas. Then clean up the canvas and DC
    CaptureShot_Img->Picture->Bitmap->Width = rect.Right;
    CaptureShot_Img->Picture->Bitmap->Height= rect.Bottom;
    CaptureShot_Img->Picture->Bitmap->Canvas->CopyRect(rect,
                                              ScreenCanvas,
                                              ScreenCanvas->ClipRect);
    delete ScreenCanvas;
    ReleaseDC(BCBHandle,dc);
  }
  };
}
//---------------------------------------------------------------------------

void __fastcall TmainFrm::CaptureSave_BtnClick(TObject *Sender)
{
  SaveDialog->Title = "Save ScreenShot";
  if (SaveDialog->Execute())
        CaptureShot_Img->Picture->SaveToFile(SaveDialog->FileName);
}
//---------------------------------------------------------------------------





//---------------------------------------------------------------------------

void __fastcall TmainFrm::WhoisSend_btnClick(TObject *Sender)
{
DWORD dllRes = 0;

if (WhoIs.Load())
        {
        Log_Memo->Lines->Add("");
        Log_Memo->Lines->Add("Starting WhoIs Service. (check own log for details)");

        WhoIs_Memo->Lines->Add("_____________Starting WhoIs Service.");

        for(int i = 0; i < WhoIsServers_lbx->Items->Count; i++)
                        {
                        if (WhoIsServers_lbx->Checked[i])
                                {
                                WhoIs_Memo->Lines->Add("==Parameters");
                                WhoIs_Memo->Lines->Add(" Target:\t\t" + WhoIsTargetIP_txt->Text);
                                WhoIs_Memo->Lines->Add(" WhoIs server:\t" + WhoIsServers_lbx->Items->Strings[i]);

                                (FARPROC) lpfn_WhoIs = GetProcAddress (WhoIs.GetIstance(), "WhoIs");
                                 if (lpfn_WhoIs != NULL)
                                	(lpfn_WhoIs)(WhoIsServers_lbx->Items->Strings[i], WhoIsTargetIP_txt->Text, WhoIs_Memo);
                                 else
                                        {
                                        WhoIs_Memo->Lines->Add("ERROR|\tService Function (WhoIs) NOT Found.");
                                        return;
                                        };
                                WhoIs_Memo->Lines->Add("");
                                }
                        };
        };
 }
//---------------------------------------------------------------------------

void __fastcall TmainFrm::TabWhoisShow(TObject *Sender)
{
 if (WhoIs.Status()) return;

  if (WhoIs.Load())
        Log_Memo->Lines->Add(WhoIs.GetDescription() + " Service DLL Loaded.");
  else
        Log_Memo->Lines->Add("ERROR|" + WhoIs.GetDescription() + " Service DLL NOT Loaded.");
}
//---------------------------------------------------------------------------

LONG __fastcall TmainFrm::RegOpenOrCreateKeyEx(LPCTSTR KeyString, HKEY &hkey, HKEY RootKey)
{
 LONG lnRes;
 lnRes = RegOpenKeyEx( RootKey,  // handle of open key
                       KeyString, // address of name of subkey to open
                       0L,KEY_ALL_ACCESS, &hkey);           // address of handle of open key
 if( ERROR_SUCCESS == lnRes )
  {
  Log_Memo->Lines->Add("Opening Folder in Registry (key: \\" +  String(KeyString) + ")");
  return lnRes;
  };
 DWORD	dwDisposition;
 lnRes = RegCreateKeyEx(RootKey, KeyString, 0, NULL, 0, 0, NULL, &hkey, &dwDisposition);
 if( ERROR_SUCCESS == lnRes )
  Log_Memo->Lines->Add("Creating Folder in Registry (key: \\" + String(KeyString) + ")");
 else
  Log_Memo->Lines->Add("Error Accessing the Registry (key: \\" + String(KeyString) + ")");

 return lnRes;
                // Remember to close the key when finished.
}

bool __fastcall TmainFrm::SaveWindowSetting(TForm * curForm, HKEY &hkey)
 {
 if (!curForm) return false;
 DWORD dwType, dwSize;
 dwType = REG_DWORD;
 dwSize = sizeof(DWORD);
 int Height = curForm->Height;
 int Width = curForm->Width;
 int Top = curForm->Top;
 int Left = curForm->Left;
 if (   (RegSetValueEx(hkey, TEXT("Left"), 0, dwType, (PBYTE)&(Left), dwSize) == ERROR_SUCCESS) &&
        (RegSetValueEx(hkey, TEXT("Height"), 0, dwType, (PBYTE)&(Height), dwSize) == ERROR_SUCCESS) &&
        (RegSetValueEx(hkey, TEXT("Width"), 0, dwType, (PBYTE)&(Width), dwSize) == ERROR_SUCCESS) &&
        (RegSetValueEx(hkey, TEXT("Top"), 0, dwType, (PBYTE)&(Top), dwSize) == ERROR_SUCCESS) )
                return true;
                return false;
 }

bool __fastcall TmainFrm::LoadWindowSetting(TForm * curForm, HKEY &hkey)
 {
 if (!curForm) return false;
 DWORD dwType, dwSize;
 dwType = REG_DWORD;
 dwSize = sizeof(DWORD);

 if (   (RegQueryValueEx(hkey, TEXT("Left"), NULL, &dwType, (PBYTE)&(curForm->Left), &dwSize) == ERROR_SUCCESS) &&
        (RegQueryValueEx(hkey, TEXT("Top"), NULL, &dwType, (PBYTE)&(curForm->Top), &dwSize) == ERROR_SUCCESS) &&
        (RegQueryValueEx(hkey, TEXT("Height"), NULL, &dwType, (PBYTE)&(curForm->Height), &dwSize) == ERROR_SUCCESS) &&
        (RegQueryValueEx(hkey, TEXT("Width"), NULL, &dwType, (PBYTE)&(curForm->Width), &dwSize) == ERROR_SUCCESS) )
                return true;
 return false;
 }



void __fastcall TmainFrm::SaveDesktop_BtnClick(TObject *Sender)
{
if (SaveToReg_Opt->Checked)
        {                               // Save data to Registry
        HKEY	hkey;
        LONG lnRes;
        Log_Memo->Lines->Add("");
        Log_Memo->Lines->Add("Saving Desktop Settings to Registry...");

        lnRes = RegOpenOrCreateKeyEx("Software\\eWorld\\IP Detective\\Desktop\\Main", hkey);
         if( ERROR_SUCCESS == lnRes )
                if (SaveWindowSetting(mainFrm, hkey) && (ERROR_SUCCESS == RegCloseKey(hkey)))
                        Log_Memo->Lines->Add("Main Window data Saved in Registry (key: HKEY_LOCAL_MACHINE\\Software\\eWorld\\IP Detective\\Desktop\\Main)");
                else
                        Log_Memo->Lines->Add("Error: Main Window data NOT Saved in Registry.");
        lnRes = RegOpenOrCreateKeyEx("Software\\eWorld\\IP Detective\\Desktop\\Terminal", hkey);
         if( ERROR_SUCCESS == lnRes )
                if (SaveWindowSetting(TerminalFrm, hkey) && (ERROR_SUCCESS == RegCloseKey(hkey)))
                        Log_Memo->Lines->Add("Terminal Window data Saved in Registry (key: HKEY_LOCAL_MACHINE\\Software\\eWorld\\IP Detective\\Desktop\\ShortCuts)");
                else
                        Log_Memo->Lines->Add("Error: Terminal Window data NOT Saved in Registry.");
        lnRes = RegOpenOrCreateKeyEx("Software\\eWorld\\IP Detective\\Desktop\\ShortCuts", hkey);
         if( ERROR_SUCCESS == lnRes )
                if (SaveWindowSetting(ShortCutsFrm, hkey) && (ERROR_SUCCESS == RegCloseKey(hkey)))
                        Log_Memo->Lines->Add("ShortCuts Window data Saved in Registry (key: HKEY_LOCAL_MACHINE\\Software\\eWorld\\IP Detective\\Desktop\\Terminal)");
                else
                        Log_Memo->Lines->Add("Error: ShortCuts Window data NOT Saved in Registry.");
//        lnRes = RegOpenOrCreateKeyEx("Software\\eWorld\\IP Detective\\Desktop\\ShortCuts", hkey);
//         if( ERROR_SUCCESS == lnRes )
//                if (SaveWindowSetting(TerminalFrm, hkey) && (ERROR_SUCCESS == RegCloseKey(hkey)))
//                        Log_Memo->Lines->Add("Active Connection Window data Saved in Registry (key: HKEY_LOCAL_MACHINE\\Software\\eWorld\\IP Detective\\Desktop\\Terminal)");
        }
else    {                               // Save data to INI File
/*        CIniEx ini;
        CString str;
        CString comment;
        ini.OpenAtExeDirectory("desktop.ini");
        ini.SetValue("MainForm","Top",mainFrm->Top);
        ini.SetValue("MainForm","Left",mainFrm->Left);
        ini.SetValue("MainForm","Hight",mainFrm->Height);
        ini.SetValue("MainForm","Width",mainFrm->Width);

        if (TerminalFrm)
                {
                ini.SetValue("TerminalForm","Top",TerminalFrm->Top);
                ini.SetValue("TerminalForm","Left",TerminalFrm->Left);
                ini.SetValue("TerminalForm","Hight",TerminalFrm->Height);
                ini.SetValue("TerminalForm","Width",TerminalFrm->Width);
                };

        if (ShortCutsFrm)
                {
                ini.SetValue("ShortCutsForm","Top",ShortCutsFrm->Top);
                ini.SetValue("ShortCutsForm","Left",ShortCutsFrm->Left);
                ini.SetValue("ShortCutsForm","Hight",ShortCutsFrm->Height);
                ini.SetValue("ShortCutsForm","Width",ShortCutsFrm->Width);
                };

/*        if (ConnFrm)
                {
                ini.SetValue("TerminalForm","Top",TerminalFrm->Top);
                ini.SetValue("TerminalForm","Left",TerminalFrm->Left);
                ini.SetValue("TerminalForm","Hight",TerminalFrm->Height);
                ini.SetValue("TerminalForm","Width",TerminalFrm->Width);
                };

        ini.WriteFile():
*/
        };
}
//---------------------------------------------------------------------------

void __fastcall TmainFrm::FormShow(TObject *Sender)
{
 HKEY	hkey;
 LONG lnRes;
 Log_Memo->Clear();
 lnRes = RegOpenKeyEx( HKEY_LOCAL_MACHINE, "Software\\eWorld\\IP Detective\\Settings", 0L,KEY_ALL_ACCESS, &hkey);

 if(ERROR_SUCCESS == lnRes )
        {
// ciao

        }
 else
        {
        Log_Memo->Lines->Add("Probably first execution on this System, Registry is empty.");
        Log_Memo->Lines->Add("Loading default factory Settings.");
        };
        RegCloseKey(hkey);

if (!SystemPerf_opt->Checked)
        {
        if (Opt_LoadData_chk->Checked)
                {
                if (WhoIsServersList.GetStatus())
                        WhoIsServers_lbx->Items->LoadFromFile(WhoIsServersList.GetFileName());

                if ( (KeepLog_chk->Checked) && (AppLog.GetStatus()) )
                        {
                        Log_Memo->Lines->LoadFromFile(AppLog.GetFileName());
                        Log_Memo->Lines->Add("");
                        Log_Memo->Lines->Add("______________New Session.");
                        };

/*                for (int i = 0; i< ?? ; i++)
                        {
                        if (AllData[i]->Load())
                         Log_Memo->Lines->Add(AllData[i]->GetDescription() + " Service DLL Loaded.");
                        else
                         Log_Memo->Lines->Add("ERROR|" + (AllData[i]->GetDescription() + " Service DLL NOT Loaded.");
                        };
  */

///////////////////////////////////////////////////////////////////////
// TO DO:       ADD TIME AND DATE
                };
/*
        if (Opt_LoadDLLs_chk->Checked)
                {
                for (int i = 0; i< ?? ; i++)
                        {
                        if (AllServices[i]->Load())
                         Log_Memo->Lines->Add(AllServices[i]->GetDescription() + " Service DLL Loaded. (Version " + AllServices[i]->GetVersion() + ")");
                        else
                         Log_Memo->Lines->Add("ERROR|" + (AllServices[i]->GetDescription() + " Service DLL NOT Loaded.");
                        };
                };
*/
        };

}
//---------------------------------------------------------------------------

void __fastcall TmainFrm::DesktopLastSaved_MnuClick(TObject *Sender)
{
if (SaveToReg_Opt->Checked)
        {                               // Load data from Registry

        HKEY	hkey;
        LONG lnRes;

        lnRes = RegOpenKeyEx( HKEY_LOCAL_MACHINE, "Software\\eWorld\\IP Detective\\Desktop\\Main", 0L, KEY_READ, &hkey);
         if( ERROR_SUCCESS == lnRes )
                if (LoadWindowSetting(mainFrm, hkey) && (ERROR_SUCCESS == RegCloseKey(hkey)))
                        Log_Memo->Lines->Add("Main Window data Loaded from Registry (key: HKEY_LOCAL_MACHINE\\Software\\eWorld\\IP Detective\\Desktop\\Main)");
                else
                        Log_Memo->Lines->Add("Error: Main Window data NOT Loaded from Registry.");
        lnRes = RegOpenKeyEx( HKEY_LOCAL_MACHINE, "Software\\eWorld\\IP Detective\\Desktop\\Terminal", 0L, KEY_READ, &hkey);
         if( ERROR_SUCCESS == lnRes )
                if (LoadWindowSetting(TerminalFrm, hkey) && (ERROR_SUCCESS == RegCloseKey(hkey)))
                        Log_Memo->Lines->Add("Terminal Window data Loaded from Registry (key: HKEY_LOCAL_MACHINE\\Software\\eWorld\\IP Detective\\Desktop\\ShortCuts)");
                else
                        Log_Memo->Lines->Add("Error: Terminal Window data NOT Loaded from Registry.");
        lnRes = RegOpenKeyEx( HKEY_LOCAL_MACHINE, "Software\\eWorld\\IP Detective\\Desktop\\ShortCuts", 0L, KEY_READ, &hkey);
         if( ERROR_SUCCESS == lnRes )
                if (LoadWindowSetting(ShortCutsFrm, hkey) && (ERROR_SUCCESS == RegCloseKey(hkey)))
                        Log_Memo->Lines->Add("ShortCuts Window data Loaded from Registry (key: HKEY_LOCAL_MACHINE\\Software\\eWorld\\IP Detective\\Desktop\\Terminal)");
                else
                        Log_Memo->Lines->Add("Error: ShortCuts Window data NOT Loaded from Registry.");

        }
else    {                               // Load data from INI File
        };
}
//---------------------------------------------------------------------------








void __fastcall TmainFrm::TabICQShow(TObject *Sender)
{
 if (ICQServ.Status() && ICQMAPI.Status()) return;

  if (ICQServ.Load())
        Log_Memo->Lines->Add(ICQServ.GetDescription() + " Service DLL Loaded.");
  else
        Log_Memo->Lines->Add("ERROR|" + ICQServ.GetDescription() + " Service DLL NOT Loaded.");

  if (ICQMAPI.Load())
        Log_Memo->Lines->Add(ICQMAPI.GetDescription() + " Service DLL Loaded.");
  else
        Log_Memo->Lines->Add("ERROR|" + ICQMAPI.GetDescription() + " Service DLL NOT Loaded.");

 FARPROC YourFunct = GetProcAddress (ICQServ.GetIstance(), "YourFunctionNumberOne");
         if (YourFunct != NULL)
        	(*YourFunct)();
         else
        	MessageBox (NULL, "No Go", NULL, NULL);
}
//---------------------------------------------------------------------------

/*
HKEY hNotePadKey;
char Fontname[128]="N/A";
DWORD DataType;
DWORD DataCount=sizeof(Fontname);
if( RegOpenKeyEx( HKEY_CURRENT_USER, "Software\\Microsoft\\NotePad", 
	0, KEY_READ, &hNotePadKey ) == ERROR_SUCCESS )
	{
		if( RegQueryValueEx( hNotePadKey, "lfFaceName", 0, 
			&DataType, (unsigned char*)Fontname, &DataCount ) == ERROR_SUCCESS )
		{
		// The fontname used by notepad is now in the Fontname variable
		}
	RegCloseKey( hNotePadKey );
}

*/
void __fastcall TmainFrm::SettingsGenApply_BtnClick(TObject *Sender)
{
 HKEY	hkey = NULL;
 LONG lnRes;
 Log_Memo->Lines->Add("");
 Log_Memo->Lines->Add("Saving New General Settings to Registry.");

 lnRes = RegOpenOrCreateKeyEx("Software\\eWorld\\IP Detective\\Settings", hkey);

 if( ERROR_SUCCESS == lnRes )
  {
  AnsiString Names[] = {"OptimizeSystemPerformance" ,
                        "Opt_LoadServicesDLLs"      ,
                        "Opt_LoadApplicationData"   ,
                        "UseTrayIcon"               ,
                        "Tray_MinimizetoIcon"       ,
                        "Tray_Minimizeinsteadofclosing" ,
                        "Tray_Showalways"           ,
                        "AutoSaveDesktop"           ,
                        "SaveSettingsonExit"        ,
                        "ShowSplashScreen"          ,
                        "RunatStartUp"              ,
                        "DisableScreenSaver"        };
  unsigned int* Values;
  Values = new unsigned int [12];
        Values[0]  = SystemPerf_opt->Checked;
        Values[1]  = Opt_LoadDLLs_chk->Checked;
        Values[2]  = Opt_LoadData_chk->Checked;
        Values[3]  = TrayIcon_chk->Checked;
        Values[4]  = Tray_Minimize_chk->Checked;
        Values[5]  = Tray_NotClose_chk->Checked;
        Values[6]  = Tray_ShowAl_chk->Checked;
        Values[7]  = DesktopAutoSave_chk->Checked;
        Values[8]  = SaveonExit_chk->Checked;
        Values[9]  = SplashShow_chk->Checked;
        Values[10] = RunStartUp_chk->Checked;
        Values[11] = DisableScreenSaver_chk->Checked;

         DWORD dwType, dwSize;
         dwType = REG_BINARY;
         dwSize = sizeof(REG_BINARY);

        for (int i = 0; i < 12; i++  )
                {
                RegSetValueEx(hkey, TEXT(Names[i].c_str()), 0, dwType,
                              (unsigned char*)(&Values[i]), dwSize);
                }
        delete[] Values;

        Log_Memo->Lines->Add("Settings Saved.");
        }

 else
  Log_Memo->Lines->Add("Error: Settings NOT Saved.");

////////////////////////////////////////////////////////// Run On Windows Startup
if (RunStartUp_chk->Checked)
  {
  RegCloseKey(hkey);
  lnRes = RegOpenKeyEx(HKEY_LOCAL_MACHINE,
                       "SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\Run", 0L,
                       KEY_WRITE, &hkey);
  if( ERROR_SUCCESS == lnRes )
        {
        if (RunStartUp_chk->Checked)
                lnRes = RegSetValueEx(hkey, "IP Detective 2002", 0, REG_SZ,
                                     (Application->GetNamePath() + Application->ExeName).c_str(), REG_SZ);
                                     // WORKS ON WIN2000-NT ????
//BUG
        else
                lnRes = RegDeleteValue(hkey, "IP Detective 2002");

        Log_Memo->Lines->Add("StartUp Updated.");
        }
  else
        Log_Memo->Lines->Add("Error: Unable to Open Registry (HKEY_LOCAL_MACHINE\\SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\Run");
  };
//////////////////////////////////////////////////////////

  //SaveSettReg("", ->Checked, hkey);
}
//---------------------------------------------------------------------------


void __fastcall TmainFrm::ClearLog_mnuClick(TObject *Sender)
{
((TMemo *)Sender)->Clear();
}
//---------------------------------------------------------------------------

void __fastcall TmainFrm::SaveLogtoFile_mnuClick(TObject *Sender)
{
SaveDialog->Title = "Save LOG..";
SaveDialog->DefaultExt = "txt";
SaveDialog->Filter = "Text files (*.txt)|*.TXT|All files (*.*)|*.*";
SaveDialog->Options.Clear();
SaveDialog->Options << ofPathMustExist;
  if (SaveDialog->Execute())
        ((TMemo *)Sender)->Lines->SaveToFile(SaveDialog->FileName);

}
//---------------------------------------------------------------------------

void __fastcall TmainFrm::ExportWhoIsServers_btnClick(TObject *Sender)
{
        SaveDialog->Title = "Export WhoIs Server List..";
        SaveDialog->DefaultExt = "txt";
        SaveDialog->Filter = "Text files (*.txt)|*.TXT|All files (*.*)|*.*";
        SaveDialog->Options.Clear();
        SaveDialog->Options << ofPathMustExist;
        if (SaveDialog->Execute())
                WhoIsServers_lbx->Items->SaveToFile(SaveDialog->FileName);
}
//---------------------------------------------------------------------------

void __fastcall TmainFrm::ImportWhoIsServers_btnClick(TObject *Sender)
{
        OpenDialog->Title = "Import WhoIs Server List..";
        OpenDialog->DefaultExt = "txt";
        OpenDialog->Filter = "Text files (*.txt)|*.TXT|All files (*.*)|*.*";
        OpenDialog->Options.Clear();
        OpenDialog->Options << ofFileMustExist << ofPathMustExist;
        if (OpenDialog->Execute())
                WhoIsServers_lbx->Items->LoadFromFile(OpenDialog->FileName);
}
//---------------------------------------------------------------------------


void __fastcall TmainFrm::unMap_btnClick(TObject *Sender)
{
  // Show the UnMap Network Drive dialog.
  WNetDisconnectDialog( NULL, RESOURCETYPE_DISK);
}
//---------------------------------------------------------------------------

void __fastcall TmainFrm::Button6Click(TObject *Sender)
{
        FARPROC lpfn_ICQAPICall_SetLicenseKey = GetProcAddress (ICQMAPI.GetIstance(), "@ICQAPICall_SetLicenseKey$qv");
static char* devname = "";
static char* devcomp = "";
static char* devcode = "";
         if (lpfn_ICQAPICall_SetLicenseKey != NULL)
//        	(*lpfn_ICQAPICall_SetLicenseKey)(devname, devcomp, devcode);
//         else
        	MessageBox (NULL, "No Go", NULL, NULL);

}
//---------------------------------------------------------------------------


void __fastcall TmainFrm::AppDirTreeViewChange(TObject *Sender,
      TTreeNode *Node)
{

 if (!AppDirTreeView->Selected->SelectedIndex)
        {
        DirDefPath_stlb->Caption  = "";
        DirActPath_stlb->Caption  = "";
        DirDescript_stlb->Caption = "";
        }
 else if (AppDirTreeView->Selected->SelectedIndex < 30)      // Service DLLs
        {
        DirDefPath_stlb->Caption  = AllServices[AppDirTreeView->Selected->SelectedIndex-11]->GetdefFileName();
        DirActPath_stlb->Caption  = AllServices[AppDirTreeView->Selected->SelectedIndex-11]->GetFileName();
        DirDescript_stlb->Caption =  "\t\t\tService DLL.\n\nThread Status:\t";
                if (AllServices[AppDirTreeView->Selected->SelectedIndex-11]->Status())
                        DirDescript_stlb->Caption = DirDescript_stlb->Caption + "Loaded.";
                else
                        DirDescript_stlb->Caption = DirDescript_stlb->Caption + "Not Loaded jet. (it will be loaded at first use)";
        DirDescript_stlb->Caption = DirDescript_stlb->Caption + "\nDescription:\t"
                                     + AllServices[AppDirTreeView->Selected->SelectedIndex-11]->GetDescription()
                                     + "\nVersion: \t\t"
                                     + AllServices[AppDirTreeView->Selected->SelectedIndex-11]->GetVersion();
        }
 else if (AppDirTreeView->Selected->SelectedIndex < 40)    // Servers DLLs
        {
        DirDefPath_stlb->Caption  = AllServers[AppDirTreeView->Selected->SelectedIndex-31]->GetdefFileName();
        DirActPath_stlb->Caption  = AllServers[AppDirTreeView->Selected->SelectedIndex-31]->GetFileName();
        DirDescript_stlb->Caption =  "\t\t\tServer DLL.\n\nThread Status:\t";
                if (AllServers[AppDirTreeView->Selected->SelectedIndex-31]->Status())
                        DirDescript_stlb->Caption = DirDescript_stlb->Caption + "Loaded.";
                else
                        DirDescript_stlb->Caption = DirDescript_stlb->Caption +  "Not Loaded yet. (it will be loaded at first use)";
        DirDescript_stlb->Caption = DirDescript_stlb->Caption +  "\nDescription:\t"
                                     + AllServers[AppDirTreeView->Selected->SelectedIndex-31]->GetDescription()
                                     + "\nVersion: \t\t"
                                     + AllServers[AppDirTreeView->Selected->SelectedIndex-31]->GetVersion();
        }
 else if (AppDirTreeView->Selected->SelectedIndex < 50)    // Application Data
        {
        DirDefPath_stlb->Caption  = AllData[AppDirTreeView->Selected->SelectedIndex-41]->GetdefFileName();
        DirActPath_stlb->Caption  = AllData[AppDirTreeView->Selected->SelectedIndex-41]->GetFileName();

        DirDescript_stlb->Caption =  "\t\t\tApplication Data File.\n\nMemory Status:\tNOT IMPLEMENTED YET.";

        DirDescript_stlb->Caption = DirDescript_stlb->Caption + "\nDescription:\t"
                                     + AllData[AppDirTreeView->Selected->SelectedIndex-41]->GetDescription()
                                     + "\nType: \t\t"
                                     + AllData[AppDirTreeView->Selected->SelectedIndex-41]->GetTypeString();
        };

}
//---------------------------------------------------------------------------

void __fastcall TmainFrm::TermConnect_btnClick(TObject *Sender)
{
 TConsole_Memo->Lines->Add("");
 TConsole_Memo->Lines->Add("");
 TConsole_Memo->Lines->Add("$ystem:\tConnecting to " + TermTargetIP_txt->Text + "@ port " + TermTargetPort_txt->Text);

 // CONNECT

 }
//---------------------------------------------------------------------------


void __fastcall TmainFrm::TermDisconnect_btnClick(TObject *Sender)
{
 TConsole_Memo->Lines->Add("");
 TConsole_Memo->Lines->Add("$ystem:\tDisconnecting from " + TermTargetIP_txt->Text + "@ port " + TermTargetPort_txt->Text);

}
//---------------------------------------------------------------------------

void __fastcall TmainFrm::LocalServer_cmbChange(TObject *Sender)
{
switch (LocalServer_cmb->ItemIndex)
        {
      case 0:
            {
//              FTP Server
            };
            break;
      case 1:
            {
//              AnonyProxy Server
            };
            break;
      case 2:
            {
//              Echo Server
//        OpenService(ICQServ, true);
        FARPROC YourFunct = GetProcAddress (LServEcho.GetIstance(), "YourFunctionNumberOne");
         if (YourFunct != NULL)
        	(*YourFunct)();
         else
        	MessageBox (NULL, "No Go", NULL, NULL);

            };
            break;

        };
}
//---------------------------------------------------------------------------





void __fastcall TmainFrm::Auto_CListBoxDragOver(TObject *Sender,
      TObject *Source, int X, int Y, TDragState State, bool &Accept)
{
  Accept = Source->ClassNameIs("TListBox");
}
//---------------------------------------------------------------------------

void __fastcall TmainFrm::Auto_CListBoxDragDrop(TObject *Sender,
      TObject *Source, int X, int Y)
{
        Auto_CListBox->Items->Add(((TListBox *)Source)->Items->Strings[((TListBox *)Source)->ItemIndex]);
}
//---------------------------------------------------------------------------

void __fastcall TmainFrm::RFCFiles_EdDblClick(TObject *Sender)
{
        OpenDialog->Title = "Load References Database..";
        OpenDialog->DefaultExt = "txt";
        OpenDialog->Filter = "Text files (*.txt)|*.TXT|All files (*.*)|*.*";
        OpenDialog->Options.Clear();
        OpenDialog->Options << ofPathMustExist;
//  if (SaveDialog->Execute())
        }
//---------------------------------------------------------------------------



void __fastcall TmainFrm::AddShortCut_btnClick(TObject *Sender)
{

if (ShortCutName_txt->Text == "") return;
if (!FileExists(ShortCutPath_txt->Text))
        {
        ShowMessage("File not found:\n" + ShortCutPath_txt->Text);
        return;
        };

  TListItem *pItem;
  pItem = ShortCutsListView->Items->Add();
  pItem->Caption = ShortCutName_txt->Text;
  pItem->SubItems->Add(ShortCutPath_txt->Text);

/*
  TListItem *pItem;
  TListColumn *pColumn;

  for (int i = 0; i < ImageList1->Count; i++)
  {
    pItem = ListView1->Items->Add();
    pItem->Caption = "Image" + IntToStr(i);
    pItem->ImageIndex = i;
  }
  // Create two columns to show during viewing as vsReport

  pColumn = ListView1->Columns->Add();
  pColumn->Caption = "Column 1";
  pColumn = ListView1->Columns->Add();
  pColumn->Caption = "Column 2";
*/
}
//---------------------------------------------------------------------------

void __fastcall TmainFrm::AddWIs_btnClick(TObject *Sender)
{
//WhoIsServers_lbx->Items->Add();
}
//---------------------------------------------------------------------------

void __fastcall TmainFrm::RemoveWIs_btnClick(TObject *Sender)
{
        if (WhoIsServers_lbx->ItemIndex != -1)
                WhoIsServers_lbx->Items->Delete(WhoIsServers_lbx->ItemIndex);
}
//---------------------------------------------------------------------------

void __fastcall TmainFrm::PingPsize_txtChange(TObject *Sender)
{
PingDefaults_chk->Checked = false;
}
//---------------------------------------------------------------------------

void __fastcall TmainFrm::PingT_txtChange(TObject *Sender)
{
PingDefaults_chk->Checked = false;        
}
//---------------------------------------------------------------------------

void __fastcall TmainFrm::PingD_txtChange(TObject *Sender)
{
PingDefaults_chk->Checked = false;        
}
//---------------------------------------------------------------------------

void __fastcall TmainFrm::PingPn_txtChange(TObject *Sender)
{
PingDefaults_chk->Checked = false;        
}
//---------------------------------------------------------------------------

void __fastcall TmainFrm::PingDefaults_chkClick(TObject *Sender)
{
  if (PingDefaults_chk->Checked)        // Default Values
        {
        PingPsize_txt->Text = IntToStr( 32 );
        PingT_txt->Text     = IntToStr( 3000 );
        PingD_txt->Text     = IntToStr( 100 );
        PingPn_txt->Text    = IntToStr( 10 );
        };
}
//---------------------------------------------------------------------------



void __fastcall TmainFrm::ShortCutOpenItemPath_imgClick(TObject *Sender)
{
        OpenDialog->Title = "Load Application Path..";
        OpenDialog->DefaultExt = "exe";
        OpenDialog->Filter = "Applications (*.exe)|*.EXE|All files (*.*)|*.*";
        OpenDialog->Options.Clear();
        OpenDialog->Options << ofFileMustExist << ofPathMustExist;
        if (OpenDialog->Execute())
                ShortCutPath_txt->Text = OpenDialog->FileName;
}
//---------------------------------------------------------------------------


void __fastcall TmainFrm::ShortCutsListViewSelectItem(TObject *Sender,
      TListItem *Item, bool Selected)
{
       if (Item->SubItems->Text != "")
            ShellExecute(NULL, "open", (Item->SubItems->Text).c_str(), "", "", SW_SHOWDEFAULT);

}
//---------------------------------------------------------------------------

void __fastcall TmainFrm::ShowLog_mnuClick(TObject *Sender)
{
ViewControlTabs->ActivePage = ViewControlTabs->Pages[0];
SettingsTabs->ActivePage = SettingsTabs->Pages[4];
}
//---------------------------------------------------------------------------


bool AppData::SetFileName(AnsiString newFileName)
{
    if (FileExists(newFileName))
        {
        this->FileName = newFileName;
        this->Status = true;
        return true;
        }
    this->FileName = "ERROR - File not Found";
    this->Status = false;
    return false;
}

AppData::AppData(AnsiString newFileName, int nDataType, AnsiString newDescription /* ="" */)
 {
        this->Status = SetFileName(defFileName);
        this->defFileName = newFileName;
        this->DataType = nDataType;        // 0 = ini, 1 = txt, 2 = Database
        this->Description = newDescription;
 }

AnsiString AppData::GetTypeString()
 {
 switch (this->DataType)
        {
        case 0: return "Standard INI File";
        case 1: return "Plain TXT File (one item for each line)";
        case 2: return "Database";
        };
 return "UnKnow";
 }

//---------------------------------------------------------------------------

void __fastcall TmainFrm::TerminalFont_mnuClick(TObject *Sender)
{
  if (FontDialog->Execute())
        {
        TConsole_Memo->Font->Assign(FontDialog->Font);
        TConsole_cmb->Font->Assign(FontDialog->Font);
        if (TerminalFrm)
                {
                TerminalFrm->TConsole_Memo->Font->Assign(FontDialog->Font);
                TerminalFrm->TConsole_cmb->Font->Assign(FontDialog->Font);
                };
        };
}

//---------------------------------------------------------------------------

void __fastcall TmainFrm::TerminalColor_mnuClick(TObject *Sender)
{
  if (ColorDialog->Execute())
        {
        TConsole_Memo->Font->Color = ColorDialog->Color;
        TConsole_cmb->Font->Color = ColorDialog->Color;
        if (TerminalFrm)
                {
                TerminalFrm->TConsole_Memo->Font->Color = ColorDialog->Color;
                TerminalFrm->TConsole_cmb->Font->Color = ColorDialog->Color;
                };
        };
}
//---------------------------------------------------------------------------

void __fastcall TmainFrm::OpenCmdList_imgClick(TObject *Sender)
{
        OpenDialog->Title = "Load Commands List..";
        OpenDialog->DefaultExt = "txt";
        OpenDialog->Filter = "Plain Text (*.txt)|*.TXT|All files (*.*)|*.*";
        OpenDialog->Options.Clear();
        OpenDialog->Options << ofFileMustExist << ofPathMustExist;
        if (OpenDialog->Execute())
                {
                TerminalCmdList_lbx->Items->LoadFromFile(OpenDialog->FileName);
                TerminalCmdPath_slb->Font->Style = TFontStyles();
                TerminalCmdPath_slb->Caption = OpenDialog->FileName;
                }
}
//---------------------------------------------------------------------------

void __fastcall TmainFrm::TermSendListCmds_btnClick(TObject *Sender)
{

   if (TerminalCmdList_lbx->Items->Count)
        {
        TConsole_Memo->Lines->Add("$ystem:\t Sending Commands List");
        if (TerminalFrm) TerminalFrm->TConsole_Memo->Lines->Add("$ystem:\t Sending Commands List");
        for (int i = 0 ; i < TerminalCmdList_lbx->Items->Count ; i++)
                {
// SEND         TerminalCmdList_lbx->Items->String[i]
                TConsole_Memo->Lines->Add("£ocal:\t" + TerminalCmdList_lbx->Items->Strings[i]);
                if (TerminalFrm) TerminalFrm->TConsole_Memo->Lines->Add("£ocal:\t" + TerminalCmdList_lbx->Items->Strings[i]);
                }
        TConsole_Memo->Lines->Add("$ystem:\t Commands List Sent.");
        if (TerminalFrm) TerminalFrm->TConsole_Memo->Lines->Add("$ystem:\t Commands List Sent.");
        }
   else
        TConsole_Memo->Lines->Add("$ystem:\t ERROR| Commands List is empty.");
        if (TerminalFrm) TerminalFrm->TConsole_Memo->Lines->Add("$ystem:\t ERROR| Commands List is empty.");
}
//---------------------------------------------------------------------------

//---------------------------------------------------------------------------


void __fastcall TmainFrm::TerminalCmdList_lbxClick(TObject *Sender)
{
   if (TermLCmdSync_chk->Checked && (TerminalCmdList_lbx->ItemIndex != -1))
        {
        TConsole_cmb->Text = TerminalCmdList_lbx->Items->Strings[TerminalCmdList_lbx->ItemIndex];
        if (TerminalFrm) TerminalFrm->TConsole_cmb->Text = TerminalCmdList_lbx->Items->Strings[TerminalCmdList_lbx->ItemIndex];
        };
 }
//---------------------------------------------------------------------------

void __fastcall TmainFrm::LogsClear_btnClick(TObject *Sender)
{
 if (!IELogs_TreeView->Selected->SelectedIndex) return;

 if (CleagLogsShowAlert_chk->Checked)
        if (MessageBox(NULL, "Are you sure to Clean this Log?", "Log Cleaner - IP Detective",
                       MB_OKCANCEL + MB_DEFBUTTON2 +MB_ICONWARNING) == IDCANCEL)
                return;

 if (CleagLogsReportClean_chk->Checked)
        CleagLogs_Memo->Clear();
 else
        CleagLogs_Memo->Lines->Add("");


 switch (IELogs_TreeView->Selected->SelectedIndex) {

  case 100:      // Clear All Logs for Internet Explorer
        {
        CleagLogs_Memo->Lines->Add("_____Cleaning All Internet Explorer Logs");
        CleagLogs_Memo->Lines->Add("");
        };
  case 101:      // Delete all items in History folder
        {
        CleagLogs_Memo->Lines->Add("Deleting Internet Explorer History. [same as Internet Options]");
        IUrlHistoryStg2* pUrlHistoryStg2 = NULL;
        HRESULT hr = CoCreateInstance(CLSID_CUrlHistory,
        NULL, CLSCTX_INPROC, IID_IUrlHistoryStg2,
        (void**)&pUrlHistoryStg2);
        if (SUCCEEDED(hr))
                {
                hr = pUrlHistoryStg2->ClearHistory();
                pUrlHistoryStg2->Release();
                CleagLogs_Memo->Lines->Add("\tHistory Cleaned.");
                }
        else
                CleagLogs_Memo->Lines->Add("ERROR|\tHistory NOT Cleaned.");
        };
        if (IELogs_TreeView->Selected->SelectedIndex != 100) break;
  case 102:      //
        {
        };
        if (IELogs_TreeView->Selected->SelectedIndex != 100) break;
  case 103:      //
        {
        };
        if (IELogs_TreeView->Selected->SelectedIndex != 100) break;
  case 104:      //
        {
        };
        if (IELogs_TreeView->Selected->SelectedIndex != 100) break;
    };
    return;
}
//---------------------------------------------------------------------------


void __fastcall TmainFrm::LAN_CPModem_btnClick(TObject *Sender)
{
WinExec("rundll32.exe shell32.dll,Control_RunDLL Modem.cpl,,add",1);
}
//---------------------------------------------------------------------------

void __fastcall TmainFrm::TRCheckAll_optClick(TObject *Sender)
{
        TRCheckAll_opt->Checked = true;
//  for (int i = 0; i < TrojanListView->Items->Count; i++)
//  {
//        TrojanListView->Items->Checked = true;
//  }

}
//---------------------------------------------------------------------------


void __fastcall TmainFrm::OpenData_imgClick(TObject *Sender)
{


  if (AppDirTreeView->Selected->SelectedIndex < 30)
        {
        OpenDialog->Title = "Load Application Service DLL..";
        OpenDialog->DefaultExt = "dll";
        OpenDialog->Filter = "Dynamic Link Libraries (*.dll)|*.DLL|All files (*.*)|*.*";
        OpenDialog->Options.Clear();
        OpenDialog->Options << ofFileMustExist << ofPathMustExist;
        if (OpenDialog->Execute())
                {
                AllServices[AppDirTreeView->Selected->SelectedIndex-11]->SetFileName(OpenDialog->FileName);
                DirActPath_stlb->Caption = AllServices[AppDirTreeView->Selected->SelectedIndex-11]->GetFileName();
                };
        }
  else if (AppDirTreeView->Selected->SelectedIndex < 40)  {
        OpenDialog->Title = "Load Application Server Service DLL..";
        OpenDialog->DefaultExt = "dll";
        OpenDialog->Filter = "Dynamic Link Libraries (*.dll)|*.DLL|All files (*.*)|*.*";
        OpenDialog->Options.Clear();
        OpenDialog->Options << ofFileMustExist << ofPathMustExist;
        if (OpenDialog->Execute())
                {
                AllServers[AppDirTreeView->Selected->SelectedIndex-31]->SetFileName(OpenDialog->FileName);
                DirActPath_stlb->Caption = AllServers[AppDirTreeView->Selected->SelectedIndex-31]->GetFileName();
                };
        }
  else if (AppDirTreeView->Selected->SelectedIndex < 50)  {
        OpenDialog->Title = "Load Application Data Files..";
        OpenDialog->DefaultExt = "dll";
        OpenDialog->Filter = "TextFile (*.txt)|*.DLL|All files (*.*)|*.*";
        OpenDialog->Options.Clear();
        OpenDialog->Options << ofFileMustExist << ofPathMustExist;
        if (OpenDialog->Execute())
                {
                AllData[AppDirTreeView->Selected->SelectedIndex-41]->SetFileName(OpenDialog->FileName);
                DirActPath_stlb->Caption = AllData[AppDirTreeView->Selected->SelectedIndex-41]->GetFileName();
                };
        };
}
//---------------------------------------------------------------------------


void __fastcall TmainFrm::RFCManageFiles_btnClick(TObject *Sender)
{
        ShellExecute(NULL, "open", (RFCFiles_Ed->Text).c_str(), "", "", SW_SHOWDEFAULT);

}
//---------------------------------------------------------------------------

void __fastcall TmainFrm::ShortCutOpenList_imgClick(TObject *Sender)
{
        OpenDialog->Title = "Load ShortCuts List..";
        OpenDialog->DefaultExt = "db";
        OpenDialog->Filter = "DataBase (*.db)|*.DB|All files (*.*)|*.*";
        OpenDialog->Options.Clear();
        OpenDialog->Options << ofFileMustExist << ofPathMustExist;
        if (OpenDialog->Execute())
                ShortCutsFileList_slb->Caption = OpenDialog->FileName;

}
//---------------------------------------------------------------------------

void __fastcall TmainFrm::LAN_CPInternet_btnClick(TObject *Sender)
{
WinExec("rundll32.exe shell32.dll,Control_RunDLL INETCPL.CPL,,add",1);
}
//---------------------------------------------------------------------------

void __fastcall TmainFrm::LAN_CPSystem_btnClick(TObject *Sender)
{
WinExec("rundll32.exe shell32.dll,Control_RunDLL sysdm.cpl,,add",1);
}
//---------------------------------------------------------------------------

void __fastcall TmainFrm::TerminalCmdList_lbxDblClick(TObject *Sender)
{
   if (TermLCmdSync_chk->Checked && (TerminalCmdList_lbx->ItemIndex != -1))
        {
        TConsole_cmb->Text = TerminalCmdList_lbx->Items->Strings[TerminalCmdList_lbx->ItemIndex];
//SEND  TConsole_cmb->Text
        TConsole_Memo->Lines->Add("£ocal:\t" + TConsole_cmb->Text);

        TerminalFrm->TConsole_cmb->Text = TConsole_cmb->Text;
        TerminalFrm->TConsole_Memo->Lines->Add("£ocal:\t" + TConsole_cmb->Text);
        };
}
//---------------------------------------------------------------------------

void __fastcall TmainFrm::IPorHost_slbClick(TObject *Sender)
{
        TEdit * TextBoxLink = (TEdit *)((TStaticText *)Sender)->FocusControl;
        TStaticText * ThisLabel = (TStaticText *)Sender;
        hostent *hp =0;
        unsigned int addr=0;
        // explain:     Using 'FocusControl' property to link a caption object to relative textbox
        //              but implementing only 1 function for all as u seen in the objects' calls. :)

 if (ThisLabel->Caption == "Target IP address:")
        {

        if (TextBoxLink->Text == "")// if user want to type an hostname clicks when it's blank
                {
                ThisLabel->Caption = "Target HostName:";
                return;
                }
        else if (TextBoxLink->Text == "127.0.0.1")// BUG on my network?! winsock2 cannot resolve localhost as 127.0.0.1
                {                                 // I find out this problem only on this program. I'll check better for it.
                TextBoxLink->Text = "localhost";
                ThisLabel->Caption = "Target HostName:";
                return;
                };
        // Convert ip-address to a usable one
        addr = inet_addr(TextBoxLink->Text.c_str()) ;
        if (!addr)
                {
                ShowMessage(TextBoxLink->Text + " is not a valid IP Address.\n[A valid IP is 127.0.0.1]");
                return;
                };
        // Retrieves the host information
        hp = gethostbyaddr( ( char *) &addr, 4, AF_INET);
        if (!hp)
                {
                ShowMessage("WinSock cannot resolve " + TextBoxLink->Text + "\nCheck IP or DNS settings.");
                return;
                };
        ThisLabel->Caption = "Target HostName:";
        TextBoxLink->Text = AnsiString(( char *)hp->h_name);

        }
 else
        {
        if (TextBoxLink->Text == "")// if user want to type an ip address clicks when it's blank
                {
                ThisLabel->Caption = "Target IP address:";
                return;
                }
        else if (TextBoxLink->Text == "localhost")// BUG on my network?! winsock2 cannot resolve localhost as 127.0.0.1
                {                                 // I find out this problem only on this program. I'll check better for it.
                TextBoxLink->Text = "127.0.0.1";
                ThisLabel->Caption = "Target IP address:";
                return;
                };
        hp = gethostbyname( ( char *) TextBoxLink->Text.c_str());
        if (hp)//->h_addrtype == AF_INET)
                {
                ShowMessage("WinSock cannot resolve " + TextBoxLink->Text + "\nCheck HostName or DNS settings.");
                return;
                };
        ThisLabel->Caption = "Target IP address:";
        in_addr *ppip=(in_addr*)hp->h_addr_list[0];
        TextBoxLink->Text = AnsiString(  inet_ntoa(*ppip)  );
        };
}
//---------------------------------------------------------------------------

void __fastcall TmainFrm::TabPingerShow(TObject *Sender)
{
 if (Ping.Status()) return;

  if (Ping.Load())
        Log_Memo->Lines->Add(Ping.GetDescription() + " Service DLL Loaded. (Version " + Ping.GetVersion() + ")");
  else
        Log_Memo->Lines->Add("ERROR|\t" + Ping.GetDescription() + " Service DLL NOT Loaded.");
}
//---------------------------------------------------------------------------

void __fastcall TmainFrm::TabFingerShow(TObject *Sender)
{
 if (Finger.Status()) return;

  if (Finger.Load())
        Log_Memo->Lines->Add(Finger.GetDescription() + " Service DLL Loaded. (Version " + Finger.GetVersion() + ")");
  else
        Log_Memo->Lines->Add("ERROR|\t" + Finger.GetDescription() + " Service DLL NOT Loaded.");
}
//---------------------------------------------------------------------------

void __fastcall TmainFrm::TabPortScannerShow(TObject *Sender)
{
 if (PortScanner.Status()) return;

  if (PortScanner.Load())
        Log_Memo->Lines->Add(PortScanner.GetDescription() + " Service DLL Loaded. (Version " + PortScanner.GetVersion() + ")");
  else
        Log_Memo->Lines->Add("ERROR|\t" + PortScanner.GetDescription() + " Service DLL NOT Loaded.");
       
}
//---------------------------------------------------------------------------

void __fastcall TmainFrm::TabTraceRouteShow(TObject *Sender)
{
 if (TraceRoute.Status()) return;

  if (TraceRoute.Load())
        Log_Memo->Lines->Add(TraceRoute.GetDescription() + " Service DLL Loaded. (Version " + TraceRoute.GetVersion() + ")");
  else
        Log_Memo->Lines->Add("ERROR|\t" + TraceRoute.GetDescription() + " Service DLL NOT Loaded.");
       
}
//---------------------------------------------------------------------------

void __fastcall TmainFrm::TabOSDetectionShow(TObject *Sender)
{
 if (OSFinger.Status()) return;

  if (OSFinger.Load())
        Log_Memo->Lines->Add(OSFinger.GetDescription() + " Service DLL Loaded. (Version " + OSFinger.GetVersion() + ")");
  else
        Log_Memo->Lines->Add("ERROR|\t" + OSFinger.GetDescription() + " Service DLL NOT Loaded.");
       
}
//---------------------------------------------------------------------------

void __fastcall TmainFrm::TabEMailValidatorShow(TObject *Sender)
{
 if (EmailServ.Status()) return;

  if (EmailServ.Load())
        Log_Memo->Lines->Add(EmailServ.GetDescription() + " Service DLL Loaded. (Version " + EmailServ.GetVersion() + ")");
  else
        Log_Memo->Lines->Add("ERROR|\t" + EmailServ.GetDescription() + " Service DLL NOT Loaded.");
       
}
//---------------------------------------------------------------------------

void __fastcall TmainFrm::TabLANServicesShow(TObject *Sender)
{
 if (LANServ.Status()) return;

  if (LANServ.Load())
        Log_Memo->Lines->Add(LANServ.GetDescription() + " Service DLL Loaded. (Version " + LANServ.GetVersion() + ")");
  else
        Log_Memo->Lines->Add("ERROR|\t" + LANServ.GetDescription() + " Service DLL NOT Loaded.");
       
}
//---------------------------------------------------------------------------

void __fastcall TmainFrm::TabTRScannerServiceShow(TObject *Sender)
{
 if (TrScanner.Status()) return;

  if (TrScanner.Load())
        Log_Memo->Lines->Add(TrScanner.GetDescription() + " Service DLL Loaded. (Version " + TrScanner.GetVersion() + ")");
  else
        Log_Memo->Lines->Add("ERROR|\t" + TrScanner.GetDescription() + " Service DLL NOT Loaded.");
       
}
//---------------------------------------------------------------------------

void __fastcall TmainFrm::TabWWWServiceShow(TObject *Sender)
{
 if (WWWServ.Status()) return;

  if (WWWServ.Load())
        Log_Memo->Lines->Add(WWWServ.GetDescription() + " Service DLL Loaded. (Version " + WWWServ.GetVersion() + ")");
  else
        Log_Memo->Lines->Add("ERROR|\t" + WWWServ.GetDescription() + " Service DLL NOT Loaded.");
       
}
//---------------------------------------------------------------------------

void __fastcall TmainFrm::TabSimpleServicesShow(TObject *Sender)
{
 if (SimpleServ.Status()) return;

  if (SimpleServ.Load())
        {
        Log_Memo->Lines->Add(SimpleServ.GetDescription() + " Service DLL Loaded. (Version " + SimpleServ.GetVersion() + ")");

        // Enumerate and save simple services
        (FARPROC) lpfn_SimpleSEnum = GetProcAddress (SimpleServ.GetIstance(), "EnumServices");
        if (lpfn_SimpleSEnum != NULL)
                {
                int i = 0;
                while (lpfn_SimpleSEnum(i) != "")
                        SimpleServices_cmb->Items->Add(lpfn_SimpleSEnum(i++));
                SimpleS_Memo->Lines->Add("Avaiable Services Listed:\t" + AnsiString(i) + " found.");
                }
        else
                SimpleS_Memo->Lines->Add("ERROR:\t Service Function (EnumServices) NOT Found.");



        }
  else
        Log_Memo->Lines->Add("ERROR|\t" + SimpleServ.GetDescription() + " Service DLL NOT Loaded.");

}
//---------------------------------------------------------------------------

void __fastcall TmainFrm::RFCRefleshList_btnClick(TObject *Sender)
{
 if (RFCFiles_Ed->Text[0] == '\\')
        {
        // Relative Path
        AnsiString RFCPath = ExtractFileDir(Application->GetNamePath()) + RFCFiles_Ed->Text;

        };


}
//---------------------------------------------------------------------------

void __fastcall TmainFrm::GetLANInfo_BtnClick(TObject *Sender)
{
        if (!LanInfos_TreeView->Selected->SelectedIndex) return;

        if (!LANServ.Load())
                {
                LANInfo_Memo->Lines->Add("ERROR:\t LAN Infos DLL NOT Loaded.");
                LANInfo_Memo->Lines->Add("Open 'Settings->Directories and DLLs' to open a valid file.");
                return;
                };

        if (LANReportClean_chk->Checked)
                LANInfo_Memo->Clear();
        else    LANInfo_Memo->Lines->Add("");

 switch (LanInfos_TreeView->Selected->SelectedIndex)
  {
  case 10:      // LAN Infos
        {
        LANInfo_Memo->Lines->Add("________Loading LAN Infos");
        LANInfo_Memo->Lines->Add("");
        LANInfo_Memo->Lines->Add("");
        };
  case 11:      //Network Infos
        {
        LANInfo_Memo->Lines->Add("________NetWork Infos");
        LANInfo_Memo->Lines->Add("");


        (FARPROC) lpfn_LAN_EnumNetwork = GetProcAddress (LANServ.GetIstance(), "EnumNetHandler");
        if (lpfn_LAN_EnumNetwork != NULL)
                (lpfn_LAN_EnumNetwork)(0, NULL , LANInfo_Memo);
        else
                LANInfo_Memo->Lines->Add("ERROR:\t Service Function (EnumNetHandler) NOT Found.");

        };
        if (LanInfos_TreeView->Selected->SelectedIndex != 10) break;
  case 12:      // Ethernet Cards
        {
        LANInfo_Memo->Lines->Add("________Ethernet Card Infos");
        LANInfo_Memo->Lines->Add("");

        (FARPROC) lpfn_GetMACAdapters = GetProcAddress (LANServ.GetIstance(), "GetMACAdapters");
        if (lpfn_GetMACAdapters != NULL)
                (lpfn_GetMACAdapters)(0, LANInfo_Memo);
        else
                LANInfo_Memo->Lines->Add("ERROR:\t Service Function (GetMACAdapters) NOT Found.");

        };
        if (LanInfos_TreeView->Selected->SelectedIndex != 10) break;
  case 13:      // LAN MAPPED Drives
        {
        LANInfo_Memo->Lines->Add("________NetWork Drives Infos");
        LANInfo_Memo->Lines->Add("");

        (FARPROC) lpfn_LAN_EnumDrives = GetProcAddress (LANServ.GetIstance(), "EnumerateDrives");
        if (lpfn_LAN_EnumDrives != NULL)
                (lpfn_LAN_EnumDrives)(LANInfo_Memo);
        else
                LANInfo_Memo->Lines->Add("ERROR:\t Service Function (EnumerateDrives) NOT Found.");
        };
        break;
  case 14:      // List Users
        {
        LANInfo_Memo->Lines->Add("________Local Users Infos");
        LANInfo_Memo->Lines->Add("");

        (FARPROC) lpfn_LAN_EnumerateUsers = GetProcAddress (LANServ.GetIstance(), "EnumerateUsers");
        if (lpfn_LAN_EnumerateUsers != NULL)
                (lpfn_LAN_EnumerateUsers)(NULL, LANInfo_Memo);
        else
                LANInfo_Memo->Lines->Add("ERROR:\t Service Function (EnumerateUsers) NOT Found.");
        };
        break;
  case 15:      // List Groups
        {
        LANInfo_Memo->Lines->Add("________Local Groups Infos");
        LANInfo_Memo->Lines->Add("");

        (FARPROC) lpfn_LAN_EnumerateGroups = GetProcAddress (LANServ.GetIstance(), "EnumerateGroups");
        if (lpfn_LAN_EnumerateGroups != NULL)
                (lpfn_LAN_EnumerateGroups)(NULL, LANInfo_Memo);
        else
                LANInfo_Memo->Lines->Add("ERROR:\t Service Function (EnumerateGroups) NOT Found.");
        };
        break;
  case 16:      // List Servers
        {
        LANInfo_Memo->Lines->Add("________Listing LAN Servers");
        LANInfo_Memo->Lines->Add("");

        (FARPROC) lpfn_LAN_EnumerateServers = GetProcAddress (LANServ.GetIstance(), "EnumerateServers");
        if (lpfn_LAN_EnumerateServers != NULL)
                (lpfn_LAN_EnumerateServers)(NULL, NULL, LANInfo_Memo);
        else
                LANInfo_Memo->Lines->Add("ERROR:\t Service Function (EnumerateServers) NOT Found.");
        };
        break;

//  bool (PASCAL FAR * lpfn_LAN_EnumNetHandler)(DWORD dwLevel, LPNETRESOURCE lpNet, TMemo* Report);
//  bool (PASCAL FAR * lpfn_LAN_EnumerateServerDisks)(AnsiString Server, TMemo *Report);
//  bool (PASCAL FAR * lpfn_LAN_GetDCName)(AnsiString Server, AnsiString Domain, TMemo *Report);;

  };
}
//---------------------------------------------------------------------------


void __fastcall TmainFrm::LAN_LocExpl_btnClick(TObject *Sender)
{
WinExec("%SystemRoot%\explorer.exe %HOMEDRIVE%",1);
}
//---------------------------------------------------------------------------

void __fastcall TmainFrm::LAN_IntExpl_btnClick(TObject *Sender)
{
//GET IE PATH

}
//---------------------------------------------------------------------------




void __fastcall TmainFrm::TraspApply_btnClick(TObject *Sender)
{
// CHECK IF WIN2000

HWND hWnd = NULL;

switch (TranspForm_cmb->ItemIndex)
        {
        case 0: hWnd = mainFrm->Handle;
                break;
        case 1: if (TerminalFrm) hWnd = TerminalFrm->Handle;
                break;
        case 2: if (ShortCutsFrm) hWnd = ShortCutsFrm->Handle;
                break;
//        case 3: if (ActConnFrm) hWnd = ActConnFrm->Handle;
//                break;
        };

if (hWnd == NULL)
        {
        ShowMessage("Window must be active to set this property.");
        return;
        };
SetWindowLong(hWnd ,GWL_EXSTYLE,GetWindowLong(hWnd,GWL_EXSTYLE)^WS_EX_LAYERED);
SetLayeredWindowAttributes(hWnd,RGB(0,0,0),TranspTrackBar->Position,LWA_ALPHA);
Log_Memo->Lines->Add(TranspForm_cmb->Text + " window Transparency is " + (int)((TranspTrackBar->Position *100)/255) + "%");
}
//---------------------------------------------------------------------------

void __fastcall TmainFrm::TransReset_btnClick(TObject *Sender)
{
// CHECK IF WIN2000

HWND hWnd = NULL;

 switch (TranspForm_cmb->ItemIndex)
        {
        case 0: hWnd = mainFrm->Handle;
                break;
        case 1: if (TerminalFrm) hWnd = TerminalFrm->Handle;
                break;
        case 2: if (ShortCutsFrm) hWnd = ShortCutsFrm->Handle;
                break;
//        case 3: if (ActConnFrm) hWnd = ActConnFrm->Handle;
//                break;
        };

 if (hWnd == NULL)
        {
        ShowMessage("Window must be active to set this property.");
        return;
        };
 SetWindowLong(hWnd ,GWL_EXSTYLE,GetWindowLong(hWnd,GWL_EXSTYLE)^WS_EX_LAYERED);
 SetLayeredWindowAttributes(hWnd,RGB(0,0,0),255,LWA_ALPHA);
 Log_Memo->Lines->Add(TranspForm_cmb->Text + " window Transparency is normal (100%).");
 TranspTrackBar->Position = TranspTrackBar->Max;
}
//---------------------------------------------------------------------------


void __fastcall TmainFrm::SaveAllSettings_btnClick(TObject *Sender)
{
SettingsGenApply_BtnClick(Sender);
//SettingsConnApply_BtnClick();
//SaveDesktopSetting_btnClick();

// + save services data
for (int i=0; i<ServiceCount;i++)
        SaveServiceData(i);

        Log_Memo->Lines->Add("Saving Terminal Settings to Registry.");
         int value;
        HKEY	hkey = NULL;
        LONG lnRes;
         char buff[256];
         DWORD dwType, dwSize;
         DWORD dwTypeB, dwSizeB;
         DWORD dwTypeS, dwSizeS;
         dwType = REG_DWORD;
         dwSize = sizeof(REG_DWORD);
         dwTypeB = REG_BINARY;
         dwSizeB = sizeof(REG_BINARY);
         dwTypeS = REG_SZ;
        lnRes = RegOpenOrCreateKeyEx("Software\\eWorld\\IP Detective\\Terminal", hkey);
         if( ERROR_SUCCESS == lnRes )
          {
         RegSetValueEx(hkey, TEXT("TargetIP"), 0, dwTypeS,
                       (unsigned char*)(TermTargetIP_txt->Text.c_str()),
                       TermTargetIP_txt->Text.Length());
         value = TermTargetPort_txt->Text.ToInt();
         RegSetValueEx(hkey, TEXT("TargetPort"), 0, dwType,
                       (unsigned char*)(&value), dwSize);
         RegSetValueEx(hkey, TEXT("CommandsPath"), 0, dwTypeS,
                       (unsigned char*)(TerminalCmdPath_slb->Caption.c_str()),
                       TerminalCmdPath_slb->Caption.Length());
         value = (int)TermLCmdSync_chk->Checked;
         RegSetValueEx(hkey, TEXT("SyncronizeCmdList"), 0, dwTypeB,
                       (unsigned char*)(&value), dwSizeB);
            };

}
//---------------------------------------------------------------------------

void __fastcall TmainFrm::ReLoadGenSettings_btnClick(TObject *Sender)
{
/*

        Log_Memo->Lines->Add("Loading Application Settings from Registry (key: HKEY_LOCAL_MACHINE\\Software\\eWorld\\IP Detective\\Settings)");

  AnsiString Names[] = {"OptimizeSystemPerformance" ,
                        "Opt_LoadServicesDLLs"      ,
                        "Opt_LoadApplicationData"   ,
                        "UseTrayIcon"               ,
                        "Tray_MinimizetoIcon"       ,
                        "Tray_Minimizeinsteadofclosing" ,
                        "Tray_Showalways"           ,
                        "AutoSaveDesktop"           ,
                        "SaveSettingsonExit"        ,
                        "ShowSplashScreen"          ,
                        "RunatStartUp"              ,
                        "DisableScreenSaver"        };
  bool** Values;
  Values = new bool* [12];
        Values[0]  = &SystemPerf_opt->Checked;
        Values[1]  = &Opt_LoadDLLs_chk->Checked;
        Values[2]  = &Opt_LoadData_chk->Checked;
        Values[3]  = &TrayIcon_chk->Checked;
        Values[4]  = &Tray_Minimize_chk->Checked;
        Values[5]  = &Tray_NotClose_chk->Checked;
        Values[6]  = &Tray_ShowAl_chk->Checked;
        Values[7]  = &DesktopAutoSave_chk->Checked;
        Values[8]  = &SaveonExit_chk->Checked;
        Values[9]  = &SplashShow_chk->Checked;
        Values[10] = &RunStartUp_chk->Checked;
        Values[11] = &DisableScreenSaver_chk->Checked;

         DWORD dwType, dwSize;
         dwType = REG_BINARY;
         dwSize = sizeof(REG_BINARY);
         DWORD result;

        for (int i = 0; i < 12; i++  ) // BUG
                {
                RegQueryValueEx(hkey, TEXT(Names[i].c_str()), NULL, &dwType, (PBYTE)&result, &dwSize)
                *Values[i] = (int)result;
                }
        delete[] Values;
*/

}
//---------------------------------------------------------------------------

void __fastcall TmainFrm::ReLoadAllSettings_btnClick(TObject *Sender)
{
LoadServiceData(0);
//ReLoadGenSettings_btnClick(Sender);
//ReLoadConnSettings_btnClick(Sender);
//ReLoadDesktopSettings_btnClick(Sender);
}
//---------------------------------------------------------------------------

bool __fastcall TmainFrm::SaveServiceData(int ServiceID)
{
 HKEY	hkey = NULL;
 LONG lnRes;
 lnRes = RegOpenOrCreateKeyEx("Software\\eWorld\\IP Detective\\Services", hkey);
 Log_Memo->Lines->Add("");

 if (ServiceID >= ServiceCount)
        return false;


 Log_Memo->Lines->Add("Saving " + AllServices[ServiceID]->GetDescription() + " Settings to Registry.");
         int value;
         DWORD dwType, dwSize;
         DWORD dwTypeB, dwSizeB;
         DWORD dwTypeS, dwSizeS;
         dwType = REG_DWORD;
         dwSize = sizeof(REG_DWORD);
         dwTypeB = REG_BINARY;
         dwSizeB = sizeof(REG_BINARY);
         dwTypeS = REG_SZ;

switch (ServiceID)
 {
////////////////////////// PING Service
case 0: {
        lnRes = RegOpenOrCreateKeyEx("Software\\eWorld\\IP Detective\\Services\\Ping", hkey);
         if( ERROR_SUCCESS == lnRes )
          {
// That's a lamer way to save. ok.
// another way: using a dynamic array of int*, is present too.
// i don't know an easier way to do it but i think that this version
// is the faster and the easier to change for anybody. :/
         RegSetValueEx(hkey, TEXT("TargetIP"), 0, dwTypeS,
                       (unsigned char*)(PingTargetIP_txt->Text.c_str()),
                       PingTargetIP_txt->Text.Length());
         value = PingTargetPort_txt->Text.ToInt();
                RegSetValueEx(hkey, TEXT("TargetPort"), 0, dwType,
                              (unsigned char*)(&value), dwSize);
         value = PingN_txt->Text.ToInt();
                RegSetValueEx(hkey, TEXT("PingTimes"), 0, dwType,
                              (unsigned char*)(&value), dwSize);
         value = (int)PingLoop_opt->Checked;
                RegSetValueEx(hkey, TEXT("PingLoop"), 0, dwTypeB,
                              (unsigned char*)(&value), dwSizeB);
         value = PingT_txt->Text.ToInt();
                RegSetValueEx(hkey, TEXT("TimeOut"), 0, dwType,
                              (unsigned char*)(&value), dwSize);
         value = PingPsize_txt->Text.ToInt();
                RegSetValueEx(hkey, TEXT("PacketSize"), 0, dwType,
                              (unsigned char*)(&value), dwSize);
         value = PingD_txt->Text.ToInt();
                RegSetValueEx(hkey, TEXT("Delay"), 0, dwType,
                              (unsigned char*)(&value), dwSize);
         value = PingPn_txt->Text.ToInt();
                RegSetValueEx(hkey, TEXT("Packets"), 0, dwType,
                              (unsigned char*)(&value), dwSize);
          };
        };
        break;
////////////////////////// Finger Service
case 1: {
        lnRes = RegOpenOrCreateKeyEx("Software\\eWorld\\IP Detective\\Services\\Finger", hkey);
         if( ERROR_SUCCESS == lnRes )
          {
         RegSetValueEx(hkey, TEXT("TargetIP"), 0, dwTypeS,
                       (unsigned char*)(FingerTargetIP_txt->Text.c_str()),
                       FingerTargetIP_txt->Text.Length());
         value = FingerTargetPort_txt->Text.ToInt();
                RegSetValueEx(hkey, TEXT("TargetPort"), 0, dwType,
                              (unsigned char*)(&value), dwSize);
          };
        };
        break;
////////////////////////// PortScanner Service
case 2: {
        lnRes = RegOpenOrCreateKeyEx("Software\\eWorld\\IP Detective\\Services\\PortScanner", hkey);
         if( ERROR_SUCCESS == lnRes )
          {
         RegSetValueEx(hkey, TEXT("TargetIP"), 0, dwTypeS,
                       (unsigned char*)(PortScannerTargetIP_txt->Text.c_str()),
                       PortScannerTargetIP_txt->Text.Length());
         RegSetValueEx(hkey, TEXT("PortDataBaseFile"), 0, dwTypeS,
                       (unsigned char*)(PortScannerDataB_slb->Caption.c_str()),
                       PortScannerDataB_slb->Caption.Length());
          };
        };
        break;

////////////////////////// TraceRoute Service
case 3: {
        lnRes = RegOpenOrCreateKeyEx("Software\\eWorld\\IP Detective\\Services\\TraceRoute", hkey);
         if( ERROR_SUCCESS == lnRes )
          {
         RegSetValueEx(hkey, TEXT("TargetIP"), 0, dwTypeS,
                       (unsigned char*)(TraceTargetIP_txt->Text.c_str()),
                       TraceTargetIP_txt->Text.Length());
          };
        };
        break;

////////////////////////// WhoIs Service
case 4: {
        lnRes = RegOpenOrCreateKeyEx("Software\\eWorld\\IP Detective\\Services\\WhoIs", hkey);
         if( ERROR_SUCCESS == lnRes )
          {
         RegSetValueEx(hkey, TEXT("TargetIP"), 0, dwTypeS,
                       (unsigned char*)(WhoIsTargetIP_txt->Text.c_str()),
                       WhoIsTargetIP_txt->Text.Length());
          };
        };
        break;

////////////////////////// OSFinger Service
case 5: {
        lnRes = RegOpenOrCreateKeyEx("Software\\eWorld\\IP Detective\\Services\\OSFinger", hkey);
         if( ERROR_SUCCESS == lnRes )
          {
          };
        };
        break;

////////////////////////// EmailServ Service
case 6: {
        lnRes = RegOpenOrCreateKeyEx("Software\\eWorld\\IP Detective\\Services\\EmailServ", hkey);
         if( ERROR_SUCCESS == lnRes )
          {
          };
        };
        break;

////////////////////////// SimpleServ Service
case 7: {
        lnRes = RegOpenOrCreateKeyEx("Software\\eWorld\\IP Detective\\Services\\SimpleServ", hkey);
         if( ERROR_SUCCESS == lnRes )
          {
         RegSetValueEx(hkey, TEXT("TargetIP"), 0, dwTypeS,
                       (unsigned char*)(SimpleSTargetIP_txt->Text.c_str()),
                       SimpleSTargetIP_txt->Text.Length());
         value = SimpleSTargetPort_txt->Text.ToInt();
                RegSetValueEx(hkey, TEXT("TargetPort"), 0, dwType,
                              (unsigned char*)(&value), dwSize);

         value = (int)SimpleSProtocolTCP_opt->Checked;
                RegSetValueEx(hkey, TEXT("AutoCleanReport"), 0, dwType,
                              (unsigned char*)(&value), dwSize);
          };
        };
        break;

////////////////////////// WWWServ Service
case 8: {
        lnRes = RegOpenOrCreateKeyEx("Software\\eWorld\\IP Detective\\Services\\WWWServ", hkey);
         if( ERROR_SUCCESS == lnRes )
          {
          };
        };
        break;

////////////////////////// TrScanner Service
case 9: {
        lnRes = RegOpenOrCreateKeyEx("Software\\eWorld\\IP Detective\\Services\\TrScanner", hkey);
         if( ERROR_SUCCESS == lnRes )
          {
          };
        };
        break;

////////////////////////// LANServ Service
case 10: {
        lnRes = RegOpenOrCreateKeyEx("Software\\eWorld\\IP Detective\\Services\\LANServ", hkey);
         if( ERROR_SUCCESS == lnRes )
          {
         value = (int)LANReportClean_chk->Checked;
                RegSetValueEx(hkey, TEXT("AutoCleanReport"), 0, dwType,
                              (unsigned char*)(&value), dwSize);
          };
        };
        break;

////////////////////////// ICQServ Service
case 11: {
        lnRes = RegOpenOrCreateKeyEx("Software\\eWorld\\IP Detective\\Services\\ICQServ", hkey);
         if( ERROR_SUCCESS == lnRes )
          {
          };
        };
        break;

////////////////////////// ICQMAPI Service
case 12: {
        lnRes = RegOpenOrCreateKeyEx("Software\\eWorld\\IP Detective\\Services\\ICQMAPI", hkey);
         if( ERROR_SUCCESS == lnRes )
          {
          };
        };
        break;
////////////////////////// Add more Service Save Routines here.
 };

 if( ERROR_SUCCESS != lnRes )
        Log_Memo->Lines->Add("ERROR|" + AllServices[ServiceID]->GetDescription() + " Settings NOT Saved to Registry.");
}


bool __fastcall TmainFrm::LoadServiceData(int ServiceID)
{
 if (ServiceID >= ServiceCount)
        return false;

 HKEY	hkey = NULL;
 LONG lnRes;
 Log_Memo->Lines->Add("");
 lnRes = RegOpenKeyEx( HKEY_LOCAL_MACHINE,
                       "Software\\eWorld\\IP Detective\\Services",
                       0L,KEY_ALL_ACCESS, &hkey);
 if( ERROR_SUCCESS != lnRes )
        return false;

 Log_Memo->Lines->Add("Loading " + AllServices[ServiceID]->GetDescription() + " Settings to Registry.");
         LONG buffLen;
         char buff[256];

switch (ServiceID)
 {
////////////////////////// PING Service
case 0: {
        lnRes = RegOpenOrCreateKeyEx("Software\\eWorld\\IP Detective\\Services\\Ping", hkey);
         if( ERROR_SUCCESS == lnRes )
          {
// That's a lamer way to load. ok.
// another way: using a dynamic array of int*, is present too.
// i don't know an easier way to do it but i think that this version
// is the faster and the easier to change for anybody. :/

        RegQueryValue(hkey, TEXT("TargetIP"), buff, &buffLen);
        PingTargetIP_txt->Text = AnsiString(buff, (int)buffLen);
          };
        };
        break;
/*
         value = PingTargetPort_txt->Text.ToInt();
                RegSetValueEx(hkey, TEXT("TargetPort"), 0, dwType,
                              (unsigned char*)(&value), dwSize);
         value = PingN_txt->Text.ToInt();
                RegSetValueEx(hkey, TEXT("PingTimes"), 0, dwType,
                              (unsigned char*)(&value), dwSize);
         value = (int)PingLoop_opt->Checked;
                RegSetValueEx(hkey, TEXT("PingLoop"), 0, dwTypeB,
                              (unsigned char*)(&value), dwSizeB);
         value = PingT_txt->Text.ToInt();
                RegSetValueEx(hkey, TEXT("TimeOut"), 0, dwType,
                              (unsigned char*)(&value), dwSize);
         value = PingPsize_txt->Text.ToInt();
                RegSetValueEx(hkey, TEXT("PacketSize"), 0, dwType,
                              (unsigned char*)(&value), dwSize);
         value = PingD_txt->Text.ToInt();
                RegSetValueEx(hkey, TEXT("Delay"), 0, dwType,
                              (unsigned char*)(&value), dwSize);
         value = PingPn_txt->Text.ToInt();
                RegSetValueEx(hkey, TEXT("Packets"), 0, dwType,
                              (unsigned char*)(&value), dwSize);
          };
        };
        break;
////////////////////////// Finger Service
case 1: {
        lnRes = RegOpenOrCreateKeyEx("Software\\eWorld\\IP Detective\\Services\\Finger", hkey);
         if( ERROR_SUCCESS == lnRes )
          {
         RegSetValueEx(hkey, TEXT("TargetIP"), 0, dwTypeS,
                       (unsigned char*)(FingerTargetIP_txt->Text.c_str()),
                       FingerTargetIP_txt->Text.Length());
         value = FingerTargetPort_txt->Text.ToInt();
                RegSetValueEx(hkey, TEXT("TargetPort"), 0, dwType,
                              (unsigned char*)(&value), dwSize);
          };
        };
        break;
////////////////////////// PortScanner Service
case 2: {
        lnRes = RegOpenOrCreateKeyEx("Software\\eWorld\\IP Detective\\Services\\PortScanner", hkey);
         if( ERROR_SUCCESS == lnRes )
          {
         RegSetValueEx(hkey, TEXT("TargetIP"), 0, dwTypeS,
                       (unsigned char*)(PortScannerTargetIP_txt->Text.c_str()),
                       PortScannerTargetIP_txt->Text.Length());
         RegSetValueEx(hkey, TEXT("PortDataBaseFile"), 0, dwTypeS,
                       (unsigned char*)(PortScannerDataB_slb->Caption.c_str()),
                       PortScannerDataB_slb->Caption.Length());
          };
        };
        break;

////////////////////////// TraceRoute Service
case 3: {
        lnRes = RegOpenOrCreateKeyEx("Software\\eWorld\\IP Detective\\Services\\TraceRoute", hkey);
         if( ERROR_SUCCESS == lnRes )
          {
         RegSetValueEx(hkey, TEXT("TargetIP"), 0, dwTypeS,
                       (unsigned char*)(TraceTargetIP_txt->Text.c_str()),
                       TraceTargetIP_txt->Text.Length());
          };
        };
        break;

////////////////////////// WhoIs Service
case 4: {
        lnRes = RegOpenOrCreateKeyEx("Software\\eWorld\\IP Detective\\Services\\WhoIs", hkey);
         if( ERROR_SUCCESS == lnRes )
          {
         RegSetValueEx(hkey, TEXT("TargetIP"), 0, dwTypeS,
                       (unsigned char*)(WhoIsTargetIP_txt->Text.c_str()),
                       WhoIsTargetIP_txt->Text.Length());
          };
        };
        break;

////////////////////////// OSFinger Service
case 5: {
        lnRes = RegOpenOrCreateKeyEx("Software\\eWorld\\IP Detective\\Services\\OSFinger", hkey);
         if( ERROR_SUCCESS == lnRes )
          {
          };
        };
        break;

////////////////////////// EmailServ Service
case 6: {
        lnRes = RegOpenOrCreateKeyEx("Software\\eWorld\\IP Detective\\Services\\EmailServ", hkey);
         if( ERROR_SUCCESS == lnRes )
          {
          };
        };
        break;

////////////////////////// SimpleServ Service
case 7: {
        lnRes = RegOpenOrCreateKeyEx("Software\\eWorld\\IP Detective\\Services\\SimpleServ", hkey);
         if( ERROR_SUCCESS == lnRes )
          {
         RegSetValueEx(hkey, TEXT("TargetIP"), 0, dwTypeS,
                       (unsigned char*)(SimpleSTargetIP_txt->Text.c_str()),
                       SimpleSTargetIP_txt->Text.Length());
         value = SimpleSTargetPort_txt->Text.ToInt();
                RegSetValueEx(hkey, TEXT("TargetPort"), 0, dwType,
                              (unsigned char*)(&value), dwSize);

         value = (int)SimpleSProtocolTCP_opt->Checked;
                RegSetValueEx(hkey, TEXT("AutoCleanReport"), 0, dwType,
                              (unsigned char*)(&value), dwSize);
          };
        };
        break;

////////////////////////// WWWServ Service
case 8: {
        lnRes = RegOpenOrCreateKeyEx("Software\\eWorld\\IP Detective\\Services\\WWWServ", hkey);
         if( ERROR_SUCCESS == lnRes )
          {
          };
        };
        break;

////////////////////////// TrScanner Service
case 9: {
        lnRes = RegOpenOrCreateKeyEx("Software\\eWorld\\IP Detective\\Services\\TrScanner", hkey);
         if( ERROR_SUCCESS == lnRes )
          {
          };
        };
        break;

////////////////////////// LANServ Service
case 10: {
        lnRes = RegOpenOrCreateKeyEx("Software\\eWorld\\IP Detective\\Services\\LANServ", hkey);
         if( ERROR_SUCCESS == lnRes )
          {
         value = (int)LANReportClean_chk->Checked;
                RegSetValueEx(hkey, TEXT("AutoCleanReport"), 0, dwType,
                              (unsigned char*)(&value), dwSize);
          };
        };
        break;

////////////////////////// ICQServ Service
case 11: {
        lnRes = RegOpenOrCreateKeyEx("Software\\eWorld\\IP Detective\\Services\\ICQServ", hkey);
         if( ERROR_SUCCESS == lnRes )
          {
          };
        };
        break;

////////////////////////// ICQMAPI Service
case 12: {
        lnRes = RegOpenOrCreateKeyEx("Software\\eWorld\\IP Detective\\Services\\ICQMAPI", hkey);
         if( ERROR_SUCCESS == lnRes )
          {
          };
        };
        break;
        */
        ////////////////////////// Add more Service Save Routines here.
 };

 if( ERROR_SUCCESS != lnRes )
        Log_Memo->Lines->Add("ERROR|" + AllServices[ServiceID]->GetDescription() + " Settings NOT Saved to Registry.");
}


void __fastcall TmainFrm::TConsole_cmbKeyPress(TObject *Sender, char &Key)
{
    if (TerminalFrm) TerminalFrm->TConsole_cmb->Text = TConsole_cmb->Text;
    if (Key == VK_RETURN)
        {
//SEND  TConsole_cmb->Text
        TConsole_Memo->Lines->Add("£ocal:\t" + TConsole_cmb->Text);
        TConsole_cmb->Items->Add(TConsole_cmb->Text);
        TConsole_cmb->Text = "";
        TConsole_cmb->Update();

        if (TerminalFrm) TerminalFrm->TConsole_Memo->Lines->Add("£ocal:\t" + TConsole_cmb->Text);
        if (TerminalFrm) TerminalFrm->TConsole_cmb->Items->Add(TConsole_cmb->Text);
        if (TerminalFrm) TerminalFrm->TConsole_cmb->Text = "";
        if (TerminalFrm) TerminalFrm->TConsole_cmb->Update();

        }
}
//---------------------------------------------------------------------------


void __fastcall TmainFrm::ShortCutsListFileOpt_btnClick(TObject *Sender)
{
ShortCutsPopupMnu->Popup(
                        mainFrm->Left + ViewControlTabs->Left + Tab_ShortCuts->Left + ShortCutsListGroup->Left + ShortCutsListFileOpt_btn->Left,
                        mainFrm->Top  + ViewControlTabs->Top  + Tab_ShortCuts->Top  + ShortCutsListGroup->Top  + ShortCutsListFileOpt_btn->Top + 30
                        );
// that's shit!
}
//---------------------------------------------------------------------------


void __fastcall TmainFrm::EditwithNotepadClick(TObject *Sender)
{
if ((ShortCutsFileList_slb->Caption != "")&&(FileExists(ShortCutsFileList_slb->Caption)))
        ShellExecute(NULL, "open", "notepad.exe", ShortCutsFileList_slb->Caption.c_str(), "", SW_SHOWDEFAULT);
}
//---------------------------------------------------------------------------

void __fastcall TmainFrm::OpenFileClick(TObject *Sender)
{
if ((ShortCutsFileList_slb->Caption != "")&&(FileExists(ShortCutsFileList_slb->Caption)))
        ShellExecute(NULL, "open", ShortCutsFileList_slb->Caption.c_str(), "", "", SW_SHOWDEFAULT);

}
//---------------------------------------------------------------------------


void __fastcall TmainFrm::ShortCutsCommandP_txtKeyPress(TObject *Sender,
      char &Key)
{
    if (Key == VK_RETURN)
        ShellExecute(NULL, "open", "cmd.exe", "", "", SW_SHOWDEFAULT);  // Win2000
}
//---------------------------------------------------------------------------

void __fastcall TmainFrm::SimpleServices_cmbChange(TObject *Sender)
{


  if (SimpleServ.Load())
        {
        // Load service Description
        (FARPROC) lpfn_GetSServiceDesc = GetProcAddress (SimpleServ.GetIstance(), "GetServiceDesc");
        if (lpfn_GetSServiceDesc != NULL)
                SimpleServiceDesc_slb->Caption = lpfn_GetSServiceDesc(SimpleServices_cmb->ItemIndex);
        else
                SimpleServiceDesc_slb->Caption = "not avaiable";

        (FARPROC) lpfn_GetSServicePort = GetProcAddress (SimpleServ.GetIstance(), "GetServicePort");
        if (lpfn_GetSServicePort != NULL)
                SimpleSTargetPort_txt->Text = lpfn_GetSServicePort(SimpleServices_cmb->ItemIndex);
        else
                SimpleSTargetPort_txt->Text = 0;
        }

}
//---------------------------------------------------------------------------


void __fastcall TmainFrm::WhoIsValidateServers_btnClick(TObject *Sender)
{
DWORD dllRes = 0;

if (WhoIs.Load())
        {
        Log_Memo->Lines->Add("");
        Log_Memo->Lines->Add("Checking WhoIs Servers' List. (check own log for details)");

        WhoIs_Memo->Lines->Add("_____________Checking WhoIs Servers' List.");

        for(int i = 0; i < WhoIsServers_lbx->Items->Count; i++)
                        {
                        if (WhoIsServers_lbx->Checked[i])
                                {
                                WhoIs_Memo->Lines->Add(" WhoIs server:\t" + WhoIsServers_lbx->Items->Strings[i]);

                                (FARPROC) lpfn_WhoIsValidate = GetProcAddress (WhoIs.GetIstance(), "ValidateServer");
                                 if (lpfn_WhoIsValidate != NULL)
                                	(lpfn_WhoIsValidate)(WhoIsServers_lbx->Items->Strings[i], 0,WhoIs_Memo);
                                 else
                                        {
                                        WhoIs_Memo->Lines->Add("ERROR|\tService Function (ValidateServer) NOT Found.");
                                        return;
                                        };
                                WhoIs_Memo->Lines->Add("");
                                }
                        };
        };
}
//---------------------------------------------------------------------------

void __fastcall TmainFrm::PortScanning_btnClick(TObject *Sender)
{

if (PortScanner.Load())
        {
        Log_Memo->Lines->Add("");
        Log_Memo->Lines->Add("LamePinging " + PingTargetIP_txt->Text + " (check own log for details)");


//                                (FARPROC) lpfn_PS_LameScan = GetProcAddress (PortScanner.GetIstance(), "LameScan");
//                                 if (lpfn_PS_LameScan != NULL)
//                                	(lpfn_PS_LameScan)();
//                                 else
                                        {
                                        Pinger_Memo->Lines->Add("ERROR|\tService Function (LameScan) NOT Found.");
                                        return;
                                        };
        };

}
//---------------------------------------------------------------------------

void __fastcall TmainFrm::PingAdvanced_slbClick(TObject *Sender)
{
        if (Pinger_Memo->Visible)
                {// Shows Advanced Settings box
                PingAdvanced_slb->Font->Style.Clear();
                PingAdvanced_slb->BorderStyle = sbsSunken;
                Pinger_Memo->Visible = false;
                PingAdvanced_grp->Visible = true;
                }
         else   {
                PingAdvanced_slb->BorderStyle = sbsNone;
                PingAdvanced_slb->Font->Style << fsUnderline;
                Pinger_Memo->Visible = true;
                PingAdvanced_grp->Visible = false;
                };
}
//---------------------------------------------------------------------------

void __fastcall TmainFrm::FingerSend_btnClick(TObject *Sender)
{

if (Finger.Load())
        {
        Log_Memo->Lines->Add("");
        Log_Memo->Lines->Add("LameFingering " + FingerTargetIP_txt->Text + " (check own log for details)");

                                (FARPROC) lpfn_Finger_Lame = GetProcAddress (Finger.GetIstance(), "LameFinger");
                                 if (lpfn_Finger_Lame != NULL)
                                        (lpfn_Finger_Lame)(FingerTargetIP_txt->Text,
                                                           FingerTargetPort_txt->Text.ToInt(),
                                                           FingerUserName_txt->Text, Finger_Memo);
                                 else
                                        {
                                        Finger_Memo->Lines->Add("ERROR|\tService Function (LameFinger) NOT Found.");
                                        return;
                                        };
                                Finger_Memo->Lines->Add("");
                        };


}
//---------------------------------------------------------------------------

void __fastcall TmainFrm::SettingsConn_TabSShow(TObject *Sender)
{
SettingsConnCurrConn_slb->Caption = "Not Connected";        

}
//---------------------------------------------------------------------------


void __fastcall TmainFrm::SimpleSConnect_btnClick(TObject *Sender)
{
if (!SimpleServices_cmb->Items->Count)
        {
        SimpleS_Memo->Lines->Add("ERROR|\tCan't list Services.");
        return;
        };


  if (SimpleServ.Load())
        {
        (FARPROC) lpfn_CallService = GetProcAddress (SimpleServ.GetIstance(), "CallService");
        if (lpfn_CallService != NULL)
                (lpfn_CallService)(SimpleServices_cmb->ItemIndex, SimpleSTargetIP_txt->Text, SimpleSTargetPort_txt->Text.ToInt(), (int)!SimpleSProtocolTCP_opt->Checked, SimpleS_Memo);
        else
                Finger_Memo->Lines->Add("ERROR|\tService Function (CallService) NOT Found.");
        };

}
//---------------------------------------------------------------------------

void __fastcall TmainFrm::Find_Log_mnuClick(TObject *Sender)
{

  FindDialog->Position = Point(((TMemo *)Sender)->Left + ((TMemo *)Sender)->Width/2, ((TMemo *)Sender)->Top);
  FindDialog->Execute();
}
//---------------------------------------------------------------------------

void __fastcall TmainFrm::Term_FileOpt_btnClick(TObject *Sender)
{
ShortCutsPopupMnu->Popup(
                        mainFrm->Left + ViewControlTabs->Left + Tab_Terminal->Left + Term_Cmd_grp->Left + Term_FileOpt_btn->Left,
                        mainFrm->Top  + ViewControlTabs->Top  + Tab_Terminal->Top  + Term_Cmd_grp->Top  + Term_FileOpt_btn->Height
                        );
// that's shit!

}
//---------------------------------------------------------------------------


void __fastcall TmainFrm::LANComputer_CmbChange(TObject *Sender)
{
        LanInfos_TreeView->Items->Item[0]->Text = LANComputer_Cmb->Text;
}
//---------------------------------------------------------------------------

//---------------------------------------------------------------------------


void __fastcall TmainFrm::Auto_CListBoxKeyPress(TObject *Sender, char &Key)
{
  if (Key == VK_DELETE)
        Auto_CListBox->Items->Delete(Auto_CListBox->ItemIndex);
}
//---------------------------------------------------------------------------




void __fastcall TmainFrm::AttackLoadDLL_btnClick(TObject *Sender)
{
   if (AttackDLLs_lbx->ItemIndex != -1)
        {
        AttackFunctions_lbx->Clear();

  if (  (AttackFunctions.SetFileName(AttackDLLs_lbx->Items->Strings[AttackDLLs_lbx->ItemIndex]))
      &&(AttackFunctions.Load()))
        {
        Attack_Memo->Lines->Add("Service DLL Loaded. (Version " + SimpleServ.GetVersion() + ")");
        // Enumerate and save functions
        (FARPROC) lpfn_SimpleSEnum = GetProcAddress (AttackFunctions.GetIstance(), "EnumServices");
        if (lpfn_SimpleSEnum != NULL)
                {
                int i = 0;
                while (lpfn_SimpleSEnum(i) != "")
                        AttackFunctions_lbx->Items->Add(lpfn_SimpleSEnum(i++));
                }
        else
                Attack_Memo->Lines->Add("ERROR:\t Service Function (EnumServices) NOT Found.");
        }
  else
        Attack_Memo->Lines->Add("ERROR|\t Service DLL NOT Loaded.");
  };
}
//---------------------------------------------------------------------------

void __fastcall TmainFrm::AttackOpenDLL_imgClick(TObject *Sender)
{
        OpenDialog->Title = "Load Attack DLL..";
        OpenDialog->DefaultExt = "dll";
        OpenDialog->Filter = "Dynamic Link Lkibrary (*.dll)|*.DLL|All files (*.*)|*.*";
        OpenDialog->Options.Clear();
        OpenDialog->Options << ofFileMustExist << ofPathMustExist;
        if (OpenDialog->Execute())
                {
                AttackDLLs_lbx->Items->Add(OpenDialog->FileName);
                AttackDLLPath_stb->Font->Style = TFontStyles();
                AttackDLLPath_stb->Caption = OpenDialog->FileName;
                }
}
//---------------------------------------------------------------------------

void __fastcall TmainFrm::AttackLoadDLLDir_imgClick(TObject *Sender)
{
        OpenDialog->Title = "Add DLL to List..";
        OpenDialog->DefaultExt = "dll";
        OpenDialog->Filter = "Dynamic Link Library (*.dll)|*.DLL|All files (*.*)|*.*";
        OpenDialog->Options.Clear();
        OpenDialog->Options << ofFileMustExist << ofPathMustExist;
        if (OpenDialog->Execute())
                {
                AttackDLLs_lbx->Items->LoadFromFile(OpenDialog->FileName);
                }

}
//---------------------------------------------------------------------------




void __fastcall TmainFrm::AttackFunctions_lbxClick(TObject *Sender)
{

  if (AttackFunctions.Load())
        {
        // Load service Description
        (FARPROC) lpfn_GetSServiceDesc = GetProcAddress (AttackFunctions.GetIstance(), "GetServiceDesc");
        if (lpfn_GetSServiceDesc != NULL)
                AttackFunctionDesc_stb->Caption = lpfn_GetSServiceDesc(AttackFunctions_lbx->ItemIndex);
        else
                AttackFunctionDesc_stb->Caption = "Not Avaiable.";

        (FARPROC) lpfn_GetSServicePort = GetProcAddress (AttackFunctions.GetIstance(), "GetServicePort");
        if (lpfn_GetSServicePort != NULL)
                AttackTargetPort_txt->Text = lpfn_GetSServicePort(AttackFunctions_lbx->ItemIndex);
        else
                AttackTargetPort_txt->Text = 0;
        }


}
//---------------------------------------------------------------------------

void __fastcall TmainFrm::AttackConnect_btnClick(TObject *Sender)
{
if (!AttackFunctions_lbx->Items->Count)
        {
        Attack_Memo->Lines->Add("ERROR|\tCan't list Functions.");
        return;
        };


  if (AttackFunctions.Load())
        {
        Attack_Memo->Clear();
        (FARPROC) lpfn_CallService = GetProcAddress (AttackFunctions.GetIstance(), "CallService");
        if (lpfn_CallService != NULL)
                (lpfn_CallService)(AttackFunctions_lbx->ItemIndex, AttackTargetIP_txt->Text, AttackTargetPort_txt->Text.ToInt(), 0, Attack_Memo);
        else
                Attack_Memo->Lines->Add("ERROR|\tService Function (CallService) NOT Found.");
        };
}
//---------------------------------------------------------------------------

void __fastcall TmainFrm::AttackUnloadDLL_btnClick(TObject *Sender)
{

AttackFunctions_lbx->Clear();
AttackFunctionDesc_stb->Caption = "";
Attack_Memo->Clear();
AttackTargetPort_txt->Text = 0;
//AttackFunctions.Unload();  TO IMPLEMENT
}
//---------------------------------------------------------------------------

void __fastcall TmainFrm::AttackLoadDLLList_imgClick(TObject *Sender)
{
        OpenDialog->Title = "Load DLLs List..";
        OpenDialog->DefaultExt = "txt";
        OpenDialog->Filter = "Plain Text (*.txt)|*.TXT|All files (*.*)|*.*";
        OpenDialog->Options.Clear();
        OpenDialog->Options << ofFileMustExist << ofPathMustExist;
        if (OpenDialog->Execute())
                {
                AttackDLLs_lbx->Clear();
                AttackDLLs_lbx->Items->LoadFromFile(OpenDialog->FileName);
                }

}
//---------------------------------------------------------------------------

void __fastcall TmainFrm::LS_Win2K_EnableLogOn_btnClick(TObject *Sender)
{
			// read the values out of the dialog

/*			GetDlgItemText( hDlg, IDC_LOGINNAME, UserName, 256 );
			GetDlgItemText( hDlg, IDC_DOMAINNAME, Domain, 256 );
			GetDlgItemText( hDlg, IDC_PASSWORD, Password, 256 );

			// stick it all in the registry
			if( RegOpenKey( HKEY_LOCAL_MACHINE, LoginKeyName, &hKey ) != ERROR_SUCCESS) {
				Abort( NULL, TEXT("Could not open Winlogon registry key"));
				return TRUE;
			}

			// write user name
			if( RegSetValueEx( hKey, DefaultUserName, 0, REG_SZ, UserName, 
				strlen(UserName)+1 ) != ERROR_SUCCESS ) {
				Abort( NULL, TEXT("Could not write DefaultUserName"));
				return TRUE;
			}

			// write domain
			if( RegSetValueEx( hKey, DefaultDomain, 0, REG_SZ, Domain, 
				strlen(Domain)+1 ) != ERROR_SUCCESS ) {
				Abort( NULL, TEXT("Could not write DefaultDomain"));
				return TRUE;
			}

			// write password
			if( RegSetValueEx( hKey, DefaultPassword, 0, REG_SZ, Password,
				strlen(Password)+1 ) != ERROR_SUCCESS ) {
				Abort( NULL, TEXT("Could not write DefaultPassword"));
				return TRUE;
			}

			// enable auto-logon
			if( RegSetValueEx( hKey, AutoLogin, 0, REG_SZ, szOne, strlen(szOne)+1 ) 
				!= ERROR_SUCCESS ) {
				RegCloseKey( hKey );
				Abort( NULL, TEXT("Could not reset AutoAdminLogon"));
				return TRUE;
			}
			MessageBox( NULL, "Autologon successfully configured.",
						 "AutoLogon", MB_ICONINFORMATION );
*/

}
//---------------------------------------------------------------------------

