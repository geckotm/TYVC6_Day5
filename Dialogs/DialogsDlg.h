
// DialogsDlg.h : header file
//

#pragma once


// CDialogsDlg dialog
class CDialogsDlg : public CDialogEx
{
// Construction
public:
	CDialogsDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOGS_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support


// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnClickedFileopen();
	CString m_sResults;
	afx_msg void OnClickedExit();
};
