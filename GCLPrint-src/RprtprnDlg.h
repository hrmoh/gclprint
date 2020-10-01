#if !defined(AFX_RPRTPRNDLG_H__F260F50B_AA40_4FF4_B6DF_8AD3981F5F47__INCLUDED_)
#define AFX_RPRTPRNDLG_H__F260F50B_AA40_4FF4_B6DF_8AD3981F5F47__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// RprtprnDlg.h : header file
//

#include "ADORecordsetPrinter.h"

/////////////////////////////////////////////////////////////////////////////
// CRprtprnDlg dialog

class CRprtprnDlg : public CDialog
{
// Construction
public:
	CRprtprnDlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CRprtprnDlg)
	enum { IDD = IDD_PRINTREPDLG };
	CString	m_sTitle;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CRprtprnDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CRprtprnDlg)
	afx_msg void OnFilePrint();
	afx_msg void OnFilePrintPreview();
	afx_msg void OnPerformanceExit();
	virtual BOOL OnInitDialog();
	afx_msg BOOL OnEraseBkgnd(CDC* pDC);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
public:
	void HandlePrint();
	BOOL m_bIsWorking;
	void SetNextFieldWidth(int iWidth);
	void ResetFieldWidths();
	void SetTitle(CString sTitle);
	void SetRecordset(CADORecordset* pRs){	m_RSPrntr.SetRecordet(pRs);}
private:
	CADORecordsetPrinter m_RSPrntr;
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_RPRTPRNDLG_H__F260F50B_AA40_4FF4_B6DF_8AD3981F5F47__INCLUDED_)
