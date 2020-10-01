// ADORecordsetPrinter.cpp: implementation of the CADORecordsetPrinter class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "GCLPrint.h"
#include "ADORecordsetPrinter.h"
#include "RecodsetPrinterView.h"
#include "resource.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif


#define HEADER_HEIGHT       2    // For printing
#define FOOTER_HEIGHT       2
#define LEFT_MARGIN         4
#define RIGHT_MARGIN        4
#define TOP_MARGIN          1
#define BOTTOM_MARGIN       1 
#define GAP                 1

#define ROWHEIGHT           250


//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CADORecordsetPrinter::CADORecordsetPrinter()
{
	m_bPrintPreview=FALSE;
	m_pTemplate=NULL;
	m_pParent=NULL;
}

CADORecordsetPrinter::~CADORecordsetPrinter()
{

}

void CADORecordsetPrinter::PrintPreview()
{
	if (m_bPrintPreview)
	{
		AfxGetApp()->m_pMainWnd->SetFocus();
		return;
	}

	CFrameWnd* pOldFrame=(CFrameWnd*)AfxGetThread()->m_pMainWnd;
	pOldFrame->ShowWindow(SW_HIDE); //added by eric

	if (!m_pTemplate)
	{
		m_pTemplate = new CSingleDocTemplate(
			m_uiMenuID,
			NULL,
			RUNTIME_CLASS(CFrameWnd),
			RUNTIME_CLASS(CRecodsetPrinterView));
		AfxGetApp()->AddDocTemplate(m_pTemplate);
	}

	CFrameWnd * pFrameWnd = m_pTemplate->CreateNewFrame( NULL, NULL );
	m_bPrintPreview=TRUE;

	m_pTemplate->InitialUpdateFrame( pFrameWnd, NULL, FALSE);

	CRecodsetPrinterView* pView=(CRecodsetPrinterView*)pFrameWnd->GetActiveView();
	pView->SetRecordsetPrinter(this);
	pView->SetOldFrameWnd(pOldFrame);

	AfxGetApp()->m_pMainWnd=pFrameWnd;
	CString strWindowTitle="ÅÌ‘ ‰„«Ì‘ ç«Å ";
	strWindowTitle+=m_strWindowTitle;
	pFrameWnd->SetWindowText(strWindowTitle);

	pFrameWnd->ShowWindow(SW_SHOWMAXIMIZED);

	pView->OnFilePrintPreview();
}

void CADORecordsetPrinter::EndPrintPreview()
{
	m_bPrintPreview=FALSE;
}

