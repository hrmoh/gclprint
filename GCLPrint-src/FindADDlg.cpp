// FindADDlg.cpp : implementation file
//

#include "stdafx.h"
#include "GCLPrint.h"
#include "FindADDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CFindADDlg dialog


CFindADDlg::CFindADDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CFindADDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CFindADDlg)
	m_sID = _T("");
	m_bPrev = FALSE;
	//}}AFX_DATA_INIT
}


void CFindADDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CFindADDlg)
	DDX_Text(pDX, IDC_EAC, m_sID);
	DDX_Check(pDX, IDC_PREV, m_bPrev);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CFindADDlg, CDialog)
	//{{AFX_MSG_MAP(CFindADDlg)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CFindADDlg message handlers

BOOL CFindADDlg::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	// TODO: Add extra initialization here
	
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void CFindADDlg::SetID(CString sID)
{
	m_sID=sID;
}
