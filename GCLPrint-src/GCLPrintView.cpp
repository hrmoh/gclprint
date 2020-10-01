// GCLPrintView.cpp : implementation of the CGCLPrintView class
//

#include "stdafx.h"
#include "GCLPrint.h"

#include "GCLPrintDoc.h"
#include "GCLPrintView.h"
#include "FindIDDlg.h"
#include "FindADDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

#include "MainFrm.h"

/////////////////////////////////////////////////////////////////////////////
// CGCLPrintView

IMPLEMENT_DYNCREATE(CGCLPrintView, CFormView)

BEGIN_MESSAGE_MAP(CGCLPrintView, CFormView)
	//{{AFX_MSG_MAP(CGCLPrintView)
	ON_WM_SIZE()
	ON_COMMAND(ID_FILE_FINDID, OnFileFindid)
	ON_COMMAND(ID_FILE_FINDAD, OnFileFindad)
	ON_COMMAND(ID_FILE_PRINT, OnFilePrint)
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CFormView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CFormView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CFormView::OnFilePrintPreview)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CGCLPrintView construction/destruction

CGCLPrintView::CGCLPrintView()
	: CFormView(CGCLPrintView::IDD)
{
	//{{AFX_DATA_INIT(CGCLPrintView)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
	m_sLastSearchedID=_T("");
	m_iSearched=0;
	m_bPrev=FALSE;

	m_sLastSearchedAD=_T("");
	m_iSearchedAD=0;
	m_bPrevAD=FALSE;


}

CGCLPrintView::~CGCLPrintView()
{
}

void CGCLPrintView::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CGCLPrintView)
	DDX_Control(pDX, IDC_FLXCUSTOMERS, m_flxCustomers);
	//}}AFX_DATA_MAP
}

BOOL CGCLPrintView::PreCreateWindow(CREATESTRUCT& cs)
{
	return CFormView::PreCreateWindow(cs);
}

void CGCLPrintView::OnInitialUpdate()
{



	CFormView::OnInitialUpdate();
//	ResizeParentToFit();

	CRect rc;
	((CMainFrame*)GetParentFrame())->GetRealyClientRect(rc);
	this->MoveWindow(&rc);
	GetParentFrame()->RecalcLayout();
	
	LoadDB(m_pRs);
}

/////////////////////////////////////////////////////////////////////////////
// CGCLPrintView printing

BOOL CGCLPrintView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CGCLPrintView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
}

void CGCLPrintView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
}

void CGCLPrintView::OnPrint(CDC* pDC, CPrintInfo* /*pInfo*/)
{
}

/////////////////////////////////////////////////////////////////////////////
// CGCLPrintView diagnostics

#ifdef _DEBUG
void CGCLPrintView::AssertValid() const
{
	CFormView::AssertValid();
}

void CGCLPrintView::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}

