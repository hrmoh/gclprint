// RgstrPDTMngrDlg.cpp : implementation file
//

#include "stdafx.h"
#include "RgstrPDTMngr.h"
#include "RgstrPDTMngrDlg.h"
#include "Encrypt.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CRgstrPDTMngrDlg dialog

CRgstrPDTMngrDlg::CRgstrPDTMngrDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CRgstrPDTMngrDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CRgstrPDTMngrDlg)
	m_sHardwareKey = _T("");
	m_sActivationCode = _T("");
	//}}AFX_DATA_INIT
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CRgstrPDTMngrDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CRgstrPDTMngrDlg)
	DDX_Text(pDX, ID_EHARDWAREKEY, m_sHardwareKey);
	DDX_Text(pDX, IDC_EACTIVATIONCODE, m_sActivationCode);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CRgstrPDTMngrDlg, CDialog)
	//{{AFX_MSG_MAP(CRgstrPDTMngrDlg)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BCHANGE, OnBchange)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CRgstrPDTMngrDlg message handlers

BOOL CRgstrPDTMngrDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon



	char s[]="c:\\";
	char VolumeName[255];
	DWORD VolumeSerialNumber;
	GetVolumeInformation(s, VolumeName, 255, &VolumeSerialNumber, NULL, NULL, NULL, 0);

	CString str;
	str.Format("%u", VolumeSerialNumber);

	CString strkey("hghsagvsghgyllahsjhhjhasjjhh");
	DWORD aSize;

	CEncrypt* encryptObj=new CEncrypt(strkey);

	if((aSize=encryptObj->Encrypt(str.GetBuffer(256),256))==-1)
	{
		return FALSE;
	}


	int iLen=2*str.GetLength()/3;///2;//2*str.GetLength()/5-1;

	CString sTemp;
	for(int i=0; i<iLen; i++)
	{
		sTemp.Format("%03u", (BYTE)str[i/*2*/]);
		m_sHardwareKey=m_sHardwareKey+sTemp;
	}


	char *pKey="Software\\GCLPrint\\GCLPrint\\Settings";
	reg=new CRegister(pKey);

	char *key="Serial Number";

	m_sActivationCode=reg->getRegValue(key, &aSize);
	


	UpdateData(FALSE);


	
	return TRUE;  // return TRUE  unless you set the focus to a control
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CRgstrPDTMngrDlg::OnPaint() 
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, (WPARAM) dc.GetSafeHdc(), 0);

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
		CDialog::OnPaint();
	}
}

HCURSOR CRgstrPDTMngrDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CRgstrPDTMngrDlg::OnBchange() 
{

	UpdateData();
	char *key="Serial Number";


	CString str=m_sActivationCode;
	
	reg->setRegValue(key,str.GetBuffer(256),str.GetLength());


}
