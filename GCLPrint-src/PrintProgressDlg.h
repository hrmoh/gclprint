#if !defined(AFX_PRINTPROGRESSDLG_H__E9AB2872_DE00_4347_9773_6A4F4EA95AB0__INCLUDED_)
#define AFX_PRINTPROGRESSDLG_H__E9AB2872_DE00_4347_9773_6A4F4EA95AB0__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// PrintProgressDlg.h : header file
//

#include "ado2.h"
#include "ZplParser.h"
/////////////////////////////////////////////////////////////////////////////
// CPrintProgressDlg dialog

class CPrintProgressDlg : public CDialog
{
// Construction
public:
	BOOL PrintNext();
	HANDLE m_hComm;
	int m_iLabelType;
	long m_lStart;
	long m_lEnd;
	long m_lCurrent;
	BOOL m_bPauseAfter;
	long m_iPrinted;
	int m_iPauseAfter;
	void SetRecordset(CADORecordset* pRs);
	CPrintProgressDlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CPrintProgressDlg)
	enum { IDD = IDD_PRINTPROGRESSDLG };
	CButton	m_btnBack;
	CSliderCtrl	m_ctlSpeedSlider;
	CButton	m_btnPause;
	CProgressCtrl	m_ctlProgressBar;
	CString	m_sNowPrinting;
	int		m_iSpeed;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CPrintProgressDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CPrintProgressDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnTimer(UINT nIDEvent);
	virtual void OnCancel();
	afx_msg void OnPause();
	afx_msg void OnReleasedcaptureSpeedslider(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnBack();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
private:
	BOOL m_bPauseForNow;
	CADORecordset* m_pRs;
	CZplParser zplParser;
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_PRINTPROGRESSDLG_H__E9AB2872_DE00_4347_9773_6A4F4EA95AB0__INCLUDED_)