void CADORecordsetPrinter::OnBeginPrinting(CDC *pDC, CPrintInfo *pInfo)
{
    ASSERT(pDC && pInfo);
    if (!pDC || !pInfo) return;

    int nMaxRowCount = m_pRecordset->GetRecordCount();
    if (!nMaxRowCount) return;

	if(!m_pParent)
		return;
    // Get a DC for the current window (will be a screen DC for print previewing)
    CDC *pCurrentDC = m_pParent->GetDC();        // will have dimensions of the client area
    if (!pCurrentDC)
		return;



    CSize PaperPixelsPerInch(pDC->GetDeviceCaps(LOGPIXELSX), pDC->GetDeviceCaps(LOGPIXELSY));
    CSize ScreenPixelsPerInch(pCurrentDC->GetDeviceCaps(LOGPIXELSX), pCurrentDC->GetDeviceCaps(LOGPIXELSY));

    int nFontSize = -144;
    CString strFontName = "Tahoma";
    m_PrinterFont.CreateFont(nFontSize, 0,0,0, FW_NORMAL, 0,0,0, ARABIC_CHARSET,
                             OUT_CHARACTER_PRECIS, CLIP_CHARACTER_PRECIS, DEFAULT_QUALITY,
                             DEFAULT_PITCH | FF_DONTCARE, strFontName);
            
    CFont *pOldFont = pDC->SelectObject(&m_PrinterFont);

    // Get the average character width (in GridCtrl units) and hence the margins
    m_CharSize = pDC->GetTextExtent(_T("abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSATUVWXYZ"),52);
    m_CharSize.cx /= 52;
    int nMargins = (LEFT_MARGIN+RIGHT_MARGIN)*m_CharSize.cx;

    // Get the page sizes (physical and logical)
    m_PaperSize = CSize(pDC->GetDeviceCaps(HORZRES), pDC->GetDeviceCaps(VERTRES));
    m_LogicalPageSize.cx = GetVirtualWidth()+nMargins;

    m_LogicalPageSize.cy = MulDiv(m_LogicalPageSize.cx, m_PaperSize.cy, m_PaperSize.cx);

    m_nPageHeight = m_LogicalPageSize.cy /*- GetFixedRowHeight()*/ - (HEADER_HEIGHT+FOOTER_HEIGHT + 2*GAP)*m_CharSize.cy;

    // Get the number of pages. Assumes no row is bigger than the page size.
    long nTotalRowHeight = 3*ROWHEIGHT;//nMaxRowCount*ROWHEIGHT;
	long lRecCount=0;
	long lMaxRec=this->m_pRecordset->GetRecordCount();
	int nNumPages=1;
	while(lRecCount<lMaxRec)
	{
		//One for header:
		nTotalRowHeight+=ROWHEIGHT;
		while( (nTotalRowHeight<=nNumPages*m_nPageHeight) && (lRecCount<lMaxRec))
		{
			nTotalRowHeight+=ROWHEIGHT;
			lRecCount++;
		}
		if(lRecCount<lMaxRec)
			nNumPages++;
	}

    // Set up the print info
    pInfo->SetMaxPage(nNumPages);
    pInfo->m_nCurPage = 1;                        // start printing at page# 1

    m_pParent->ReleaseDC(pCurrentDC);
    pDC->SelectObject(pOldFont);

}


void CADORecordsetPrinter::SetNextFieldWidth(WORD wWidth)
{
	m_iaColumnWidth.Add(wWidth);
}

long CADORecordsetPrinter::GetVirtualWidth()
{
	long lRet=0;
	for(int i=0; i<m_iaColumnWidth.GetSize();i++)
		lRet+=m_iaColumnWidth.GetAt(i);
	return lRet;
}

