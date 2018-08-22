; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CIPCTraceClientDlg
LastTemplate=CDialog
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "IPCTraceClient.h"

ClassCount=4
Class1=CIPCTraceClientApp
Class2=CIPCTraceClientDlg

ResourceCount=4
Resource2=IDR_MAINFRAME
Resource3=IDD_IPCTRACECLIENT_DIALOG
Resource4=IDD_IPCTRACECLIENT_DIALOG (English (U.S.))

[CLS:CIPCTraceClientApp]
Type=0
HeaderFile=IPCTraceClient.h
ImplementationFile=IPCTraceClient.cpp
Filter=N

[CLS:CIPCTraceClientDlg]
Type=0
HeaderFile=IPCTraceClientDlg.h
ImplementationFile=IPCTraceClientDlg.cpp
Filter=D
BaseClass=CDialog
VirtualFilter=dWC



[DLG:IDD_IPCTRACECLIENT_DIALOG]
Type=1
ControlCount=3
Control1=IDOK,button,1342242817
Control2=IDCANCEL,button,1342242816
Control3=IDC_STATIC,static,1342308352
Class=CIPCTraceClientDlg

[DLG:IDD_IPCTRACECLIENT_DIALOG (English (U.S.))]
Type=1
Class=?
ControlCount=2
Control1=IDC_STATIC,static,1342308352
Control2=IDC_BTN_TRACE,button,1342242816

