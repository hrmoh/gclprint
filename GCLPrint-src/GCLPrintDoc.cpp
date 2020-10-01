// GCLPrintDoc.cpp : implementation of the CGCLPrintDoc class
//

#include "stdafx.h"
#include "GCLPrint.h"

#include "GCLPrintDoc.h"
#include "GCLPrintView.h"

#include "ZplParser.h"

#include "CustomersDlg.h"
#include "PrintConfDlg.h"
#include "PrintConfNoZPLDlg.h"
#include "MsgDlg.h"

#include "MaryamString.h"

#include "TitlesDlg.h"
#include "PrintProgressDlg.h"

#include "ManualReadDlg.h"
#include "GenIDsDlg.h"

#include "LabelPrinterType.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

extern CGCLPrintApp theApp;

/////////////////////////////////////////////////////////////////////////////
// CGCLPrintDoc

IMPLEMENT_DYNCREATE(CGCLPrintDoc, CDocument)

BEGIN_MESSAGE_MAP(CGCLPrintDoc, CDocument)
	//{{AFX_MSG_MAP(CGCLPrintDoc)
	ON_COMMAND(ID_SENDTOZ4M, OnSendToZ4M)
	ON_COMMAND(ID_PRINTTT, OnPrinttt)
	ON_COMMAND(ID_SETTINGS_PATHS, OnSettingsPaths)
	ON_COMMAND(ID_FILE_SORTONID, OnFileSortonid)
	ON_COMMAND(ID_FILE_TITLES, OnFileTitles)
	ON_COMMAND(ID_FILE_SORTONAD, OnFileSortonad)
	ON_COMMAND(ID_FILE_PRINTLIST, OnFilePrintlist)
	ON_COMMAND(ID_FILE_DELCONTENTS, OnFileDelcontents)
	ON_COMMAND(ID_FILE_INSERTDLG, OnFileInsertdlg)
	ON_COMMAND(ID_FILE_LOADLABELFILE, OnFileLoadlabelfile)
	ON_COMMAND(ID_FILE_GENIDS, OnFileGenids)
	ON_COMMAND(ID_SETTINGS_PRINTERTYPE, OnSettingsPrintertype)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CGCLPrintDoc construction/destruction

CGCLPrintDoc::CGCLPrintDoc()
{
	m_bStartChecked=FALSE;
	m_lStart=-1;
	m_lEnd=-1;
	m_iPauseAfter=30;
	m_bPauseAfter=FALSE;
	m_iPrinterPort=0;
	m_bZplPrinting=(theApp.GetProfileInt("Settings", "Label Printer Type", 1)==0);
}

CGCLPrintDoc::~CGCLPrintDoc()
{
}

BOOL CGCLPrintDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;
	if(ConnectToDB(FALSE)==FALSE) return FALSE;
	SetViewRS(m_pRs.GetRecordset());
	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CGCLPrintDoc serialization

void CGCLPrintDoc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
	}
	else
	{
	}
}

/////////////////////////////////////////////////////////////////////////////
// CGCLPrintDoc diagnostics

#ifdef _DEBUG
void CGCLPrintDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CGCLPrintDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CGCLPrintDoc commands

BOOL CGCLPrintDoc::OnOpenDocument(LPCTSTR lpszPathName) 
{
	if (!CDocument::OnOpenDocument(lpszPathName))
		return FALSE;
	CFile fWhiteList;
	if(ConnectToDB())
	{
		if(fWhiteList.Open(lpszPathName, CFile::modeRead))
		{
			long nFileSize=fWhiteList.GetLength();
			POSITION pos=GetFirstViewPosition();
			long iLastStep=0;
			CGCLPrintView* pView=(CGCLPrintView*)GetNextView(pos);
			long nProcess=0;
			pView->BeginProgress();
			long lOrder=0;

			while(FetchRecordAndInsertToDB(lOrder, &fWhiteList))
			{
				if(long(nProcess*17000/nFileSize)>iLastStep)
				{
					iLastStep++;
					pView->SetProgress(nProcess*170, nFileSize);
				}
				nProcess++;
			}
			m_pRs.Update();
			pView->HideProgressBar();
			pView->LoadDB(m_pRs.GetRecordset());
			fWhiteList.Close();
		}
	}
	
	return FALSE;
}