void CADORecordsetPrinter::OnPrint(CDC *pDC, CPrintInfo *pInfo)
{
    if (!pDC || !pInfo) return;

    //CRect rcPage(pInfo->m_rectDraw);
    CFont *pOldFont = pDC->SelectObject(&m_PrinterFont);

    // Set the page map mode to use GridCtrl units, and setup margin
    pDC->SetMapMode(MM_ANISOTROPIC);
    pDC->SetWindowExt(m_LogicalPageSize);
    pDC->SetViewportExt(m_PaperSize);
    pDC->SetWindowOrg(-LEFT_MARGIN*m_CharSize.cx, 0);

    // Header
    pInfo->m_rectDraw.top    = 0;
    pInfo->m_rectDraw.left   = 0;
    pInfo->m_rectDraw.right  = m_LogicalPageSize.cx - (LEFT_MARGIN+RIGHT_MARGIN)*m_CharSize.cx;
    pInfo->m_rectDraw.bottom = HEADER_HEIGHT*m_CharSize.cy;
//    PrintHeader(pDC, pInfo);
    pDC->OffsetWindowOrg(0, -HEADER_HEIGHT*m_CharSize.cy);

    // Gap between header and column headings
    pDC->OffsetWindowOrg(0, -GAP*m_CharSize.cy);

    // Print the column headings
//    pInfo->m_rectDraw.bottom = GetFixedRowHeight(); 
//    PrintColumnHeadings(pDC, pInfo);
//    pDC->OffsetWindowOrg(0, -GetFixedRowHeight()); 

    // We need to find out which row to start printing for this page.
	DWORD nCurrPrintRow = 0;//GetFixedRowCount();
    UINT nNumPages = 1;
    int nTotalRowHeight = 3*ROWHEIGHT; //0;
    CRect rect;
    rect.bottom = -1;


	m_pRecordset->MoveFirst();
    while (nCurrPrintRow < m_pRecordset->GetRecordCount() && nNumPages < pInfo->m_nCurPage && !m_pRecordset->IsEOF())
    {
        nTotalRowHeight += ROWHEIGHT;
        if (nTotalRowHeight > m_nPageHeight) {
            nNumPages++;
            if (nNumPages == pInfo->m_nCurPage) break;
            nTotalRowHeight = 2*ROWHEIGHT;
        }
		m_pRecordset->MoveNext();
        nCurrPrintRow++;
    }

    if (nCurrPrintRow >= m_pRecordset->GetRecordCount()) return;


    rect.top = rect.bottom+1;
    rect.bottom = rect.top + ROWHEIGHT - 1;

    if (rect.bottom > m_nPageHeight) return;            // Gone past end of page

    rect.right = -1;

	if(pInfo->m_nCurPage==1)
	{
        rect.left = rect.right+1;
        rect.right = rect.left + GetVirtualWidth() - 1;
		DrawTitle(pDC, rect);		
        rect.top = rect.bottom+ROWHEIGHT+1;
		rect.bottom = rect.top + ROWHEIGHT - 1;

	}

    rect.right = -1;


	for(int col=m_pRecordset->GetFieldCount()-1;col>-1;col--)
	{
		if(m_iaColumnWidth.GetAt(col)>0)
		{

        rect.left = rect.right+1;
        rect.right = rect.left + m_iaColumnWidth.GetAt(col) - 1;

        DrawHeaderCell(pDC, nCurrPrintRow, col, rect);		
		}
	}

//    nCurrPrintRow++;
    
    // Draw as many rows as will fit on the printed page.
    // Clip the printed page so that there is no partially shown
    // row at the bottom of the page (the same row which will be fully
    // shown at the top of the next page).

    BOOL bFirstPrintedRow = TRUE;

	/*
	if(nCurrPrintRow>0)
	{
		m_pRecordset->MovePrevious();
		nCurrPrintRow--;
	}

*/
    while (nCurrPrintRow < this->m_pRecordset->GetRecordCount())
    {
        rect.top = rect.bottom+1;
        rect.bottom = rect.top + ROWHEIGHT - 1;

        if (rect.bottom > m_nPageHeight) break;            // Gone past end of page

        rect.right = -1;
		int iLastCol=this->m_iaColumnWidth.GetSize()-1;
		while( (m_iaColumnWidth.GetAt(iLastCol)==0)&&(iLastCol>0))
			iLastCol--;
		int iFirstCol=0;
		while( (m_iaColumnWidth.GetAt(iFirstCol)==0)&&(iFirstCol<iLastCol))
			iFirstCol++;

        for (int col = this->m_iaColumnWidth.GetSize()-1; col >-1; col--)
        {
			if(m_iaColumnWidth.GetAt(col)>0)
			{

            rect.left = rect.right+1;
            rect.right = rect.left + m_iaColumnWidth.GetAt(col) - 1;

            if(DrawCell(pDC, nCurrPrintRow, col, rect))
			{
                int Overlap = (col == iFirstCol)? 0:1;
                pDC->MoveTo(rect.left-Overlap, rect.bottom);
                pDC->LineTo(rect.right, rect.bottom);
                if (nCurrPrintRow == 0) {
                    pDC->MoveTo(rect.left-Overlap, rect.top);
                    pDC->LineTo(rect.right, rect.top);
                }
            Overlap = (bFirstPrintedRow)? 0:1;
                pDC->MoveTo(rect.right, rect.top-Overlap);
                pDC->LineTo(rect.right, rect.bottom);    
                if (col == iLastCol) {
                    pDC->MoveTo(rect.left, rect.top-Overlap);
                    pDC->LineTo(rect.left, rect.bottom);    
                }
			}

			}
        }
        nCurrPrintRow++;
		if(!m_pRecordset->IsEOF())
			m_pRecordset->MoveNext();
        bFirstPrintedRow = FALSE;
    }

    // Footer
    pInfo->m_rectDraw.bottom = FOOTER_HEIGHT*m_CharSize.cy;
    pDC->SetWindowOrg(-LEFT_MARGIN*m_CharSize.cx, -m_LogicalPageSize.cy + FOOTER_HEIGHT*m_CharSize.cy);
    PrintFooter(pDC, pInfo);

    // SetWindowOrg back for next page
    pDC->SetWindowOrg(0,0);

    pDC->SelectObject(pOldFont);


}

