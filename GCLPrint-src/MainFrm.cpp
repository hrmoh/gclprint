// MainFrm.cpp : implementation of the CMainFrame class
//

#include "stdafx.h"
#include "GCLPrint.h"

#include "MainFrm.h"

#include "GCLPrintDoc.h"

#include "Splash.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

#include <afxpriv.h>

extern CGCLPrintApp theApp;

/////////////////////////////////////////////////////////////////////////////
// CMainFrame

IMPLEMENT_DYNCREATE(CMainFrame, CFrameWnd)

BEGIN_MESSAGE_MAP(CMainFrame, CFrameWnd)
	//{{AFX_MSG_MAP(CMainFrame)
	ON_WM_CREATE()
	ON_WM_SIZE()
	ON_MESSAGE(WM_SETMESSAGESTRING, OnSetMessageString)
	ON_COMMAND(ID_SEL_START, OnSelStart)
	ON_UPDATE_COMMAND_UI(ID_SEL_START, OnUpdateSelStart)
	ON_COMMAND(ID_SEL_END, OnSelEnd)
	ON_UPDATE_COMMAND_UI(ID_SEL_END, OnUpdateSelEnd)
	ON_COMMAND(ID_PRINT_CURRENTITEM, OnPrintCurrentitem)
	ON_WM_MOVE()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

static UINT indicators[] =
{
	ID_SEPARATOR,           // status line indicator	
	ID_INDICATOR_PROGRESS_PANE,
//	ID_INDICATOR_CAPS,
//	ID_INDICATOR_NUM,
//	ID_INDICATOR_SCRL,
};

/////////////////////////////////////////////////////////////////////////////
// CMainFrame construction/destruction

CMainFrame::CMainFrame()
{
	m_bCreated = FALSE;
	m_bStartChecked = FALSE;
	m_bEndChecked = FALSE;
}

CMainFrame::~CMainFrame()
{
}

int CMainFrame::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CFrameWnd::OnCreate(lpCreateStruct) == -1)
		return -1;
	
	if (!m_wndToolBar.CreateEx(this, TBSTYLE_FLAT, WS_CHILD | WS_VISIBLE | CBRS_TOP
		| CBRS_TOOLTIPS | CBRS_FLYBY | CBRS_SIZE_DYNAMIC) ||
		!m_wndToolBar.LoadToolBar(IDR_MAINFRAME))
	{
		TRACE0("Failed to create toolbar\n");
		return -1;      // fail to create
	}
	m_wndToolBar.SetButtonStyle(m_wndToolBar.CommandToIndex(ID_SEL_START), TBSTYLE_CHECK);
	m_wndToolBar.SetButtonStyle(m_wndToolBar.CommandToIndex(ID_SEL_END), TBSTYLE_CHECK);
//	 m_wndToolBar.ModifyStyleEx(WS_EX_LEFT, WS_EX_RIGHT);
//	 m_wndToolBar.ModifyStyleEx(WS_EX_LTRREADING, WS_EX_RTLREADING);

/*
     if (!m_wndNavBar.CreateEx(this, TBSTYLE_FLAT, WS_CHILD | WS_VISIBLE | CBRS_TOP
          | CBRS_GRIPPER | CBRS_TOOLTIPS | CBRS_FLYBY | CBRS_SIZE_DYNAMIC) ||
          !m_wndNavBar.LoadToolBar(IDR_NAVBAR))
      {
         TRACE0("Failed to create toolbar\n");
        return FALSE;      // fail to create
     }

     int nWidth = 200;
     int nHeight = 125;

	 CFont font;
	VERIFY(font.CreateFont(
			12,                        // nHeight
			0,                         // nWidth
			0,                         // nEscapement
			0,                         // nOrientation
			FW_NORMAL,                 // nWeight
			FALSE,                     // bItalic
			FALSE,                     // bUnderline
			0,                         // cStrikeOut
			DEFAULT_CHARSET,              // nCharSet
			OUT_DEFAULT_PRECIS,        // nOutPrecision
			CLIP_DEFAULT_PRECIS,       // nClipPrecision
			DEFAULT_QUALITY,           // nQuality
			DEFAULT_PITCH | FF_DONTCARE,  // nPitchAndFamily
			"Tahoma"));                 // lpszFacename


	 //m_wndNavBar.SetFont(&font);
 
	 m_wndNavBar.SetButtonInfo(4, IDC_ESEARCH, TBBS_SEPARATOR, nWidth);
 
     CRect rect;
     m_wndNavBar.GetItemRect(4, &rect);	 
     rect.bottom = rect.top + nHeight;
 
	 m_ctlSearchBox.Create(WS_CHILD | WS_VISIBLE | CBS_DROPDOWN , rect, &m_wndNavBar, IDC_ESEARCH);
	 m_ctlSearchBox.ModifyStyleEx(WS_EX_LEFT, WS_EX_RIGHT);
	 m_ctlSearchBox.ModifyStyleEx(WS_EX_LTRREADING, WS_EX_RTLREADING);
	 m_ctlSearchBox.SetFont(&font);
*/

	if (!m_wndStatusBar.Create(this) ||
		!m_wndStatusBar.SetIndicators(indicators,
		  sizeof(indicators)/sizeof(UINT)))
	{
		TRACE0("Failed to create status bar\n");
		return -1;      // fail to create
	}

	m_wndToolBar.EnableDocking(CBRS_ALIGN_ANY);
