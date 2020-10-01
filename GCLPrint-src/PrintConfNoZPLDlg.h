#if !defined(AFX_PRINTCONFNOZPLDLG_H__867912CE_62BA_4E86_843E_79B853273DBD__INCLUDED_)
#define AFX_PRINTCONFNOZPLDLG_H__867912CE_62BA_4E86_843E_79B853273DBD__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// PrintConfNoZPLDlg.h : header file
//

#include "ado2.h"

/////////////////////////////////////////////////////////////////////////////
// CPrintConfNoZPLDlg dialog

class CPrintConfNoZPLDlg : public CDialog
{
// Construction
public:
	CPrintConfNoZPLDlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CPrintConfNoZPLDlg)
	enum { IDD = IDD_PRINTNOZPLDLG };
	CEdit	m_ctlPause;
	CString	m_sFromID;
	CString	m_sFromAC;
	CString	m_sToID;
	CString	m_sToAC;
	BOOL	m_bPause;
	int		m_iPauseAgter;
	int		m_iLabelType;
	int		m_iPrintSpeed;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CPrintConfNoZPLDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CPrintConfNoZPLDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnChkpause();
	virtual void OnOK();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
private:
	CADORecordset* m_pRs;
public:
	BOOL PrintNext(HDC hdc, LPDEVMODE pDevMode);
	void SetRecordset(CADORecordset* pRs){m_pRs=pRs;}

	long m_lStart;
	long m_lEnd;
	long m_lCurrent;

};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_PRINTCONFNOZPLDLG_H__867912CE_62BA_4E86_843E_79B853273DBD__INCLUDED_)
