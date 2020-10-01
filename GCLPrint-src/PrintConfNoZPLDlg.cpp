// PrintConfNoZPLDlg.cpp : implementation file
//

#include "stdafx.h"
#include "GCLPrint.h"
#include "PrintConfNoZPLDlg.h"

#include "Code128.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

extern CGCLPrintApp theApp;

/////////////////////////////////////////////////////////////////////////////
// CPrintConfNoZPLDlg dialog


CPrintConfNoZPLDlg::CPrintConfNoZPLDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CPrintConfNoZPLDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CPrintConfNoZPLDlg)
	m_sFromID = _T("");
	m_sFromAC = _T("");
	m_sToID = _T("");
	m_sToAC = _T("");
	m_bPause = FALSE;
	m_iPauseAgter = 0;
	m_iLabelType = -1;
	m_iPrintSpeed = -1;
	//}}AFX_DATA_INIT
}


void CPrintConfNoZPLDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CPrintConfNoZPLDlg)
	DDX_Control(pDX, IDC_EPAUSEN, m_ctlPause);
	DDX_Text(pDX, IDC_FROMID, m_sFromID);
	DDX_Text(pDX, IDC_FROMAC, m_sFromAC);
	DDX_Text(pDX, IDC_TOID, m_sToID);
	DDX_Text(pDX, IDC_TOAC, m_sToAC);
	DDX_Check(pDX, IDC_CHKPAUSE, m_bPause);
	DDX_Text(pDX, IDC_EPAUSEN, m_iPauseAgter);
	DDX_Radio(pDX, IDC_LABELTYPE, m_iLabelType);
	DDX_CBIndex(pDX, IDC_CPRINTERSPEED, m_iPrintSpeed);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CPrintConfNoZPLDlg, CDialog)
	//{{AFX_MSG_MAP(CPrintConfNoZPLDlg)
	ON_BN_CLICKED(IDC_CHKPAUSE, OnChkpause)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CPrintConfNoZPLDlg message handlers

BOOL CPrintConfNoZPLDlg::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	m_ctlPause.EnableWindow(this->m_bPause);

	m_iLabelType=theApp.GetProfileInt("Settings", "Last Label Type", 0);
	m_iPrintSpeed=theApp.GetProfileInt("Settings", "Speed", 2)-2;

	UpdateData(FALSE);

	
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void CPrintConfNoZPLDlg::OnChkpause() 
{
	UpdateData();
	m_ctlPause.EnableWindow(m_bPause);
	
}


void OnBeginPrinting(CDC *pDC, CPrintInfo* pInfo)
{
    // maybe pre cache some pens or brushes, or modify the
    // properties of the DC
//	pInfo->SetMinPage(1);
	pInfo->SetMaxPage(1);
}

void OnPrint(CDC *pDC, CPrintInfo* pInfo)
{
    // Do your drawing/printing exactly as you would in a
    // CView::OnDraw function. The CPrintInfo structure
    // will give you the bounds and the current page number


}

void OnEndPrinting(CDC *pDC, CPrintInfo* pInfo)
{
    // Clean up pens or brushes, or restore the DC
}


void CPrintConfNoZPLDlg::OnOK() 
{
	UpdateData();

	theApp.WriteProfileInt("Settings", "Last Label Type", m_iLabelType);
	theApp.WriteProfileInt("Settings", "Speed", m_iPrintSpeed+2);

    CPrintDialog printDlg(FALSE);

    if (printDlg.DoModal() == IDCANCEL)     // Get printer settings from user
        return;


	m_pRs->MoveFirst();
	m_pRs->Move(m_lStart);
	m_lCurrent=m_lStart;
	LPDEVMODE pDevMode = printDlg.GetDevMode();
	PrintNext(printDlg.GetPrinterDC(), pDevMode);


	CDialog::OnOK();
}

