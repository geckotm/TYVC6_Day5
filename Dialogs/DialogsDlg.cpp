
// DialogsDlg.cpp : implementation file
//

#include "stdafx.h"
#include "Dialogs.h"
#include "MsgDlg.h"
#include "DialogsDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CDialogsDlg dialog



CDialogsDlg::CDialogsDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_DIALOGS_DIALOG, pParent)
	, m_sResults(_T(""))
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CDialogsDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_RESULTS, m_sResults);
}

BEGIN_MESSAGE_MAP(CDialogsDlg, CDialogEx)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_FILEOPEN, &CDialogsDlg::OnClickedFileopen)
	ON_BN_CLICKED(IDC_EXIT, &CDialogsDlg::OnClickedExit)
	ON_BN_CLICKED(IDC_BCUSTOMDIALOG, &CDialogsDlg::OnClickedBcustomdialog)
	ON_BN_CLICKED(IDC_BWHICHOPTION, &CDialogsDlg::OnClickedBwhichoption)
END_MESSAGE_MAP()


// CDialogsDlg message handlers

BOOL CDialogsDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon

	// TODO: Add extra initialization here

	return TRUE;  // return TRUE  unless you set the focus to a control
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CDialogsDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// The system calls this function to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CDialogsDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CDialogsDlg::OnClickedFileopen()
{
	CFileDialog myFileOpenDialog(TRUE);

	// Show the dialog and capture the result
	if (myFileOpenDialog.DoModal() == IDOK)
	{
		//get the filename selected
		m_sResults = myFileOpenDialog.GetFileName();
		//update the dialog
		UpdateData(FALSE);
	}
}


void CDialogsDlg::OnClickedExit()
{
	OnOK();
}


void CDialogsDlg::OnClickedBcustomdialog()
{
	// TODO: Add your control notification handler code here

	if (m_dMsgDlg.DoModal() == IDOK)
	{
		//The user pressed OK, display what he has typed in the main dialog
		m_sResults = m_dMsgDlg.m_sMessage;
		//update DialogsDlg
		UpdateData(FALSE);
	}
}


void CDialogsDlg::OnClickedBwhichoption()
{
	switch (m_dMsgDlg.m_iOption)
	{
	case 0:
		m_sResults = _T("Option 1 was selected");
		break;
	case 1:
		m_sResults = _T("Option 2 was selected");
		break;
	case 2:
		m_sResults = _T("Option 1 was selected");
		break;
	case 3:
		m_sResults = _T("Option 2 was selected");
		break;
	default:
		m_sResults = _T("No option was selected");
		break;
	}
	UpdateData(FALSE);
}
