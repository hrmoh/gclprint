// PrintConfDlg.cpp : implementation file
//

#include "stdafx.h"
#include "GCLPrint.h"
#include "PrintConfDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

extern CGCLPrintApp theApp;

/////////////////////////////////////////////////////////////////////////////
// CPrintConfDlg dialog


CPrintConfDlg::CPrintConfDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CPrintConfDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CPrintConfDlg)
	m_sFromID = _T("");
	m_sFromAC = _T("");
	m_sToAC = _T("");
	m_sToID = _T("");
	m_iPauseAgter = 0;
	m_iWhichPort = -1;
	m_bPause = FALSE;
	m_iLabelType = -1;
	m_iDarkness = 0;
	m_iPrintSpeed = -1;
	//}}AFX_DATA_INIT
}


void CPrintConfDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CPrintConfDlg)
	DDX_Control(pDX, IDC_DARKNESS, m_ctlSlider);
	DDX_Control(pDX, IDC_EPAUSEN, m_ctlPause);
	DDX_Text(pDX, IDC_FROMID, m_sFromID);
	DDX_Text(pDX, IDC_FROMAC, m_sFromAC);
	DDX_Text(pDX, IDC_TOAC, m_sToAC);
	DDX_Text(pDX, IDC_TOID, m_sToID);
	DDX_Text(pDX, IDC_EPAUSEN, m_iPauseAgter);
	DDX_CBIndex(pDX, IDC_CPORT, m_iWhichPort);
	DDX_Check(pDX, IDC_CHKPAUSE, m_bPause);
	DDX_Radio(pDX, IDC_LABELTYPE, m_iLabelType);
	DDX_Slider(pDX, IDC_DARKNESS, m_iDarkness);
	DDX_CBIndex(pDX, IDC_CPRINTERSPEED, m_iPrintSpeed);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CPrintConfDlg, CDialog)
	//{{AFX_MSG_MAP(CPrintConfDlg)
	ON_BN_CLICKED(IDC_CHKPAUSE, OnChkPause)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CPrintConfDlg message handlers

void CPrintConfDlg::OnChkPause() 
{
	UpdateData();
	m_ctlPause.EnableWindow(m_bPause);
}

BOOL CPrintConfDlg::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	m_ctlPause.EnableWindow(this->m_bPause);
	m_ctlSlider.SetRange(0, 30);
	m_iWhichPort=theApp.GetProfileInt("Settings", "Last Port", 0);
	m_iLabelType=theApp.GetProfileInt("Settings", "Last Label Type", 0);
	m_iDarkness=theApp.GetProfileInt("Settings", "Darkness", 30);
	m_iPrintSpeed=theApp.GetProfileInt("Settings", "Speed", 2)-2;

	UpdateData(FALSE);
	
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void CPrintConfDlg::OnOK() 
{
	UpdateData();

	theApp.WriteProfileInt("Settings", "Last Port", m_iWhichPort);
	theApp.WriteProfileInt("Settings", "Last Label Type", m_iLabelType);
	theApp.WriteProfileInt("Settings", "Darkness", m_iDarkness);
	theApp.WriteProfileInt("Settings", "Speed", m_iPrintSpeed+2);

	CDialog::OnOK();
}