BOOL CPrintConfNoZPLDlg::PrintNext(HDC hdc, LPDEVMODE pDevMode)
{

	if(m_iLabelType==3)
	{
		int iTypeToPrint;
		m_pRs->GetFieldValue(9, iTypeToPrint);
	}
	else
	{
	if(m_iLabelType==0)
	{
    CDC dc;
    dc.Attach(hdc);     // Get and attach a printer DC
    dc.m_bPrinting = TRUE;

	// Set landscape
	pDevMode->dmFields |= DM_ORIENTATION;
	pDevMode->dmOrientation = DMORIENT_PORTRAIT;
	dc.ResetDC(pDevMode);


	
    CString strTitle;                       // Get the application title
    strTitle.LoadString(AFX_IDS_APP_TITLE);

    DOCINFO di;                             // Initialise print document details
    ::ZeroMemory (&di, sizeof (DOCINFO));
    di.cbSize = sizeof (DOCINFO);
    di.lpszDocName = strTitle;

    BOOL bPrintingOK = dc.StartDoc(&di);    // Begin a new print job

    // Get the printing extents and store in the m_rectDraw field of a 
    // CPrintInfo object
    CPrintInfo Info;
    Info.m_rectDraw.SetRect(0,0, 
                            dc.GetDeviceCaps(HORZRES), 
                            dc.GetDeviceCaps(VERTRES));
	Info.m_bDirect=TRUE;
    OnBeginPrinting(&dc, &Info);            // Call your "Init printing" function
	Info.SetMaxPage(m_lEnd-m_lStart+1);
    for (UINT page = Info.GetMinPage(); 
         page <= Info.GetMaxPage() && bPrintingOK; 
         page++)
	 {
	CString szSubscriptionCode;
	m_pRs->GetFieldValue(1, szSubscriptionCode);

	CString szAddressCode;
	m_pRs->GetFieldValue(2, szAddressCode);
	char sTemp[255];
	strcpy(sTemp, szSubscriptionCode);
	for(int i=3; i<15; i++)
		sTemp[i-3]=sTemp[i];
	sTemp[12]=0;

        dc.StartPage();                     // begin new page
        Info.m_nCurPage = page;
        OnPrint(&dc, &Info);                // Call your "Print page" function

	    int nFontSize = 44;
		CString strFontName = "B Titr Bold";
		CFont fCompanyTitleFont;
		fCompanyTitleFont.CreateFont(nFontSize, 0,0,0, FW_NORMAL, 0,0,0, ARABIC_CHARSET,
                             OUT_CHARACTER_PRECIS, CLIP_CHARACTER_PRECIS, DEFAULT_QUALITY,
                             DEFAULT_PITCH | FF_DONTCARE, strFontName);
            
		CFont *pOldFont = dc.SelectObject(&fCompanyTitleFont);

		CRect rect(40,25,400, 75);



		dc.DrawText(theApp.GetProfileString("Settings", "Company Name", ""), -1, rect, DT_RTLREADING|DT_CENTER);

	    nFontSize = 48;
		strFontName = "B Traffic";
		CFont fRegionNameFont;
		fRegionNameFont.CreateFont(nFontSize, 0,0,0, FW_NORMAL, 0,0,0, ARABIC_CHARSET,
                             OUT_CHARACTER_PRECIS, CLIP_CHARACTER_PRECIS, DEFAULT_QUALITY,
                             DEFAULT_PITCH | FF_DONTCARE, strFontName);

		CRect rect1(140,75,300, 125);

		dc.SelectObject(&fRegionNameFont);

		dc.DrawText(theApp.GetProfileString("Settings", "Region Name", ""), -1, rect1, DT_RTLREADING|DT_CENTER);


		CCode128	oBarcode;

		double dNarrowBar=0.014;
		double dHeight=0.35;

		oBarcode.LoadData(sTemp,dNarrowBar,dHeight,dc.GetSafeHdc(),70,140,SUBSETC);
		oBarcode.DrawBitmap();

	    nFontSize = 75;
		strFontName = "B Traffic";
		CFont fSubscriptionCodeFont;
		fSubscriptionCodeFont.CreateFont(nFontSize, 0,0,0, FW_NORMAL, 0,0,0, ARABIC_CHARSET,
                             OUT_CHARACTER_PRECIS, CLIP_CHARACTER_PRECIS, DEFAULT_QUALITY,
                             DEFAULT_PITCH | FF_DONTCARE, strFontName);

		CRect rect2(30,210,410, 260);

		dc.SelectObject(&fSubscriptionCodeFont);

		dc.DrawText(szSubscriptionCode, -1, rect2, DT_RTLREADING|DT_CENTER);

		CRect rect3(30,270,410, 300);
		dc.SelectObject(&fRegionNameFont);
		dc.DrawText(szAddressCode, -1, rect3, DT_RTLREADING|DT_CENTER);



		dc.SelectObject(pOldFont);

        bPrintingOK = (dc.EndPage() > 0);   // end page

		int iTimerInterval=1000;
		switch(theApp.GetProfileInt("Settings", "Speed", 2))
		{
		case 2:
			iTimerInterval=1800;
			break;
		case 3:
			iTimerInterval=1600;
			break;
		case 4:
			iTimerInterval=1400;
			break;
		case 5:
			iTimerInterval=1200;
			break;
		case 6:
			iTimerInterval=1000;
			break;
		case 7:
			iTimerInterval=800;
			break;
		case 8:
			iTimerInterval=600;
			break;
		case 9:
			iTimerInterval=400;
			break;
		case 10:
			iTimerInterval=200;
			break;
		}
		if( (m_iLabelType==2) /*|| (m_iLabelType==3)*/ )
			iTimerInterval=iTimerInterval*2;

		Sleep(iTimerInterval);

		m_lCurrent++;
		if(m_lCurrent>m_lEnd)
			return FALSE;

		m_pRs->MoveNext();

    }
    OnEndPrinting(&dc, &Info);              // Call your "Clean up" function

    if (bPrintingOK)
        dc.EndDoc();                        // end a print job
    else
        dc.AbortDoc();                      // abort job.
		

    dc.DeleteDC();                          // delete the printer DC
	}
	else
	if(m_iLabelType==1)
	{//nobarcode
    CDC dc;
    dc.Attach(hdc);     // Get and attach a printer DC
    dc.m_bPrinting = TRUE;

	// Set landscape
	pDevMode->dmFields |= DM_ORIENTATION;
	pDevMode->dmOrientation = DMORIENT_PORTRAIT;
	dc.ResetDC(pDevMode);


	
    CString strTitle;                       // Get the application title
    strTitle.LoadString(AFX_IDS_APP_TITLE);

    DOCINFO di;                             // Initialise print document details
    ::ZeroMemory (&di, sizeof (DOCINFO));
    di.cbSize = sizeof (DOCINFO);
    di.lpszDocName = strTitle;

    BOOL bPrintingOK = dc.StartDoc(&di);    // Begin a new print job

    // Get the printing extents and store in the m_rectDraw field of a 
    // CPrintInfo object
    CPrintInfo Info;
    Info.m_rectDraw.SetRect(0,0, 
                            dc.GetDeviceCaps(HORZRES), 
                            dc.GetDeviceCaps(VERTRES));
	Info.m_bDirect=TRUE;
    OnBeginPrinting(&dc, &Info);            // Call your "Init printing" function
	Info.SetMaxPage(m_lEnd-m_lStart+1);
    for (UINT page = Info.GetMinPage(); 
         page <= Info.GetMaxPage() && bPrintingOK; 
         page++)
	 {
	CString szSubscriptionCode;
	m_pRs->GetFieldValue(1, szSubscriptionCode);

	CString szAddressCode;
	m_pRs->GetFieldValue(2, szAddressCode);
	char sTemp[255];
	strcpy(sTemp, szSubscriptionCode);
	for(int i=3; i<15; i++)
		sTemp[i-3]=sTemp[i];
	sTemp[12]=0;

        dc.StartPage();                     // begin new page
        Info.m_nCurPage = page;
        OnPrint(&dc, &Info);                // Call your "Print page" function


		HBITMAP hBitmap=(HBITMAP)::LoadImage(AfxGetInstanceHandle(), MAKEINTRESOURCE(IDB_ARM), IMAGE_BITMAP, 0, 0, LR_CREATEDIBSECTION);
		CBitmap arm;
		arm.Attach(hBitmap);
		BITMAP bm;
		arm.GetBitmap(&bm);
		
		CDC dcMem;
		dcMem.CreateCompatibleDC(&dc);

		dcMem.SelectObject(&arm);

		dc.StretchBlt(175, 50, 150, 125, &dcMem, 0, 0, bm.bmWidth, bm.bmHeight, SRCCOPY);

	    int nFontSize = 48;
		CString strFontName = "B Traffic";
		CFont fRegionNameFont;
		fRegionNameFont.CreateFont(nFontSize, 0,0,0, FW_NORMAL, 0,0,0, ARABIC_CHARSET,
                             OUT_CHARACTER_PRECIS, CLIP_CHARACTER_PRECIS, DEFAULT_QUALITY,
                             DEFAULT_PITCH | FF_DONTCARE, strFontName);

		CRect rect1(260,25,420, 75);

		dc.SelectObject(&fRegionNameFont);

		dc.DrawText(theApp.GetProfileString("Settings", "Region Name", ""), -1, rect1, DT_RTLREADING|DT_CENTER);


/*		CCode128	oBarcode;

		double dNarrowBar=0.014;
		double dHeight=0.35;

		oBarcode.LoadData(sTemp,dNarrowBar,dHeight,dc.GetSafeHdc(),70,140,SUBSETC);
		oBarcode.DrawBitmap();*/


	    nFontSize = 75;
		strFontName = "B Traffic";
		CFont fSubscriptionCodeFont;
		fSubscriptionCodeFont.CreateFont(nFontSize, 0,0,0, FW_NORMAL, 0,0,0, ARABIC_CHARSET,
                             OUT_CHARACTER_PRECIS, CLIP_CHARACTER_PRECIS, DEFAULT_QUALITY,
                             DEFAULT_PITCH | FF_DONTCARE, strFontName);

		CRect rect2(30,210,410, 260);

		dc.SelectObject(&fSubscriptionCodeFont);

		dc.DrawText(szSubscriptionCode, -1, rect2, DT_RTLREADING|DT_CENTER);

		CRect rect3(30,270,410, 300);
		dc.SelectObject(&fRegionNameFont);
		dc.DrawText(szAddressCode, -1, rect3, DT_RTLREADING|DT_CENTER);

		nFontSize = 44;
		strFontName = "B Titr Bold";
		CFont fCompanyTitleFont;
		fCompanyTitleFont.CreateFont(nFontSize, 0,0,0, FW_NORMAL, 0,0,0, ARABIC_CHARSET,
                             OUT_CHARACTER_PRECIS, CLIP_CHARACTER_PRECIS, DEFAULT_QUALITY,
                             DEFAULT_PITCH | FF_DONTCARE, strFontName);
            
		CFont *pOldFont = dc.SelectObject(&fCompanyTitleFont);

		CRect rect(40,175,400, 225);



		dc.DrawText(theApp.GetProfileString("Settings", "Company Name", ""), -1, rect, DT_RTLREADING|DT_CENTER);


		dc.SelectObject(pOldFont);

        bPrintingOK = (dc.EndPage() > 0);   // end page

		int iTimerInterval=1000;
		switch(theApp.GetProfileInt("Settings", "Speed", 2))
		{
		case 2:
			iTimerInterval=1800;
			break;
		case 3:
			iTimerInterval=1600;
			break;
		case 4:
			iTimerInterval=1400;
			break;
		case 5:
			iTimerInterval=1200;
			break;
		case 6:
			iTimerInterval=1000;
			break;
		case 7:
			iTimerInterval=800;
			break;
		case 8:
			iTimerInterval=600;
			break;
		case 9:
			iTimerInterval=400;
			break;
		case 10:
			iTimerInterval=200;
			break;
		}
		if( (m_iLabelType==2) /*|| (m_iLabelType==3)*/ )
			iTimerInterval=iTimerInterval*2;

		Sleep(iTimerInterval);

		m_lCurrent++;
		if(m_lCurrent>m_lEnd)
			return FALSE;

		m_pRs->MoveNext();

    }
    OnEndPrinting(&dc, &Info);              // Call your "Clean up" function

    if (bPrintingOK)
        dc.EndDoc();                        // end a print job
    else
        dc.AbortDoc();                      // abort job.
		

    dc.DeleteDC();                          // delete the printer DC

	}
	}

	if(m_pRs->IsEof())
		return FALSE;

	return TRUE;

}
