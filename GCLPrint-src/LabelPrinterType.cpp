// LabelPrinterType.cpp : implementation file
//

#include "stdafx.h"
#include "GCLPrint.h"
#include "LabelPrinterType.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

extern CGCLPrintApp theApp;

/////////////////////////////////////////////////////////////////////////////
// CLabelPrinterType dialog


CLabelPrinterType::CLabelPrinterType(CWnd* pParent /*=NULL*/)
	: CDialog(CLabelPrinterType::IDD, pParent)
{
	//{{AFX_DATA_INIT(CLabelPrinterType)
	m_iPrinterType = -1;
	//}}AFX_DATA_INIT
}


void CLabelPrinterType::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CLabelPrinterType)
	DDX_Radio(pDX, IDC_RPRINTYPE, m_iPrinterType);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CLabelPrinterType, CDialog)
	//{{AFX_MSG_MAP(CLabelPrinterType)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CLabelPrinterType message handlers

BOOL CLabelPrinterType::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	m_iPrinterType=theApp.GetProfileInt("Settings", "Label Printer Type", 1);

	UpdateData(FALSE);
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void CLabelPrinterType::OnOK() 
{
	// TODO: Add extra validation here
	UpdateData();
	theApp.WriteProfileInt("Settings", "Label Printer Type", m_iPrinterType);	
	CDialog::OnOK();
}
