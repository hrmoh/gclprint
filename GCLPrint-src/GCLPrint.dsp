# Microsoft Developer Studio Project File - Name="GCLPrint" - Package Owner=<4>
# Microsoft Developer Studio Generated Build File, Format Version 6.00
# ** DO NOT EDIT **

# TARGTYPE "Win32 (x86) Application" 0x0101

CFG=GCLPrint - Win32 Debug
!MESSAGE This is not a valid makefile. To build this project using NMAKE,
!MESSAGE use the Export Makefile command and run
!MESSAGE 
!MESSAGE NMAKE /f "GCLPrint.mak".
!MESSAGE 
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "GCLPrint.mak" CFG="GCLPrint - Win32 Debug"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "GCLPrint - Win32 Release" (based on "Win32 (x86) Application")
!MESSAGE "GCLPrint - Win32 Debug" (based on "Win32 (x86) Application")
!MESSAGE 

# Begin Project
# PROP AllowPerConfigDependencies 0
# PROP Scc_ProjName ""
# PROP Scc_LocalPath ""
CPP=cl.exe
MTL=midl.exe
RSC=rc.exe

!IF  "$(CFG)" == "GCLPrint - Win32 Release"

# PROP BASE Use_MFC 5
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "Release"
# PROP BASE Intermediate_Dir "Release"
# PROP BASE Target_Dir ""
# PROP Use_MFC 5
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "Release"
# PROP Intermediate_Dir "Release"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MT /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /Yu"stdafx.h" /FD /c
# ADD CPP /nologo /MT /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_MBCS" /Yu"stdafx.h" /FD /c
# ADD BASE MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD BASE RSC /l 0x429 /d "NDEBUG"
# ADD RSC /l 0x429 /d "NDEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 /nologo /subsystem:windows /machine:I386
# ADD LINK32 ComCtl32.lib /nologo /subsystem:windows /machine:I386

!ELSEIF  "$(CFG)" == "GCLPrint - Win32 Debug"

# PROP BASE Use_MFC 5
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "Debug"
# PROP BASE Intermediate_Dir "Debug"
# PROP BASE Target_Dir ""
# PROP Use_MFC 5
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "Debug"
# PROP Intermediate_Dir "Debug"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MTd /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /Yu"stdafx.h" /FD /GZ /c
# ADD CPP /nologo /MTd /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_MBCS" /FR /Yu"stdafx.h" /FD /GZ /c
# ADD BASE MTL /nologo /D "_DEBUG" /mktyplib203 /win32
# ADD MTL /nologo /D "_DEBUG" /mktyplib203 /win32
# ADD BASE RSC /l 0x429 /d "_DEBUG"
# ADD RSC /l 0x429 /d "_DEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 /nologo /subsystem:windows /debug /machine:I386 /pdbtype:sept
# ADD LINK32 /nologo /subsystem:windows /debug /machine:I386 /pdbtype:sept

!ENDIF 

# Begin Target

# Name "GCLPrint - Win32 Release"
# Name "GCLPrint - Win32 Debug"
# Begin Group "Source Files"

# PROP Default_Filter "cpp;c;cxx;rc;def;r;odl;idl;hpj;bat"
# Begin Source File

SOURCE=.\ado2.cpp
# End Source File
# Begin Source File

SOURCE=.\ADORecordsetPrinter.cpp
# End Source File
# Begin Source File

SOURCE=.\Barcode.cpp
# End Source File
# Begin Source File

SOURCE=.\Code128.cpp
# End Source File
# Begin Source File

SOURCE=.\CustomersDlg.cpp
# End Source File
# Begin Source File

SOURCE=.\Encrypt.cpp
# End Source File
# Begin Source File

SOURCE=.\FindADDlg.cpp
# End Source File
# Begin Source File

SOURCE=.\FindIDDlg.cpp
# End Source File
# Begin Source File

SOURCE=.\font.cpp
# End Source File
# Begin Source File

