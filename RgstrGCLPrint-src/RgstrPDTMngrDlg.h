// RgstrPDTMngrDlg.h : header file
//

#if !defined(AFX_RGSTRPDTMNGRDLG_H__4CCA7756_37D7_420C_931C_A4A49BF7D018__INCLUDED_)
#define AFX_RGSTRPDTMNGRDLG_H__4CCA7756_37D7_420C_931C_A4A49BF7D018__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


#include "Register.h"


/////////////////////////////////////////////////////////////////////////////
// CRgstrPDTMngrDlg dialog

class CRgstrPDTMngrDlg : public CDialog
{
// Construction
public:
	CRgstrPDTMngrDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CRgstrPDTMngrDlg)
	enum { IDD = IDD_RGSTRPDTMNGR_DIALOG };
	CString	m_sHardwareKey;
	CString	m_sActivationCode;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CRgstrPDTMngrDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CRgstrPDTMngrDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnBchange();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()

private:
	CRegister* reg;

};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_RGSTRPDTMNGRDLG_H__4CCA7756_37D7_420C_931C_A4A49BF7D018__INCLUDED_)
