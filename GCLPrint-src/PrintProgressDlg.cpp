// PrintProgressDlg.cpp : implementation file
//

#include "stdafx.h"
#include "GCLPrint.h"
#include "PrintProgressDlg.h"

#include "MaryamString.h"

#include "MsgDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

extern CGCLPrintApp theApp;

/////////////////////////////////////////////////////////////////////////////
// CPrintProgressDlg dialog


CPrintProgressDlg::CPrintProgressDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CPrintProgressDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CPrintProgressDlg)
	m_sNowPrinting = _T("");
	m_iSpeed = 0;
	//}}AFX_DATA_INIT
}


void CPrintProgressDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CPrintProgressDlg)
	DDX_Control(pDX, IDC_BACK, m_btnBack);
	DDX_Control(pDX, IDC_SPEEDSLIDER, m_ctlSpeedSlider);
	DDX_Control(pDX, IDC_PAUSE, m_btnPause);
	DDX_Control(pDX, IDC_PRINTPROGRESS, m_ctlProgressBar);
	DDX_Text(pDX, IDC_SNOWPRINTING, m_sNowPrinting);
	DDX_Slider(pDX, IDC_SPEEDSLIDER, m_iSpeed);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CPrintProgressDlg, CDialog)
	//{{AFX_MSG_MAP(CPrintProgressDlg)
	ON_WM_TIMER()
	ON_BN_CLICKED(IDC_PAUSE, OnPause)
	ON_NOTIFY(NM_RELEASEDCAPTURE, IDC_SPEEDSLIDER, OnReleasedcaptureSpeedslider)
	ON_BN_CLICKED(IDC_BACK, OnBack)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CPrintProgressDlg message handlers

void CPrintProgressDlg::SetRecordset(CADORecordset *pRs)
{
	m_pRs=pRs;
}

BOOL CPrintProgressDlg::OnInitDialog() 
{
	CDialog::OnInitDialog();
	

	zplParser.Open("design\\mahallat.zpl", TRUE);



	
	CMaryamString sCompanyName(theApp.GetProfileString("Settings", "Company Name", ""));
	zplParser.SetVar(0, sCompanyName.GetString());
	zplParser.SetNobarcodeVar(0, sCompanyName.GetString());

	CMaryamString sRegionName(theApp.GetProfileString("Settings", "Region Name", ""));

	zplParser.SetVar(1, sRegionName.GetString());
	zplParser.SetNobarcodeVar(1, sRegionName.GetString());

	if( (m_iLabelType==1) || (m_iLabelType==2) || (m_iLabelType==3))
		zplParser.LoadArmToPrinter(m_hComm);

	CString sDarkness;
	sDarkness.Format("~SD%.2d", theApp.GetProfileInt("Settings", "Darkness", 30));
	DWORD dwWritten;
	WriteFile(m_hComm,  sDarkness, 5, &dwWritten, NULL);	

	m_pRs->MoveFirst();
	m_pRs->Move(m_lStart);
	m_iPrinted=0;



	m_bPauseForNow=FALSE;

	m_ctlProgressBar.SetRange(0, m_lEnd-m_lStart+1);

	m_ctlProgressBar.SetPos(0);

	m_ctlSpeedSlider.SetRange(0, 8);
	m_iSpeed=theApp.GetProfileInt("Settings", "Speed", 2)-2;

	m_lCurrent=m_lStart;
	if(!PrintNext())
	{
		CPrintProgressDlg::OnOK();
		return FALSE;
	}

	int iTimerInterval=1000;
	switch(theApp.GetProfileInt("Settings", "Speed", 2))
	{
	case 2:
		iTimerInterval=787;
		break;
	case 3:
		iTimerInterval=525;
		break;
	case 4:
		iTimerInterval=393;
		break;
	case 5:
		iTimerInterval=314;
		break;
	case 6:
		iTimerInterval=262;
		break;
	case 7:
		iTimerInterval=224;
		break;
	case 8:
		iTimerInterval=196;
		break;
	case 9:
		iTimerInterval=181;
		break;
	case 10:
		iTimerInterval=163;
		break;
	}
	if( (m_iLabelType==2) /*|| (m_iLabelType==3)*/ )
		iTimerInterval=iTimerInterval*2;
	SetTimer(ID_PROGRESSTIMER, iTimerInterval, NULL);

	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

BOOL CPrintProgressDlg::PrintNext()
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
	zplParser.SetVar(2, sTemp);
	zplParser.SetNobarcodeVar(2, "");
	zplParser.SetVar(3, szSubscriptionCode);
	zplParser.SetNobarcodeVar(3, szSubscriptionCode);
	zplParser.SetVar(4, szAddressCode);
	zplParser.SetNobarcodeVar(4, szAddressCode);

	theApp.GetProfileInt("Settings", "Darkness", 30);

	if(m_iLabelType==3)
	{
		int iTypeToPrint;
		m_pRs->GetFieldValue(9, iTypeToPrint);
		zplParser.Print(m_hComm, iTypeToPrint);
	}
	else
		zplParser.Print(m_hComm, m_iLabelType);
	m_ctlProgressBar.SetPos(m_lCurrent-m_lStart+1);
	m_sNowPrinting.Format("ç«Å »—ç”» %d «“ %d", m_lCurrent-m_lStart+1, m_lEnd-m_lStart+1);
	UpdateData(FALSE);
	m_pRs->MoveNext();

	m_lCurrent++;
	if(m_lCurrent>m_lEnd)
		return FALSE;

	m_iPrinted++;
	
	if(m_bPauseAfter)
	{
		if(m_iPrinted==(m_iPauseAfter))
		{
			m_iPrinted=0;
			m_bPauseForNow=TRUE;
			KillTimer(ID_PROGRESSTIMER);			
			m_btnPause.SetWindowText("«œ«„Â »œÂ");
			m_btnBack.EnableWindow();
		}
		
	}

	if(m_pRs->IsEof())
		return FALSE;

	return TRUE;

}

