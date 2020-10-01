// TitlesDlg.cpp : implementation file
//

#include "stdafx.h"
#include "GCLPrint.h"
#include "TitlesDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

extern CGCLPrintApp theApp;

/////////////////////////////////////////////////////////////////////////////
// CTitlesDlg dialog


CTitlesDlg::CTitlesDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CTitlesDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CTitlesDlg)
	m_sCompanyName = _T("");
	m_sRegionName = _T("");
	//}}AFX_DATA_INIT
}


void CTitlesDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CTitlesDlg)
	DDX_Text(pDX, IDC_ECOMPANY, m_sCompanyName);
	DDX_Text(pDX, IDC_EREGION, m_sRegionName);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CTitlesDlg, CDialog)
	//{{AFX_MSG_MAP(CTitlesDlg)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CTitlesDlg message handlers

BOOL CTitlesDlg::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	// TODO: Add extra initialization here
	m_sCompanyName=theApp.GetProfileString("Settings", "Company Name", "");
	m_sRegionName=theApp.GetProfileString("Settings", "Region Name", "");

	UpdateData(FALSE);
	
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void CTitlesDlg::OnOK() 
{

	UpdateData();
	theApp.WriteProfileString("Settings", "Company Name", m_sCompanyName);
	theApp.WriteProfileString("Settings", "Region Name", m_sRegionName);
	
	CDialog::OnOK();
}
