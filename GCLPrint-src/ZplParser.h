// ZplParser.h: interface for the CZplParser class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_ZPLPARSER_H__CD198FAC_21F1_4102_B39D_18F9356D7413__INCLUDED_)
#define AFX_ZPLPARSER_H__CD198FAC_21F1_4102_B39D_18F9356D7413__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class CZplParser  
{
public:
	void LoadArmToPrinter(HANDLE hComm);
	void Print(HANDLE hComm, int iLabelType);
	void SetVar(int iIndex, CString szVar);
	void SetNobarcodeVar(int iIndex, CString szVar);
	void Open(CHAR* pBuffer);
	BOOL Open(LPCTSTR lpszPathName, BOOL bFile);
	CZplParser();
	virtual ~CZplParser();

private:
	CStringArray m_saCommands;
	CStringArray m_saVariables;

	CStringArray m_saNoBarcodeCommands;
	CStringArray m_saNoBarcodeVariables;
};

#endif // !defined(AFX_ZPLPARSER_H__CD198FAC_21F1_4102_B39D_18F9356D7413__INCLUDED_)
