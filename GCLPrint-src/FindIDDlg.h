#if !defined(AFX_FINDIDDLG_H__C954B98B_F391_4869_9EF0_2E6A4C89A6C5__INCLUDED_)
#define AFX_FINDIDDLG_H__C954B98B_F391_4869_9EF0_2E6A4C89A6C5__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// FindIDDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CFindIDDlg dialog

class CFindIDDlg : public CDialog
{
// Construction
public:
	CFindIDDlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CFindIDDlg)
	enum { IDD = IDD_FINDID };
	CString	m_sID;
	BOOL	m_bPrev;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CFindIDDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CFindIDDlg)
	virtual BOOL OnInitDialog();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
public:
	void SetID(CString sID);
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_FINDIDDLG_H__C954B98B_F391_4869_9EF0_2E6A4C89A6C5__INCLUDED_)
