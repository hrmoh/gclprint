#if !defined(AFX_LABELPRINTERTYPE_H__CD4D8CD3_089A_4112_83D0_0A190496110D__INCLUDED_)
#define AFX_LABELPRINTERTYPE_H__CD4D8CD3_089A_4112_83D0_0A190496110D__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// LabelPrinterType.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CLabelPrinterType dialog

class CLabelPrinterType : public CDialog
{
// Construction
public:
	CLabelPrinterType(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CLabelPrinterType)
	enum { IDD = IDD_PRINTYPE };
	int		m_iPrinterType;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CLabelPrinterType)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CLabelPrinterType)
	virtual BOOL OnInitDialog();
	virtual void OnOK();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_LABELPRINTERTYPE_H__CD4D8CD3_089A_4112_83D0_0A190496110D__INCLUDED_)
