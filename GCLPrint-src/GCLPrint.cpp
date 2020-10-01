// GCLPrint.cpp : Defines the class behaviors for the application.
//

#include "stdafx.h"
#include "GCLPrint.h"

#include "MainFrm.h"
#include "GCLPrintDoc.h"
#include "GCLPrintView.h"
#include "Splash.h"

#include "Encrypt.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CGCLPrintApp

BEGIN_MESSAGE_MAP(CGCLPrintApp, CWinApp)
	//{{AFX_MSG_MAP(CGCLPrintApp)
	ON_COMMAND(ID_APP_ABOUT, OnAppAbout)
	//}}AFX_MSG_MAP
	// Standard file based document commands
	ON_COMMAND(ID_FILE_NEW, CWinApp::OnFileNew)
	ON_COMMAND(ID_FILE_OPEN, CWinApp::OnFileOpen)
	// Standard print setup command
	ON_COMMAND(ID_FILE_PRINT_SETUP, CWinApp::OnFilePrintSetup)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CGCLPrintApp construction

CGCLPrintApp::CGCLPrintApp()
{
}

/////////////////////////////////////////////////////////////////////////////
// The one and only CGCLPrintApp object

CGCLPrintApp theApp;

/////////////////////////////////////////////////////////////////////////////
// CGCLPrintApp initialization

BOOL CGCLPrintApp::InitInstance()
{
	// CG: The following block was added by the Splash Screen component.
\
	{
\
		CCommandLineInfo cmdInfo;
\
		ParseCommandLine(cmdInfo);
\

\
		CSplashWnd::EnableSplashScreen(cmdInfo.m_bShowSplash);
\
	}
	AfxEnableControlContainer();

	// Standard initialization

	InitCommonControls();


#ifdef _AFXDLL
	Enable3dControls();			// Call this when using MFC in a shared DLL
#else
	Enable3dControlsStatic();	// Call this when linking to MFC statically
#endif

	
	// Change the registry key under which our settings are stored.
	SetRegistryKey(_T("GCLPrint"));


	LoadStdProfileSettings();  // Load standard INI file options (including MRU)

	// Register document templates

	CSingleDocTemplate* pDocTemplate;
	pDocTemplate = new CSingleDocTemplate(
		IDR_MAINFRAME,
		RUNTIME_CLASS(CGCLPrintDoc),
		RUNTIME_CLASS(CMainFrame),       // main SDI frame window
		RUNTIME_CLASS(CGCLPrintView));
	AddDocTemplate(pDocTemplate);

	// Parse command line for standard shell commands, DDE, file open
	CCommandLineInfo cmdInfo;
	ParseCommandLine(cmdInfo);

	// Dispatch commands specified on the command line
	if (!ProcessShellCommand(cmdInfo))
		return FALSE;
	if(	!VerifySoftwareKey())
		return FALSE;
	m_pMainWnd->ShowWindow(SW_SHOW);
	m_pMainWnd->UpdateWindow();

	return TRUE;
}


/////////////////////////////////////////////////////////////////////////////
// CAboutDlg dialog used for App About

class CAboutDlg : public CDialog
{
public:
	CAboutDlg();

// Dialog Data
	//{{AFX_DATA(CAboutDlg)
	enum { IDD = IDD_ABOUTBOX };
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAboutDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	//{{AFX_MSG(CAboutDlg)
		// No message handlers
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialog(CAboutDlg::IDD)
{
	//{{AFX_DATA_INIT(CAboutDlg)
	//}}AFX_DATA_INIT
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CAboutDlg)
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialog)
	//{{AFX_MSG_MAP(CAboutDlg)
		// No message handlers
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

// App command to run the dialog
void CGCLPrintApp::OnAppAbout()
{
	CAboutDlg aboutDlg;
	aboutDlg.DoModal();
}

/////////////////////////////////////////////////////////////////////////////
// CGCLPrintApp message handlers


BOOL CGCLPrintApp::PreTranslateMessage(MSG* pMsg)
{
	// CG: The following lines were added by the Splash Screen component.
	if (CSplashWnd::PreTranslateAppMessage(pMsg))
		return TRUE;

	return CWinApp::PreTranslateMessage(pMsg);
}


BOOL CGCLPrintApp::VerifySoftwareKey()
{
	CString m_sHardwareKey;

	char s[]="c:\\";
	char VolumeName[255];
	DWORD VolumeSerialNumber;
	GetVolumeInformation(s, VolumeName, 255, &VolumeSerialNumber, NULL, NULL, NULL, 0);

	m_sHardwareKey.Format("%u", VolumeSerialNumber);

	
	CString strkey("hghsagvsghgyllahsjhhjhasjjhh");
	DWORD aSize;

	CEncrypt* encryptObj=new CEncrypt(strkey);

	if((aSize=encryptObj->Encrypt(m_sHardwareKey.GetBuffer(256),256))==-1)
	{
		AfxMessageBox("Error: I can not do serial check!");
		return FALSE;
	}

	CString str=m_sHardwareKey;
	
	int iLen=2*str.GetLength()/3;///2;//2*str.GetLength()/5-1;


	CString sTemp;
	m_sHardwareKey="";
	for(int i=0; i<iLen; i++)
	{
		sTemp.Format("%03u", (BYTE)str[i]);
		m_sHardwareKey=m_sHardwareKey+sTemp;
	}

	CString sRegisteryActivationCode=GetProfileString("Settings", "Serial Number","");


	CString strkey2("a786gbad87bja987832gba7");
	DWORD aSize2;

	CEncrypt* encryptObj2=new CEncrypt(strkey2);

	CString str2=m_sHardwareKey;

	if((aSize2=encryptObj2->Encrypt(str2.GetBuffer(256),256))==-1)
	{
		return FALSE;
	}

	int iLen2=2*str2.GetLength()/5-1;

	CString sTemp2;
	CString m_sActivationCode="";
	for(int i2=0; i2<iLen2; i2++)
	{
		sTemp2.Format("%03u", (BYTE)str2[i2*2]);
		m_sActivationCode=m_sActivationCode+sTemp2;
	}



	if(sRegisteryActivationCode==m_sActivationCode)
		return TRUE;


	return FALSE;
}
/*
BOOL CAboutDlg::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	m_btnOK.SetFont("Tahoma", 14);

	m_ctlAuthor.SetURL(_T("mailto:mohammadi.hr@gmail.com"));
	m_ctlAuthor.SetUnderline(FALSE);
	m_ctlAuthor.SetLinkCursor(AfxGetApp()->LoadCursor(IDC_HPOINT));


	// Load in our bmp, create our effects etc...
	CPictureHolder myTmpPicture;
	myTmpPicture.CreateFromBitmap(IDB_ABOUT);
	m_bmpRenderSource.Create32BitFromPicture(&myTmpPicture,400,304);
	m_bmpRenderTarget.Create32BitFromPicture(&myTmpPicture,400,304);

	m_uTimer=SetTimer(ID_ABOUTDLGSTARTERTIMER, 5000, NULL);

	
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE

}
*/