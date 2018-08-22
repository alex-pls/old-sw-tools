// IPDetective Project
//
// Status: Aborted
//
// by Alessandro Polo 2002
// eWorld Network :: www.ewgate.net
//------------------------------------------------------------------------------

#ifndef mainH
#define mainH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ComCtrls.hpp>
#include <ExtCtrls.hpp>
#include <Menus.hpp>
#include <CheckLst.hpp>
#include <Dialogs.hpp>
#include "cdiroutl.h"
//#include <Grids.hpp>
//#include <Outline.hpp>
//#include "SHDocVw_OCX.h"
//#include <OleServer.hpp>
#include <ImgList.hpp>
#include <Graphics.hpp>

        // Serial IO Stuff
#include <vector>

        // TrayIcon Stuff
#define MYWM_NOTIFY         (WM_APP+100)
#define IDC_MYICON                     1006
extern HINSTANCE g_hinst;
LRESULT IconDrawItem(LPDRAWITEMSTRUCT lpdi);
//---------------------------------------------------------------------------

class TmainFrm : public TForm
{
__published:	// IDE-managed Components
        TMainMenu *MainMenu;
        TPanel *Panel1;
        TMenuItem *File1;
        TMenuItem *Edit1;
        TMenuItem *About1;
        TPageControl *ViewControlTabs;
        TStatusBar *StatusBar1;
        TTabSheet *Tab_Settings;
        TTabSheet *Tab_LocalInfos;
        TTabSheet *Tab_Automations;
        TTabSheet *Tab_Services;
        TMenuItem *IPDetective1;
        TMenuItem *N1;
        TMenuItem *SurfeWorld;
        TMenuItem *N2;
        TMenuItem *Exit1;
        TTabSheet *Tab_ActiveConnection;
        TTabSheet *Tab_Servers;
        TPageControl *ServicesTab;
        TTabSheet *TabPinger;
        TTabSheet *TabFinger;
        TTabSheet *TabPortScanner;
        TTabSheet *TabTraceRoute;
        TTabSheet *TabWhois;
        TTabSheet *TabOSDetection;
        TTabSheet *TabEMailValidator;
        TTabSheet *TabSimpleServices;
        TTabSheet *Tab_Terminal;
        TTabSheet *Tab_ShortCuts;
        TTabSheet *Tab_References;
        TListView *ShortCutsListView;
        TStaticText *IPHost0_slb;
        TEdit *TargetIP_txt;
        TTabSheet *TabWWWService;
        TButton *Button1;
        TButton *Button2;
        TMenuItem *Upgrades1;
        TMemo *TConsole_Memo;
        TTabSheet *TabTRScannerService;
        TOpenDialog *OpenDialog;
        TSaveDialog *SaveDialog;
        TTabSheet *TabLANServices;
        TMemo *LANInfo_Memo;
        TMemo *Pinger_Memo;
        TButton *PingConnect_Btn;
        TCheckListBox *Auto_CListBox;
        TListView *Ref_ListView;
        TTabSheet *TabICQ;
        TGroupBox *GroupBox2;
        TEdit *RFCFiles_Ed;
        TLabel *Label2;
        TMemo *WhoIs_Memo;
        TGroupBox *GroupBox3;
        TGroupBox *GroupBox4;
        TButton *WhoisSend_btn;
        TLabel *Label3;
        TCheckListBox *WhoIsServers_lbx;
        TButton *AddWIs_btn;
        TEdit *WhoIsTargetIP_txt;
        TStaticText *IPHost1_slb;
        TButton *ImportWhoIsServers_btn;
        TButton *ExportWhoIsServers_btn;
        TMenuItem *ReportBugs1;
        TButton *RemoveWIs_btn;
        TTreeView *LanInfos_TreeView;
        TGroupBox *GroupBox5;
        TMemo *SimpleS_Memo;
        TComboBox *SimpleServices_cmb;
        TRadioButton *SimpleSProtocolTCP_opt;
        TRadioButton *RadioButton6;
        TLabel *Label4;
        TEdit *SimpleSTargetPort_txt;
        TListView *TrojanListView;
        TGroupBox *GroupBox6;
        TLabel *Label6;
        TStaticText *StaticText4;
        TButton *TrojanListReflesh_btn;
        TButton *Button19;
        TLabel *Label5;
        TCheckBox *LANReportClean_chk;
        TPageControl *SettingsTabs;
        TTabSheet *SettingsGen_TabS;
        TTabSheet *SettingsConn_TabS;
        TTabSheet *SettingsDir_TabS;
        TGroupBox *Term_Cmd_grp;
        TButton *TermConnect_btn;
        TButton *Button21;
        TStaticText *TerminalCmdPath_slb;
        TImage *OpenCmdList_img;
        TListBox *TerminalCmdList_lbx;
        TButton *Term_FileOpt_btn;
        TButton *TermSendListCmds_btn;
        TCheckBox *TermLCmdSync_chk;
        TGroupBox *GroupBox11;
        TEdit *TermTargetIP_txt;
        TLabel *Label7;
        TEdit *TermTargetPort_txt;
        TLabel *Label8;
        TButton *TermDisconnect_btn;
        TTreeView *AppDirTreeView;
        TGroupBox *GroupBox1;
        TStaticText *DirActPath_stlb;
        TLabel *Label9;
        TLabel *Label10;
        TStaticText *DirDefPath_stlb;
        TImage *OpenData_img;
        TGroupBox *ShortCutsListGroup;
        TButton *ShortCutsListFileOpt_btn;
        TImage *ShortCutOpenList_img;
        TStaticText *ShortCutsFileList_slb;
        TButton *Button25;
        TGroupBox *GroupBox9;
        TComboBox *LocalServer_cmb;
        TLabel *Label11;
        TLabel *Label12;
        TLabel *Label13;
        TEdit *Edit10;
        TButton *Button26;
        TButton *Button27;
        TGroupBox *GroupBox12;
        TListView *ListView1;
        TGroupBox *GroupBox13;
        TRadioButton *RadioButton10;
        TRadioButton *RadioButton11;
        TRadioButton *RadioButton12;
        TListView *ListView3;
        TGroupBox *GroupBox14;
        TLabel *Label14;
        TLabel *Label15;
        TStaticText *PortScannerDataB_slb;
        TButton *Button28;
        TButton *Button29;
        TRadioGroup *RadioGroup3;
        TRadioButton *RadioButton13;
        TRadioButton *RadioButton14;
        TRadioButton *RadioButton15;
        TRadioGroup *RadioGroup4;
        TGroupBox *GroupBox7;
        TRadioButton *RadioButton7;
        TRadioButton *RadioButton8;
        TRadioButton *RadioButton9;
        TRadioButton *RadioButton16;
        TRadioButton *TRCheckAll_opt;
        TRadioButton *RadioButton18;
        TButton *PortScanning_btn;
        TButton *Button31;
        TStaticText *DirDescript_stlb;
        TLabel *Label16;
        TButton *RFCRefleshList_btn;
        TButton *RFCManageFiles_btn;
        TGroupBox *GroupBox15;
        TMemo *Memo2;
        TGroupBox *GroupBox16;
        TRadioButton *RadioButton20;
        TEdit *PingN_txt;
        TUpDown *UpDown1;
        TRadioButton *PingLoop_opt;
        TLabel *Label17;
        TEdit *PingT_txt;
        TUpDown *UpDown2;
        TLabel *Label18;
        TEdit *PingD_txt;
        TUpDown *UpDown3;
        TLabel *Label19;
        TEdit *PingPn_txt;
        TUpDown *UpDown4;
        TLabel *Label20;
        TEdit *PingPsize_txt;
        TUpDown *UpDown5;
        TMemo *Finger_Memo;
        TMemo *Memo6;
        TMemo *Memo7;
        TMemo *Memo8;
        TGroupBox *GroupBox17;
        TButton *Button32;
        TCheckBox *PingDefaults_chk;
        TMenuItem *N3;
        TMenuItem *N4;
        TMenuItem *PasteIP1;
        TMenuItem *CopyIP1;
        TGroupBox *GroupBox18;
        TRadioButton *SaveToReg_Opt;
        TRadioButton *RadioButton2;
        TGroupBox *GroupBox19;
        TButton *SettingsConnApply_Btn;
        TButton *ReLoadConnSettings_btn;
        TButton *SettingsGenApply_Btn;
        TButton *ReLoadGenSettings_btn;
        TMenuItem *Windows1;
        TMenuItem *WinMain_Mnu;
        TMenuItem *N5;
        TMenuItem *WinShortcuts_Mnu;
        TMenuItem *WinTerminal_Mnu;
        TMenuItem *WinActiveConnections_Mnu;
        TMenuItem *N6;
        TMenuItem *Loaddesktop1;
        TMenuItem *default1;
        TMenuItem *DesktopLastSaved_Mnu;
        TMenuItem *SaveDesktop_Btn;
        TCheckBox *TrayIcon_chk;
        TCheckBox *Tray_NotClose_chk;
        TCheckBox *Tray_Minimize_chk;
        TGroupBox *GroupBox20;
        TCheckBox *RunStartUp_chk;
        TCheckBox *SplashShow_chk;
        TPopupMenu *ShortCutsList_PopMnu;
        TMenuItem *Update1;
        TMenuItem *MenuItem1;
        TMenuItem *Style1;
        TMenuItem *SmallIcons1;
        TMenuItem *Icons1;
        TMenuItem *List1;
        TMenuItem *Report1;
        TMenuItem *MenuItem2;
        TPopupMenu *Terminal_PopMnu;
        TMenuItem *MenuItem3;
        TMenuItem *MenuItem4;
        TMenuItem *MenuItem5;
        TMenuItem *TerminalFont_mnu;
        TMenuItem *TerminalColor_mnu;
        TMenuItem *MenuItem10;
        TMenuItem *MenuItem11;
        TPopupMenu *Ticon_PopupMnu;
        TMenuItem *Properties1;
        TMenuItem *WinShortcuts_Mnu2;
        TMenuItem *Shutdown_Mnu;
        TCheckBox *Tray_ShowAl_chk;
        TMenuItem *TrayIcon_Mnu;
        TMenuItem *WinTerminal_Mnu2;
        TMenuItem *WinActiveConn_Mnu2;
        TMenuItem *N7;
        TPageControl *LS_PageControl;
        TTabSheet *TabSheet5;
        TMemo *OSInfo_Memo;
        TButton *GetOSInfo_Btn;
        TCheckBox *OSReportClean_chk;
        TTreeView *LocalInfos_TreeView;
        TTabSheet *TabSheet6;
        TGroupBox *GroupBox21;
        TButton *SerialConnect_Btn;
        TGroupBox *GroupBox23;
        TGroupBox *GroupBox24;
        TButton *SerialOpenSocket_Btn;
        TRichEdit *SerialOutData_REd;
        TLabel *Label21;
        TComboBox *SerialPort_CBox;
        TLabel *Label22;
        TComboBox *SerialBaud_CBox;
        TLabel *Label23;
        TStaticText *SerialStatus_Lb;
        TButton *SerialSend_Btn;
        TRichEdit *SerialDataIn_REd;
        TCheckBox *DisableScreenSaver_chk;
        TTabSheet *TabSheet7;
        TGroupBox *GroupBox22;
        TGroupBox *GroupBox25;
        TButton *CaptureScreen_Btn;
        TButton *CaptureSave_Btn;
        TRadioButton *CaptureFullScreen_opt;
        TRadioButton *RadioButton22;
        TImage *CaptureShot_Img;
        TEdit *CaptureWindow_Ed;
        TGroupBox *GroupBox26;
        TRadioButton *SystemPerf_opt;
        TRadioButton *RadioButton23;
        TCheckBox *Opt_LoadDLLs_chk;
        TCheckBox *Opt_LoadData_chk;
        TTabSheet *EventLog_TabS;
        TMemo *Log_Memo;
        TCheckBox *SaveonExit_chk;
        TCheckBox *DesktopAutoSave_chk;
        TGroupBox *GroupBox27;
        TCheckBox *CheckBox8;
        TComboBox *ComboBox3;
        TLabel *Label24;
        TLabel *Label25;
        TStaticText *SettingsConnCurrConn_slb;
        TButton *Button6;
        TPopupMenu *txtBox_Popup;
        TMenuItem *ClearLog_mnu;
        TMenuItem *N8;
        TMenuItem *SaveLogtoFile_mnu;
        TMenuItem *Connections1;
        TCheckBox *KeepLog_chk;
        TGroupBox *GroupBox28;
        TButton *Map_btn;
        TButton *unMap_btn;
        TGroupBox *GroupBox29;
        TImage *ShortCutOpenItemPath_img;
        TEdit *ShortCutName_txt;
        TCheckBox *CheckBox2;
        TButton *AddShortCut_btn;
        TGroupBox *GroupBox30;
        TGroupBox *GroupBox31;
        TListBox *ListBox2;
        TUpDown *UpDown6;
        TImageList *MenuImageList;
        TButton *WhoIsValidateServers_btn;
        TGroupBox *GroupBox32;
        TStaticText *IPHost2_slb;
        TEdit *FingerTargetIP_txt;
        TStaticText *StaticText6;
        TEdit *FingerTargetPort_txt;
        TGroupBox *GroupBox33;
        TButton *FingerSend_btn;
        TButton *Button5;
        TGroupBox *GroupBox34;
        TEdit *ShortCutPath_txt;
        TMenuItem *N9;
        TMenuItem *ShowLog_mnu;
        TColorDialog *ColorDialog;
        TFontDialog *FontDialog;
        TFindDialog *FindDialog;
        TImageList *LocalSysImageList;
        TTabSheet *TabSheet4;
        TImageList *LANImageList;
        TTabSheet *TabSheet9;
        TButton *LAN_CPModem_btn;
        TButton *LAN_CPSystem_btn;
        TButton *LAN_CPInternet_btn;
        TButton *LAN_IntExpl_btn;
        TButton *LAN_LocExpl_btn;
        TStaticText *IPHost3_slb;
        TEdit *SimpleSTargetIP_txt;
        TEdit *PingTargetIP_txt;
        TStaticText *IPHost4_slb;
        TButton *GetLANInfo_Btn;
        TLabel *Label26;
        TPanel *Panel2;
        TMemo *Memo1;
        TMemo *CleagLogs_Memo;
        TButton *LogsClear_btn;
        TTreeView *IELogs_TreeView;
        TCheckBox *CleagLogsReportClean_chk;
        TCheckBox *CleagLogsShowAlert_chk;
        TTabSheet *DeskTop_TabS;
        TGroupBox *GroupBox35;
        TComboBox *TranspForm_cmb;
        TTrackBar *TranspTrackBar;
        TButton *TraspApply_btn;
        TButton *TransReset_btn;
        TGroupBox *GroupBox36;
        TStaticText *IPHos5_slb;
        TEdit *TraceTargetIP_txt;
        TButton *ReLoadDesktopSettings_btn;
        TButton *SaveDesktopSetting_btn;
        TButton *SaveAllSettings_btn;
        TButton *ReLoadAllSettings_btn;
        TStaticText *StaticText1;
        TEdit *PingTargetPort_txt;
        TGroupBox *GroupBox37;
        TStaticText *StaticText2;
        TEdit *PortScannerTargetIP_txt;
        TImage *Image1;
        TLabel *Label1;
        TGroupBox *GroupBox38;
        TRadioButton *RadioButton3;
        TRadioButton *RadioButton4;
        TEdit *Edit3;
        TButton *Button9;
        TButton *Button10;
        TGroupBox *GroupBox39;
        TEdit *ShortCutsCommandP_txt;
        TComboBox *TConsole_cmb;
        TPopupMenu *ShortCutsPopupMnu;
        TMenuItem *OpenFile;
        TMenuItem *EditwithNotepad;
        TMenuItem *N10;
        TMenuItem *loadDefault;
        TGroupBox *GroupBox8;
        TStaticText *SimpleServiceDesc_slb;
        TGroupBox *GroupBox40;
        TStaticText *StaticText3;
        TEdit *OSDetectTargetIP_txt;
        TMemo *OSDetect_Memo;
        TGroupBox *GroupBox41;
        TRadioButton *RadioButton5;
        TRadioButton *RadioButton17;
        TRadioButton *RadioButton19;
        TCheckBox *CheckBox1;
        TComboBox *ComboBox1;
        TLabel *Label27;
        TLabel *Label28;
        TLabel *Label30;
        TStaticText *PingAdvanced_slb;
        TEdit *FingerUserName_txt;
        TGroupBox *GroupBox42;
        TGroupBox *GroupBox43;
        TCheckBox *CheckBox3;
        TListBox *ListBox1;
        TStaticText *StaticText5;
        TStaticText *StaticText7;
        TImage *Image2;
        TButton *Button3;
        TButton *Button4;
        TLabel *Label29;
        TComboBox *LANComputer_Cmb;
        TGroupBox *PingAdvanced_grp;
        TEdit *PingMessage_txt;
        TLabel *Label31;
        TButton *SimpleSConnect_btn;
        TMenuItem *N11;
        TMenuItem *Find_Log_mnu;
        TPanel *Panel3;
        TPanel *Panel4;
        TGroupBox *GroupBox10;
        TStaticText *StaticText8;
        TEdit *AttackTargetIP_txt;
        TStaticText *StaticText9;
        TEdit *AttackTargetPort_txt;
        TGroupBox *GroupBox44;
        TListBox *AttackDLLs_lbx;
        TStaticText *AttackDLLPath_stb;
        TGroupBox *GroupBox45;
        TListBox *AttackFunctions_lbx;
        TGroupBox *GroupBox46;
        TStaticText *AttackFunctionDesc_stb;
        TButton *AttackConnect_btn;
        TButton *Button8;
        TButton *AttackLoadDLL_btn;
        TMemo *Attack_Memo;
        TImage *AttackOpenDLL_img;
        TImage *AttackLoadDLLDir_img;
        TButton *AttackUnloadDLL_btn;
        TImage *AttackLoadDLLList_img;
        TGroupBox *GroupBox47;
        TLabel *Label32;
        TLabel *Label33;
        TLabel *Label34;
        TEdit *Edit2;
        TEdit *Edit4;
        TEdit *Edit5;
        TButton *LS_Win2K_EnableLogOn_btn;
        TButton *Button11;
        void __fastcall GetOSInfo_BtnClick(TObject *Sender);
        void __fastcall Map_btnClick(TObject *Sender);
        void __fastcall Ref_ListViewClick(TObject *Sender);
        void __fastcall IPDetective1Click(TObject *Sender);
        void __fastcall WinShortcuts_MnuClick(TObject *Sender);
        void __fastcall WinTerminal_MnuClick(TObject *Sender);
        void __fastcall TrayIcon_MnuClick(TObject *Sender);
        void __fastcall Shutdown_MnuClick(TObject *Sender);
        void __fastcall WinActiveConn_MnuClick(TObject *Sender);
        void __fastcall WinMain_MnuClick(TObject *Sender);
        void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
        void __fastcall Button1Click(TObject *Sender);
        void __fastcall SurfeWorldClick(TObject *Sender);
        void __fastcall SerialConnect_BtnClick(TObject *Sender);
        void __fastcall SerialOpenSocket_BtnClick(TObject *Sender);
        void __fastcall SerialSend_BtnClick(TObject *Sender);
        void __fastcall Ref_ListViewSelectItem(TObject *Sender,
          TListItem *Item, bool Selected);
        void __fastcall PingConnect_BtnClick(TObject *Sender);
        void __fastcall CaptureScreen_BtnClick(TObject *Sender);
        void __fastcall CaptureSave_BtnClick(TObject *Sender);
        void __fastcall WhoisSend_btnClick(TObject *Sender);
        void __fastcall TabWhoisShow(TObject *Sender);
        void __fastcall SaveDesktop_BtnClick(TObject *Sender);
        void __fastcall FormShow(TObject *Sender);
        void __fastcall DesktopLastSaved_MnuClick(TObject *Sender);
        void __fastcall TabICQShow(TObject *Sender);
        void __fastcall SettingsGenApply_BtnClick(TObject *Sender);
        void __fastcall ClearLog_mnuClick(TObject *Sender);
        void __fastcall SaveLogtoFile_mnuClick(TObject *Sender);
        void __fastcall ExportWhoIsServers_btnClick(TObject *Sender);
        void __fastcall ImportWhoIsServers_btnClick(TObject *Sender);
        void __fastcall unMap_btnClick(TObject *Sender);
        void __fastcall Button6Click(TObject *Sender);
        void __fastcall AppDirTreeViewChange(TObject *Sender,
          TTreeNode *Node);
        void __fastcall TermConnect_btnClick(TObject *Sender);
        void __fastcall TermDisconnect_btnClick(TObject *Sender);
        void __fastcall LocalServer_cmbChange(TObject *Sender);
        void __fastcall Auto_CListBoxDragOver(TObject *Sender,
          TObject *Source, int X, int Y, TDragState State, bool &Accept);
        void __fastcall Auto_CListBoxDragDrop(TObject *Sender,
          TObject *Source, int X, int Y);
        void __fastcall RFCFiles_EdDblClick(TObject *Sender);
        void __fastcall AddShortCut_btnClick(TObject *Sender);
        void __fastcall AddWIs_btnClick(TObject *Sender);
        void __fastcall RemoveWIs_btnClick(TObject *Sender);
        void __fastcall PingPsize_txtChange(TObject *Sender);
        void __fastcall PingT_txtChange(TObject *Sender);
        void __fastcall PingD_txtChange(TObject *Sender);
        void __fastcall PingPn_txtChange(TObject *Sender);
        void __fastcall PingDefaults_chkClick(TObject *Sender);
        void __fastcall ShortCutOpenItemPath_imgClick(TObject *Sender);
        void __fastcall ShortCutsListViewSelectItem(TObject *Sender,
          TListItem *Item, bool Selected);
        void __fastcall ShowLog_mnuClick(TObject *Sender);
        void __fastcall TerminalFont_mnuClick(TObject *Sender);
        void __fastcall TerminalColor_mnuClick(TObject *Sender);
        void __fastcall OpenCmdList_imgClick(TObject *Sender);
        void __fastcall TermSendListCmds_btnClick(TObject *Sender);
        void __fastcall TerminalCmdList_lbxClick(TObject *Sender);
        void __fastcall LogsClear_btnClick(TObject *Sender);
        void __fastcall LAN_CPModem_btnClick(TObject *Sender);
        void __fastcall TRCheckAll_optClick(TObject *Sender);
        void __fastcall OpenData_imgClick(TObject *Sender);
        void __fastcall RFCManageFiles_btnClick(TObject *Sender);
        void __fastcall ShortCutOpenList_imgClick(TObject *Sender);
        void __fastcall LAN_CPInternet_btnClick(TObject *Sender);
        void __fastcall LAN_CPSystem_btnClick(TObject *Sender);
        void __fastcall TerminalCmdList_lbxDblClick(TObject *Sender);
        void __fastcall IPorHost_slbClick(TObject *Sender);
        void __fastcall TabPingerShow(TObject *Sender);
        void __fastcall TabFingerShow(TObject *Sender);
        void __fastcall TabPortScannerShow(TObject *Sender);
        void __fastcall TabTraceRouteShow(TObject *Sender);
        void __fastcall TabOSDetectionShow(TObject *Sender);
        void __fastcall TabEMailValidatorShow(TObject *Sender);
        void __fastcall TabLANServicesShow(TObject *Sender);
        void __fastcall TabTRScannerServiceShow(TObject *Sender);
        void __fastcall TabWWWServiceShow(TObject *Sender);
        void __fastcall TabSimpleServicesShow(TObject *Sender);
        void __fastcall RFCRefleshList_btnClick(TObject *Sender);
        void __fastcall GetLANInfo_BtnClick(TObject *Sender);
        void __fastcall LAN_LocExpl_btnClick(TObject *Sender);
        void __fastcall LAN_IntExpl_btnClick(TObject *Sender);
        void __fastcall TraspApply_btnClick(TObject *Sender);
        void __fastcall TransReset_btnClick(TObject *Sender);
        void __fastcall SaveAllSettings_btnClick(TObject *Sender);
        void __fastcall ReLoadGenSettings_btnClick(TObject *Sender);
        void __fastcall ReLoadAllSettings_btnClick(TObject *Sender);
        void __fastcall TConsole_cmbKeyPress(TObject *Sender, char &Key);
        void __fastcall ShortCutsListFileOpt_btnClick(TObject *Sender);
        void __fastcall EditwithNotepadClick(TObject *Sender);
        void __fastcall OpenFileClick(TObject *Sender);
        void __fastcall ShortCutsCommandP_txtKeyPress(TObject *Sender,
          char &Key);
        void __fastcall SimpleServices_cmbChange(TObject *Sender);
        void __fastcall WhoIsValidateServers_btnClick(TObject *Sender);
        void __fastcall PortScanning_btnClick(TObject *Sender);
        void __fastcall PingAdvanced_slbClick(TObject *Sender);
        void __fastcall FingerSend_btnClick(TObject *Sender);
        void __fastcall SettingsConn_TabSShow(TObject *Sender);
        void __fastcall SimpleSConnect_btnClick(TObject *Sender);
        void __fastcall Find_Log_mnuClick(TObject *Sender);
        void __fastcall Term_FileOpt_btnClick(TObject *Sender);
        void __fastcall LANComputer_CmbChange(TObject *Sender);
        void __fastcall Auto_CListBoxKeyPress(TObject *Sender, char &Key);
        void __fastcall AttackLoadDLL_btnClick(TObject *Sender);
        void __fastcall AttackOpenDLL_imgClick(TObject *Sender);
        void __fastcall AttackLoadDLLDir_imgClick(TObject *Sender);
        void __fastcall AttackFunctions_lbxClick(TObject *Sender);
        void __fastcall AttackConnect_btnClick(TObject *Sender);
        void __fastcall AttackUnloadDLL_btnClick(TObject *Sender);
        void __fastcall AttackLoadDLLList_imgClick(TObject *Sender);
        void __fastcall LS_Win2K_EnableLogOn_btnClick(TObject *Sender);

private:        // private user declarations
    void __fastcall DrawItem(TMessage& Msg);
    void __fastcall MyNotify(TMessage& Msg);
    bool __fastcall TrayMessage(DWORD dwMessage);
    PSTR __fastcall TipText(void);
                                        // Tray Icon Stuff


