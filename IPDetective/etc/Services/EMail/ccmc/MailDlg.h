class CMailDlg : public CDialog
{
public:
	CMailDlg(CWnd* pParent = NULL);	// standard constructor

	//{{AFX_DATA(CMailDlg)
	enum { IDD = IDD_MAIL_DIALOG };
	CString	m_sBCC;
	CString	m_sBody;
	CString	m_sCC;
	CString	m_sFile;
	CString	m_sSubject;
	CString	m_sTo;
	//}}AFX_DATA

	CString	m_sProfile;
  CString m_sPassword;

	//{{AFX_VIRTUAL(CMailDlg)
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

protected:
	HICON m_hIcon;

	//{{AFX_MSG(CMailDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnConfiguration();
	afx_msg void OnSend();
	afx_msg void OnBrowseFile();
	afx_msg void OnDestroy();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

