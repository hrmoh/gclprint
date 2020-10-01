// CustomersDlg.cpp : implementation file
//

#include "stdafx.h"
#include "GCLPrint.h"
#include "CustomersDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CCustomersDlg dialog


CCustomersDlg::CCustomersDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CCustomersDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CCustomersDlg)
	m_sID = _T("");
	m_sFLName = _T("");
	m_sAddress = _T("");
	m_sAddressCode = _T("");
	m_sDate = _T("");
	m_sDomainCode = _T("");
	m_sFrequency = _T("");
	m_sPCon = _T("");
	m_sPDate = _T("");
	m_sQType = _T("");
	m_sQuant = _T("");
	m_sSerial = _T("");
	//}}AFX_DATA_INIT
}


void CCustomersDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CCustomersDlg)
	DDX_Text(pDX, IDC_ID, m_sID);
	DDX_Text(pDX, IDC_NAME, m_sFLName);
	DDX_Text(pDX, IDC_ADDRESS, m_sAddress);
	DDX_Text(pDX, IDC_ADDRESSCODE, m_sAddressCode);
	DDX_Text(pDX, IDC_DATE, m_sDate);
	DDX_Text(pDX, IDC_DCODE, m_sDomainCode);
	DDX_Text(pDX, IDC_FREQUENCY, m_sFrequency);
	DDX_Text(pDX, IDC_PCON, m_sPCon);
	DDX_Text(pDX, IDC_PDATE, m_sPDate);
	DDX_Text(pDX, IDC_QTYPE, m_sQType);
	DDX_Text(pDX, IDC_QUANT, m_sQuant);
	DDX_Text(pDX, IDC_SERIAL, m_sSerial);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CCustomersDlg, CDialog)
	//{{AFX_MSG_MAP(CCustomersDlg)
		// NOTE: the ClassWizard will add message map macros here
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CCustomersDlg message handlers

void CCustomersDlg::SetRecordInfo(CString sIS, CString sFLName, CString sAddress, CString sAddressCode, CString sDomainCode, CString sPDate, CString sPQ, CString sO, CString sQType, CString sDate, CString sQuant, CString sSerial)
{
	m_sID = sIS;
	m_sFLName = sFLName;
	m_sAddress = sAddress;
	m_sAddressCode = sAddressCode;
	m_sDate = sDate;
	m_sDomainCode = sDomainCode;
	m_sFrequency = sO;
	m_sPCon = sPQ;
	m_sPDate = sPDate;
	m_sQType = sQType;
	m_sQuant=sQuant;
	m_sSerial=sSerial;
}
