// ManualReadDlg.cpp : implementation file
//

#include "stdafx.h"
#include "GCLPrint.h"
#include "ManualReadDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CManualReadDlg dialog


CManualReadDlg::CManualReadDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CManualReadDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CManualReadDlg)
	m_sID = _T("");
	m_sAD = _T("");
	m_sSerial = _T("");
	m_sName = _T("");
	m_sAddress = _T("");
	//}}AFX_DATA_INIT
}


void CManualReadDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CManualReadDlg)
	DDX_Text(pDX, IDC_FIELD1, m_sID);
	DDX_Text(pDX, IDC_FIELD2, m_sAD);
	DDX_Text(pDX, IDC_FIELD3, m_sSerial);
	DDX_Text(pDX, IDC_FIELD4, m_sName);
	DDX_Text(pDX, IDC_FIELD5, m_sAddress);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CManualReadDlg, CDialog)
	//{{AFX_MSG_MAP(CManualReadDlg)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CManualReadDlg message handlers

void CManualReadDlg::OnOK() 
{
	UpdateData();
	if(m_sID.GetLength())			
		CDialog::OnOK();
}
