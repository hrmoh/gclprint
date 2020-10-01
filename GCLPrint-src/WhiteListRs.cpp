// WhiteListRs.cpp: implementation of the CWhiteListRs class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "GCLPrint.h"
#include "WhiteListRs.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CWhiteListRs::CWhiteListRs()
{
	m_baConvertTable[64]=32;
	m_baConvertTable[74]='é';	//231;	//é
	m_baConvertTable[75]='«';	//166;	//«
	m_baConvertTable[76]='«';	//166;	//«
	m_baConvertTable[77]='»';	//167;	//»
	m_baConvertTable[78]='Å';	//168;	//Å
	m_baConvertTable[79]=' ';	//170;	// 
	m_baConvertTable[90]='€';	//239;	//€
	m_baConvertTable[91]='À';	//171;	//À
	m_baConvertTable[92]='Ã';	//172;	//Ã
	m_baConvertTable[93]='Ã';	//172;	//Ã
	m_baConvertTable[94]='ç';	//173;	//ç
	m_baConvertTable[95]='ç';	//173;	//ç
	m_baConvertTable[96]=45;
	m_baConvertTable[97]=32;
	m_baConvertTable[107]='Õ';	//224;	//Õ
	m_baConvertTable[108]='Õ';	//224;	//Õ
	m_baConvertTable[109]='„';	//246;	//„
	m_baConvertTable[110]='Œ';	//225;	//Œ
	m_baConvertTable[111]='Œ';	//225;	//Œ
	m_baConvertTable[122]=32;
	m_baConvertTable[123]='œ';	//226;	//œ
	m_baConvertTable[124]='–';	//227;	//–
	m_baConvertTable[125]='—';	//228;	//—
	m_baConvertTable[126]='“';	//229;	//“
	m_baConvertTable[127]='∆';	//165;	//∆
	m_baConvertTable[193]='”';	//232;	//”
	m_baConvertTable[194]='‘';	//233;	//‘
	m_baConvertTable[195]='’';	//234;	//’
	m_baConvertTable[196]='÷';	//235;	//÷
	m_baConvertTable[197]='ÿ';	//236;	//ÿ
	m_baConvertTable[198]='Ÿ';	//237;	//Ÿ
	m_baConvertTable[199]='⁄';	//238;	//⁄
	m_baConvertTable[200]='⁄';	//238;	//⁄
	m_baConvertTable[201]='€';	//239;	//€
	m_baConvertTable[209]='›';	//241;	//›
	m_baConvertTable[210]='ﬁ';	//242;	//ﬁ
	m_baConvertTable[211]='ﬁ';	//242;	//ﬁ
	m_baConvertTable[212]='ò';	//243;	//ò
	m_baConvertTable[213]='ê';	//244;	//ê
	m_baConvertTable[214]='·';	//245;	//·
	m_baConvertTable[215]='·';	//245;	//·
	m_baConvertTable[216]='·';	//189;	//·«
	m_baConvertTable[217]='„';	//246;	//„
	m_baConvertTable[226]='‰';	//248;	//‰
	m_baConvertTable[227]='‰';	//248;	//‰
	m_baConvertTable[228]='Ê';	//251;	//Ê
	m_baConvertTable[229]='Â';	//249;	//Â
	m_baConvertTable[230]='Â';	//249;	//Â
	m_baConvertTable[231]='Ì';	//253;	//Ì
	m_baConvertTable[232]='Ì';	//253;	//Ì
	m_baConvertTable[240]=48;	//0
	m_baConvertTable[241]=49;	//1
	m_baConvertTable[242]=50;	//2	
	m_baConvertTable[243]=51;	//3	
	m_baConvertTable[244]=52;	//4
	m_baConvertTable[245]=53;	//5
	m_baConvertTable[246]=54;	//6
	m_baConvertTable[247]=55;	//7
	m_baConvertTable[248]=56;	//8
	m_baConvertTable[249]=57;	//9

}

BOOL CWhiteListRs::ReadDomainCode(BYTE* pBuffer)
{
	strcpy(m_szDomainCode, ChangeCodePage(pBuffer, 0, 2));	
	return TRUE;
}

BOOL CWhiteListRs::ReadFrequency(BYTE* pBuffer)
{
	strcpy(m_szFrequency, ChangeCodePage(pBuffer, 2, 1));	
	return TRUE;
}


BOOL CWhiteListRs::ReadSubscriptionCode(BYTE* pBuffer)
{
	strcpy(m_szSubscriptionCode, ChangeCodePage(pBuffer, 4, 15));	
	return TRUE;
}

BOOL CWhiteListRs::ReadConsumptionKind(BYTE* pBuffer)
{
	strcpy(m_szConsumptionKind, ChangeCodePage(pBuffer, 19, 2));	
	return TRUE;
}

BOOL CWhiteListRs::ReadPrevDate(BYTE* pBuffer)
{
	strcpy(m_szPrevDate, ChangeCodePage(pBuffer, 21, 2));	
	strcat(m_szPrevDate, "/");	
	strcat(m_szPrevDate, ChangeCodePage(pBuffer, 23, 2));
	strcat(m_szPrevDate, "/");	
	strcat(m_szPrevDate, ChangeCodePage(pBuffer, 25, 2));
	return TRUE;
}