//	m_wndNavBar.EnableDocking(CBRS_ALIGN_ANY);
	m_wndStatusBar.ModifyStyleEx(WS_EX_LTRREADING, WS_EX_RTLREADING, 0);
	EnableDocking(CBRS_ALIGN_ANY);
	DockControlBar(&m_wndToolBar);
//	DockControlBar(&m_wndNavBar);

	m_bCreated = FALSE;

	BOOL bMaximized=FALSE;
	if(theApp.GetProfileInt("Settings", "Maximized", 0)==1)
		bMaximized=TRUE;


	CRect rc;

	rc.left=theApp.GetProfileInt("Settings", "x1Win", 100);
	rc.top=theApp.GetProfileInt("Settings", "y1Win", 100);
	rc.right=theApp.GetProfileInt("Settings", "x2Win", 500);
	rc.bottom=theApp.GetProfileInt("Settings", "y2Win", 400);

	MoveWindow(&rc, FALSE);

	if(bMaximized)
		ShowWindow(SW_MAXIMIZE);

	// CG: The following line was added by the Splash Screen component.
	if(theApp.GetProfileInt("Settings", "Show Splash", 0)==1)
		CSplashWnd::ShowSplashScreen(this);
	return 0;
}

BOOL CMainFrame::PreCreateWindow(CREATESTRUCT& cs)
{
	cs.style &= ~(LONG) FWS_ADDTOTITLE;
	cs.dwExStyle|=WS_EX_RIGHT;	
	if( !CFrameWnd::PreCreateWindow(cs) )
		return FALSE;
	return TRUE;
}

/////////////////////////////////////////////////////////////////////////////
// CMainFrame diagnostics

#ifdef _DEBUG
void CMainFrame::AssertValid() const
{
	CFrameWnd::AssertValid();
}

void CMainFrame::Dump(CDumpContext& dc) const
{
	CFrameWnd::Dump(dc);
}

#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CMainFrame message handlers


void CMainFrame::OnSomeLongProgess()
{
	RECT MyRect;
	m_wndStatusBar.GetItemRect(1, &MyRect);
	if(m_bCreated == FALSE)
	{
		m_ctlProgress.Create(WS_VISIBLE|WS_CHILD, MyRect, &m_wndStatusBar, ID_INDICATOR_PROGRESS_PANE);
		m_ctlProgress.ModifyStyleEx(0, WS_EX_RIGHT, 0);
		m_ctlProgress.SetRange(0, 100);
		m_ctlProgress.SetStep(1);
		m_bCreated=TRUE;
	}
	for(int i=0; i<100; i++)
	{
		Sleep(20);
		m_ctlProgress.StepIt();
	}
}

void CMainFrame::OnSize(UINT nType, int cx, int cy) 
{
	CFrameWnd::OnSize(nType, cx, cy);

	if(m_bCreated)
	{
		RECT rc;
		m_wndStatusBar.GetItemRect(1, &rc);
		m_ctlProgress.SetWindowPos(&wndTop, rc.left, rc.top, rc.right-rc.left, rc.bottom-rc.top, 0);
	}

	if(m_wndToolBar)
	{
		RECT rc,rect;
		m_wndToolBar.GetClientRect(&rc);
		GetWindowRect(&rect);

		if(nType==SIZE_MAXIMIZED)
			theApp.WriteProfileInt("Settings", "Maximized", 1);
		else
		{
			theApp.WriteProfileInt("Settings", "Maximized", 0);
			if(nType==SIZE_RESTORED)
			{
				theApp.WriteProfileInt("Settings", "x1Win", rect.left);
				theApp.WriteProfileInt("Settings", "y1Win", rect.top);
				theApp.WriteProfileInt("Settings", "x2Win", rect.right);
				theApp.WriteProfileInt("Settings", "y2Win", rect.bottom);
			}
		}
		rc.left=rect.right-(rc.right-rc.left);
		rc.right=rect.right;
		m_wndToolBar.MoveWindow(&rc);
		RecalcLayout();
	}
}

void CMainFrame::SetProgress(DWORD dwCur, DWORD dwAll)
{
		m_ctlProgress.StepIt();
}


