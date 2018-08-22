class CMailConfigurationDlg : public CDialog
{
public:
	CMailConfigurationDlg(CWnd* pParent = NULL);   // standard constructor

	//{{AFX_DATA(CMailConfigurationDlg)
	enum { IDD = IDD_CONFIGURATION };
	CString	m_sPassword;
	CString	m_sProfile;
	//}}AFX_DATA

	//{{AFX_VIRTUAL(CMailConfigurationDlg)
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

protected:

	//{{AFX_MSG(CMailConfigurationDlg)
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

