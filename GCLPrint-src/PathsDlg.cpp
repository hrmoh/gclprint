// PathsDlg.cpp : implementation file
//

#include "stdafx.h"
#include "GCLPrint.h"
#include "PathsDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CPathsDlg dialog


CPathsDlg::CPathsDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CPathsDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CPathsDlg)
	m_strMDB = _T("");
	//}}AFX_DATA_INIT
	m_bChanged=FALSE;
}


void CPathsDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CPathsDlg)
	DDX_Text(pDX, IDC_EMDB, m_strMDB);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CPathsDlg, CDialog)
	//{{AFX_MSG_MAP(CPathsDlg)
	ON_BN_CLICKED(IDC_CHANGE, OnChange)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CPathsDlg message handlers
#include "GCLPrint.h"

extern CGCLPrintApp theApp;

BOOL CPathsDlg::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	m_strMDB=theApp.GetProfileString("Settings", "MDBPath");
	UpdateData(FALSE);

	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void CPathsDlg::OnChange() 
{
	CFileDialog fileDlg( TRUE, NULL, NULL, OFN_ALLOWMULTISELECT | OFN_HIDEREADONLY, "Å«Ìê«Â œ«œÂ Â«Ì «ò”” (*.mdb)|*.mdb||All Files (*.*)|*.*||", this);
	fileDlg.m_ofn.lpstrTitle = " ⁄ÌÌ‰ „”Ì— Å«Ìê«Â œ«œÂ Â«";
	fileDlg.m_ofn.lpstrInitialDir=m_strMDB;
	if ( fileDlg.DoModal() == IDOK)
	{
		m_strMDB = fileDlg.GetPathName();
		UpdateData(FALSE);
		m_bChanged=TRUE;
	}
}

#include "MsgDlg.h"
void CPathsDlg::OnOK() 
{
	if(m_bChanged)
	{
		CMsgDlg msgDlg;
		msgDlg.m_sMessage="»—«Ì «⁄„«·  €ÌÌ— »«Ìœ «“ »—‰«„Â Œ«—Ã ‘ÊÌœ.";
		msgDlg.DoModal();
		theApp.WriteProfileString("Settings", "MDBPath", m_strMDB);
	}
	CDialog::OnOK();
}
