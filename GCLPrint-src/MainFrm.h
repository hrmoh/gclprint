// MainFrm.h : interface of the CMainFrame class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_MAINFRM_H__58EE0A3E_E523_4957_BA9D_85E86BBCE267__INCLUDED_)
#define AFX_MAINFRM_H__58EE0A3E_E523_4957_BA9D_85E86BBCE267__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class CMainFrame : public CFrameWnd
{
	
protected: // create from serialization only
	CMainFrame();
	DECLARE_DYNCREATE(CMainFrame)

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMainFrame)
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CMainFrame();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:  // control bar embedded members
	CStatusBar  m_wndStatusBar;
	CToolBar    m_wndToolBar;
//	CToolBar    m_wndNavBar;	
	BOOL m_bCreated;
public:
	void GetRealyClientRect(CRect& rc);
	void BeginProgress();
	void EndProgress();
	void SetProgress(DWORD dwCur, DWORD dwAll);
	void OnSomeLongProgess();
	CProgressCtrl m_ctlProgress;
// Generated message map functions
protected:
	//{{AFX_MSG(CMainFrame)
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnSize(UINT nType, int cx, int cy);
	afx_msg LRESULT OnSetMessageString(WPARAM wParam, LPARAM lParam);
	afx_msg void OnSelStart();
	afx_msg void OnUpdateSelStart(CCmdUI* pCmdUI);
	afx_msg void OnSelEnd();
	afx_msg void OnUpdateSelEnd(CCmdUI* pCmdUI);
	afx_msg void OnPrintCurrentitem();
	afx_msg void OnMove(int x, int y);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
private:
	BOOL m_bStartChecked;
	BOOL m_bEndChecked;
	CComboBox m_ctlSearchBox;
	CString m_sStatusBarString;
	void StatusBarMessage(TCHAR* fmt, ...);

};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MAINFRM_H__58EE0A3E_E523_4957_BA9D_85E86BBCE267__INCLUDED_)
