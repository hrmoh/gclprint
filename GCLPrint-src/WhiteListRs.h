// WhiteListRs.h: interface for the CWhiteListRs class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_WHITELISTRS_H__1BC4528F_C9C3_4102_A8F3_274FBC32B9C2__INCLUDED_)
#define AFX_WHITELISTRS_H__1BC4528F_C9C3_4102_A8F3_274FBC32B9C2__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000



class CWhiteListRs
{

public:
	CHAR m_szDomainCode[2];
	ULONG lDomainCodeStatus;

	CHAR m_szFrequency[1];
	ULONG lFrequencyStatus;


	CHAR m_szSubscriptionCode[15];
	ULONG lSubscriptionCodeStatus;

	CHAR m_szConsumptionKind[4];
	ULONG lConsumptionKindStatus;

	CHAR m_szPrevDate[6];
	ULONG lPrevDateStatus;

	CHAR m_szPrevCounter[10];
	ULONG lPrevCounterStatus;

	CHAR m_szFLName[60];
	ULONG lFLNameStatus;

	CHAR m_szAddress[70];
	ULONG lAddressStatus;

	CHAR m_szAddressCode[10];
	ULONG lAddressCodeStatus;

	CHAR m_szCounterSerial[10];
	ULONG lCounterSerialStatus;

	CHAR m_szCapacity[4];
	ULONG lCapacityStatus;

	CHAR m_szFileDate[6];
	ULONG lFileDateStatus;

public:
	BOOL IsItADigit(BYTE bChar);


	CWhiteListRs();

	BOOL ReadDomainCode(BYTE* pBuffer);
	BOOL ReadFrequency(BYTE* pBuffer);
	BOOL ReadSubscriptionCode(BYTE* pBuffer);
	BOOL ReadConsumptionKind(BYTE* pBuffer);
	BOOL ReadPrevDate(BYTE* pBuffer);
	BOOL ReadPrevCounter(BYTE* pBuffer);
	BOOL ReadFLName(BYTE* pBuffer);
	BOOL ReadAddress(BYTE* pBuffer);
	BOOL ReadAddressCode(BYTE* pBuffer);
	BOOL ReadCounterSerial(BYTE* pBuffer);
	BOOL ReadCapacity(BYTE* pBuffer);
	BOOL ReadFileDate(BYTE* pBuffer);

private:
	BOOL RequiersSpace(BYTE bChar);
	CString ChangeCodePage(BYTE* pBuffer, int iStart, int iLength);
	CString ChangeCodePageForString(BYTE* pBuffer, int iStart, int iLength);
	BYTE m_baConvertTable[255];
};

#endif // !defined(AFX_WHITELISTRS_H__1BC4528F_C9C3_4102_A8F3_274FBC32B9C2__INCLUDED_)
