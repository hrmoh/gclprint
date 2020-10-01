#if !defined(AFX_RECODSETPRINTERVIEW_H__2CBE2655_F28A_4368_9732_97890A5A70CA__INCLUDED_)
#define AFX_RECODSETPRINTERVIEW_H__2CBE2655_F28A_4368_9732_97890A5A70CA__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// RecodsetPrinterView.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CRecodsetPrinterView view

#include "ADORecordsetPrinter.h"

class CRecodsetPrinterView : public CView
{
protected:
	CRecodsetPrinterView();           // protected constructor used by dynamic creation
	DECLARE_DYNCREATE(CRecodsetPrinterView)

// Attributes
public:

// Operations
public:
	virtual void OnFilePrintPreview();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CRecodsetPrinterView)
	protected:
	virtual void OnDraw(CDC* pDC);      // overridden to draw this view
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnPrint(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrintPreview(CDC* pDC, CPrintInfo* pInfo, POINT point, CPreviewView* pView);
	//}}AFX_VIRTUAL

public:


	void SetRecordsetPrinter(CADORecordsetPrinter* pRecordsetPrinter){m_pRecordsetPrinter=pRecordsetPrinter; m_pRecordsetPrinter->SetParent((CWnd*)this);}
	void SetOldFrameWnd(CFrameWnd* pOldFrame){m_pOldFrame=pOldFrame;}
// Implementation
protected:
	virtual ~CRecodsetPrinterView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

	// Generated message map functions
protected:
	//{{AFX_MSG(CRecodsetPrinterView)
		// NOTE - the ClassWizard will add and remove member functions here.
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
private:
	CADORecordsetPrinter* m_pRecordsetPrinter;
	CFrameWnd *m_pOldFrame;
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_RECODSETPRINTERVIEW_H__2CBE2655_F28A_4368_9732_97890A5A70CA__INCLUDED_)