BOOL CGCLPrintDoc::FetchRecordAndInsertToDB(long& lOrder, CFile *pWhiteListFile)
{
	
			BYTE inBuffer[255];
			UINT uReadBytes=pWhiteListFile->Read(inBuffer, 170);
			if(uReadBytes!=170)
				return FALSE;

			BOOL bReadCorrectly=FALSE;
			bReadCorrectly|= m_rsRecSet.ReadFrequency(inBuffer);
			bReadCorrectly|= m_rsRecSet.ReadSubscriptionCode(inBuffer);
			bReadCorrectly|= m_rsRecSet.ReadConsumptionKind(inBuffer);
			bReadCorrectly|= m_rsRecSet.ReadFLName(inBuffer);
			bReadCorrectly|= m_rsRecSet.ReadAddress(inBuffer);
			bReadCorrectly|= m_rsRecSet.ReadAddressCode(inBuffer);
			bReadCorrectly|= m_rsRecSet.ReadCounterSerial(inBuffer);
			bReadCorrectly|= m_rsRecSet.ReadCapacity(inBuffer);

			m_pRs.AddNew();
			

			lOrder++;
			m_pRs.SetFieldValue(0, lOrder);
			m_pRs.SetFieldValue(1, (CString)m_rsRecSet.m_szSubscriptionCode);
			m_pRs.SetFieldValue(2, (CString)m_rsRecSet.m_szAddressCode);
			m_pRs.SetFieldValue(3, (CString)m_rsRecSet.m_szFrequency);
			m_pRs.SetFieldValue(4, (CString)m_rsRecSet.m_szConsumptionKind);
			m_pRs.SetFieldValue(5, (CString)m_rsRecSet.m_szCapacity);
			m_pRs.SetFieldValue(6, (CString)m_rsRecSet.m_szCounterSerial);
			m_pRs.SetFieldValue(7, (CString)m_rsRecSet.m_szFLName);
			m_pRs.SetFieldValue(8, (CString)m_rsRecSet.m_szAddress);
			int iTypeToPrint=3;
			m_pRs.SetFieldValue(9, (int)iTypeToPrint);


			return TRUE;

}

void CGCLPrintDoc::OnSendToZ4M() 
{

	if( (m_lStart==-1) || (m_lEnd==-1) )
	{
		CMsgDlg MsgDlg;
		MsgDlg.m_sMessage="·ÿ›« «Ê· ¬€«“ Ê Å«Ì«‰ ›Â—”  ç«Å —« «‰ Œ«» ò‰Ìœ";
		MsgDlg.DoModal();
		return;
	}
	if(m_lStart>m_lEnd)
	{
		long lTemp=m_lEnd;
		m_lEnd=m_lStart;
		m_lStart=lTemp;
	}

	m_pRs.MoveFirst();
	m_pRs.Move(m_lStart);

	if(m_bZplPrinting)
	{
	CPrintConfDlg PrintConfDlg;

	m_pRs.GetFieldValue(1, PrintConfDlg.m_sFromID);
	m_pRs.GetFieldValue(2, PrintConfDlg.m_sFromAC);

	m_pRs.MoveFirst();
	m_pRs.Move(m_lEnd);

	m_pRs.GetFieldValue(1, PrintConfDlg.m_sToID);
	m_pRs.GetFieldValue(2, PrintConfDlg.m_sToAC);


	PrintConfDlg.m_bPause=m_bPauseAfter;
	PrintConfDlg.m_iPauseAgter=m_iPauseAfter;
	PrintConfDlg.m_iWhichPort=m_iPrinterPort;

	UINT uRes=PrintConfDlg.DoModal();

	m_iPrinterPort=PrintConfDlg.m_iWhichPort;
	m_iPauseAfter=PrintConfDlg.m_iPauseAgter;
	m_bPauseAfter=PrintConfDlg.m_bPause;

	
	if(uRes==IDOK)
	{
			HANDLE hComm;
			OpenComPort(hComm);
			PrintLabel(hComm, PrintConfDlg.m_iLabelType);
			CloseComPort(hComm);
	}
	}
	else
	{
		//General Printing:
		CPrintConfNoZPLDlg PrintConfDlg;


		m_pRs.GetFieldValue(1, PrintConfDlg.m_sFromID);
		m_pRs.GetFieldValue(2, PrintConfDlg.m_sFromAC);

		m_pRs.MoveFirst();
		m_pRs.Move(m_lEnd);

		m_pRs.GetFieldValue(1, PrintConfDlg.m_sToID);
		m_pRs.GetFieldValue(2, PrintConfDlg.m_sToAC);


		PrintConfDlg.m_bPause=m_bPauseAfter;
		PrintConfDlg.m_iPauseAgter=m_iPauseAfter;

		PrintConfDlg.m_lStart=m_lStart;
		PrintConfDlg.m_lEnd=m_lEnd;

		PrintConfDlg.SetRecordset(&m_pRs);

		PrintConfDlg.DoModal();

	}


}

void CGCLPrintDoc::SetViewRS(_RecordsetPtr pRs)
{
	POSITION pos=GetFirstViewPosition();
	CGCLPrintView* pView=(CGCLPrintView*)GetNextView(pos);
	pView->SetRs(pRs);
	
}