BOOL CADORecordsetPrinter::DrawCell(CDC *pDC, int nRow, int nCol, CRect rect, BOOL bEraseBk)
{
    COLORREF TextBkClr = RGB(255, 255, 255);
    COLORREF TextClr   = RGB(0, 0, 0);

	if(m_pRecordset->IsEOF())
		return FALSE;
    int nSavedDC = pDC->SaveDC();

    pDC->SetBkMode(TRANSPARENT);

	{
        rect.right++; rect.bottom++;    // FillRect doesn't draw RHS or bottom
        if (bEraseBk) 
        {
            CBrush brush(TextBkClr);
            pDC->FillRect(rect, &brush);
        }
        rect.right--; rect.bottom--;
        pDC->SetTextColor(TextClr);
    }


    pDC->SelectObject(&m_PrinterFont);


	CString strValue;
	this->m_pRecordset->GetFieldValue(nCol, strValue);

	int iLen=strValue.GetLength();
	if(iLen>0)
	if(strValue[iLen-1]=='.')
	{
		strValue.Delete(strValue.GetLength()-1);
	}

    DrawText(pDC->m_hDC, strValue, -1, rect, DT_RTLREADING|DT_CENTER);

    pDC->RestoreDC(nSavedDC);

    return TRUE;
}


BOOL CADORecordsetPrinter::DrawHeaderCell(CDC *pDC, int nRow, int nCol, CRect rect, BOOL bEraseBk)
{
    COLORREF TextBkClr = RGB(255, 255, 255);
    COLORREF TextClr   = RGB(0, 0, 0);

    int nSavedDC = pDC->SaveDC();

    pDC->SetBkMode(TRANSPARENT);

	{
        rect.right++; rect.bottom++;    // FillRect doesn't draw RHS or bottom

        if (bEraseBk) 
        {
            CBrush brush(TextBkClr);
            pDC->FillRect(rect, &brush);
        }
        rect.right--; rect.bottom--;
        pDC->SetTextColor(TextClr);
    }


    pDC->SelectObject(&m_PrinterFont);


	CADOFieldInfo fldInfo;
	m_pRecordset->GetFieldInfo(nCol, &fldInfo);
	

    DrawText(pDC->m_hDC, fldInfo.m_strName, -1, rect, DT_RTLREADING|DT_CENTER);

		int iLastCol=this->m_iaColumnWidth.GetSize()-1;
		while( (m_iaColumnWidth.GetAt(iLastCol)==0)&&(iLastCol>0))
			iLastCol--;

		int iFirstCol=0;
		while( (m_iaColumnWidth.GetAt(iFirstCol)==0)&&(iFirstCol<iLastCol))
			iFirstCol++;



	int col=nCol;
                int Overlap = (col == iFirstCol)? 0:1;
                pDC->MoveTo(rect.left-Overlap, rect.bottom);
                pDC->LineTo(rect.right, rect.bottom);
//                if (nCurrPrintRow == 0) {
				{
                    pDC->MoveTo(rect.left-Overlap, rect.top);
                    pDC->LineTo(rect.right, rect.top);
                }
/*
            }
            if (m_nGridLines == GVL_BOTH || m_nGridLines == GVL_VERT) 
            {
*/
                Overlap = 0;
                pDC->MoveTo(rect.right, rect.top-Overlap);
                pDC->LineTo(rect.right, rect.bottom);    
                if (col == iLastCol) {
                    pDC->MoveTo(rect.left, rect.top-Overlap);
                    pDC->LineTo(rect.left, rect.bottom);    
                }




    pDC->RestoreDC(nSavedDC);

    return TRUE;
}


void CADORecordsetPrinter::OnEndPrinting(CDC *pDC, CPrintInfo *pInfo)
{
    m_PrinterFont.DeleteObject();
}

