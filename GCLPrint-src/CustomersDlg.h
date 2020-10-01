#if !defined(AFX_CUSTOMERSDLG_H__EBFF1779_B607_402F_93E8_CBEB47BDFAB5__INCLUDED_)
#define AFX_CUSTOMERSDLG_H__EBFF1779_B607_402F_93E8_CBEB47BDFAB5__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// CustomersDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CCustomersDlg dialog

class CCustomersDlg : public CDialog
{
// Construction
public:
void SetRecordInfo(CString sIS, CString sFLName, CString sAddress, CString sAddressCode, CString sDomainCode, CString sPDate, CString sPQ, CString sO, CString sQType, CString sDate, CString sQuant, CString sSerial);
	CCustomersDlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CCustomersDlg)
	enum { IDD = IDD_CUSTOMER };
	CString	m_sID;
	CString	m_sFLName;
	CString	m_sAddress;
	CString	m_sAddressCode;
	CString	m_sDate;
	CString	m_sDomainCode;
	CString	m_sFrequency;
	CString	m_sPCon;
	CString	m_sPDate;
	CString	m_sQType;
	CString	m_sQuant;
	CString	m_sSerial;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CCustomersDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CCustomersDlg)
		// NOTE: the ClassWizard will add member functions here
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CUSTOMERSDLG_H__EBFF1779_B607_402F_93E8_CBEB47BDFAB5__INCLUDED_)