void CGCLPrintDoc::OpenComPort(HANDLE &hComm)
{
	CString sCom="COM2";
	switch(m_iPrinterPort)
	{
	case 0:
		sCom="COM1";
		break;
	case 1:
		sCom="COM2";
		break;
	case 2:
		sCom="LPT1";
		break;
	}
	hComm = CreateFile(
  sCom,                       /* ??????????? */
  GENERIC_READ | GENERIC_WRITE, /* ??????? */
  0,                            /* ????? */
  NULL,                         /* ???????? */
  OPEN_EXISTING,                /* ????? */
  FILE_ATTRIBUTE_NORMAL,        /* ?? */
  NULL                          /* ??????????? */
  );


	if(hComm == INVALID_HANDLE_VALUE)
	{
	/* ????? */
	}

	DCB dcb;
	GetCommState(hComm, &dcb); /* DCB ??? */
	dcb.BaudRate = 9600;
	dcb.ByteSize = 8;
	dcb.Parity = NOPARITY;
	dcb.fParity = TRUE;
	dcb.StopBits = ONESTOPBIT;
	SetCommState(hComm, &dcb); /* DCB ??? */
}

void CGCLPrintDoc::PrintLabel(HANDLE hComm, int iLabelType)
{

	CPrintProgressDlg pdlg;
	pdlg.m_bPauseAfter=m_bPauseAfter;
	pdlg.m_iPauseAfter=m_iPauseAfter;  
	pdlg.m_hComm=hComm;
	pdlg.m_iLabelType=iLabelType;
	pdlg.m_lStart=m_lStart;
	pdlg.m_lEnd=m_lEnd;
	pdlg.SetRecordset(&m_pRs);
	pdlg.DoModal();
	
	/*

	CZplParser zplParser;
	zplParser.Open("design\\mahallat.zpl", TRUE);



	
	CMaryamString sCompanyName(theApp.GetProfileString("Settings", "Company Name", ""));
	zplParser.SetVar(0, sCompanyName.GetString());
	zplParser.SetNobarcodeVar(0, sCompanyName.GetString());

	CMaryamString sRegionName(theApp.GetProfileString("Settings", "Region Name", ""));

	zplParser.SetVar(1, sRegionName.GetString());
	zplParser.SetNobarcodeVar(1, sRegionName.GetString());

	

	if( (iLabelType==1) || (iLabelType==2))
		zplParser.LoadArmToPrinter(hComm);

	CString sDarkness;
	sDarkness.Format("~SD%.2d", theApp.GetProfileInt("Settings", "Darkness", 30));
	DWORD dwWritten;
	WriteFile(hComm,  sDarkness, 5, &dwWritten, NULL);	

	m_pRs.MoveFirst();
	m_pRs.Move(m_lStart);
	int iPrinted=0;


	CMsgDlg msgDlg;
	msgDlg.m_sMessage="»—«Ì «œ«„Â ç«Å œò„Â  √ÌÌœ —« »“‰Ìœ.";
	BOOL bAbort=FALSE;

	//CPrintProgressDlg pdlg;

	for(long l=m_lStart; (l<=m_lEnd)&&(!bAbort); l++)
	{
	CString szSubscriptionCode;
	m_pRs.GetFieldValue(1, szSubscriptionCode);

	CString szAddressCode;
	m_pRs.GetFieldValue(2, szAddressCode);
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

	zplParser.Print(hComm, iLabelType);
	m_pRs.MoveNext();
	iPrinted++;
	if(m_bPauseAfter)
	{
		if(iPrinted==(m_iPauseAfter))
		{
			if(l!=m_lEnd)
				if(msgDlg.DoModal()==IDCANCEL)
					bAbort=TRUE;
			iPrinted=0;
		}
		
	}
	}
*/
}

void CGCLPrintDoc::CloseComPort(HANDLE &hComm)
{
	CloseHandle(hComm);
}


void CGCLPrintDoc::GoTo(long lWhere)
{
	m_pRs.MoveFirst();
	m_pRs.Move(lWhere-1);
}

long CGCLPrintDoc::FindID(CString sID, int iOrder)
{
	long lRet=-1;
	CADORecordset pT = CADORecordset(&m_pDb);		
	CString strQuery="SELECT Customers.AOrder FROM Customers WHERE Customers.SubscriptionCode LIKE '%"+sID+"%' ORDER BY Customers.AOrder";
	pT.Open(strQuery, CADORecordset::openQuery);
	int i=0;
	while( (!pT.IsEof()) && (i<iOrder))
	{
		pT.MoveNext();
		i++;
	}
	if(!pT.IsEof())
		pT.GetFieldValue(0, lRet);
	pT.Close();
	return lRet;
}

long CGCLPrintDoc::FindAD(CString sID, int iOrder)
{
	long lRet=-1;
	CADORecordset pT = CADORecordset(&m_pDb);		
	CString strQuery="SELECT Customers.AOrder FROM Customers WHERE Customers.AddressCode LIKE '%"+sID+"%' ORDER BY Customers.AOrder";
	pT.Open(strQuery, CADORecordset::openQuery);
	int i=0;
	while( (!pT.IsEof()) && (i<iOrder))
	{
		pT.MoveNext();
		i++;
	}
	if(!pT.IsEof())
		pT.GetFieldValue(0, lRet);
	pT.Close();
	return lRet;
}

