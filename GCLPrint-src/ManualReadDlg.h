#if !defined(AFX_MANUALREADDLG_H__6CCCBF54_4618_46AD_BE21_CAE78BEA36CB__INCLUDED_)
#define AFX_MANUALREADDLG_H__6CCCBF54_4618_46AD_BE21_CAE78BEA36CB__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// ManualReadDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CManualReadDlg dialog

class CManualReadDlg : public CDialog
{
// Construction
public:
	CManualReadDlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CManualReadDlg)
	enum { IDD = IDD_INSERTCUSTOMER };
	CString	m_sID;
	CString	m_sAD;
	CString	m_sSerial;
	CString	m_sName;
	CString	m_sAddress;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CManualReadDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CManualReadDlg)
	virtual void OnOK();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MANUALREADDLG_H__6CCCBF54_4618_46AD_BE21_CAE78BEA36CB__INCLUDED_)
