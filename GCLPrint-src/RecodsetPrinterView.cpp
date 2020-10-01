// RecodsetPrinterView.cpp : implementation file
//

#include "stdafx.h"
#include "GCLPrint.h"
#include "RecodsetPrinterView.h"
#include "PersianPreviewView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CRecodsetPrinterView

IMPLEMENT_DYNCREATE(CRecodsetPrinterView, CView)

CRecodsetPrinterView::CRecodsetPrinterView()
{
}

CRecodsetPrinterView::~CRecodsetPrinterView()
{
}


BEGIN_MESSAGE_MAP(CRecodsetPrinterView, CView)
	//{{AFX_MSG_MAP(CRecodsetPrinterView)
		// NOTE - the ClassWizard will add and remove mapping macros here.
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CRecodsetPrinterView drawing

void CRecodsetPrinterView::OnDraw(CDC* pDC)
{
	CDocument* pDoc = GetDocument();
	// TODO: add draw code here
}

/////////////////////////////////////////////////////////////////////////////
// CRecodsetPrinterView diagnostics

#ifdef _DEBUG
void CRecodsetPrinterView::AssertValid() const
{
	CView::AssertValid();
}

void CRecodsetPrinterView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CRecodsetPrinterView message handlers

void CRecodsetPrinterView::OnFilePrintPreview()
{
  // In derived classes, implement special window handling here.
  // Be sure to Unhook Frame Window close if hooked.
  // Must not create this on the frame. Must outlive this function.

  CPrintPreviewState* pState = new CPrintPreviewState;

  // DoPrintPreview's return value does not necessarily indicate that
  // Print Preview succeeded or failed, but rather what actions are
  // necessary at this point. If DoPrintPreview returns TRUE, it means
  // that OnEndPrintPreview will be (or has already been) called and
  // the pState structure will be/has been deleted.
  // If DoPrintPreview returns FALSE, it means that OnEndPrintPreview
  // WILL NOT be called and that cleanup, including deleting pState,
  // must be done here.

  if (!DoPrintPreview(AFX_IDD_PREVIEW_TOOLBAR, this,
     RUNTIME_CLASS(CPersianPreviewView), pState))
  {
     // In derived classes, reverse special window handling here for
     // Preview failure case.

     TRACE0("Error: DoPrintPreview failed.\n");
     AfxMessageBox(AFX_IDP_COMMAND_FAILURE);
     delete pState; // Preview failed to initialize, delete State now.
  }

//	CView::OnFilePrintPreview();
}

BOOL CRecodsetPrinterView::OnPreparePrinting(CPrintInfo* pInfo) 
{
	return DoPreparePrinting(pInfo);
}

void CRecodsetPrinterView::OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo) 
{
	// TODO: Add your specialized code here and/or call the base class
	
	//CView::OnBeginPrinting(pDC, pInfo);
	m_pRecordsetPrinter->OnBeginPrinting(pDC, pInfo);
}

void CRecodsetPrinterView::OnEndPrinting(CDC* pDC, CPrintInfo* pInfo) 
{
	// TODO: Add your specialized code here and/or call the base class
	
	//CView::OnEndPrinting(pDC, pInfo);
	m_pRecordsetPrinter->OnEndPrinting(pDC, pInfo);
}

void CRecodsetPrinterView::OnPrint(CDC* pDC, CPrintInfo* pInfo) 
{
	// TODO: Add your specialized code here and/or call the base class
	
	//CView::OnPrint(pDC, pInfo);
	m_pRecordsetPrinter->OnPrint(pDC, pInfo);
}

void CRecodsetPrinterView::OnEndPrintPreview(CDC* pDC, CPrintInfo* pInfo, POINT point, CPreviewView* pView) 
{
	CView::OnEndPrintPreview(pDC, pInfo, point, pView);

	m_pOldFrame->ShowWindow(SW_SHOW);
	AfxGetApp()->m_pMainWnd=m_pOldFrame;
	m_pRecordsetPrinter->EndPrintPreview();
	GetParentFrame()->DestroyWindow();

}