    LONG __fastcall TmainFrm::RegOpenOrCreateKeyEx(LPCTSTR KeyString,  HKEY &hkey, HKEY RootKey = HKEY_LOCAL_MACHINE);
    bool __fastcall TmainFrm::SaveWindowSetting(TForm * curForm, HKEY &hkey);
    bool __fastcall TmainFrm::LoadWindowSetting(TForm * curForm, HKEY &hkey);
    bool __fastcall TmainFrm::SaveSettReg(AnsiString name, bool value, HKEY &hkey);
    DWORD __fastcall TmainFrm::LoadSettReg(AnsiString name, HKEY &hkey);

    bool __fastcall TmainFrm::SaveServiceData(int ServiceID);
    bool __fastcall TmainFrm::LoadServiceData(int ServiceID);
                                        // Application Setting Saving


//    bool __fastcall TmainFrm::OpenService(ServiceDLL Service, bool Report);
                                        // Service DLL loading report
    void __fastcall WndProc(Messages::TMessage &Message);
                                        // Various System Stuff

    std::vector <BYTE> m_TextStream;    // Serial Port IO
    TBackgroundCommThread *m_CommThread;

public:         // public user declarations
        __fastcall TmainFrm(TComponent* Owner);

        BEGIN_MESSAGE_MAP
        MESSAGE_HANDLER(WM_DRAWITEM,TMessage,DrawItem)
        MESSAGE_HANDLER(MYWM_NOTIFY,TMessage,MyNotify)
        END_MESSAGE_MAP(TForm)


