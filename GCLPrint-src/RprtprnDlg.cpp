// RprtprnDlg.cpp : implementation file
//

#include "stdafx.h"
#include "GCLPrint.h"
#include "RprtprnDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CRprtprnDlg dialog


CRprtprnDlg::CRprtprnDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CRprtprnDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CRprtprnDlg)
	m_sTitle = _T("");
	//}}AFX_DATA_INIT
	m_bIsWorking=FALSE;
}


void CRprtprnDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CRprtprnDlg)
	DDX_Text(pDX, IDC_STITLE, m_sTitle);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CRprtprnDlg, CDialog)
	//{{AFX_MSG_MAP(CRprtprnDlg)
	ON_COMMAND(ID_FILE_PRINT, OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, OnFilePrintPreview)
	ON_COMMAND(ID_PERFORMANCE_EXIT, OnPerformanceExit)
	ON_WM_ERASEBKGND()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CRprtprnDlg message handlers

void CRprtprnDlg::OnFilePrint() 
{
	m_RSPrntr.SetParent(this);
	m_RSPrntr.Print();
}

void CRprtprnDlg::OnFilePrintPreview() 
{
	// TODO: Add your command handler code here
	m_RSPrntr.SetParent(this);
	m_RSPrntr.PrintPreview();
}

void CRprtprnDlg::OnPerformanceExit() 
{
	OnOK();	
}

BOOL CRprtprnDlg::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	m_RSPrntr.SetMenuID(IDR_PRNRPMENU);

	m_RSPrntr.SetParent(this);

	
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void CRprtprnDlg::SetTitle(CString sTitle)
{
	if(m_sTitle)
		m_sTitle=sTitle;
	m_RSPrntr.SetTitle(sTitle);
}

void CRprtprnDlg::ResetFieldWidths()
{
	m_RSPrntr.ResetFieldWidths();
}

void CRprtprnDlg::SetNextFieldWidth(int iWidth)
{
	m_RSPrntr.SetNextFieldWidth(iWidth);
}

void CRprtprnDlg::HandlePrint()
{
	m_RSPrntr.SetParent(this);
	m_RSPrntr.Print();
}


BOOL CRprtprnDlg::OnEraseBkgnd(CDC* pDC) 
{

	CRect rect;
	this->GetClientRect(&rect);
	CBrush Brush(RGB(128, 128, 128));
	pDC->FillRect(&rect, &Brush);
	return TRUE;
	//return CDialog::OnEraseBkgnd(pDC);
}