void CGCLPrintDoc::ShowCurrent()
{
	CString sID;
	CString sFLName;
	CString sAddress;
	CString sAddressCode;
	CString sDate;
	CString sDomainCode;
	CString sFrequency;
	CString sPCon;
	CString sPDate;
	CString sQType;
	CString sCounterSerial;
	CString sCapacity;

	m_pRs.GetFieldValue(1, sDomainCode);
	m_pRs.GetFieldValue(2, sFrequency);
	m_pRs.GetFieldValue(1, sID);
	m_pRs.GetFieldValue(4, sQType);
	m_pRs.GetFieldValue(5, sPDate);
	m_pRs.GetFieldValue(6, sPCon);
	m_pRs.GetFieldValue(7, sFLName);
	m_pRs.GetFieldValue(8, sAddress);
	m_pRs.GetFieldValue(9, sAddressCode);
	m_pRs.GetFieldValue(10, sCounterSerial);
	m_pRs.GetFieldValue(11, sCapacity);
	m_pRs.GetFieldValue(12, sDate);


	CCustomersDlg CustomersDlg;
	CustomersDlg.SetRecordInfo(sID, sFLName, sAddress, sAddressCode, sDomainCode, sPDate, sPCon, sFrequency, sQType, sDate, sCapacity, sCounterSerial);
	CustomersDlg.DoModal();
}


void CGCLPrintDoc::CheckCurrentAsStart(BOOL bStartChecked)
{
	long lRow;
	m_pRs.GetFieldValue(0, lRow);
	lRow--;
	if(bStartChecked)
	{
		if(m_lStart==lRow)
		{
			m_lStart=-1;
		}
		else
			m_lStart=lRow;
	}
	else
			m_lStart=-1;
}

void CGCLPrintDoc::CheckCurrentAsEnd(BOOL bEndChecked)
{
	long lRow;
	m_pRs.GetFieldValue(0, lRow);
	lRow--;
	if(bEndChecked)
	{
		if(m_lEnd==lRow)
		{
			m_lEnd=-1;
		}
		else
			m_lEnd=lRow;
	}
	else
			m_lEnd=-1;
}


void CGCLPrintDoc::OnPrinttt() 
{
	long l1=m_lStart;
	long l2=m_lEnd;
	m_pRs.GetFieldValue(0, m_lStart);
	m_lEnd=m_lStart;
	HANDLE hComm;
	OpenComPort(hComm);
	PrintLabel(hComm, 0);
	CloseComPort(hComm);	
	m_lStart=l1;
	m_lEnd=l2;
}

#include "PathsDlg.h"
void CGCLPrintDoc::OnSettingsPaths() 
{
	// TODO: Add your command handler code here
	CPathsDlg	dlgPaths;
	dlgPaths.DoModal();
}


#include "GCLPrint.h"

extern CGCLPrintApp theApp;

BOOL CGCLPrintDoc::ConnectToDB(BOOL bEmpty)
{

	CString strMDB=theApp.GetProfileString("Settings", "MDBPath");

	if(strMDB.GetLength()==0)
			return FALSE;

	CString strConnection = _T("Provider=Microsoft.Jet.OLEDB.4.0;Data Source=");
	strConnection+=strMDB;
	strConnection+=";Persist Security Info=False";


	if(m_pRs.IsOpen())
		m_pRs.Close();
	if(m_pDb.IsOpen())
		m_pDb.Close();
	if(m_pDb.Open(strConnection))
	{
		if(bEmpty)
			m_pDb.Execute("DELETE FROM Customers");
		m_pRs = CADORecordset(&m_pDb);		
		m_pRs.Open("SELECT Customers.AOrder AS [—œÌ›], Customers.SubscriptionCode AS [‘„«—Â «‘ —«ò], Customers.AddressCode AS [òœ ¬œ—”], Customers.Frequency AS [›—ò«‰”], Customers.ConsumptionKind AS [‰Ê⁄ „’—›], Customers.Capacity AS [Ÿ—›Ì  ò‰ Ê—], Customers.CounterSerial AS [”—Ì«· ò‰ Ê—], Customers.FLName AS [‰«„ „‘ —ò], Customers.Address AS [‰‘«‰Ì], Customers.TypeToPrint AS [‰Ê⁄ œ—ŒÊ«” ] FROM Customers ORDER BY AOrder;", CADORecordset::openQuery);
	}
	else
	{
		AfxMessageBox(m_pDb.GetLastErrorString());
		DWORD dwError = m_pDb.GetLastError();
		return FALSE;
	}
	return TRUE;	
}




