#if !defined(AFX_PATHSDLG_H__16C30873_9C82_45C7_AFBE_F2CEAAA82CF7__INCLUDED_)
#define AFX_PATHSDLG_H__16C30873_9C82_45C7_AFBE_F2CEAAA82CF7__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// PathsDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CPathsDlg dialog

class CPathsDlg : public CDialog
{
// Construction
public:
	CPathsDlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CPathsDlg)
	enum { IDD = IDD_PATHS };
	CString	m_strMDB;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CPathsDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CPathsDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnChange();
	virtual void OnOK();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
private:
	BOOL m_bChanged;
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_PATHSDLG_H__16C30873_9C82_45C7_AFBE_F2CEAAA82CF7__INCLUDED_)
