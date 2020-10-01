// GCLPrintView.h : interface of the CGCLPrintView class
//
/////////////////////////////////////////////////////////////////////////////
//{{AFX_INCLUDES()
#include "mshflexgrid.h"
//}}AFX_INCLUDES

#if !defined(AFX_GCLPRINTVIEW_H__698A7DE0_6F16_43BA_B817_62745480D61D__INCLUDED_)
#define AFX_GCLPRINTVIEW_H__698A7DE0_6F16_43BA_B817_62745480D61D__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CGCLPrintView : public CFormView
{
protected: // create from serialization only
	CGCLPrintView();
	DECLARE_DYNCREATE(CGCLPrintView)

public:
	//{{AFX_DATA(CGCLPrintView)
	enum { IDD = IDD_GCLPRINT_FORM };
	CMSHFlexGrid	m_flxCustomers;
	//}}AFX_DATA

// Attributes
public:
	CGCLPrintDoc* GetDocument();

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CGCLPrintView)
	public:
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	virtual void OnInitialUpdate(); // called first time after construct
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnPrint(CDC* pDC, CPrintInfo* pInfo);
	//}}AFX_VIRTUAL

// Implementation
public:
	void SetRs(_RecordsetPtr pRs);
	void LoadDB(_RecordsetPtr pRs);
	void BeginProgress();
	void HideProgressBar();
	void SetProgress(DWORD dwCur, DWORD dwAll);
	virtual ~CGCLPrintView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CGCLPrintView)
	afx_msg void OnSize(UINT nType, int cx, int cy);
	afx_msg void OnMouseUpFlxcustomers(short Button, short Shift, long x, long y);
	afx_msg void OnSelChangeFlxcustomers();
	afx_msg void OnFileFindid();
	afx_msg void OnFileFindad();
	afx_msg void OnDblClickFlxcustomers();
	afx_msg void OnFilePrint();
	DECLARE_EVENTSINK_MAP()
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
private:
	BOOL m_bPrev;
	BOOL m_bPrevAD;
	int m_iSearched;
	int m_iSearchedAD;
	_RecordsetPtr m_pRs;

	CString m_sLastSearchedID;
	CString m_sLastSearchedAD;
};

#ifndef _DEBUG  // debug version in GCLPrintView.cpp
inline CGCLPrintDoc* CGCLPrintView::GetDocument()
   { return (CGCLPrintDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_GCLPRINTVIEW_H__698A7DE0_6F16_43BA_B817_62745480D61D__INCLUDED_)
