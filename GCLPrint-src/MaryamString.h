// MaryamString.h: interface for the CMaryamString class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_MARYAMSTRING_H__21F67349_D61E_4E71_8E9A_F389C90C3C58__INCLUDED_)
#define AFX_MARYAMSTRING_H__21F67349_D61E_4E71_8E9A_F389C90C3C58__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class CMaryamString  
{
public:
	CString GetString();
	void ConvertMe();
	CMaryamString(CString InitialString, BOOL IsInMaryamCodePage=FALSE);
	virtual ~CMaryamString();

private:
	CString GetSmall(char c, char pc);
	CString GetCapital(char c, char pc);
	CString m_sText;
};

#endif // !defined(AFX_MARYAMSTRING_H__21F67349_D61E_4E71_8E9A_F389C90C3C58__INCLUDED_)