void CPrintProgressDlg::OnTimer(UINT nIDEvent) 
{
	if(nIDEvent==ID_PROGRESSTIMER)
		if(!PrintNext())
		{
			KillTimer(ID_PROGRESSTIMER);
			CPrintProgressDlg::OnOK();
		}
	
	CDialog::OnTimer(nIDEvent);
}

void CPrintProgressDlg::OnCancel() 
{
	KillTimer(ID_PROGRESSTIMER);	
	CDialog::OnCancel();
}

void CPrintProgressDlg::OnPause() 
{
	m_bPauseForNow=!m_bPauseForNow;
	if(m_bPauseForNow)
	{
		KillTimer(ID_PROGRESSTIMER);			
		m_btnPause.SetWindowText("«œ«„Â »œÂ");
		m_btnBack.EnableWindow();
	}
	else
	{
	int iTimerInterval=1000;
	switch(theApp.GetProfileInt("Settings", "Speed", 2))
	{
	case 2:
		iTimerInterval=787;
		break;
	case 3:
		iTimerInterval=525;
		break;
	case 4:
		iTimerInterval=393;
		break;
	case 5:
		iTimerInterval=314;
		break;
	case 6:
		iTimerInterval=262;
		break;
	case 7:
		iTimerInterval=224;
		break;
	case 8:
		iTimerInterval=196;
		break;
	case 9:
		iTimerInterval=181;
		break;
	case 10:
		iTimerInterval=163;
		break;
	}
	if(m_iLabelType==2)
		iTimerInterval=iTimerInterval*2;
	SetTimer(ID_PROGRESSTIMER, iTimerInterval, NULL);

		m_btnPause.SetWindowText("„Êﬁ « »«Ì” ");
		m_btnBack.EnableWindow(FALSE);
	}

}

void CPrintProgressDlg::OnReleasedcaptureSpeedslider(NMHDR* pNMHDR, LRESULT* pResult) 
{

	if(!m_bPauseForNow)
	KillTimer(ID_PROGRESSTIMER);			

	UpdateData();

	theApp.WriteProfileInt("Settings", "Speed", m_iSpeed+2);

	if(!m_bPauseForNow)
	{
	int iTimerInterval=1000;
	switch(theApp.GetProfileInt("Settings", "Speed", 2))
	{
	case 2:
		iTimerInterval=787;
		break;
	case 3:
		iTimerInterval=525;
		break;
	case 4:
		iTimerInterval=393;
		break;
	case 5:
		iTimerInterval=314;
		break;
	case 6:
		iTimerInterval=262;
		break;
	case 7:
		iTimerInterval=224;
		break;
	case 8:
		iTimerInterval=196;
		break;
	case 9:
		iTimerInterval=181;
		break;
	case 10:
		iTimerInterval=163;
		break;
	}
	if(m_iLabelType==2)
		iTimerInterval=iTimerInterval*2;
	SetTimer(ID_PROGRESSTIMER, iTimerInterval, NULL);
	}
	
		
	*pResult = 0;
}

void CPrintProgressDlg::OnBack() 
{
	if(m_lCurrent>m_lStart)
	{
		m_lCurrent--;
		m_pRs->MovePrevious();
		m_ctlProgressBar.SetPos(m_lCurrent-m_lStart+1);
		m_sNowPrinting.Format("ç«Å »—ç”» %d «“ %d", m_lCurrent-m_lStart+1, m_lEnd-m_lStart+1);
		UpdateData(FALSE);
	}
}