BOOL CWhiteListRs::ReadPrevCounter(BYTE* pBuffer)
{
	strcpy(m_szPrevCounter, ChangeCodePage(pBuffer, 27, 10));	
	return TRUE;
}

BOOL CWhiteListRs::ReadFLName(BYTE* pBuffer)
{
	strcpy(m_szFLName, ChangeCodePageForString(pBuffer, 37, 40));	
	return TRUE;
}

BOOL CWhiteListRs::ReadAddress(BYTE* pBuffer)
{
	strcpy(m_szAddress, ChangeCodePageForString(pBuffer, 77, 50));	
	return TRUE;
}


BOOL CWhiteListRs::ReadCounterSerial(BYTE* pBuffer)
{
	strcpy(m_szCounterSerial, ChangeCodePage(pBuffer, 128, 10));	
	return TRUE;
}

BOOL CWhiteListRs::ReadAddressCode(BYTE* pBuffer)
{
	strcpy(m_szAddressCode, ChangeCodePage(pBuffer, 138, 10));	
	return TRUE;
}

BOOL CWhiteListRs::ReadCapacity(BYTE* pBuffer)
{
	strcpy(m_szCapacity, ChangeCodePage(pBuffer, 148, 4));	
	return TRUE;
}

BOOL CWhiteListRs::ReadFileDate(BYTE* pBuffer)
{
	strcpy(m_szFileDate, ChangeCodePage(pBuffer, 152, 2));	
	strcat(m_szFileDate, "/");	
	strcat(m_szFileDate, ChangeCodePage(pBuffer, 154, 2));
	strcat(m_szFileDate, "/");	
	strcat(m_szFileDate, ChangeCodePage(pBuffer, 156, 2));
	return TRUE;
}


CString CWhiteListRs::ChangeCodePage(BYTE *pBuffer, int iStart, int iLength)
{
	char strConverted[255];

	int iConvertedIndex=0;

	for(int i=iStart; i<iStart+iLength; i++)
	{
		strConverted[iConvertedIndex]=m_baConvertTable[pBuffer[i]];
		iConvertedIndex++;
	}
	strConverted[iConvertedIndex]='\0';
	CString strReturnValue;
	strReturnValue= strConverted;
	return strReturnValue;
}

CString CWhiteListRs::ChangeCodePageForString(BYTE *pBuffer, int iStart, int iLength)
{
	char strConverted[255];

	int iConvertedIndex=0;

	int n=iStart+iLength-1;
	for(n=iStart+iLength-1; pBuffer[n]==64; n--);

	int iStartDigit=-1;
	int iEndDigit=-1;

	int iFollowingSpaces=0;

	for(int i=n; i>iStart-1; i--)
	{
		if(pBuffer[i]==64)
			iFollowingSpaces++;
		else
			iFollowingSpaces=0;
		if(iFollowingSpaces<3)
		{
		if(IsItADigit(pBuffer[i]))
		{
			if(iStartDigit==-1)
				iStartDigit=iConvertedIndex;
			iEndDigit=iConvertedIndex;
		}
		else
		{
			if(iEndDigit>0)
			{
				//reverse number:
				char bTemp[255];
				for(int j=iEndDigit;j>iStartDigit-1;j--)
					bTemp[iEndDigit-j+iStartDigit]=strConverted[j];
				for(j=iStartDigit;j<=iEndDigit;j++)
					strConverted[j]=bTemp[j];
				iStartDigit=-1;
				iEndDigit=-1;
			}
		}


		strConverted[iConvertedIndex]=m_baConvertTable[pBuffer[i]];		
		iConvertedIndex++;
		if(pBuffer[i]==216)
		{
			if(i-1>-1)
				if(pBuffer[i-1]!=215)
				{
					strConverted[iConvertedIndex]='«';
					iConvertedIndex++;
				}
		}
		else if(RequiersSpace(pBuffer[i]))
		{
			strConverted[iConvertedIndex]=' ';
			iConvertedIndex++;
		}
		}
	}
	while( (strConverted[iConvertedIndex-1]==' ') && (iConvertedIndex>0) ) iConvertedIndex--;
	if(iEndDigit>0)
	{
		//reverse number:
		char bTemp[255];
		for(int j=iEndDigit;j>iStartDigit-1;j--)
		bTemp[iEndDigit-j+iStartDigit]=strConverted[j];
		for(j=iStartDigit;j<=iEndDigit;j++)
			strConverted[j]=bTemp[j];
		iStartDigit=-1;
		iEndDigit=-1;
	}

	strConverted[iConvertedIndex]='\0';	
	CString strReturnValue;
	strReturnValue= strConverted;
	return strReturnValue;
}

BOOL CWhiteListRs::RequiersSpace(BYTE bChar)
{
	switch(bChar)
	{
	case 92:	//Ã
	case 94:
	case 110:	//Œ
	case 199:	//⁄
	case 210:
	case 214:
	case 109:	//„
	case 226:	//‰
	case 229: //Â
	case 232:return TRUE;
	default:return FALSE;	
	}
	return FALSE;
}


BOOL CWhiteListRs::IsItADigit(BYTE bChar)
{
	if( (bChar>239) && (bChar<250) )
		return TRUE;
	return FALSE;
}
