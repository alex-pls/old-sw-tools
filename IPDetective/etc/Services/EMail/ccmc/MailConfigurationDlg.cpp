#include "stdafx.h"
#include "Mail.h"
#include "MailConfigurationDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

CMailConfigurationDlg::CMailConfigurationDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CMailConfigurationDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CMailConfigurationDlg)
	m_sPassword = _T("");
	m_sProfile = _T("");
	//}}AFX_DATA_INIT
}

void CMailConfigurationDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CMailConfigurationDlg)
	DDX_Text(pDX, IDC_PASSWORD, m_sPassword);
	DDX_Text(pDX, IDC_PROFILE, m_sProfile);
	//}}AFX_DATA_MAP

  if (pDX->m_bSaveAndValidate)
  {
    if (m_sProfile.IsEmpty())
    {
      AfxMessageBox(_T("Please specify a valid profile"));
      pDX->PrepareEditCtrl(IDC_PROFILE);
      pDX->Fail();
    }
  }
}


BEGIN_MESSAGE_MAP(CMailConfigurationDlg, CDialog)
	//{{AFX_MSG_MAP(CMailConfigurationDlg)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

