#if !defined(AFX_GENIDSDLG_H__0CE21B37_B737_4815_B6BE_C9ED4E14383D__INCLUDED_)
#define AFX_GENIDSDLG_H__0CE21B37_B737_4815_B6BE_C9ED4E14383D__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// GenIDsDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CGenIDsDlg dialog

class CGenIDsDlg : public CDialog
{
// Construction
public:
	CGenIDsDlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CGenIDsDlg)
	enum { IDD = IDD_GENIDS };
	CString	m_sFrom;
	CString	m_sTo;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CGenIDsDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CGenIDsDlg)
	virtual void OnOK();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_GENIDSDLG_H__0CE21B37_B737_4815_B6BE_C9ED4E14383D__INCLUDED_)