void CGCLPrintDoc::OnFileSortonid() 
{
	BeginWaitCursor();

	m_pDb.Execute("SELECT Customers.SubscriptionCode, Customers.ConsumptionKind, Customers.FLName, Customers.Address, Customers.AddressCode, Customers.CounterSerial, Customers.Capacity, Customers.Frequency, Customers.TypeToPrint INTO TempWhiteList FROM Customers ORDER BY Customers.SubscriptionCode;");
	m_pDb.Execute("DELETE FROM Customers;");

	CADORecordset pTempRs;
	pTempRs = CADORecordset(&m_pDb);

	pTempRs.Open("SELECT TempWhiteList.SubscriptionCode, TempWhiteList.AddressCode, TempWhiteList.Frequency, TempWhiteList.ConsumptionKind, TempWhiteList.Capacity, TempWhiteList.CounterSerial, TempWhiteList.FLName, TempWhiteList.Address, TempWhiteList.TypeToPrint FROM TempWhiteList ORDER BY TempWhiteList.SubscriptionCode;", CADORecordset::openQuery);


	pTempRs.MoveFirst();
	long lOrder=0;
	while(!pTempRs.IsEof())
	{

		CString szSubscriptionCode, szAddressCode, szFrequency, szConsumptionKind, szCapacity, szCounterSerial, szFLName, szAddress;
		int iTypeToPrint;

		pTempRs.GetFieldValue(0, szSubscriptionCode);
		pTempRs.GetFieldValue(1, szAddressCode);
		pTempRs.GetFieldValue(2, szFrequency);
		pTempRs.GetFieldValue(3, szConsumptionKind);
		pTempRs.GetFieldValue(4, szCapacity);
		pTempRs.GetFieldValue(5, szCounterSerial);
		pTempRs.GetFieldValue(6, szFLName);
		pTempRs.GetFieldValue(7, szAddress);
		pTempRs.GetFieldValue(8, iTypeToPrint);

		lOrder++;

		m_pRs.AddNew();

		m_pRs.SetFieldValue(0, lOrder);
		m_pRs.SetFieldValue(1, (CString)szSubscriptionCode);
		m_pRs.SetFieldValue(2, (CString)szAddressCode);
		m_pRs.SetFieldValue(3, (CString)szFrequency);
		m_pRs.SetFieldValue(4, (CString)szConsumptionKind);
		m_pRs.SetFieldValue(5, (CString)szCapacity);
		m_pRs.SetFieldValue(6, (CString)szCounterSerial);
		m_pRs.SetFieldValue(7, (CString)szFLName);
		m_pRs.SetFieldValue(8, (CString)szAddress);
		m_pRs.SetFieldValue(9, (int)iTypeToPrint);

		pTempRs.MoveNext();


	}
	m_pRs.Update();

	m_pDb.Execute("DROP TABLE TempWhiteList;");

	if(m_pRs.IsOpen())
		m_pRs.Close();
	m_pRs.Open("SELECT Customers.AOrder AS [—œÌ›], Customers.SubscriptionCode AS [‘„«—Â «‘ —«ò], Customers.AddressCode AS [òœ ¬œ—”], Customers.Frequency AS [›—ò«‰”], Customers.ConsumptionKind AS [‰Ê⁄ „’—›], Customers.Capacity AS [Ÿ—›Ì  ò‰ Ê—], Customers.CounterSerial AS [”—Ì«· ò‰ Ê—], Customers.FLName AS [‰«„ „‘ —ò], Customers.Address AS [‰‘«‰Ì],Customers.TypeToPrint AS [‰Ê⁄ œ—ŒÊ«” ] FROM Customers ORDER BY AOrder;", CADORecordset::openQuery);

	POSITION pos=GetFirstViewPosition();
	CGCLPrintView* pView=(CGCLPrintView*)GetNextView(pos);
	pView->LoadDB(m_pRs.GetRecordset());

/*
	m_pDb.Execute("SELECT Customers.SubscriptionCode, Customers.ConsumptionKind, Customers.FLName, Customers.Address, Customers.AddressCode, Customers.CounterSerial, Customers.Capacity, Customers.Frequency, (SELECT COUNT(*) FROM Customers c2 WHERE c2.SubscriptionCode<=Customers.SubscriptionCode) AS AOrder INTO TempWhiteList FROM Customers ORDER BY Customers.SubscriptionCode;");
	m_pDb.Execute("DROP TABLE Customers;");
	m_pDb.Execute("SELECT TempWhiteList.SubscriptionCode, TempWhiteList.ConsumptionKind, TempWhiteList.FLName, TempWhiteList.Address, TempWhiteList.AddressCode, TempWhiteList.CounterSerial, TempWhiteList.Capacity, TempWhiteList.Frequency, TempWhiteList.AOrder INTO Customers FROM TempWhiteList ORDER BY TempWhiteList.SubscriptionCode;");
	m_pDb.Execute("DROP TABLE TempWhiteList;");
	if(m_pRs.IsOpen())
		m_pRs.Close();
	m_pRs.Open("SELECT Customers.AOrder AS [—œÌ›], Customers.SubscriptionCode AS [‘„«—Â «‘ —«ò], Customers.AddressCode AS [òœ ¬œ—”], Customers.Frequency AS [›—ò«‰”], Customers.ConsumptionKind AS [‰Ê⁄ „’—›], Customers.Capacity AS [Ÿ—›Ì  ò‰ Ê—], Customers.CounterSerial AS [‘„«—Â ”—Ì«· ò‰ Ê—], Customers.FLName AS [‰«„ „‘ —ò], Customers.Address AS [‰‘«‰Ì] FROM Customers ORDER BY AOrder;", CADORecordset::openQuery);
	POSITION pos=GetFirstViewPosition();
	CGCLPrintView* pView=(CGCLPrintView*)GetNextView(pos);
	pView->LoadDB(m_pRs.GetRecordset());
*/
	EndWaitCursor();
}

