#if !defined(AFX_FINDADDLG_H__2E02CA45_8F61_4F49_B6AC_7BB2D876AAA7__INCLUDED_)
#define AFX_FINDADDLG_H__2E02CA45_8F61_4F49_B6AC_7BB2D876AAA7__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// FindADDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CFindADDlg dialog

class CFindADDlg : public CDialog
{
// Construction
public:
	CFindADDlg(CWnd* pParent = NULL);   // standard constructor
	void SetID(CString sID);
// Dialog Data
	//{{AFX_DATA(CFindADDlg)
	enum { IDD = IDD_FINDAD };
	CString	m_sID;
	BOOL	m_bPrev;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CFindADDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CFindADDlg)
	virtual BOOL OnInitDialog();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_FINDADDLG_H__2E02CA45_8F61_4F49_B6AC_7BB2D876AAA7__INCLUDED_)