void CADORecordsetPrinter::Print()
{
	CDC dc;
    CPrintDialog printDlg(FALSE);

    if (printDlg.DoModal() != IDOK)             // Get printer settings from user
        return;

    dc.Attach(printDlg.GetPrinterDC());         // attach a printer DC
    dc.m_bPrinting = TRUE;

    CString strTitle;
    //strTitle.LoadString(AFX_IDS_APP_TITLE);
	strTitle="»—‰«„Â „œÌ—Ì  ò‰ Ê—ŒÊ«‰Ì »«—òœÌ - ";
	strTitle+=m_strWindowTitle;

    DOCINFO di;                                 // Initialise print doc details
    memset(&di, 0, sizeof (DOCINFO));
    di.cbSize = sizeof (DOCINFO);
    di.lpszDocName = strTitle;

    BOOL bPrintingOK = dc.StartDoc(&di);        // Begin a new print job

     CPrintInfo Info;
    Info.m_rectDraw.SetRect(0,0, dc.GetDeviceCaps(HORZRES), dc.GetDeviceCaps(VERTRES));

    OnBeginPrinting(&dc, &Info);                // Initialise printing
    for (UINT page = Info.GetMinPage(); page <= Info.GetMaxPage() && bPrintingOK; page++)
    {
        dc.StartPage();                         // begin new page
        Info.m_nCurPage = page;
        OnPrint(&dc, &Info);                    // Print page
        bPrintingOK = (dc.EndPage() > 0);       // end page
    }
    OnEndPrinting(&dc, &Info);                  // Clean up after printing

    if (bPrintingOK)
        dc.EndDoc();                            // end a print job
    else
        dc.AbortDoc();                          // abort job.

    dc.Detach();                                // detach the printer DC
}


