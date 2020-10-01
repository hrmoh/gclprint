// GCLPrintDoc.h : interface of the CGCLPrintDoc class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_GCLPRINTDOC_H__C3FFCB19_27CE_4AFC_B289_F1776B1B4D69__INCLUDED_)
#define AFX_GCLPRINTDOC_H__C3FFCB19_27CE_4AFC_B289_F1776B1B4D69__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "WhiteListRs.h"	// Added by ClassView
#include "ado2.h"	// Added by ClassView

#include "RprtprnDlg.h"


class CGCLPrintDoc : public CDocument
{
protected: // create from serialization only
	CGCLPrintDoc();
	DECLARE_DYNCREATE(CGCLPrintDoc)

private:
	int m_iPrinterPort;
	BOOL m_bPauseAfter;
	int m_iPauseAfter;
	long m_lStart;
	long m_lEnd;
	BOOL m_bStartChecked;
	BOOL ConnectToDB(BOOL bEmpty=TRUE);

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CGCLPrintDoc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	virtual BOOL OnOpenDocument(LPCTSTR lpszPathName);
	//}}AFX_VIRTUAL

// Implementation
public:
	void PrintLabel(HANDLE hComm, int iLabelType);
	void SetViewRS(_RecordsetPtr pRs);
	virtual ~CGCLPrintDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	CADORecordset m_pRs;
	CADODatabase m_pDb;

	//{{AFX_MSG(CGCLPrintDoc)
	afx_msg void OnSendToZ4M();
	afx_msg void OnPrinttt();
	afx_msg void OnSettingsPaths();
	afx_msg void OnFileSortonid();
	afx_msg void OnFileTitles();
	afx_msg void OnFileSortonad();
	afx_msg void OnFilePrintlist();
	afx_msg void OnFileDelcontents();
	afx_msg void OnFileInsertdlg();
	afx_msg void OnFileLoadlabelfile();
	afx_msg void OnFileGenids();
	afx_msg void OnSettingsPrintertype();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
	CWhiteListRs m_rsRecSet;
BOOL FetchRecordAndInsertToDB(long& lOrder, CFile *pWhiteListFile);
BOOL FetchRecordFromLabelFileAndInsertToDB(long& lOrder, CFile *pWhiteListFile);

public:
	CString AddControlCode(CString sID);
	void HandlePrint();
	void CheckForPrint();
	void CheckCurrentAsStart(BOOL bStartChecked);
	void CheckCurrentAsEnd(BOOL bEndChecked);
	void ShowCurrent();
	long FindAD(CString sID, int iOrder);
	long FindID(CString sID, int iOrder);
	void GoTo(long lWhere);
	void OpenComPort(HANDLE &hComm);
	void CloseComPort(HANDLE &hComm);

private:
	BOOL m_bZplPrinting;
	CRprtprnDlg m_dlgRprtprn;

};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_GCLPRINTDOC_H__C3FFCB19_27CE_4AFC_B289_F1776B1B4D69__INCLUDED_)