//*************************************************************************
// OnSetMessageString
//*************************************************************************
LRESULT CMainFrame::OnSetMessageString(WPARAM wParam, LPARAM lParam)
{
	UINT nIDLast = m_nIDLastMessage;
	m_nFlags &= ~WF_NOPOPMSG;

	CWnd* pMessageBar = GetMessageBar();
	if (pMessageBar != NULL)
	{
		CString sMsg;
		CString strMessage;

		// set the message bar text
		if (lParam != 0)
		{
			ASSERT(wParam == 0);    // can't have both an ID and a string
            			m_sStatusBarString = (LPCTSTR)lParam;
            			sMsg = m_sStatusBarString;
		}
		else if (wParam != 0)
		{
			// map SC_CLOSE to PREVIEW_CLOSE when in print preview mode
			if (wParam == AFX_IDS_SCCLOSE && m_lpfnCloseProc != NULL)
				wParam = AFX_IDS_PREVIEW_CLOSE;

			// get message associated with the ID indicated by wParam
            			if (wParam == AFX_IDS_IDLEMESSAGE)
                				sMsg = m_sStatusBarString;
else
{
	GetMessageString(wParam, strMessage);
	sMsg = strMessage;
}
		}
		if(sMsg=="")
			pMessageBar->SetWindowText("ÂãÇÏå");
		else
		pMessageBar->SetWindowText(sMsg);

		// update owner of the bar in terms of last message selected
		CFrameWnd* pFrameWnd = pMessageBar->GetParentFrame();
		if (pFrameWnd != NULL)
		{
			m_nIDLastMessage = (UINT)wParam;
			m_nIDTracking = (UINT)wParam;
		}
	}

	m_nIDLastMessage = (UINT)wParam;    	// new ID (or 0)
	m_nIDTracking = (UINT)wParam;       	// so F1 on toolbar buttons work

	return nIDLast;
}



//*************************************************************************
// StatusBarMessage
//*************************************************************************
void CMainFrame::StatusBarMessage(TCHAR * fmt,...)
{
	TCHAR buffer[256]= _T("");

	CStatusBar* pStatus = (CStatusBar*) 
		GetDescendantWindow(AFX_IDW_STATUS_BAR);

	va_list argptr;
	va_start(argptr, fmt);
	_vstprintf(buffer, fmt, argptr);
	va_end(argptr);

   	m_sStatusBarString = buffer;

    	SetMessageText((LPCTSTR)m_sStatusBarString);
    	return;
}


void CMainFrame::EndProgress()
{
		CString sReplacementText = "ÂãÇÏå";
		((CMainFrame*)AfxGetMainWnd())->StatusBarMessage(sReplacementText.GetBuffer(0)); 
		m_ctlProgress.SetPos(0);
}

void CMainFrame::BeginProgress()
{
	RECT MyRect;
	m_wndStatusBar.GetItemRect(1, &MyRect);
	if(m_bCreated == FALSE)
	{
		m_ctlProgress.Create(WS_VISIBLE|WS_CHILD|PBS_SMOOTH, MyRect, &m_wndStatusBar, ID_INDICATOR_PROGRESS_PANE);
		m_ctlProgress.SetRange32(0, 100);
		m_ctlProgress.SetStep(1);
		m_bCreated=TRUE;

	}

	CString sReplacementText = "ÈÇÒÎæÇäí áíÓÊ ÓÝíÏ : áØÝÇ ÕÈÑ ˜äíÏ";
	((CMainFrame*)AfxGetMainWnd())->StatusBarMessage(sReplacementText.GetBuffer(0)); 
}

void CMainFrame::OnSelStart() 
{
	m_bStartChecked=!m_bStartChecked;
	((CGCLPrintDoc*)GetActiveDocument())->CheckCurrentAsStart(m_bStartChecked);
}

void CMainFrame::OnUpdateSelStart(CCmdUI* pCmdUI) 
{
	pCmdUI->SetCheck(m_bStartChecked);	
}


void CMainFrame::OnSelEnd() 
{
	m_bEndChecked=!m_bEndChecked;
	((CGCLPrintDoc*)GetActiveDocument())->CheckCurrentAsEnd(m_bEndChecked);
}

void CMainFrame::OnUpdateSelEnd(CCmdUI* pCmdUI) 
{
	pCmdUI->SetCheck(m_bEndChecked);	
}

void CMainFrame::GetRealyClientRect(CRect &rc)
{
	GetClientRect(&rc);
	if(m_wndToolBar.IsVisible())
	{
		CRect rc1;
		m_wndToolBar.GetWindowRect(&rc1);
		rc.top=rc.top-(rc1.top-rc1.bottom);
	}
	if(m_wndStatusBar.IsVisible())
	{
		CRect rc1;
		m_wndStatusBar.GetWindowRect(&rc1);
		rc.bottom=rc.bottom-(rc1.top-rc1.bottom);
	}
}


void CMainFrame::OnPrintCurrentitem() 
{
	// TODO: Add your command handler code here
	((CGCLPrintDoc*)GetActiveDocument())->CheckForPrint();		
}

void CMainFrame::OnMove(int x, int y) 
{
	CFrameWnd::OnMove(x, y);
	
	RECT rect;
	GetWindowRect(&rect);

	theApp.WriteProfileInt("Settings", "x1Win", rect.left);
	theApp.WriteProfileInt("Settings", "y1Win", rect.top);
	theApp.WriteProfileInt("Settings", "x2Win", rect.right);
	theApp.WriteProfileInt("Settings", "y2Win", rect.bottom);
	
}


