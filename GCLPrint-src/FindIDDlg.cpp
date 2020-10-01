// FindIDDlg.cpp : implementation file
//

#include "stdafx.h"
#include "GCLPrint.h"
#include "FindIDDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CFindIDDlg dialog


CFindIDDlg::CFindIDDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CFindIDDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CFindIDDlg)
	m_sID = _T("");
	m_bPrev = FALSE;
	//}}AFX_DATA_INIT
}


void CFindIDDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CFindIDDlg)
	DDX_Text(pDX, IDC_EID, m_sID);
	DDX_Check(pDX, IDC_PREV, m_bPrev);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CFindIDDlg, CDialog)
	//{{AFX_MSG_MAP(CFindIDDlg)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CFindIDDlg message handlers

void CFindIDDlg::SetID(CString sID)
{
	m_sID=sID;
}

BOOL CFindIDDlg::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}