CGCLPrintDoc* CGCLPrintView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CGCLPrintDoc)));
	return (CGCLPrintDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CGCLPrintView message handlers

void CGCLPrintView::SetProgress(DWORD dwCur, DWORD dwAll)
{
	CMainFrame* pFrame = (CMainFrame*)GetParentFrame();
	pFrame->SetProgress(dwCur, dwAll);
}

void CGCLPrintView::HideProgressBar()
{
	CMainFrame* pFrame = (CMainFrame*)GetParentFrame();
	pFrame->EndProgress();
	m_flxCustomers.ShowWindow(SW_SHOW);
}

void CGCLPrintView::BeginProgress()
{
	m_flxCustomers.ShowWindow(SW_HIDE);
	CMainFrame* pFrame = (CMainFrame*)GetParentFrame();
	pFrame->BeginProgress();	
}

void CGCLPrintView::LoadDB(_RecordsetPtr pRs)
{
	if(pRs->RecordCount)
	{
		if(!m_flxCustomers.IsWindowVisible())
			m_flxCustomers.ShowWindow(SW_SHOW);
		m_flxCustomers.SetRefDataSource(pRs);

		m_flxCustomers.SetColWidth(0, 0, 700);
		m_flxCustomers.SetColWidth(1, 0, 1800);
		m_flxCustomers.SetColWidth(2, 0, 1200);
		m_flxCustomers.SetColWidth(3, 0, 900);	
		m_flxCustomers.SetColWidth(4, 0, 900);
		m_flxCustomers.SetColWidth(5, 0, 1100);
		m_flxCustomers.SetColWidth(6, 0, 1300);
		m_flxCustomers.SetColWidth(7, 0, 3000);
		m_flxCustomers.SetColWidth(8, 0, 5000);
		m_flxCustomers.SetColWidth(9, 0, 1500);
		m_flxCustomers.CollapseAll(0);
	}
	else
		m_flxCustomers.ShowWindow(SW_HIDE);
}

void CGCLPrintView::OnSize(UINT nType, int cx, int cy) 
{
	CFormView::OnSize(nType, cx, cy);
	
	if(m_flxCustomers.m_hWnd)
	{
		RECT rc;
		GetClientRect(&rc);
		m_flxCustomers.MoveWindow(0, 0, rc.right-rc.left, rc.bottom-rc.top);
	}
	
}

void CGCLPrintView::SetRs(_RecordsetPtr pRs)
{
	m_pRs=pRs;
}

BEGIN_EVENTSINK_MAP(CGCLPrintView, CFormView)
    //{{AFX_EVENTSINK_MAP(CGCLPrintView)
	ON_EVENT(CGCLPrintView, IDC_FLXCUSTOMERS, -607 /* MouseUp */, OnMouseUpFlxcustomers, VTS_I2 VTS_I2 VTS_I4 VTS_I4)
	ON_EVENT(CGCLPrintView, IDC_FLXCUSTOMERS, 69 /* SelChange */, OnSelChangeFlxcustomers, VTS_NONE)
	ON_EVENT(CGCLPrintView, IDC_FLXCUSTOMERS, -601 /* DblClick */, OnDblClickFlxcustomers, VTS_NONE)
	//}}AFX_EVENTSINK_MAP
END_EVENTSINK_MAP()






void CGCLPrintView::OnMouseUpFlxcustomers(short Button, short Shift, long x, long y) 
{
	if( Button == MK_RBUTTON)
	{
		m_flxCustomers.SetRowSel(m_flxCustomers.GetMouseRow());
		CMenu mMenu;
		mMenu.LoadMenu(IDR_GRIDMENU); 
		CMenu* tRacker;
		CPoint point(x, y);
		ClientToScreen(&point); 
		tRacker=mMenu.GetSubMenu(0);
		tRacker->TrackPopupMenu(TPM_LEFTALIGN | TPM_LEFTBUTTON | TPM_RIGHTBUTTON, point.x , point.y , AfxGetMainWnd()); 
	}
}


void CGCLPrintView::OnSelChangeFlxcustomers() 
{
	long l=m_flxCustomers.GetTopRow();
	GetDocument()->GoTo(m_flxCustomers.GetRow());	
}


void CGCLPrintView::OnFileFindid() 
{


	CFindIDDlg fIDDlg;
	fIDDlg.SetID(m_sLastSearchedID);
	fIDDlg.m_bPrev=m_bPrev;
	if(fIDDlg.DoModal()==IDOK)
	{
		if(m_sLastSearchedID == fIDDlg.m_sID)
		{
			if(fIDDlg.m_bPrev)
			{
				if(m_iSearched>0)
					m_iSearched--;
			}
			else
				m_iSearched++;
		}
		else
			m_iSearched=0;
		long iIndex=GetDocument()->FindID(fIDDlg.m_sID, m_iSearched);
		if(iIndex<0)
			MessageBox("íÇÝÊ äÔÏ");
		else
			m_flxCustomers.SetTopRow(iIndex);
	}
	m_sLastSearchedID=fIDDlg.m_sID;
	m_bPrev=fIDDlg.m_bPrev;

}

void CGCLPrintView::OnFileFindad() 
{

	CFindADDlg fIDDlg;
	fIDDlg.SetID(m_sLastSearchedAD);
	fIDDlg.m_bPrev=m_bPrev;
	if(fIDDlg.DoModal()==IDOK)
	{
		if(m_sLastSearchedAD == fIDDlg.m_sID)
		{
			if(fIDDlg.m_bPrev)
			{
				if(m_iSearched>0)
					m_iSearched--;
			}
			else
				m_iSearched++;
		}
		else
			m_iSearched=0;
		long iIndex=GetDocument()->FindAD(fIDDlg.m_sID, m_iSearched);
		if(iIndex<0)
			MessageBox("íÇÝÊ äÔÏ");
		else
			m_flxCustomers.SetTopRow(iIndex);
	}
	m_sLastSearchedAD=fIDDlg.m_sID;
	m_bPrev=fIDDlg.m_bPrev;


}

void CGCLPrintView::OnDblClickFlxcustomers() 
{
//	GetDocument()->ShowCurrent();
}

void CGCLPrintView::OnFilePrint() 
{
	GetDocument()->HandlePrint();	
}


