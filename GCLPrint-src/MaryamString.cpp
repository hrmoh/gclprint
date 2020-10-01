// MaryamString.cpp: implementation of the CMaryamString class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "GCLPrint.h"
#include "MaryamString.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CMaryamString::CMaryamString(CString InitialString, BOOL IsInMaryamCodePage)
{
	m_sText=InitialString;
	if(!IsInMaryamCodePage)
	{
		ConvertMe();
	}
}

CMaryamString::~CMaryamString()
{

}



void CMaryamString::ConvertMe()
{
	CString sTemp;
	for(int i=0;i<m_sText.GetLength();i++)
	{
		if(i==m_sText.GetLength()-1)			
			sTemp+=GetCapital(m_sText[i], i>0?m_sText[i-1]:0);			
		else
		{
		if((m_sText[i+1]==' ')||(m_sText[i+1]=='/0')||(m_sText[i+1]==13)||(m_sText[i+1]==')'||(m_sText[i+1]=='(')))
			sTemp+=GetCapital(m_sText[i], i>0?m_sText[i-1]:0);			
		else
		{
			if(i>0)
			{
				sTemp+=GetSmall(m_sText[i], m_sText[i-1]);
			}
			else
			{
				sTemp+=GetSmall(m_sText[i], 0);
			}
		}
		}
	}

	CString sResult="";

	i=0;
	BOOL bPriorIsNumber=FALSE;
	if(sTemp.GetLength()>0)
	do
	{
		if( (sTemp[i]>='0')&&(sTemp[i]<='9') )
		{
			CString sTemp2="";
			while((sTemp[i]>='0')&&(sTemp[i]<='9'))
			{
				sTemp2+=sTemp[i++];
				if(i>=sTemp.GetLength())
					break;
			}
			bPriorIsNumber=TRUE;
			sResult=sTemp2+sResult;
		}
		if(i<sTemp.GetLength())
		if( (sTemp[i]<'0')||(sTemp[i]>'9') )
		{
			CString sTemp2="";
			while((sTemp[i]<'0')||(sTemp[i]>'9'))
			{
				sTemp2+=sTemp[i++];
				if(i>=sTemp.GetLength())
					break;
			}
			sTemp2.MakeReverse();
			if(bPriorIsNumber)
				sResult=sTemp2+sResult;
			else
				sResult=sResult+sTemp2;
			bPriorIsNumber=FALSE;
		}
	}
	while(i<sTemp.GetLength());
	m_sText=sResult;
}