void CGCLPrintDoc::OnFileTitles() 
{
	CTitlesDlg	dlg;
	dlg.DoModal();
}

void CGCLPrintDoc::CheckForPrint()
{
	long lRow;
	m_pRs.GetFieldValue(0, lRow);
	lRow--;
	m_lStart=lRow;
	m_lEnd=lRow;
	OnSendToZ4M();
}

void CGCLPrintDoc::OnFileSortonad() 
{
	BeginWaitCursor();

	m_pDb.Execute("SELECT Customers.SubscriptionCode, Customers.ConsumptionKind, Customers.FLName, Customers.Address, Customers.AddressCode, Customers.CounterSerial, Customers.Capacity, Customers.Frequency, Customers.TypeToPrint INTO TempWhiteList FROM Customers ORDER BY Customers.AddressCode;");
	m_pDb.Execute("DELETE FROM Customers;");

	CADORecordset pTempRs;
	pTempRs = CADORecordset(&m_pDb);

	pTempRs.Open("SELECT TempWhiteList.SubscriptionCode, TempWhiteList.AddressCode, TempWhiteList.Frequency, TempWhiteList.ConsumptionKind, TempWhiteList.Capacity, TempWhiteList.CounterSerial, TempWhiteList.FLName, TempWhiteList.Address, TempWhiteList.TypeToPrint FROM TempWhiteList ORDER BY TempWhiteList.AddressCode;", CADORecordset::openQuery);


	pTempRs.MoveFirst();
	long lOrder=0;
	while(!pTempRs.IsEof())
	{

		CString szSubscriptionCode, szAddressCode, szFrequency, szConsumptionKind, szCapacity, szCounterSerial, szFLName, szAddress;
		int iTypeToPrint;

		pTempRs.GetFieldValue(0, szSubscriptionCode);
		pTempRs.GetFieldValue(1, szAddressCode);
		pTempRs.GetFieldValue(2, szFrequency);
		pTempRs.GetFieldValue(3, szConsumptionKind);
		pTempRs.GetFieldValue(4, szCapacity);
		pTempRs.GetFieldValue(5, szCounterSerial);
		pTempRs.GetFieldValue(6, szFLName);
		pTempRs.GetFieldValue(7, szAddress);
		pTempRs.GetFieldValue(8, iTypeToPrint);

		lOrder++;

		m_pRs.AddNew();

		m_pRs.SetFieldValue(0, lOrder);
		m_pRs.SetFieldValue(1, (CString)szSubscriptionCode);
		m_pRs.SetFieldValue(2, (CString)szAddressCode);
		m_pRs.SetFieldValue(3, (CString)szFrequency);
		m_pRs.SetFieldValue(4, (CString)szConsumptionKind);
		m_pRs.SetFieldValue(5, (CString)szCapacity);
		m_pRs.SetFieldValue(6, (CString)szCounterSerial);
		m_pRs.SetFieldValue(7, (CString)szFLName);
		m_pRs.SetFieldValue(8, (CString)szAddress);
		m_pRs.SetFieldValue(9, (int)iTypeToPrint);

		pTempRs.MoveNext();


	}
	m_pRs.Update();

	m_pDb.Execute("DROP TABLE TempWhiteList;");

	if(m_pRs.IsOpen())
		m_pRs.Close();
	m_pRs.Open("SELECT Customers.AOrder AS [—œÌ›], Customers.SubscriptionCode AS [‘„«—Â «‘ —«ò], Customers.AddressCode AS [òœ ¬œ—”], Customers.Frequency AS [›—ò«‰”], Customers.ConsumptionKind AS [‰Ê⁄ „’—›], Customers.Capacity AS [Ÿ—›Ì  ò‰ Ê—], Customers.CounterSerial AS [”—Ì«· ò‰ Ê—], Customers.FLName AS [‰«„ „‘ —ò], Customers.Address AS [‰‘«‰Ì], Customers.TypeToPrint AS [‰Ê⁄ œ—ŒÊ«” ] FROM Customers ORDER BY AOrder;", CADORecordset::openQuery);

	POSITION pos=GetFirstViewPosition();
	CGCLPrintView* pView=(CGCLPrintView*)GetNextView(pos);
	pView->LoadDB(m_pRs.GetRecordset());

	EndWaitCursor();
	
}

