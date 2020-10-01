// GenIDsDlg.cpp : implementation file
//

#include "stdafx.h"
#include "GCLPrint.h"
#include "GenIDsDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CGenIDsDlg dialog


CGenIDsDlg::CGenIDsDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CGenIDsDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CGenIDsDlg)
	m_sFrom = _T("");
	m_sTo = _T("");
	//}}AFX_DATA_INIT
}


void CGenIDsDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CGenIDsDlg)
	DDX_Text(pDX, IDC_FROM, m_sFrom);
	DDX_Text(pDX, IDC_TO, m_sTo);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CGenIDsDlg, CDialog)
	//{{AFX_MSG_MAP(CGenIDsDlg)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CGenIDsDlg message handlers

void CGenIDsDlg::OnOK() 
{
	UpdateData();

	if(m_sFrom>m_sTo)
		return;
	if(m_sFrom.GetLength()!=13)
		return;
	if(m_sTo.GetLength()!=13)
		return;
	
	CDialog::OnOK();
}
