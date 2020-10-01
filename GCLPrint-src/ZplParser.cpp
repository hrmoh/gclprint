// ZplParser.cpp: implementation of the CZplParser class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "GCLPrint.h"
#include "ZplParser.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

extern CGCLPrintApp theApp;

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CZplParser::CZplParser()
{

}

CZplParser::~CZplParser()
{

}

BOOL CZplParser::Open(LPCTSTR lpszPathName, BOOL bFile)
{
/*	CFile fZPL;
	fZPL.Open(lpszPathName, CFile::modeRead);
	CHAR *sFile;
	sFile = new CHAR[fZPL.GetLength()];
	fZPL.Read(sFile, fZPL.GetLength());
	fZPL.Close();
	Open(sFile);
	delete []sFile;*/
	Open(NULL);
	return TRUE;	
	
}	

void CZplParser::Open(CHAR *pBuffer)
{
/*	long i=0;
	while((pBuffer[i]!='\0')&&(i<strlen(pBuffer)))
	{
		TCHAR* pNewStr;
		pNewStr = new TCHAR[1000];
		int j=0;
		while( (pBuffer[i]!=13) && (pBuffer[i]!=10) && (i<strlen(pBuffer)) )
		{
			pNewStr[j]=_T(pBuffer[i]);
			i++;
			j++;
		}
		if(j>0)
		{
		pNewStr[j]=_T('\0');
		if(pNewStr[0]=='^')
			m_saCommands.Add(pNewStr);
		}
		if(pBuffer[i]==10)	i++;
		if(pBuffer[i]==13)	i++;
		if(pBuffer[i]=='\0')
			i++;
	}*/
	m_saCommands.Add("^XA");
	m_saCommands.Add("^FO60,50^BY3");
	m_saCommands.Add("^ADN,36,20");
	m_saCommands.Add("^A@N,25,25,E:F_TITR.FNT");
	m_saCommands.Add("^FD$Var$^FS");
	m_saCommands.Add("^FO180,90^BY3");
	m_saCommands.Add("^ADN,36,20");
	m_saCommands.Add("^A@N,30,30,E:F_TRAFIC.FNT");
	m_saCommands.Add("^FD$Var$^FS");
	m_saCommands.Add("^FO80,150^BY3");
	m_saCommands.Add("^BCN,70,N,N,N");
	m_saCommands.Add("^FD>;$Var$^FS");
	m_saCommands.Add("^ADN,36,20");
	m_saCommands.Add("^FO50,230^BY3");
	m_saCommands.Add("^A@N,35,45,E:F_TRAFIC.FNT");
	m_saCommands.Add("^FD$Var$^FS");
	m_saCommands.Add("^FO150,290^BY3");
	m_saCommands.Add("^ADN,36,20");
	m_saCommands.Add("^A@N,30,30,E:F_TRAFIC.FNT");
	m_saCommands.Add("^FD$Var$^FS");	
	m_saCommands.Add("^XZ");




	for(int i=0; i<m_saCommands.GetSize(); i++)
	{
		if(m_saCommands[i].FindOneOf("$Var$")>0)
			m_saVariables.Add("$Var$");
	}



	m_saNoBarcodeCommands.Add("^XA");
	m_saNoBarcodeCommands.Add("^FO140,20^XGR:1.GRF,1,1^FS");

	m_saNoBarcodeCommands.Add("^FO60,180^BY3");
	m_saNoBarcodeCommands.Add("^ADN,36,20");
	m_saNoBarcodeCommands.Add("^A@N,25,25,E:F_TITR.FNT");
	m_saNoBarcodeCommands.Add("^FD$Var$^FS");

	m_saNoBarcodeCommands.Add("^FO300,40^BY3");
	m_saNoBarcodeCommands.Add("^ADN,36,20");
	m_saNoBarcodeCommands.Add("^A@N,30,30,E:F_TRAFIC.FNT");
	m_saNoBarcodeCommands.Add("^FD$Var$^FS");

//	m_saCommands.Add("^FO80,130^BY3");
//	m_saCommands.Add("^BCN,70,N,N,N");

	m_saNoBarcodeCommands.Add("^FO60,40^BY3");
	m_saNoBarcodeCommands.Add("^ADN,36,20");
	m_saNoBarcodeCommands.Add("^A@N,30,30,E:F_TRAFIC.FNT");
	m_saNoBarcodeCommands.Add("^FD$Var$^FS");

//	m_saCommands.Add("^FD>;$Var$^FS");
	m_saNoBarcodeCommands.Add("^ADN,36,20");
	m_saNoBarcodeCommands.Add("^FO60,230^BY3");
	m_saNoBarcodeCommands.Add("^A@N,35,45,E:F_TRAFIC.FNT");
	m_saNoBarcodeCommands.Add("^FD$Var$^FS");
	m_saNoBarcodeCommands.Add("^FO150,280^BY3");
	m_saNoBarcodeCommands.Add("^ADN,36,20");
	m_saNoBarcodeCommands.Add("^A@N,30,30,E:F_TRAFIC.FNT");
	m_saNoBarcodeCommands.Add("^FD$Var$^FS");
	m_saNoBarcodeCommands.Add("^XZ");




	for(i=0; i<m_saNoBarcodeCommands.GetSize(); i++)
	{
		if(m_saNoBarcodeCommands[i].FindOneOf("$Var$")>0)
			m_saNoBarcodeVariables.Add("$Var$");
	}

}