void CGCLPrintDoc::OnFilePrintlist() 
{
	m_dlgRprtprn.m_bIsWorking=TRUE;
	m_dlgRprtprn.SetRecordset(&m_pRs);

	CString sTitle="›Â—”  „‘ —òÌ‰ "+theApp.GetProfileString("Settings", "Region Name", "");
	m_dlgRprtprn.SetTitle(sTitle);

	m_dlgRprtprn.ResetFieldWidths();
	



	m_dlgRprtprn.SetNextFieldWidth(700);
	m_dlgRprtprn.SetNextFieldWidth(1800);	
	m_dlgRprtprn.SetNextFieldWidth(1200);
	m_dlgRprtprn.SetNextFieldWidth(0);
	m_dlgRprtprn.SetNextFieldWidth(0);
	m_dlgRprtprn.SetNextFieldWidth(0);
	m_dlgRprtprn.SetNextFieldWidth(1200);
	m_dlgRprtprn.SetNextFieldWidth(3000);
	m_dlgRprtprn.SetNextFieldWidth(5000);

	m_dlgRprtprn.DoModal();
	m_dlgRprtprn.m_bIsWorking=FALSE;
	
}

void CGCLPrintDoc::HandlePrint()
{
	if(m_dlgRprtprn.m_bIsWorking)
		m_dlgRprtprn.HandlePrint();
}

void CGCLPrintDoc::OnFileDelcontents() 
{
	BeginWaitCursor();
	m_pDb.Execute("DELETE FROM Customers;");

	if(m_pRs.IsOpen())
		m_pRs.Close();
	m_pRs.Open("SELECT Customers.AOrder AS [—œÌ›], Customers.SubscriptionCode AS [‘„«—Â «‘ —«ò], Customers.AddressCode AS [òœ ¬œ—”], Customers.Frequency AS [›—ò«‰”], Customers.ConsumptionKind AS [‰Ê⁄ „’—›], Customers.Capacity AS [Ÿ—›Ì  ò‰ Ê—], Customers.CounterSerial AS [”—Ì«· ò‰ Ê—], Customers.FLName AS [‰«„ „‘ —ò], Customers.Address AS [‰‘«‰Ì], Customers.TypeToPrint AS [‰Ê⁄ œ—ŒÊ«” ] FROM Customers ORDER BY AOrder;", CADORecordset::openQuery);
	POSITION pos=GetFirstViewPosition();
	CGCLPrintView* pView=(CGCLPrintView*)GetNextView(pos);
	pView->LoadDB(m_pRs.GetRecordset());
	EndWaitCursor();
}

void CGCLPrintDoc::OnFileInsertdlg() 
{
	CManualReadDlg	dlg;
	if(dlg.DoModal()==IDOK)
	{
		m_pRs.AddNew();

		m_pRs.SetFieldValue(0, m_pRs.GetRecordCount());
		m_pRs.SetFieldValue(1, (CString)dlg.m_sID);
		m_pRs.SetFieldValue(2, (CString)dlg.m_sAD);
		m_pRs.SetFieldValue(6, (CString)dlg.m_sSerial);
		m_pRs.SetFieldValue(7, (CString)dlg.m_sName);
		m_pRs.SetFieldValue(8, (CString)dlg.m_sAddress);
		m_pRs.Update();

		POSITION pos=GetFirstViewPosition();
		CGCLPrintView* pView=(CGCLPrintView*)GetNextView(pos);
		pView->LoadDB(m_pRs.GetRecordset());

	}	
}

void CGCLPrintDoc::OnFileLoadlabelfile() 
{
	CFileDialog fileDlg( TRUE, "zip", NULL, OFN_HIDEREADONLY|OFN_OVERWRITEPROMPT, "›«Ì· ”›«—‘ »—ç”» (*.dat)|*.dat||");
	fileDlg.m_ofn.lpstrTitle = "„Õ· Ê ‰«„ ›«Ì· ”›«—‘ »—ç”» —« „‘Œ’ ò‰Ìœ";

    if ( fileDlg.DoModal() == IDOK )
	{
		if(ConnectToDB())
		{
			CFile fLabelFile(fileDlg.GetPathName(), CFile::modeRead);

			long nFileSize=fLabelFile.GetLength();
			POSITION pos=GetFirstViewPosition();
			long iLastStep=0;
			CGCLPrintView* pView=(CGCLPrintView*)GetNextView(pos);
			long nProcess=0;
			pView->BeginProgress();
			long lOrder=0;

			while(FetchRecordFromLabelFileAndInsertToDB(lOrder, &fLabelFile))
			{
				if(long(nProcess*17000/nFileSize)>iLastStep)
				{
					iLastStep++;
					pView->SetProgress(nProcess*170, nFileSize);
				}
				nProcess++;
			}
			m_pRs.Update();
			pView->HideProgressBar();
			pView->LoadDB(m_pRs.GetRecordset());
			fLabelFile.Close();

		}		
	}
	
}

