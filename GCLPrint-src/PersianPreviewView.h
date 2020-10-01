// PersianPreviewView.h: Schnittstelle für die Klasse CPersianPreviewView.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_PERSIANPREVIEWVIEW_H__98D22C01_14DD_4C23_8623_4BA786C8D28F__INCLUDED_)
#define AFX_PERSIANPREVIEWVIEW_H__98D22C01_14DD_4C23_8623_4BA786C8D28F__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include <afxpriv.h>

class CPersianPreviewView : public CPreviewView  
{
public:
	DECLARE_DYNCREATE(CPersianPreviewView)
	CPersianPreviewView();
	virtual ~CPersianPreviewView();

	void OnActivateView( BOOL bActivate, CView* pActivateView, CView* pDeactiveView );

// Generierte Message-Map-Funktionen
protected:
	//{{AFX_MSG(CPersianPreviewView)
	afx_msg void OnUpdateNumPageChange(CCmdUI* pCmdUI);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#endif // !defined(AFX_PERSIANPREVIEWVIEW_H__98D22C01_14DD_4C23_8623_4BA786C8D28F__INCLUDED_)