CString CMaryamString::GetCapital(char c, char pc)
{
	TCHAR cTemp[3];
	cTemp[1]='\0';
	cTemp[2]='\0';
	switch(c)
	{
	case '(':
		cTemp[0]=')';
		break;
	case ')':
		cTemp[0]='(';
		break;
	case '�':
		cTemp[0]=char(65);//tanha
		break;
	case '�':
		cTemp[0]=char(73);//chasban
		if((pc==0)||(pc==' ')||(pc=='�')||(pc=='�')||(pc=='�')||(pc=='�')||(pc=='�')||(pc=='�')||(pc=='�')||(pc=='(')||(pc==')'))
			cTemp[0]=char(72);//tanha
		break;
	case '�':
		cTemp[0]=char(75);//chasban
		if((pc==0)||(pc==' ')||(pc=='�')||(pc=='�')||(pc=='�')||(pc=='�')||(pc=='�')||(pc=='�')||(pc=='�')||(pc=='(')||(pc==')'))
			cTemp[0]=char(74);//tanha
		break;
	case '�':
		cTemp[0]=char(79);//chasban
		if((pc==0)||(pc==' ')||(pc=='�')||(pc=='�')||(pc=='�')||(pc=='�')||(pc=='�')||(pc=='�')||(pc=='�')||(pc=='(')||(pc==')'))
			cTemp[0]=char(78);//tanha
		break;
	case '�':
		cTemp[0]=char(83);//chasban
		if((pc==0)||(pc==' ')||(pc=='�')||(pc=='�')||(pc=='�')||(pc=='�')||(pc=='�')||(pc=='�')||(pc=='�')||(pc=='(')||(pc==')'))
			cTemp[0]=char(82);//tanha
		break;
	case '�':
		cTemp[0]=char(87);//chasban
		if((pc==0)||(pc==' ')||(pc=='�')||(pc=='�')||(pc=='�')||(pc=='�')||(pc=='�')||(pc=='�')||(pc=='�')||(pc=='(')||(pc==')'))
			cTemp[0]=char(86);//tanha
		break;
	case '�':
		cTemp[0]=char(91); //chasban
		if((pc==0)||(pc==' ')||(pc=='�')||(pc=='�')||(pc=='�')||(pc=='�')||(pc=='�')||(pc=='�')||(pc=='�')||(pc=='(')||(pc==')'))
			cTemp[0]=char(90); //tanha
		break;
	case '�':
		cTemp[0]='c'; //chasban
		if((pc==0)||(pc==' ')||(pc=='�')||(pc=='�')||(pc=='�')||(pc=='�')||(pc=='�')||(pc=='�')||(pc=='�')||(pc=='(')||(pc==')'))
			cTemp[0]='b';
		break;
	case '�':
		cTemp[0]='g';//chasban
		if((pc==0)||(pc==' ')||(pc=='�')||(pc=='�')||(pc=='�')||(pc=='�')||(pc=='�')||(pc=='�')||(pc=='�')||(pc=='(')||(pc==')'))
			cTemp[0]='f';//tanha	
		break;
	case '�':
		cTemp[0]=char(95); //chasban
		if((pc==0)||(pc==' ')||(pc=='�')||(pc=='�')||(pc=='�')||(pc=='�')||(pc=='�')||(pc=='�')||(pc=='�')||(pc=='(')||(pc==')'))
			cTemp[0]=char(94); //tanha
		break;
	case '�':
		cTemp[0]='m'; //chasban
		if((pc==0)||(pc==' ')||(pc=='�')||(pc=='�')||(pc=='�')||(pc=='�')||(pc=='�')||(pc=='�')||(pc=='�')||(pc=='(')||(pc==')'))
			cTemp[0]='l'; //tanha
		break;
	case '�':
		cTemp[0]='k'; //chasban
		if((pc==0)||(pc==' ')||(pc=='�')||(pc=='�')||(pc=='�')||(pc=='�')||(pc=='�')||(pc=='�')||(pc=='�')||(pc=='(')||(pc==')'))
			cTemp[0]='j'; //tanha
		break;
	case '�':
		cTemp[0]='s'; //chasban
		if((pc==0)||(pc==' ')||(pc=='�')||(pc=='�')||(pc=='�')||(pc=='�')||(pc=='�')||(pc=='�')||(pc=='�')||(pc=='(')||(pc==')'))
			cTemp[0]='r'; //tanha
		break;
	case '�':
		cTemp[0]='q'; //chasban
		if((pc==0)||(pc==' ')||(pc=='�')||(pc=='�')||(pc=='�')||(pc=='�')||(pc=='�')||(pc=='�')||(pc=='�')||(pc=='(')||(pc==')'))
			cTemp[0]='p'; //tanha
		break;
	case '�':
		cTemp[0]='o'; //chasban
		if((pc==0)||(pc==' ')||(pc=='�')||(pc=='�')||(pc=='�')||(pc=='�')||(pc=='�')||(pc=='�')||(pc=='�')||(pc=='(')||(pc==')'))
			cTemp[0]='n'; //tanha
		break;
	case '�':
		cTemp[0]='u';//chasban
		if((pc==0)||(pc==' ')||(pc=='�')||(pc=='�')||(pc=='�')||(pc=='�')||(pc=='�')||(pc=='�')||(pc=='�')||(pc=='(')||(pc==')'))
			cTemp[0]='t';//tanha
		break;
	case '�':
		cTemp[0]='y';//chasban
		if((pc==0)||(pc==' ')||(pc=='�')||(pc=='�')||(pc=='�')||(pc=='�')||(pc=='�')||(pc=='�')||(pc=='�')||(pc=='(')||(pc==')'))
		cTemp[0]='x';//tanha
		break;
	case '�':
		cTemp[0]=char(125);//chasban
		if((pc==0)||(pc==' ')||(pc=='�')||(pc=='�')||(pc=='�')||(pc=='�')||(pc=='�')||(pc=='�')||(pc=='�')||(pc=='(')||(pc==')'))
			cTemp[0]=char(124);//tanha
		break;
	case '�':
		cTemp[0]=char(132);//chasban
		if((pc==0)||(pc==' ')||(pc=='�')||(pc=='�')||(pc=='�')||(pc=='�')||(pc=='�')||(pc=='�')||(pc=='�')||(pc=='(')||(pc==')'))
			cTemp[0]=char(131);//tanha
		break;
	case '�':
		cTemp[0]=char(137);//tanha
		if((pc==0)||(pc==' ')||(pc=='�')||(pc=='�')||(pc=='�')||(pc=='�')||(pc=='�')||(pc=='�')||(pc=='�')||(pc=='(')||(pc==')'))
			cTemp[0]=char(135);//tanha
		break;
	case '�':
		cTemp[0]=char(145);//chasban
		if((pc==0)||(pc==' ')||(pc=='�')||(pc=='�')||(pc=='�')||(pc=='�')||(pc=='�')||(pc=='�')||(pc=='�')||(pc=='(')||(pc==')'))
			cTemp[0]=char(139);//tanha
		break;
	case '�':
		cTemp[0]=char(148);//chasban
		if((pc==0)||(pc==' ')||(pc=='�')||(pc=='�')||(pc=='�')||(pc=='�')||(pc=='�')||(pc=='�')||(pc=='�')||(pc=='(')||(pc==')'))
			cTemp[0]=char(147);//tanha
		break;
	case '�':
		cTemp[0]=char(152);//chasban
		if((pc==0)||(pc==' ')||(pc=='�')||(pc=='�')||(pc=='�')||(pc=='�')||(pc=='�')||(pc=='�')||(pc=='�')||(pc=='(')||(pc==')'))
			cTemp[0]=char(151);//tanha
		break;
	case '�':
		cTemp[0]=char(156);//chasban
		if((pc==0)||(pc==' ')||(pc=='�')||(pc=='�')||(pc=='�')||(pc=='�')||(pc=='�')||(pc=='�')||(pc=='�')||(pc=='(')||(pc==')'))
			cTemp[0]=char(155);//tanha
		break;
	case '�':
		cTemp[0]=char(162);//chasban
		if((pc==0)||(pc==' ')||(pc=='�')||(pc=='�')||(pc=='�')||(pc=='�')||(pc=='�')||(pc=='�')||(pc=='�')||(pc=='(')||(pc==')'))
			cTemp[0]=char(161);//tanha
		break;
	case '�':
		cTemp[0]=char(166);//chasban
		if((pc==0)||(pc==' ')||(pc=='�')||(pc=='�')||(pc=='�')||(pc=='�')||(pc=='�')||(pc=='�')||(pc=='�')||(pc=='(')||(pc==')'))
			cTemp[0]=char(165);//tanha
		break;
	case '�':
		cTemp[0]=char(170);//chasban
		if((pc==0)||(pc==' ')||(pc=='�')||(pc=='�')||(pc=='�')||(pc=='�')||(pc=='�')||(pc=='�')||(pc=='�')||(pc=='(')||(pc==')'))
			cTemp[0]=char(169);//tanha
		break;
	case '�':
		cTemp[0]=char(174);//chasban
		if((pc==0)||(pc==' ')||(pc=='�')||(pc=='�')||(pc=='�')||(pc=='�')||(pc=='�')||(pc=='�')||(pc=='�')||(pc=='(')||(pc==')'))
			cTemp[0]=char(173);//tanha
		break;
	case '�':
		cTemp[0]=char(180);//chasban
		if((pc==0)||(pc==' ')||(pc=='�')||(pc=='�')||(pc=='�')||(pc=='�')||(pc=='�')||(pc=='�')||(pc=='�')||(pc=='(')||(pc==')'))
			cTemp[0]=char(179);//tanha
		break;
	case '�':
		cTemp[0]=char(184);//chasban
		if((pc==0)||(pc==' ')||(pc=='�')||(pc=='�')||(pc=='�')||(pc=='�')||(pc=='�')||(pc=='�')||(pc=='�')||(pc=='(')||(pc==')'))
			cTemp[0]=char(183);//tanha
		break;
	case '�':
		cTemp[0]=char(190);//chasban
		if((pc==0)||(pc==' ')||(pc=='�')||(pc=='�')||(pc=='�')||(pc=='�')||(pc=='�')||(pc=='�')||(pc=='�')||(pc=='(')||(pc==')'))
			cTemp[0]=char(189);//tanha
		break;
	case '�':
		cTemp[0]=char(188);//chasban
		if((pc==0)||(pc==' ')||(pc=='�')||(pc=='�')||(pc=='�')||(pc=='�')||(pc=='�')||(pc=='�')||(pc=='�')||(pc=='(')||(pc==')'))
			cTemp[0]=char(187);//tanha
		break;
	case '�':
		cTemp[0]=char(194);//chasban
		if((pc==0)||(pc==' ')||(pc=='�')||(pc=='�')||(pc=='�')||(pc=='�')||(pc=='�')||(pc=='�')||(pc=='�')||(pc=='(')||(pc==')'))
			cTemp[0]=char(193);//tanha
		break;
	default:
		cTemp[0]=c;
	}
//	strrev(cTemp);
	return CString(cTemp);
}

