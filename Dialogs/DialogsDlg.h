
// DialogsDlg.h : header file
//

#pragma once
#include "MsgDlg.h"


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

	afx_msg void OnClickedFileopen();
	afx_msg void OnClickedExit();
	afx_msg void OnClickedBcustomdialog();
	CString m_sResults;

protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	HICON m_hIcon;

	// Generated message map functions
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()

private:
	CMsgDlg m_dMsgDlg;
public:
	afx_msg void OnClickedBwhichoption();
};