void CZplParser::SetVar(int iIndex, CString szVar)
{
	m_saVariables[iIndex]=szVar;
}

void CZplParser::SetNobarcodeVar(int iIndex, CString szVar)
{
	m_saNoBarcodeVariables[iIndex]=szVar;
}


void CZplParser::Print(HANDLE hComm, int iLabelType)
{
	if( (iLabelType==0) ||(iLabelType==2) )
	{
	int v=0;
	for(int i=0; i<m_saCommands.GetSize() ; i++)
	{
		int iWhere=m_saCommands[i].FindOneOf("$Var$");
		if(iWhere>0)
		{
			char sBuffer[255];
			for(int j=0; m_saCommands[i].GetAt(j)!='$'; j++)
				sBuffer[j]=m_saCommands[i].GetAt(j);
			sBuffer[j]='\0';
			j++;
			for(; m_saCommands[i].GetAt(j)!='$'; j++);
			j++;
			strcat(sBuffer, m_saVariables[v]);
			char sBuffer2[255];
			for(int k=j; k<m_saCommands[i].GetLength(); k++)
				sBuffer2[k-j]=m_saCommands[i].GetAt(k);
			sBuffer2[k-j]='\0';
			strcat(sBuffer, sBuffer2);
			DWORD dwWritten;
			WriteFile(hComm, sBuffer , strlen(sBuffer), &dwWritten, NULL);
			v++;
		}
		else
		{
			DWORD dwWritten;
			char sTemp[255];
			strcpy(sTemp, m_saCommands[i]);
			WriteFile(hComm, m_saCommands[i] , m_saCommands[i].GetLength(), &dwWritten, NULL);
			if(i==0)
			{
					CString	sPrintSpeed;
					sPrintSpeed.Format("^PR%d", theApp.GetProfileInt("Settings", "Speed", 2));
					WriteFile(hComm,  sPrintSpeed, sPrintSpeed.GetLength(), &dwWritten, NULL);	
			}

		}
	}
	}

	if( (iLabelType==1) ||(iLabelType==2) )
	{

	int v=0;
	for(int i=0; i<m_saNoBarcodeCommands.GetSize() ; i++)
	{
		int iWhere=m_saNoBarcodeCommands[i].FindOneOf("$Var$");
		if(iWhere>0)
		{
			char sBuffer[255];
			for(int j=0; m_saNoBarcodeCommands[i].GetAt(j)!='$'; j++)
				sBuffer[j]=m_saNoBarcodeCommands[i].GetAt(j);
			sBuffer[j]='\0';
			j++;
			for(; m_saNoBarcodeCommands[i].GetAt(j)!='$'; j++);
			j++;
			strcat(sBuffer, m_saNoBarcodeVariables[v]);
			char sBuffer2[255];
			for(int k=j; k<m_saNoBarcodeCommands[i].GetLength(); k++)
				sBuffer2[k-j]=m_saNoBarcodeCommands[i].GetAt(k);
			sBuffer2[k-j]='\0';
			strcat(sBuffer, sBuffer2);
			DWORD dwWritten;
			WriteFile(hComm, sBuffer , strlen(sBuffer), &dwWritten, NULL);
			v++;
		}
		else
		{
			DWORD dwWritten;
			char sTemp[255];
			strcpy(sTemp, m_saNoBarcodeCommands[i]);
			WriteFile(hComm, m_saNoBarcodeCommands[i] , m_saNoBarcodeCommands[i].GetLength(), &dwWritten, NULL);
			if(i==0)
			{
					CString	sPrintSpeed;
					sPrintSpeed.Format("^PR%d", theApp.GetProfileInt("Settings", "Speed", 2));
					WriteFile(hComm,  sPrintSpeed, sPrintSpeed.GetLength(), &dwWritten, NULL);	
			}
		}
	}

	}

}

