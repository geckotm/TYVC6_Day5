
// DialogsDlg.cpp : implementation file
//

#include "stdafx.h"
#include "Dialogs.h"
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
