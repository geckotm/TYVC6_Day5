// MsgDlg.cpp : implementation file
//

#include "stdafx.h"
#include "Dialogs.h"
#include "MsgDlg.h"
#include "afxdialogex.h"


// CMsgDlg dialog

IMPLEMENT_DYNAMIC(CMsgDlg, CDialog)

CMsgDlg::CMsgDlg(CWnd* pParent /*=NULL*/)
	: CDialog(IDD_MESSAGEDLG, pParent)
	, m_sMessage(_T(""))
	, m_iOption(0)
{

}

CMsgDlg::~CMsgDlg()
{
}

void CMsgDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_MESSAGE, m_sMessage);
	DDX_Radio(pDX, IDC_OPTION1, m_iOption);
}


BEGIN_MESSAGE_MAP(CMsgDlg, CDialog)
	ON_EN_CHANGE(IDC_MESSAGE, &CMsgDlg::OnEnChangeMessage)
END_MESSAGE_MAP()


// CMsgDlg message handlers


void CMsgDlg::OnEnChangeMessage()
{
	// TODO:  If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CDialog::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.

	// TODO:  Add your control notification handler code here
}
