#if !defined(AFX_PRINTCONFDLG_H__7B3A319B_3FC4_4EB9_9197_6D42E3A43AAE__INCLUDED_)
#define AFX_PRINTCONFDLG_H__7B3A319B_3FC4_4EB9_9197_6D42E3A43AAE__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// PrintConfDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CPrintConfDlg dialog

class CPrintConfDlg : public CDialog
{
// Construction
public:
	CPrintConfDlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CPrintConfDlg)
	enum { IDD = IDD_PRINTDLG };
	CSliderCtrl	m_ctlSlider;
	CEdit	m_ctlPause;
	CString	m_sFromID;
	CString	m_sFromAC;
	CString	m_sToAC;
	CString	m_sToID;
	int		m_iPauseAgter;
	int		m_iWhichPort;
	BOOL	m_bPause;
	int		m_iLabelType;
	int		m_iDarkness;
	int		m_iPrintSpeed;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CPrintConfDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CPrintConfDlg)
	afx_msg void OnChkPause();
	virtual BOOL OnInitDialog();
	virtual void OnOK();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_PRINTCONFDLG_H__7B3A319B_3FC4_4EB9_9197_6D42E3A43AAE__INCLUDED_)
