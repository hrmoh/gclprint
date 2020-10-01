// LangPreviewView.cpp: Implementierung der Klasse CPersianPreviewView.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "stdafx.h"
#include "PersianPreviewView.h"
//#include "Dic.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

#if !defined(WS_EX_LAYOUT_RTL)
#define WS_EX_LAYOUT_RTL 0x00400000L
#endif

//////////////////////////////////////////////////////////////////////
// Konstruktion/Destruktion
//////////////////////////////////////////////////////////////////////

IMPLEMENT_DYNCREATE(CPersianPreviewView, CPreviewView)

BEGIN_MESSAGE_MAP(CPersianPreviewView, CPreviewView)
	//{{AFX_MSG_MAP(CPersianPreviewView)
	ON_UPDATE_COMMAND_UI(AFX_ID_PREVIEW_NUMPAGE, OnUpdateNumPageChange)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

CPersianPreviewView::CPersianPreviewView()
{
}

CPersianPreviewView::~CPersianPreviewView()
{

}

void CPersianPreviewView::OnActivateView(BOOL bActivate, CView*, CView*)
{
	if (bActivate)
	{
		if (m_pToolBar) {
			//m_pToolBar->ModifyStyleEx(0, WS_EX_LAYOUT_RTL, SWP_ASYNCWINDOWPOS);
			m_pToolBar->ModifyStyleEx(0, WS_EX_RTLREADING, 0);
			m_pToolBar->ModifyStyleEx(0, WS_EX_RIGHT, 0);
			m_pToolBar->ModifyStyleEx(0, WS_EX_CLIENTEDGE, 0);

			m_pToolBar->GetDlgItem(AFX_ID_PREVIEW_PRINT)  ->SetWindowText( _T("Ç ..."));
			m_pToolBar->GetDlgItem(AFX_ID_PREVIEW_NEXT)   ->SetWindowText( _T("ÕİÍå ÈÚÏ"));
			m_pToolBar->GetDlgItem(AFX_ID_PREVIEW_PREV)   ->SetWindowText( _T("ÕİÍå ŞÈá"));
//			m_pToolBar->GetDlgItem(AFX_ID_PREVIEW_NUMPAGE)->SetWindowText( _T(""));
			m_pToolBar->GetDlgItem(AFX_ID_PREVIEW_ZOOMIN) ->SetWindowText( _T("äÒÏí˜ ÊÑ"));
			m_pToolBar->GetDlgItem(AFX_ID_PREVIEW_ZOOMOUT)->SetWindowText( _T("ÏæÑÊÑ"));
			m_pToolBar->GetDlgItem(AFX_ID_PREVIEW_CLOSE)  ->SetWindowText( _T("ÎÑæÌ"));
		}
	}

}

void CPersianPreviewView::OnUpdateNumPageChange(CCmdUI* pCmdUI)
{
	CPreviewView::OnUpdateNumPageChange(pCmdUI);

	UINT nPages = (m_nZoomState == ZOOM_OUT ? m_nPages : m_nZoomOutPages);
	if (nPages == 1)
		pCmdUI->SetText(_T("Ïæ ÕİÍå Çí"));
	else
		pCmdUI->SetText(_T("Ê˜ ÕİÍå Çí"));
}