BOOL CGCLPrintDoc::FetchRecordFromLabelFileAndInsertToDB(long& lOrder, CFile *pWhiteListFile)
{
	
			
			CString szSubscriptionCode, szAddressCode, szFrequency, szErrorCode;

			char cSubscriptionCode[16];
			char cAddressCode[11];
			char cFrequency[2];
			char cErrorCode[2];

			UINT uReadBytes=pWhiteListFile->Read(cSubscriptionCode, 15);
			if(uReadBytes!=15)
				return FALSE;
			pWhiteListFile->Read(cAddressCode, 10);
			pWhiteListFile->Read(cFrequency, 1);
			pWhiteListFile->Read(cErrorCode, 1);

			cSubscriptionCode[15]='\0';
			cAddressCode[10]='\0';
			cFrequency[1]='\0';
			cErrorCode[1]='\0';

			szSubscriptionCode=cSubscriptionCode;
			szAddressCode=cAddressCode;
			szFrequency=cFrequency;
			szErrorCode=cErrorCode;

			if( (atoi(szErrorCode)==0))
			{
				CADORecordset pT = CADORecordset(&m_pDb);		
				CString strQuery="SELECT Customers.TypeToPrint FROM Customers WHERE (Customers.SubscriptionCode LIKE '%"+szSubscriptionCode+"%') AND (Customers.TypeToPrint=1) ORDER BY Customers.AOrder";
				pT.Open(strQuery, CADORecordset::openQuery);
				if(pT.IsEOF())
				{
					m_pRs.AddNew();
			

					lOrder++;
					m_pRs.SetFieldValue(0, lOrder);
					m_pRs.SetFieldValue(1, (CString)szSubscriptionCode);
					m_pRs.SetFieldValue(2, (CString)szAddressCode);
					m_pRs.SetFieldValue(3, (CString)szFrequency);
					m_pRs.SetFieldValue(9, (CString)szErrorCode);

				}
				else
					m_pDb.Execute("UPDATE Customers SET TypeToPrint=2 WHERE (Customers.SubscriptionCode LIKE '%"+szSubscriptionCode+"%')");				
				pT.Close();

			}

			else

			{
				CADORecordset pT = CADORecordset(&m_pDb);		
				CString strQuery="SELECT Customers.TypeToPrint FROM Customers WHERE (Customers.SubscriptionCode LIKE '%"+szSubscriptionCode+"%') AND (Customers.TypeToPrint=0) ORDER BY Customers.AOrder";
				pT.Open(strQuery, CADORecordset::openQuery);
				if(pT.IsEOF())
				{
					m_pRs.AddNew();
			

					lOrder++;
					m_pRs.SetFieldValue(0, lOrder);
					m_pRs.SetFieldValue(1, (CString)szSubscriptionCode);
					m_pRs.SetFieldValue(2, (CString)szAddressCode);
					m_pRs.SetFieldValue(3, (CString)szFrequency);
					m_pRs.SetFieldValue(9, (CString)szErrorCode);

				}
				else
				{
					m_pDb.Execute("UPDATE Customers SET TypeToPrint=2 WHERE (Customers.SubscriptionCode LIKE '%"+szSubscriptionCode+"%')");
				}
				pT.Close();

			}


			m_pRs.Update();


			return TRUE;

}

void CGCLPrintDoc::OnFileGenids() 
{
	CGenIDsDlg dlg;
	if(dlg.DoModal()==IDOK)
	{
	BeginWaitCursor();
	if(ConnectToDB())		
		{
				long lOrder=0;
				CString sNow=dlg.m_sFrom;
				while(sNow<=dlg.m_sTo)
				{
					m_pRs.AddNew();
					lOrder++;
					m_pRs.SetFieldValue(0, lOrder);
					CString sID=AddControlCode(sNow);
					m_pRs.SetFieldValue(1, (CString)sID);
					CString szErrorCode="3";	
					m_pRs.SetFieldValue(9, (CString)szErrorCode);
					sNow.Format("%13.f", atof(sNow)+1);

				}
				m_pRs.Update();

				POSITION pos=GetFirstViewPosition();
				CGCLPrintView* pView=(CGCLPrintView*)GetNextView(pos);
				pView->LoadDB(m_pRs.GetRecordset());

		}
	EndWaitCursor();
	}
}

CString CGCLPrintDoc::AddControlCode(CString sID)
{
	int s1=0;
	int s2=0;
	CString sOld=sID;
	sID="";
	for(int i=1; i<13; i++)
	{
		sID=sID+CString(sOld[i]);
	}
	for(i=11; i>0; i--)
	{
		s1=s1+int(int(sID[i])-int('0'))*i;
		s2=s2+int(int(sID[12-i])-int('0'))*i;
	}
	s1=s1%11;
	s2=s2%11;
	if(s1==10)
		s1=0;
	if(s2==10)
		s2=0;
	char l1[2];
	char r1[2];

	l1[1]='\0';
	r1[1]='\0';

	l1[0]=s1+'0';
	r1[0]=s2+'0';
	sID=sOld+CString(l1)+CString(r1);
	return sID;
}

void CGCLPrintDoc::OnSettingsPrintertype() 
{
	CLabelPrinterType pdlg;
	pdlg.DoModal();
	m_bZplPrinting=(theApp.GetProfileInt("Settings", "Label Printer Type", 1)==0);
}