    void NewBytesReceived(const std::vector<BYTE> &stream);// Serial Port IO

};
//---------------------------------------------------------------------------
extern PACKAGE TmainFrm *mainFrm;
//---------------------------------------------------------------------------


class AppData
 {
private:
        AnsiString FileName;
        int DataType;                   // 0 = INI
                                        // 1 = TXT 1 Column
                                        // 2 = Database
        AnsiString defFileName;
        AnsiString Description;
        bool Status;

public:
        AppData(AnsiString newFileName, int nDataType, AnsiString newDescription = "" );
        bool SetFileName(AnsiString newFileName);
        AnsiString GetTypeString();

        AnsiString GetDescription(){return Description;};
        AnsiString GetFileName(){return FileName;};
        AnsiString GetdefFileName(){return defFileName;};
        bool GetStatus(){return (this->Status);};
        int GetType() {return (this->DataType);};
 };




 AppData DesktopINI("desktop.ini", 0, "Desktop Settings");
 AppData SettingsINI("settings.ini", 0, "Application Settings");
 AppData PortNames("portsnm.db", 2, "Ports' Names DataBase");
 AppData OSReference("osfinger.db", 2, "OS Detercion Data");
 AppData TRPortNames("trports.db", 2, "Trojan Ports List");
 AppData ShortCutsList("shortcuts.db", 2, "ShortCuts List");
 AppData ReferenceList("refs.db", 2, "Files Reference List");

 AppData WhoIsServersList("wislist.txt", 1, "WhoIs Servers List");

 AppData AppLog("log.txt", 1, "Application Log");


 AppData *AllData[]        = { &DesktopINI ,
                               &SettingsINI ,
                               &PortNames ,
                               &OSReference ,
                               &TRPortNames ,
                               &ShortCutsList ,
                               &ReferenceList  };




#endif