int g_days_in_month2[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
int j_days_in_month2[12] = {31, 31, 31, 31, 31, 31, 30, 30, 30, 30, 30, 29};



void gregorian_to_jalali2(
	int *j_y,
	int *j_m,
	int *j_d,
	const int g_y,
	const int g_m,
	const int g_d)
{
   int gy, gm, gd;
   int jy, jm, jd;
   long g_day_no, j_day_no;
   int j_np;
 
   int i;
   gy = g_y-1600;
   gm = g_m-1;
   gd = g_d-1;
 
   g_day_no = 365*gy+(gy+3)/4-(gy+99)/100+(gy+399)/400;
   for (i=0;i<gm;++i)
      g_day_no += g_days_in_month2[i];
   if (gm>1 && ((gy%4==0 && gy%100!=0) || (gy%400==0)))
      /* leap and after Feb */
      ++g_day_no;
   g_day_no += gd;
 
   j_day_no = g_day_no-79;
 
   j_np = j_day_no / 12053;
   j_day_no %= 12053;
 
   jy = 979+33*j_np+4*(j_day_no/1461);
   j_day_no %= 1461;
 
   if (j_day_no >= 366) {
      jy += (j_day_no-1)/365;
      j_day_no = (j_day_no-1)%365;
   }
 
   for (i = 0; j_day_no >= j_days_in_month2[i]; ++i) {
      j_day_no -= j_days_in_month2[i];
   }
   jm = i+1;
   jd = j_day_no+1;
   *j_y = jy;
   *j_m = jm;
   *j_d = jd;
}


void CADORecordsetPrinter::PrintFooter(CDC *pDC, CPrintInfo *pInfo)
{
    CRect rc(pInfo->m_rectDraw);
    CFont BoldFont;
    LOGFONT lf;

    //draw line
    pDC->MoveTo(rc.left, rc.top);
    pDC->LineTo(rc.right, rc.top);

    //create bold font for header and footer
    m_PrinterFont.GetLogFont(&lf);
    lf.lfWeight = FW_BOLD;
    BoldFont.CreateFontIndirect(&lf);

    CFont *pNormalFont = pDC->SelectObject(&BoldFont);
    int nPrevBkMode = pDC->SetBkMode(TRANSPARENT);

    // draw page number
    CString   sTemp ;
    rc.OffsetRect(0, m_CharSize.cy/2);
    sTemp.Format(_T("’›ÕÂ %d «“ %d"), pInfo->m_nCurPage, pInfo->GetMaxPage());
    pDC->DrawText(sTemp,-1,rc, DT_RIGHT | DT_SINGLELINE | DT_NOPREFIX | DT_NOCLIP | DT_VCENTER |DT_RTLREADING);

    //CTime t = CTime::GetCurrentTime();
    //sTemp = t.Format(_T("%c"));

		SYSTEMTIME systime;
		int		m_JD;
		int		m_JM;
		int		m_JY;
		int		m_GD;
		int		m_GM;
		int		m_GY;

		GetLocalTime(&systime);
		m_GD = systime.wDay-1;
		m_GM = systime.wMonth-1;
		m_GY = systime.wYear;
		gregorian_to_jalali2(&m_JY, &m_JM, &m_JD, m_GY, m_GM+1, m_GD+1);

		char cYear[10];
		itoa(m_JY, cYear, 10);
		strcpy(cYear, &cYear[2]);
		char cMonth[3];
		CString sMonth;
		sMonth.Format("%.2d", m_JM);
		strcpy(cMonth, sMonth);
		strcat(cYear, "/");
		strcat(cYear, cMonth);
		char cDay[3];
		CString sDay;
		sDay.Format("%.2d", m_JD);
		strcpy(cDay, sDay);
		strcat(cYear, "/");
		strcat(cYear, cDay);

	sTemp=" «—ÌŒ= ";
	sTemp+=cYear;
	sTemp+=" °”«⁄ = ";

	CString sTime;
	sTime.Format("%.2d:%.2d:%.2d",systime.wHour, systime.wMinute, systime.wSecond);
	sTemp+=sTime;




    pDC->DrawText(sTemp,-1,rc, DT_LEFT | DT_SINGLELINE | DT_NOPREFIX | DT_NOCLIP | DT_VCENTER | DT_RTLREADING);

    pDC->SetBkMode(nPrevBkMode);
    pDC->SelectObject(pNormalFont);
    BoldFont.DeleteObject();

}

void CADORecordsetPrinter::ResetFieldWidths()
{
	m_iaColumnWidth.RemoveAll();
}

BOOL CADORecordsetPrinter::DrawTitle(CDC *pDC, CRect rect)
{
    COLORREF TextBkClr = RGB(230, 230, 230);
    COLORREF TextClr   = RGB(0, 0, 0);

    int nSavedDC = pDC->SaveDC();

    pDC->SetBkMode(TRANSPARENT);

	{
        rect.right++; rect.bottom++;    // FillRect doesn't draw RHS or bottom

        CBrush brush(TextBkClr);
        pDC->FillRect(rect, &brush);
        rect.right--; rect.bottom--;
        pDC->SetTextColor(TextClr);
    }


//    pDC->SelectObject(&m_PrinterFont);

    CFont BoldFont;
    LOGFONT lf;


    //create bold font for header and footer
    m_PrinterFont.GetLogFont(&lf);
    lf.lfWeight = FW_BOLD;
	//strcpy(lf.lfFaceName,"Time New Roman");
    BoldFont.CreateFontIndirect(&lf);

    CFont *pNormalFont = pDC->SelectObject(&BoldFont);




    DrawText(pDC->m_hDC, m_strWindowTitle, -1, rect, DT_RTLREADING|DT_CENTER|DT_VCENTER|DT_SINGLELINE);

                pDC->MoveTo(rect.left, rect.bottom);
                pDC->LineTo(rect.right, rect.bottom);
                pDC->MoveTo(rect.left, rect.top);
                pDC->LineTo(rect.right, rect.top);
                pDC->MoveTo(rect.right, rect.top);
                pDC->LineTo(rect.right, rect.bottom);    
                pDC->MoveTo(rect.left, rect.top);
                pDC->LineTo(rect.left, rect.bottom);    



    pDC->RestoreDC(nSavedDC);

    pDC->SelectObject(pNormalFont);
    BoldFont.DeleteObject();


	return TRUE;
}

