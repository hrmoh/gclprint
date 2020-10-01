// GCLPrint.h : main header file for the GCLPRINT application
//

#if !defined(AFX_GCLPRINT_H__1F6A6A80_BC82_446C_BD8B_9B8FF9D428AE__INCLUDED_)
#define AFX_GCLPRINT_H__1F6A6A80_BC82_446C_BD8B_9B8FF9D428AE__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CGCLPrintApp:
// See GCLPrint.cpp for the implementation of this class
//

class CGCLPrintApp : public CWinApp
{
public:
	BOOL VerifySoftwareKey();
	virtual BOOL PreTranslateMessage(MSG* pMsg);
	CGCLPrintApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CGCLPrintApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation
	//{{AFX_MSG(CGCLPrintApp)
	afx_msg void OnAppAbout();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_GCLPRINT_H__1F6A6A80_BC82_446C_BD8B_9B8FF9D428AE__INCLUDED_)
