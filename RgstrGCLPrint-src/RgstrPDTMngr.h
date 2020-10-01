// RgstrPDTMngr.h : main header file for the RGSTRPDTMNGR application
//

#if !defined(AFX_RGSTRPDTMNGR_H__757D7792_0AB2_477A_8619_A3A28FA21A44__INCLUDED_)
#define AFX_RGSTRPDTMNGR_H__757D7792_0AB2_477A_8619_A3A28FA21A44__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CRgstrPDTMngrApp:
// See RgstrPDTMngr.cpp for the implementation of this class
//

class CRgstrPDTMngrApp : public CWinApp
{
public:
	CRgstrPDTMngrApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CRgstrPDTMngrApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CRgstrPDTMngrApp)
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_RGSTRPDTMNGR_H__757D7792_0AB2_477A_8619_A3A28FA21A44__INCLUDED_)