void CZplParser::LoadArmToPrinter(HANDLE hComm)
{
	DWORD dwWritten;
	CString sCommand="~DG1.GRF,05000,025,00000000000000000000000000000000000000000000000000";
	WriteFile(hComm,  sCommand, sCommand.GetLength(), &dwWritten, NULL);	
	sCommand="00000000000000000000000000000000000000000000000000";
	WriteFile(hComm,  "00000000000000000000000000000000000000000000000000", sCommand.GetLength(), &dwWritten, NULL);
	WriteFile(hComm,  "00000000000000000000000000000000000000000000000000", sCommand.GetLength(), &dwWritten, NULL);
	WriteFile(hComm,  "00000000000000000000000000000000000000000000000000", sCommand.GetLength(), &dwWritten, NULL);
	WriteFile(hComm,  "00000000000000000000000000000000000000000000000000", sCommand.GetLength(), &dwWritten, NULL);
	WriteFile(hComm,  "00000000000000000000000000000000000000000000000000", sCommand.GetLength(), &dwWritten, NULL);
	WriteFile(hComm,  "00000000000000000000000000000000000000000000000000", sCommand.GetLength(), &dwWritten, NULL);
	WriteFile(hComm,  "00000000000000000000000000000000000000000000000000", sCommand.GetLength(), &dwWritten, NULL);
	WriteFile(hComm,  "00000000000000000000000000000000000000000000000000", sCommand.GetLength(), &dwWritten, NULL);
	WriteFile(hComm,  "00000000000000000000000000000000000000000000000000", sCommand.GetLength(), &dwWritten, NULL);
	WriteFile(hComm,  "00000000000000000000000000000000000000000000000000", sCommand.GetLength(), &dwWritten, NULL);
	WriteFile(hComm,  "00000000000000000000000000000000000000000000000000", sCommand.GetLength(), &dwWritten, NULL);
	WriteFile(hComm,  "00000000000000000000000000000000000000000000000000", sCommand.GetLength(), &dwWritten, NULL);
	WriteFile(hComm,  "00000000000000000000000000000000000000000000000000", sCommand.GetLength(), &dwWritten, NULL);
	WriteFile(hComm,  "00000000000000000000000000000000000000000000000000", sCommand.GetLength(), &dwWritten, NULL);
	WriteFile(hComm,  "00000000000000000000000000000000000000000000000000", sCommand.GetLength(), &dwWritten, NULL);
	WriteFile(hComm,  "00000000000000000000000000000000000000000000000000", sCommand.GetLength(), &dwWritten, NULL);
WriteFile(hComm,  "00000000000000000000000000000000000000000000000000", sCommand.GetLength(), &dwWritten, NULL);
WriteFile(hComm,  "00000000000000000000000000000000000000000000000000", sCommand.GetLength(), &dwWritten, NULL);
WriteFile(hComm,  "00000000000000000000000000000000000000000000000000", sCommand.GetLength(), &dwWritten, NULL);
WriteFile(hComm,  "00000000000000000000000000000000000000000000000000", sCommand.GetLength(), &dwWritten, NULL);
WriteFile(hComm,  "00000000000000000000000000000000000000000000000000", sCommand.GetLength(), &dwWritten, NULL);
WriteFile(hComm,  "00000000000000000000000010000000000000000000000000", sCommand.GetLength(), &dwWritten, NULL);
WriteFile(hComm,  "0000000000000000000000003C000000000000000000000000", sCommand.GetLength(), &dwWritten, NULL);
WriteFile(hComm,  "0000000000000000000000003C000000000000000000000000", sCommand.GetLength(), &dwWritten, NULL);
WriteFile(hComm,  "0000000000000000000000003C000000000000000000000000", sCommand.GetLength(), &dwWritten, NULL);
WriteFile(hComm,  "0000000000000000000000007E000000000000000000000000", sCommand.GetLength(), &dwWritten, NULL);
WriteFile(hComm,  "0000000000000000000000007E000000000000000000000000", sCommand.GetLength(), &dwWritten, NULL);
WriteFile(hComm,  "000000000000000000000000FE000000000000000000000000", sCommand.GetLength(), &dwWritten, NULL);
WriteFile(hComm,  "000000000000000000000000FE100000000000000000000000", sCommand.GetLength(), &dwWritten, NULL);
WriteFile(hComm,  "000000000000000000000001FF180000000000000000000000", sCommand.GetLength(), &dwWritten, NULL);
WriteFile(hComm,  "000000000000000000000003FF0C0000000000000000000000", sCommand.GetLength(), &dwWritten, NULL);
WriteFile(hComm,  "000000000000000000000003FF0C0000000000000000000000", sCommand.GetLength(), &dwWritten, NULL);
WriteFile(hComm,  "000000000000000000000007FF0E0000000000000000000000", sCommand.GetLength(), &dwWritten, NULL);
WriteFile(hComm,  "00000000000000000000000FFF8F0000000000000000000000", sCommand.GetLength(), &dwWritten, NULL);
WriteFile(hComm,  "00000000000000000000000FFF0F0000000000000000000000", sCommand.GetLength(), &dwWritten, NULL);
WriteFile(hComm,  "00000000000000000000001FFF8F8000000000000000000000", sCommand.GetLength(), &dwWritten, NULL);
WriteFile(hComm,  "00000000000000000000003FFF8F8000000000000000000000", sCommand.GetLength(), &dwWritten, NULL);
WriteFile(hComm,  "00000000000000000000007FFF9FC000000000000000000000", sCommand.GetLength(), &dwWritten, NULL);
WriteFile(hComm,  "0000000000000000000000FFFF9FC000000000000000000000", sCommand.GetLength(), &dwWritten, NULL);
WriteFile(hComm,  "0000000000000000000000FFFF9FC000000000000000000000", sCommand.GetLength(), &dwWritten, NULL);
WriteFile(hComm,  "0000000000000000000001FFFF9FE000000000000000000000", sCommand.GetLength(), &dwWritten, NULL);
WriteFile(hComm,  "0000000000000000000003FFFF1FE000000000000000000000", sCommand.GetLength(), &dwWritten, NULL);
WriteFile(hComm,  "0000000000000000000007FFFF3FE100000000000000000000", sCommand.GetLength(), &dwWritten, NULL);
WriteFile(hComm,  "000000000000000000000FFFFF3FE180000000000000000000", sCommand.GetLength(), &dwWritten, NULL);
WriteFile(hComm,  "000000000000000000001FFFFF7FF180000000000000000000", sCommand.GetLength(), &dwWritten, NULL);
WriteFile(hComm,  "000000000000000000003FFFFF7FF1C0000000000000000000", sCommand.GetLength(), &dwWritten, NULL);
WriteFile(hComm,  "000000000000000000003FFFFEFFF1C0000000000000000000", sCommand.GetLength(), &dwWritten, NULL);
WriteFile(hComm,  "000000000000000000007FFFFFFFF3E0000000000000000000", sCommand.GetLength(), &dwWritten, NULL);
WriteFile(hComm,  "000000000000000000007FFFFFFFF3E0000000000000000000", sCommand.GetLength(), &dwWritten, NULL);
WriteFile(hComm,  "00000000000000000000FFFFFFFFF3E0000000000000000000", sCommand.GetLength(), &dwWritten, NULL);
WriteFile(hComm,  "00000000000000000000FFFFFFFFF3F0000000000000000000", sCommand.GetLength(), &dwWritten, NULL);
WriteFile(hComm,  "00000000000000000001FFFFFFFFF3F0000000000000000000", sCommand.GetLength(), &dwWritten, NULL);
WriteFile(hComm,  "00000000000000000001FFFFFFFFF7F0000000000000000000", sCommand.GetLength(), &dwWritten, NULL);
WriteFile(hComm,  "00000000000000000001FFFFFFFFEFF8000000000000000000", sCommand.GetLength(), &dwWritten, NULL);
WriteFile(hComm,  "00000000000000000001FFFFFFFFEFF8000000000000000000", sCommand.GetLength(), &dwWritten, NULL);
WriteFile(hComm,  "00000000000000000001FFFFFFFFFFF8000000000000000000", sCommand.GetLength(), &dwWritten, NULL);
WriteFile(hComm,  "00000000000000000001FFFFFFFFFFF8000000000000000000", sCommand.GetLength(), &dwWritten, NULL);
WriteFile(hComm,  "00000000000000000001FFFFFFFFFFF8000000000000000000", sCommand.GetLength(), &dwWritten, NULL);
WriteFile(hComm,  "00000000000000000000FFFFFFFFFFF8000000000000000000", sCommand.GetLength(), &dwWritten, NULL);
WriteFile(hComm,  "00000000000000000000FFFFFFFFFFF8000000000000000000", sCommand.GetLength(), &dwWritten, NULL);
WriteFile(hComm,  "00000000000000000000FFFFFFFFFFF8000000000000000000", sCommand.GetLength(), &dwWritten, NULL);
WriteFile(hComm,  "00000000000000000000FFFFFFFFFFF8000000000000000000", sCommand.GetLength(), &dwWritten, NULL);
WriteFile(hComm,  "000000000000000000007FFFFFFFFFF8000000000000000000", sCommand.GetLength(), &dwWritten, NULL);
WriteFile(hComm,  "000000000000000000007FFFFFFFFFF0000000000000000000", sCommand.GetLength(), &dwWritten, NULL);
WriteFile(hComm,  "000000000000000000003FFFFFFFFFF0000000000000000000", sCommand.GetLength(), &dwWritten, NULL);
WriteFile(hComm,  "000000000000000000003FFFFFFFFFF0000000000000000000", sCommand.GetLength(), &dwWritten, NULL);
WriteFile(hComm,  "000000000000000000001FFFFFFFFFE0000000000000000000", sCommand.GetLength(), &dwWritten, NULL);
WriteFile(hComm,  "000000000000000000001FFFFFFFFFE0000000000000000000", sCommand.GetLength(), &dwWritten, NULL);
WriteFile(hComm,  "000000000000000000000FFFFFFFFFC0000000000000000000", sCommand.GetLength(), &dwWritten, NULL);
WriteFile(hComm,  "00000000000000000000077010000000000000000000000000", sCommand.GetLength(), &dwWritten, NULL);
WriteFile(hComm,  "00000000000000000000000000000000000000000000000000", sCommand.GetLength(), &dwWritten, NULL);
WriteFile(hComm,  "00000000000000000000000000000000000000000000000000", sCommand.GetLength(), &dwWritten, NULL);
WriteFile(hComm,  "00000000000000000000000000000300000000000000000000", sCommand.GetLength(), &dwWritten, NULL);
WriteFile(hComm,  "000000000000000000003FFFFFFFFFF8000000000000000000", sCommand.GetLength(), &dwWritten, NULL);
WriteFile(hComm,  "000000000000000000007FFFFFFFFFF8000000000000000000", sCommand.GetLength(), &dwWritten, NULL);
WriteFile(hComm,  "00000000000000000000FFFFFFFFFFFC000000000000000000", sCommand.GetLength(), &dwWritten, NULL);
WriteFile(hComm,  "00000000000000000000FFFFFFFFFFFC000000000000000000", sCommand.GetLength(), &dwWritten, NULL);
WriteFile(hComm,  "00000000000000000000FFFFFFFFFFFC000000000000000000", sCommand.GetLength(), &dwWritten, NULL);
WriteFile(hComm,  "000000000000000000007FFFFFFFFFF8000000000000000000", sCommand.GetLength(), &dwWritten, NULL);
WriteFile(hComm,  "000000000000000000007FFFFFFFFFF0000000000000000000", sCommand.GetLength(), &dwWritten, NULL);
WriteFile(hComm,  "00000000000000000000000000000000000000000000000000", sCommand.GetLength(), &dwWritten, NULL);
WriteFile(hComm,  "00000000000000000000000000000000000000000000000000", sCommand.GetLength(), &dwWritten, NULL);
WriteFile(hComm,  "00000000000000000000000000000000000000000000000000", sCommand.GetLength(), &dwWritten, NULL);
WriteFile(hComm,  "00000000000000000000001FFFFFE000000000000000000000", sCommand.GetLength(), &dwWritten, NULL);
WriteFile(hComm,  "0000000000000000000000FFFFFFF000000000000000000000", sCommand.GetLength(), &dwWritten, NULL);
WriteFile(hComm,  "0000000000000000000000FFFFFFF000000000000000000000", sCommand.GetLength(), &dwWritten, NULL);
WriteFile(hComm,  "0000000000000000000000FFFFFFF000000000000000000000", sCommand.GetLength(), &dwWritten, NULL);
WriteFile(hComm,  "00000000000000000000007FFFFFE000000000000000000000", sCommand.GetLength(), &dwWritten, NULL);
WriteFile(hComm,  "00000000000000000000003FFFFF8000000000000000000000", sCommand.GetLength(), &dwWritten, NULL);
WriteFile(hComm,  "00000000000000003FA0001FFFFF00007FA000000000000000", sCommand.GetLength(), &dwWritten, NULL);
WriteFile(hComm,  "0000000000000003FFFC000FFFFF0007FFFE00000000000000", sCommand.GetLength(), &dwWritten, NULL);
WriteFile(hComm,  "000000000000001FFFFF8007FFFC001FFFFF80000000000000", sCommand.GetLength(), &dwWritten, NULL);
WriteFile(hComm,  "000000000000007FFFFFE003FFFC003FFFFFE0000000000000", sCommand.GetLength(), &dwWritten, NULL);
WriteFile(hComm,  "00000000000000FFFFFFF001FFF800FFFFFFF0000000000000", sCommand.GetLength(), &dwWritten, NULL);
WriteFile(hComm,  "00000000000001FFFFFFFC00FFF003FFFFFFFC000000000000", sCommand.GetLength(), &dwWritten, NULL);
WriteFile(hComm,  "00000000000007FFFFFFFE007FF007FFFFFFFE000000000000", sCommand.GetLength(), &dwWritten, NULL);
WriteFile(hComm,  "0000000000000FFFFFFFFF007FE00FFFFFFFFF000000000000", sCommand.GetLength(), &dwWritten, NULL);
WriteFile(hComm,  "0000000000001FFFFFFFFFC03FE01FFFFFFFFF800000000000", sCommand.GetLength(), &dwWritten, NULL);
WriteFile(hComm,  "0000000000003FFFF0FFFFC03FC03FFFE07FFF800000000000", sCommand.GetLength(), &dwWritten, NULL);
WriteFile(hComm,  "0000000000003FFF800FFFE01FC07FFF000FFFE00000000000", sCommand.GetLength(), &dwWritten, NULL);
WriteFile(hComm,  "0000000000007FFC0003FFF01F80FFFC0001FFE00000000000", sCommand.GetLength(), &dwWritten, NULL);
WriteFile(hComm,  "000000000000FFF80000FFF00F80FFF00000FFE00000000000", sCommand.GetLength(), &dwWritten, NULL);
WriteFile(hComm,  "000000000000FFE000007FF80F81FFF000007FF00000000000", sCommand.GetLength(), &dwWritten, NULL);
WriteFile(hComm,  "000000000001FFC000003FF80F01FFC000003FF80000000000", sCommand.GetLength(), &dwWritten, NULL);
WriteFile(hComm,  "000000000001FFC000001FFC0F03FFC000001FF80000000000", sCommand.GetLength(), &dwWritten, NULL);
WriteFile(hComm,  "000000000003FF8000000FFC0703FF8000000FFC0000000000", sCommand.GetLength(), &dwWritten, NULL);
WriteFile(hComm,  "000000000003FF0000000FFE0607FF0000000FFC0000000000", sCommand.GetLength(), &dwWritten, NULL);
WriteFile(hComm,  "000000000003FF00000007FE0007FF0000000FFC0000000000", sCommand.GetLength(), &dwWritten, NULL);
WriteFile(hComm,  "000000000007FE00000007FF0007FE00000007FC0000000000", sCommand.GetLength(), &dwWritten, NULL);
WriteFile(hComm,  "000000000007FE00000003FF000FFC00000007FE0000000000", sCommand.GetLength(), &dwWritten, NULL);
WriteFile(hComm,  "000000000007FE00000003FF000FFC00000003FE0000000000", sCommand.GetLength(), &dwWritten, NULL);
WriteFile(hComm,  "000000000007FC00000001FF000FF800000003FE0000000000", sCommand.GetLength(), &dwWritten, NULL);
WriteFile(hComm,  "000000000007FC00000001FF801FF800000003FE0000000000", sCommand.GetLength(), &dwWritten, NULL);
WriteFile(hComm,  "000000000007FC00000001FFC03FF800000003FE0000000000", sCommand.GetLength(), &dwWritten, NULL);
WriteFile(hComm,  "000000000007FC00000001FFF9FFF800000003FC0000000000", sCommand.GetLength(), &dwWritten, NULL);
WriteFile(hComm,  "000000000003FC00000000FFFFFFF000000003FC0000000000", sCommand.GetLength(), &dwWritten, NULL);
WriteFile(hComm,  "000000000001FC00000000FFFFFFF000000003F00000000000", sCommand.GetLength(), &dwWritten, NULL);
WriteFile(hComm,  "0000000000007C00000000FFFFFFF000000003E00000000000", sCommand.GetLength(), &dwWritten, NULL);
WriteFile(hComm,  "000000001F003E00000000FFFFFFF000070007C01FF0000000", sCommand.GetLength(), &dwWritten, NULL);
WriteFile(hComm,  "00000000FFE03E00070000FFFFFFF0003E0007C0FFFC000000", sCommand.GetLength(), &dwWritten, NULL);
WriteFile(hComm,  "00000003FFF01F0003C000FFFFFFF0007C000781FFFF000000", sCommand.GetLength(), &dwWritten, NULL);
WriteFile(hComm,  "00000007FFFC1F0003F000FFFFFFF000FC000F01FFFF800000", sCommand.GetLength(), &dwWritten, NULL);
WriteFile(hComm,  "0000000FFFFC0F8003F800FFFFFFF001F8000F03FFFFC00000", sCommand.GetLength(), &dwWritten, NULL);
WriteFile(hComm,  "0000001FFFFE0F8001FC01FFFFFFF803FC001F07FFFFC00000", sCommand.GetLength(), &dwWritten, NULL);
WriteFile(hComm,  "0000003FFFFE0FC001FC01FFE0FFF803FC003E07FFFFE00000", sCommand.GetLength(), &dwWritten, NULL);
WriteFile(hComm,  "0000003FFFFE0FE003FE03FFC03FFC07FC007E0FFFFFF00000", sCommand.GetLength(), &dwWritten, NULL);
WriteFile(hComm,  "0000007FFFFF07F003FE03FF801FFC07FE00FE07FFFFF00000", sCommand.GetLength(), &dwWritten, NULL);
WriteFile(hComm,  "0000007FFFFF07F807FE03FF000FFC07FF01FF07FFFFF00000", sCommand.GetLength(), &dwWritten, NULL);
WriteFile(hComm,  "0000007FFFFE07FC0FFE03FE000FFE07FFCFFF07FFFFF00000", sCommand.GetLength(), &dwWritten, NULL);
WriteFile(hComm,  "000000FFFFFE07FFFFFE07FE0007FE07FFFFFF07FFFFF00000", sCommand.GetLength(), &dwWritten, NULL);
WriteFile(hComm,  "000000FFFFFE0FFFFFFE07FC0007FE07FFFFFF03FFFFF00000", sCommand.GetLength(), &dwWritten, NULL);
WriteFile(hComm,  "000000FFFFFC0FFFFFFE07FC0007FE07FFFFFF03FFFFF00000", sCommand.GetLength(), &dwWritten, NULL);
WriteFile(hComm,  "000000FFFFF81FFFFFFE07FE0007FE03FFFFFF81FFFFF00000", sCommand.GetLength(), &dwWritten, NULL);
WriteFile(hComm,  "000000FFFFF01FFFFFFC07FE0007FE03FFFFFF80FFFFF00000", sCommand.GetLength(), &dwWritten, NULL);
WriteFile(hComm,  "0000007FFF803FFFFFFE03FE000FFE07FFFFFFC01FFFF00000", sCommand.GetLength(), &dwWritten, NULL);
WriteFile(hComm,  "0000007FFC003FFFFFFF03FF000FFC0FFFFFFFE001FFF00000", sCommand.GetLength(), &dwWritten, NULL);
WriteFile(hComm,  "0000007FF800FFFFFFFF83FF801FFC0FFFFFFFF001FFE00000", sCommand.GetLength(), &dwWritten, NULL);
WriteFile(hComm,  "0000007FF801FFFFFFFF83FFC03FFC1FFFFFFFF801FFE00000", sCommand.GetLength(), &dwWritten, NULL);
WriteFile(hComm,  "0000003FFC03FFE3FFFFC1FFF9FFF81FFFF47FFE07FFC00000", sCommand.GetLength(), &dwWritten, NULL);
WriteFile(hComm,  "0000001FFFFFFFC0FF7FC1FFFFFFF01FE1A03FFFFFFFC00000", sCommand.GetLength(), &dwWritten, NULL);
WriteFile(hComm,  "0000001FFFFFFFC0000FC0FFFFFFF01F00001FFFFFFF800000", sCommand.GetLength(), &dwWritten, NULL);
WriteFile(hComm,  "0000000FFFFFFF800007C0FFFFFFE01E00001FFFFFFF000000", sCommand.GetLength(), &dwWritten, NULL);
WriteFile(hComm,  "00000007FFFFFE000003C07FFFFFC01E00000FFFFFFE000000", sCommand.GetLength(), &dwWritten, NULL);
WriteFile(hComm,  "00000003FFFFFE000003803FFFFFC00C000003FFFFFC000000", sCommand.GetLength(), &dwWritten, NULL);
WriteFile(hComm,  "00000001FFFFFC000003801FFFFF800C000001FFFFF8000000", sCommand.GetLength(), &dwWritten, NULL);
WriteFile(hComm,  "00000000FFFFF00000020007FFFE00040000007FFFE0000000", sCommand.GetLength(), &dwWritten, NULL);
WriteFile(hComm,  "000000003FFFC00000020001FFF800000000000FFF80000000", sCommand.GetLength(), &dwWritten, NULL);
WriteFile(hComm,  "0000000007FF0000000000003FC0000000000007FE00000000", sCommand.GetLength(), &dwWritten, NULL);
WriteFile(hComm,  "00000000000000000000000000000000000000000000000000", sCommand.GetLength(), &dwWritten, NULL);
WriteFile(hComm,  "00000000000000000000000000000000000000000000000000", sCommand.GetLength(), &dwWritten, NULL);
WriteFile(hComm,  "00000000000000000000000000000000000000000000000000", sCommand.GetLength(), &dwWritten, NULL);
WriteFile(hComm,  "00000000000000000000000000000000000000000000000000", sCommand.GetLength(), &dwWritten, NULL);
WriteFile(hComm,  "00000000000000000000000000000000000000000000000000", sCommand.GetLength(), &dwWritten, NULL);
WriteFile(hComm,  "00000000000000000000000000000000000000000000000000", sCommand.GetLength(), &dwWritten, NULL);
WriteFile(hComm,  "00000000000000000000000000000000000000000000000000", sCommand.GetLength(), &dwWritten, NULL);
WriteFile(hComm,  "00000000000000000000000000000000000000000000000000", sCommand.GetLength(), &dwWritten, NULL);
WriteFile(hComm,  "00000000000000000000000000000000000000000000000000", sCommand.GetLength(), &dwWritten, NULL);
WriteFile(hComm,  "00000000000000000000000000000000000000000000000000", sCommand.GetLength(), &dwWritten, NULL);
WriteFile(hComm,  "00000000000000000000000000000000000000000000000000", sCommand.GetLength(), &dwWritten, NULL);
WriteFile(hComm,  "00000000000000000000000000000000000000000000000000", sCommand.GetLength(), &dwWritten, NULL);
WriteFile(hComm,  "00000000000000000000000000000000000000000000000000", sCommand.GetLength(), &dwWritten, NULL);
WriteFile(hComm,  "00000000000000000000000000000000000000000000000000", sCommand.GetLength(), &dwWritten, NULL);
WriteFile(hComm,  "00000000000000000000000000000000000000000000000000", sCommand.GetLength(), &dwWritten, NULL);
WriteFile(hComm,  "00000000000000000000000000000000000000000000000000", sCommand.GetLength(), &dwWritten, NULL);
WriteFile(hComm,  "00000000000000000000000000000000000000000000000000", sCommand.GetLength(), &dwWritten, NULL);
WriteFile(hComm,  "00000000000000000000000000000000000000000000000000", sCommand.GetLength(), &dwWritten, NULL);
WriteFile(hComm,  "00000000000000000000000000000000000000000000000000", sCommand.GetLength(), &dwWritten, NULL);
WriteFile(hComm,  "00000000000000000000000000000000000000000000000000", sCommand.GetLength(), &dwWritten, NULL);
WriteFile(hComm,  "00000000000000000000000000000000000000000000000000", sCommand.GetLength(), &dwWritten, NULL);
WriteFile(hComm,  "00000000000000000000000000000000000000000000000000", sCommand.GetLength(), &dwWritten, NULL);
WriteFile(hComm,  "00000000000000000000000000000000000000000000000000", sCommand.GetLength(), &dwWritten, NULL);
WriteFile(hComm,  "00000000000000000000000000000000000000000000000000", sCommand.GetLength(), &dwWritten, NULL);
WriteFile(hComm,  "00000000000000000000000000000000000000000000000000", sCommand.GetLength(), &dwWritten, NULL);
WriteFile(hComm,  "00000000000000000000000000000000000000000000000000", sCommand.GetLength(), &dwWritten, NULL);
WriteFile(hComm,  "00000000000000000000000000000000000000000000000000", sCommand.GetLength(), &dwWritten, NULL);
WriteFile(hComm,  "00000000000000000000000000000000000000000000000000", sCommand.GetLength(), &dwWritten, NULL);
WriteFile(hComm,  "00000000000000000000000000000000000000000000000000", sCommand.GetLength(), &dwWritten, NULL);
WriteFile(hComm,  "00000000000000000000000000000000000000000000000000", sCommand.GetLength(), &dwWritten, NULL);
WriteFile(hComm,  "00000000000000000000000000000000000000000000000000", sCommand.GetLength(), &dwWritten, NULL);
WriteFile(hComm,  "00000000000000000000000000000000000000000000000000", sCommand.GetLength(), &dwWritten, NULL);
WriteFile(hComm,  "00000000000000000000000000000000000000000000000000", sCommand.GetLength(), &dwWritten, NULL);
WriteFile(hComm,  "00000000000000000000000000000000000000000000000000", sCommand.GetLength(), &dwWritten, NULL);
WriteFile(hComm,  "00000000000000000000000000000000000000000000000000", sCommand.GetLength(), &dwWritten, NULL);
WriteFile(hComm,  "00000000000000000000000000000000000000000000000000", sCommand.GetLength(), &dwWritten, NULL);
WriteFile(hComm,  "00000000000000000000000000000000000000000000000000", sCommand.GetLength(), &dwWritten, NULL);
WriteFile(hComm,  "00000000000000000000000000000000000000000000000000", sCommand.GetLength(), &dwWritten, NULL);
WriteFile(hComm,  "00000000000000000000000000000000000000000000000000", sCommand.GetLength(), &dwWritten, NULL);
WriteFile(hComm,  "00000000000000000000000000000000000000000000000000", sCommand.GetLength(), &dwWritten, NULL);
WriteFile(hComm,  "00000000000000000000000000000000000000000000000000", sCommand.GetLength(), &dwWritten, NULL);
WriteFile(hComm,  "00000000000000000000000000000000000000000000000000", sCommand.GetLength(), &dwWritten, NULL);
WriteFile(hComm,  "00000000000000000000000000000000000000000000000000", sCommand.GetLength(), &dwWritten, NULL);
WriteFile(hComm,  "00000000000000000000000000000000000000000000000000", sCommand.GetLength(), &dwWritten, NULL);
WriteFile(hComm,  "00000000000000000000000000000000000000000000000000", sCommand.GetLength(), &dwWritten, NULL);
WriteFile(hComm,  "00000000000000000000000000000000000000000000000000", sCommand.GetLength(), &dwWritten, NULL);
WriteFile(hComm,  "00000000000000000000000000000000000000000000000000", sCommand.GetLength(), &dwWritten, NULL);
WriteFile(hComm,  "00000000000000000000000000000000000000000000000000", sCommand.GetLength(), &dwWritten, NULL);
WriteFile(hComm,  "00000000000000000000000000000000000000000000000000", sCommand.GetLength(), &dwWritten, NULL);
WriteFile(hComm,  "00000000000000000000000000000000000000000000000000", sCommand.GetLength(), &dwWritten, NULL);
WriteFile(hComm,  "00000000000000000000000000000000000000000000000000", sCommand.GetLength(), &dwWritten, NULL);


}
