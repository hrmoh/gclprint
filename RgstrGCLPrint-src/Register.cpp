// Register.cpp: implementation of the CRegister class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "RgstrPDTMngr.h"
#include "Register.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////



CRegister::CRegister(char *pKey)
{
	
	parentKey=(char *)malloc(sizeof(char)*MAX_LENGTH);

	parentKey=strcpy(parentKey,pKey);

	DWORD dwDisposition=0;
	
	RegCreateKeyEx(HKEY_CURRENT_USER, parentKey,0, NULL, 0, KEY_ALL_ACCESS, NULL, &hKey, &dwDisposition);


}

CRegister::~CRegister()
{

}

char *CRegister::getRegValue(char *key,DWORD *aSize)
{
	DWORD dwType=REG_SZ;
	char *dest=NULL;

	

	DWORD dwDataSize=0;

	if(RegQueryValueEx(hKey, key, 0, &dwType,(PBYTE)NULL, &dwDataSize)==ERROR_SUCCESS && hKey!=NULL)
	{
			
			dest=(char *)malloc(sizeof(char)*dwDataSize);
			RegQueryValueEx(hKey, key, 0, &dwType,(PBYTE)(LPTSTR)dest,&dwDataSize);
	}
	else
	{
		return NULL;
	}

	
	*aSize=dwDataSize;
	dest[dwDataSize]='\0';
	return dest;
	
}


void CRegister::setRegValue(char *key,char * newValue,long actualSize)
{

	
	DWORD dwType=REG_SZ;
	
	if(hKey!=NULL)
	{
			 RegSetValueEx(hKey,_T(key),0,dwType,(const unsigned char *)newValue,actualSize);
	}
	

}