SOURCE=.\GCLPrint.cpp
# End Source File
# Begin Source File

SOURCE=.\GCLPrint.rc
# End Source File
# Begin Source File

SOURCE=.\GCLPrintDoc.cpp
# End Source File
# Begin Source File

SOURCE=.\GCLPrintView.cpp
# End Source File
# Begin Source File

SOURCE=.\GenIDsDlg.cpp
# End Source File
# Begin Source File

SOURCE=.\LabelPrinterType.cpp
# End Source File
# Begin Source File

SOURCE=.\MainFrm.cpp
# End Source File
# Begin Source File

SOURCE=.\ManualReadDlg.cpp
# End Source File
# Begin Source File

SOURCE=.\MaryamString.cpp
# End Source File
# Begin Source File

SOURCE=.\MsgDlg.cpp
# End Source File
# Begin Source File

SOURCE=.\mshflexgrid.cpp
# End Source File
# Begin Source File

SOURCE=.\PathsDlg.cpp
# End Source File
# Begin Source File

SOURCE=.\PersianPreviewView.cpp
# End Source File
# Begin Source File

SOURCE=.\picture.cpp
# End Source File
# Begin Source File

SOURCE=.\PrintConfDlg.cpp
# End Source File
# Begin Source File

SOURCE=.\PrintConfNoZPLDlg.cpp
# End Source File
# Begin Source File

SOURCE=.\PrintProgressDlg.cpp
# End Source File
# Begin Source File

SOURCE=.\RecodsetPrinterView.cpp
# End Source File
# Begin Source File

SOURCE=.\recordset4mshflexgrid.cpp
# End Source File
# Begin Source File

SOURCE=.\RprtprnDlg.cpp
# End Source File
# Begin Source File

SOURCE=.\Splash.cpp
# End Source File
# Begin Source File

SOURCE=.\StdAfx.cpp
# ADD CPP /Yc"stdafx.h"
# End Source File
# Begin Source File

SOURCE=.\TitlesDlg.cpp
# End Source File
# Begin Source File

SOURCE=.\WhiteListRs.cpp
# End Source File
# Begin Source File

SOURCE=.\ZplParser.cpp
# End Source File
# End Group
# Begin Group "Header Files"

# PROP Default_Filter "h;hpp;hxx;hm;inl"
# Begin Source File

SOURCE=.\ado2.h
# End Source File
# Begin Source File

SOURCE=.\ADORecordsetPrinter.h
# End Source File
# Begin Source File

SOURCE=.\Barcode.h
# End Source File
# Begin Source File

SOURCE=.\bblib.h
# End Source File
# Begin Source File

SOURCE=.\Code128.h
# End Source File
# Begin Source File

SOURCE=.\CustomersDlg.h
# End Source File
# Begin Source File

SOURCE=.\Encrypt.h
# End Source File
# Begin Source File

SOURCE=.\FindADDlg.h
# End Source File
# Begin Source File

SOURCE=.\FindIDDlg.h
# End Source File
# Begin Source File

SOURCE=.\font.h
# End Source File
# Begin Source File

SOURCE=.\GCLPrint.h
# End Source File
# Begin Source File

SOURCE=.\GCLPrintDoc.h
# End Source File
# Begin Source File

SOURCE=.\GCLPrintView.h
# End Source File
# Begin Source File

SOURCE=.\GenIDsDlg.h
# End Source File
# Begin Source File

SOURCE=.\LabelPrinterType.h
# End Source File
# Begin Source File

SOURCE=.\MainFrm.h
# End Source File
# Begin Source File

SOURCE=.\ManualReadDlg.h
# End Source File
# Begin Source File

SOURCE=.\MaryamString.h
# End Source File
# Begin Source File

SOURCE=.\MsgDlg.h
# End Source File
# Begin Source File

SOURCE=.\mshflexgrid.h
# End Source File
# Begin Source File