CString CMaryamString::GetSmall(char c, char pc)
{
	TCHAR cTemp[2];
	cTemp[1]='\0';
	switch(c)
	{
	case '(':
		cTemp[0]=')';
		break;
	case ')':
		cTemp[0]='(';
		break;
	case '�':
		cTemp[0]=char(65);//tanha
		break;
	case '�':
		cTemp[0]=char(73);//chasban
		if((pc==0)||(pc==' ')||(pc=='�')||(pc=='�')||(pc=='�')||(pc=='�')||(pc=='�')||(pc=='�')||(pc=='�')||(pc=='(')||(pc==')')||(pc=='(')||(pc==')'))
			cTemp[0]=char(72);//tanha
		break;
	case '�':
		cTemp[0]=char(70);//vasat
		if((pc==0)||(pc==' ')||(pc=='�')||(pc=='�')||(pc=='�')||(pc=='�')||(pc=='�')||(pc=='�')||(pc=='�')||(pc=='(')||(pc==')'))
			cTemp[0]=char(71);;//avval
		
		break;
	case '�':
		cTemp[0]=char(195);//chasban
		if((pc==0)||(pc==' ')||(pc=='�')||(pc=='�')||(pc=='�')||(pc=='�')||(pc=='�')||(pc=='�')||(pc=='�')||(pc=='(')||(pc==')'))
			cTemp[0]=char(196);//tanha
		break;
	case '�':
		cTemp[0]=char(188);//chasban
		if((pc==0)||(pc==' ')||(pc=='�')||(pc=='�')||(pc=='�')||(pc=='�')||(pc=='�')||(pc=='�')||(pc=='�')||(pc=='(')||(pc==')'))
			cTemp[0]=char(187);//tanha
		break;
	case '�':
		cTemp[0]=char(191);//chasban
		if((pc==0)||(pc==' ')||(pc=='�')||(pc=='�')||(pc=='�')||(pc=='�')||(pc=='�')||(pc=='�')||(pc=='�')||(pc=='(')||(pc==')'))
			cTemp[0]=char(192);//tanha

		break;
	case '�':
		cTemp[0]=char(185);//chasban
		if((pc==0)||(pc==' ')||(pc=='�')||(pc=='�')||(pc=='�')||(pc=='�')||(pc=='�')||(pc=='�')||(pc=='�')||(pc=='(')||(pc==')'))
			cTemp[0]=char(186);//tanha
		break;
	case '�':
		cTemp[0]=char(181);//chasban
		if((pc==0)||(pc==' ')||(pc=='�')||(pc=='�')||(pc=='�')||(pc=='�')||(pc=='�')||(pc=='�')||(pc=='�')||(pc=='(')||(pc==')'))
			cTemp[0]=char(182);//tanha
		break;
	case '�':
		cTemp[0]=char(177);//chasban
		if((pc==0)||(pc==' ')||(pc=='�')||(pc=='�')||(pc=='�')||(pc=='�')||(pc=='�')||(pc=='�')||(pc=='�')||(pc=='(')||(pc==')'))
			cTemp[0]=char(178);//tanha
		break;
	case '�':
		cTemp[0]=char(171);//chasban
		if((pc==0)||(pc==' ')||(pc=='�')||(pc=='�')||(pc=='�')||(pc=='�')||(pc=='�')||(pc=='�')||(pc=='�')||(pc=='(')||(pc==')'))
			cTemp[0]=char(172);//tanha
		break;
	case '�':
		cTemp[0]=char(167);//chasban
		if((pc==0)||(pc==' ')||(pc=='�')||(pc=='�')||(pc=='�')||(pc=='�')||(pc=='�')||(pc=='�')||(pc=='�')||(pc=='(')||(pc==')'))
			cTemp[0]=char(168);//tanha
		break;
	case '�':
		cTemp[0]=char(163);//chasban
		if((pc==0)||(pc==' ')||(pc=='�')||(pc=='�')||(pc=='�')||(pc=='�')||(pc=='�')||(pc=='�')||(pc=='�')||(pc=='(')||(pc==')'))
			cTemp[0]=char(164);//tanha
		break;
	case '�':
		//cTemp[0]=char(159);//chasban
		cTemp[0]=char(160);//chasban
		if((pc==0)||(pc==' ')||(pc=='�')||(pc=='�')||(pc=='�')||(pc=='�')||(pc=='�')||(pc=='�')||(pc=='�')||(pc=='(')||(pc==')'))
			cTemp[0]=char(160);//tanha
		break;
	case '�':
		cTemp[0]=char(153);//chasban
		if((pc==0)||(pc==' ')||(pc=='�')||(pc=='�')||(pc=='�')||(pc=='�')||(pc=='�')||(pc=='�')||(pc=='�')||(pc=='(')||(pc==')'))
			cTemp[0]=char(154);//tanha
		break;
	case '�':
		cTemp[0]=char(149);//chasban
		if((pc==0)||(pc==' ')||(pc=='�')||(pc=='�')||(pc=='�')||(pc=='�')||(pc=='�')||(pc=='�')||(pc=='�')||(pc=='(')||(pc==')'))
			cTemp[0]=char(150);//tanha
		break;
	case '�':
		cTemp[0]=char(145);//chasban
		if((pc==0)||(pc==' ')||(pc=='�')||(pc=='�')||(pc=='�')||(pc=='�')||(pc=='�')||(pc=='�')||(pc=='�')||(pc=='(')||(pc==')'))
			cTemp[0]=char(146);//tanha

		break;
	case '�':
		cTemp[0]=char(137);//chasban
		if((pc==0)||(pc==' ')||(pc=='�')||(pc=='�')||(pc=='�')||(pc=='�')||(pc=='�')||(pc=='�')||(pc=='�')||(pc=='(')||(pc==')'))
			cTemp[0]=char(138);//tanha
		break;
	case '�':
		cTemp[0]=char(133); //vasat
		if((pc==0)||(pc==' ')||(pc=='�')||(pc=='�')||(pc=='�')||(pc=='�')||(pc=='�')||(pc=='�')||(pc=='�')||(pc=='(')||(pc==')'))
			cTemp[0]=char(134); //avval
		break;
	case '�':
		//cTemp[0]=char(126); //vasat
		if((pc==0)||(pc==' ')||(pc=='�')||(pc=='�')||(pc=='�')||(pc=='�')||(pc=='�')||(pc=='�')||(pc=='�')||(pc=='(')||(pc==')'))
			cTemp[0]=char(130); //avval
		break;
	case '�':
		cTemp[0]='z'; //vasat
		if((pc==0)||(pc==' ')||(pc=='�')||(pc=='�')||(pc=='�')||(pc=='�')||(pc=='�')||(pc=='�')||(pc=='�')||(pc=='(')||(pc==')'))
			cTemp[0]=char(123); //avval
		break;
	case '�':
		cTemp[0]='v'; //vasat
		if((pc==0)||(pc==' ')||(pc=='�')||(pc=='�')||(pc=='�')||(pc=='�')||(pc=='�')||(pc=='�')||(pc=='�')||(pc=='(')||(pc==')'))
			cTemp[0]='w'; //avval
		break;
	case '�':
		cTemp[0]='m'; //chasban
		if((pc==0)||(pc==' ')||(pc=='�')||(pc=='�')||(pc=='�')||(pc=='�')||(pc=='�')||(pc=='�')||(pc=='�')||(pc=='(')||(pc==')'))
			cTemp[0]='l'; //tanha
		break;
	case '�':
		cTemp[0]='k'; //chasban
		if((pc==0)||(pc==' ')||(pc=='�')||(pc=='�')||(pc=='�')||(pc=='�')||(pc=='�')||(pc=='�')||(pc=='�')||(pc=='(')||(pc==')'))
			cTemp[0]='j'; //tanha
		break;
	case '�':
		cTemp[0]='s'; //chasban
		if((pc==0)||(pc==' ')||(pc=='�')||(pc=='�')||(pc=='�')||(pc=='�')||(pc=='�')||(pc=='�')||(pc=='�')||(pc=='(')||(pc==')'))
			cTemp[0]='r'; //tanha
		break;
	case '�':
		cTemp[0]='q'; //chasban
		if((pc==0)||(pc==' ')||(pc=='�')||(pc=='�')||(pc=='�')||(pc=='�')||(pc=='�')||(pc=='�')||(pc=='�')||(pc=='(')||(pc==')'))
			cTemp[0]='p'; //tanha
		break;
	case '�':
		cTemp[0]='o'; //chasban
		if((pc==0)||(pc==' ')||(pc=='�')||(pc=='�')||(pc=='�')||(pc=='�')||(pc=='�')||(pc=='�')||(pc=='�')||(pc=='(')||(pc==')'))
			cTemp[0]='n'; //tanha
		break;
	case '�':
		cTemp[0]=char(96); //chasban
		if((pc==0)||(pc==' ')||(pc=='�')||(pc=='�')||(pc=='�')||(pc=='�')||(pc=='�')||(pc=='�')||(pc=='�')||(pc=='(')||(pc==')'))
			cTemp[0]=char(97); //'a' //tanha
		break;
	case '�':
		cTemp[0]='h'; //vasat
		if((pc==0)||(pc==' ')||(pc=='�')||(pc=='�')||(pc=='�')||(pc=='�')||(pc=='�')||(pc=='�')||(pc=='�')||(pc=='(')||(pc==')'))
			cTemp[0]='i'; //avval
		break;
	case '�':
		cTemp[0]='d';//vasat
		if((pc==0)||(pc==' ')||(pc=='�')||(pc=='�')||(pc=='�')||(pc=='�')||(pc=='�')||(pc=='�')||(pc=='�')||(pc=='(')||(pc==')'))
			cTemp[0]='e';//avval
		break;
	case '�':
		cTemp[0]=char(92); //chasban
		if((pc==0)||(pc==' ')||(pc=='�')||(pc=='�')||(pc=='�')||(pc=='�')||(pc=='�')||(pc=='�')||(pc=='�')||(pc=='(')||(pc==')'))
			cTemp[0]=char(93); //tanha
		break;
	case '�':
		cTemp[0]=char(88);//vasat
		if((pc==0)||(pc==' ')||(pc=='�')||(pc=='�')||(pc=='�')||(pc=='�')||(pc=='�')||(pc=='�')||(pc=='�')||(pc=='(')||(pc==')'))
			cTemp[0]=char(89);//avval
		break;
	case '�':
		cTemp[0]=char(84);//vasat
		if((pc==0)||(pc==' ')||(pc=='�')||(pc=='�')||(pc=='�')||(pc=='�')||(pc=='�')||(pc=='�')||(pc=='�')||(pc=='(')||(pc==')'))
			cTemp[0]=char(85);//avval
		break;
	case '�':
		cTemp[0]=char(80);//vasat
		if((pc==0)||(pc==' ')||(pc=='�')||(pc=='�')||(pc=='�')||(pc=='�')||(pc=='�')||(pc=='�')||(pc=='�')||(pc=='(')||(pc==')'))
			cTemp[0]=char(81);//avval
		break;
	case '�':
		cTemp[0]=char(76);//vasat
		if((pc==0)||(pc==' ')||(pc=='�')||(pc=='�')||(pc=='�')||(pc=='�')||(pc=='�')||(pc=='�')||(pc=='�')||(pc=='(')||(pc==')'))
			cTemp[0]=char(77);//avval
		break;
	default:
		cTemp[0]=c;
	}	
	return CString(cTemp);
}

CString CMaryamString::GetString()
{
	return m_sText;
}
