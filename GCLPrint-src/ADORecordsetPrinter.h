// ADORecordsetPrinter.h: interface for the CADORecordsetPrinter class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_ADORECORDSETPRINTER_H__F2403BA1_B274_47A6_9E45_5026B976ED73__INCLUDED_)
#define AFX_ADORECORDSETPRINTER_H__F2403BA1_B274_47A6_9E45_5026B976ED73__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "ado2.h"

class CADORecordsetPrinter  
{
public:
	BOOL DrawTitle(CDC *pDC, CRect rect);
	void ResetFieldWidths();
	void PrintFooter(CDC *pDC, CPrintInfo *pInfo);
	void Print();
	void OnEndPrinting(CDC *pDC, CPrintInfo *pInfo);
	void OnPrint(CDC *pDC, CPrintInfo *pInfo);
	long GetVirtualWidth();
	void SetNextFieldWidth(WORD wWidth);
	void OnBeginPrinting(CDC *pDC, CPrintInfo *pInfo);
	void EndPrintPreview();
	void PrintPreview();
	CADORecordsetPrinter();
	virtual ~CADORecordsetPrinter();

	void SetRecordet(CADORecordset* pRecordset){m_pRecordset=pRecordset;}
	void SetMenuID(UINT uiMenuID){m_uiMenuID=uiMenuID;}
	void SetTitle(CString strWindowTitle){m_strWindowTitle=strWindowTitle;}
	void SetParent(CWnd* pWnd){m_pParent=pWnd;}
private:
	BOOL DrawCell(CDC* pDC, int nRow, int nCol, CRect rect, BOOL bEraseBk=FALSE);
	BOOL DrawHeaderCell(CDC* pDC, int nRow, int nCol, CRect rect, BOOL bEraseBk=FALSE);
	CWordArray m_iaColumnWidth;
	CSize m_CharSize;
	CFont m_PrinterFont;
	CWnd* m_pParent;
	CADORecordset* m_pRecordset;
	BOOL m_bPrintPreview;
	CSingleDocTemplate* m_pTemplate;
	UINT m_uiMenuID;
	CString m_strWindowTitle;
    int         m_nPageHeight;
    CSize       m_LogicalPageSize,      // Page size in gridctrl units.
                m_PaperSize;            // Page size in device units.

};

#endif // !defined(AFX_ADORECORDSETPRINTER_H__F2403BA1_B274_47A6_9E45_5026B976ED73__INCLUDED_)