SOURCE=.\PathsDlg.h
# End Source File
# Begin Source File

SOURCE=.\PersianPreviewView.h
# End Source File
# Begin Source File

SOURCE=.\picture.h
# End Source File
# Begin Source File

SOURCE=.\PrintConfDlg.h
# End Source File
# Begin Source File

SOURCE=.\PrintConfNoZPLDlg.h
# End Source File
# Begin Source File

SOURCE=.\PrintProgressDlg.h
# End Source File
# Begin Source File

SOURCE=.\RecodsetPrinterView.h
# End Source File
# Begin Source File

SOURCE=.\recordset4mshflexgrid.h
# End Source File
# Begin Source File

SOURCE=.\Resource.h
# End Source File
# Begin Source File

SOURCE=.\RprtprnDlg.h
# End Source File
# Begin Source File

SOURCE=.\Splash.h
# End Source File
# Begin Source File

SOURCE=.\StdAfx.h
# End Source File
# Begin Source File

SOURCE=.\TitlesDlg.h
# End Source File
# Begin Source File

SOURCE=.\WhiteListRs.h
# End Source File
# Begin Source File

SOURCE=.\ZplParser.h
# End Source File
# End Group
# Begin Group "Resource Files"

# PROP Default_Filter "ico;cur;bmp;dlg;rc2;rct;bin;rgs;gif;jpg;jpeg;jpe"
# Begin Source File

SOURCE=.\res\arm.bmp
# End Source File
# Begin Source File

SOURCE=.\res\default1.bin
# End Source File
# Begin Source File

SOURCE=.\res\GCLPrint.ico
# End Source File
# Begin Source File

SOURCE=.\res\GCLPrint.rc2
# End Source File
# Begin Source File

SOURCE=.\res\GCLPrintDoc.ico
# End Source File
# Begin Source File

SOURCE=.\res\Logo.bmp
# End Source File
# Begin Source File

SOURCE=.\res\manifest.bin
# End Source File
# Begin Source File

SOURCE=.\res\navbar.bmp
# End Source File
# Begin Source File

SOURCE=.\Splsh16.bmp
# End Source File
# Begin Source File

SOURCE=.\res\Toolbar.bmp
# End Source File
# End Group
# Begin Source File

SOURCE=.\res\GCLPrint.exe.manifest
# End Source File
# End Target
# End Project
# Section GCLPrint : {BEF6E003-A874-101A-8BBA-00AA00300CAB}
# 	2:5:Class:COleFont
# 	2:10:HeaderFile:font.h
# 	2:8:ImplFile:font.cpp
# End Section
# Section GCLPrint : {0ECD9B64-23AA-11D0-B351-00A0C9055D8E}
# 	2:21:DefaultSinkHeaderFile:mshflexgrid.h
# 	2:16:DefaultSinkClass:CMSHFlexGrid
# End Section
# Section GCLPrint : {72ADFD78-2C39-11D0-9903-00A0C91BC942}
# 	1:10:IDB_SPLASH:103
# 	2:21:SplashScreenInsertKey:4.0
# End Section
# Section GCLPrint : {7BF80981-BF32-101A-8BBB-00AA00300CAB}
# 	2:5:Class:CPicture
# 	2:10:HeaderFile:picture.h
# 	2:8:ImplFile:picture.cpp
# End Section
# Section GCLPrint : {0ECD9B62-23AA-11D0-B351-00A0C9055D8E}
# 	2:5:Class:CMSHFlexGrid
# 	2:10:HeaderFile:mshflexgrid.h
# 	2:8:ImplFile:mshflexgrid.cpp
# End Section
# Section GCLPrint : {0000050E-0000-0010-8000-00AA006D2EA4}
# 	2:5:Class:CRecordset4MSHFlexGrid
# 	2:10:HeaderFile:recordset4mshflexgrid.h
# 	2:8:ImplFile:recordset4mshflexgrid.cpp
# End Section
