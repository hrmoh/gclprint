; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CGCLPrintDoc
LastTemplate=CDialog
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "GCLPrint.h"
LastPage=0

ClassCount=19
Class1=CGCLPrintApp
Class2=CGCLPrintDoc
Class3=CGCLPrintView
Class4=CMainFrame

ResourceCount=28
Resource1=IDD_ABOUTBOX
Resource2=IDD_PRINTNOZPLDLG (Neutral (Default))
Resource7=IDD_CUSTOMER (Unknown language: 0x29
Class5=CAboutDlg
Resource3=IDD_PRINTREPDLG (Neutral (Default))
Resource4="IDR_NAVBAR" (English (U.S.))
Resource5=IDD_TITLES (Neutral (Default))
Resource6=IDD_ABOUTBOX (Neutral (Default))
Resource8=IDR_NAVBAR (English (U.S.))
Resource9=IDD_CUSTOMER (Unknown language: 0x29
Resource10=IDR_GRIDMENU (Neutral (Default))
Class6=CFindIDDlg
Resource11=IDD_GCLPRINT_FORM
Class7=CFindADDlg
Resource12=IDD_PATHS (Neutral (Default))
Class8=CCustomersDlg
Resource13=IDR_MAINFRAME
Class9=CPrintConfDlg
Class10=CMsgDlg
Class11=CSplashWnd
Resource14=IDD_GCLPRINT_FORM (English (U.S.))
Resource15=IDD_FINDAD (Neutral (Default))
Class12=CPathsDlg
Resource16=IDD_CUSTOMER (Unknown language: 0x29
Resource17=IDD_GENIDS (Neutral (Default))
Resource18=IDR_MAINFRAME (Neutral (Default))
Resource19=IDD_PRINTYPE (Neutral (Default))
Resource20=IDD_CUSTOMER
Class13=CTitlesDlg
Class14=CPrintProgressDlg
Resource21=IDD_FINDID (Neutral (Default))
Resource22=IDR_MAINFRAME (English (U.S.))
Class15=CRprtprnDlg
Resource23=IDD_PRINTDLG (Neutral (Default))
Class16=CManualReadDlg
Resource24=IDD_PRINTPROGRESSDLG
Class17=CGenIDsDlg
Resource25=IDD_MSG (Neutral (Default))
Class18=CPrintConfNoZPLDlg
Resource26=IDD_PRINTDLG (Neutral (Default) - A)
Resource27=IDD_INSERTCUSTOMER (Neutral (Default))
Class19=CLabelPrinterType
Resource28=IDR_PRNRPMENU (Neutral (Default))

[CLS:CGCLPrintApp]
Type=0
HeaderFile=GCLPrint.h
ImplementationFile=GCLPrint.cpp
Filter=N
LastObject=CGCLPrintApp
BaseClass=CWinApp
VirtualFilter=AC

[CLS:CGCLPrintDoc]
Type=0
HeaderFile=GCLPrintDoc.h
ImplementationFile=GCLPrintDoc.cpp
Filter=N
BaseClass=CDocument
VirtualFilter=DC
LastObject=IDC_FROM

[CLS:CGCLPrintView]
Type=0
HeaderFile=GCLPrintView.h
ImplementationFile=GCLPrintView.cpp
Filter=D
LastObject=CGCLPrintView
BaseClass=CFormView
VirtualFilter=VWC


[CLS:CMainFrame]
Type=0
HeaderFile=MainFrm.h
ImplementationFile=MainFrm.cpp
Filter=T
LastObject=ID_SETTINGS_PRINTERTYPE
BaseClass=CFrameWnd
VirtualFilter=fWC




[CLS:CAboutDlg]
Type=0
HeaderFile=GCLPrint.cpp
ImplementationFile=GCLPrint.cpp
Filter=D
LastObject=CAboutDlg

[DLG:IDD_ABOUTBOX]
Type=1
ControlCount=4
Control1=IDC_STATIC,static,1342177283
Control2=IDC_STATIC,static,1342308352
Control3=IDC_STATIC,static,1342308352
Control4=IDOK,button,1342373889
Class=CAboutDlg

[MNU:IDR_MAINFRAME]
Type=1
Class=CMainFrame
Command3=ID_FILE_SAVE
Command4=ID_FILE_SAVE_AS
Command5=ID_FILE_PRINT
Command6=ID_FILE_PRINT_PREVIEW
Command7=ID_FILE_PRINT_SETUP
Command8=ID_FILE_MRU_FILE1
Command9=ID_APP_EXIT
Command10=ID_EDIT_UNDO
Command11=ID_EDIT_CUT
Command12=ID_EDIT_COPY
Command13=ID_EDIT_PASTE
Command14=ID_VIEW_TOOLBAR
Command15=ID_VIEW_STATUS_BAR
CommandCount=16
Command1=ID_FILE_NEW
Command2=ID_FILE_OPEN
Command16=ID_APP_ABOUT

[ACL:IDR_MAINFRAME]
Type=1
Class=CMainFrame
Command1=ID_EDIT_COPY
Command2=ID_FILE_NEW
Command3=ID_FILE_PRINT
Command4=ID_FILE_SAVE
Command5=ID_EDIT_PASTE
Command6=ID_EDIT_UNDO
Command7=ID_EDIT_CUT
Command8=ID_FILE_OPEN
Command9=ID_FILE_FINDID
Command10=ID_FILE_FINDAD
Command11=ID_PREV_PANE
Command12=ID_EDIT_COPY
Command13=ID_EDIT_PASTE
Command14=ID_EDIT_CUT
Command15=ID_EDIT_UNDO
CommandCount=15

[DLG:IDD_GCLPRINT_FORM]
Type=1
Class=CGCLPrintView
ControlCount=1
Control1=IDC_FLXCUSTOMERS,{0ECD9B64-23AA-11D0-B351-00A0C9055D8E},1073807360

[DLG:IDD_GCLPRINT_FORM (English (U.S.))]
Type=1
Class=CGCLPrintView
ControlCount=1
Control1=IDC_FLXCUSTOMERS,{0ECD9B64-23AA-11D0-B351-00A0C9055D8E},1342242816

[ACL:IDR_MAINFRAME (English (U.S.))]
Type=1
Class=?
Command1=ID_EDIT_COPY
Command2=ID_FILE_NEW
Command3=ID_FILE_PRINT
Command4=ID_FILE_SAVE
Command5=ID_EDIT_PASTE
Command6=ID_EDIT_UNDO
Command7=ID_EDIT_CUT
Command8=ID_FILE_OPEN
Command9=ID_FILE_FINDID
Command10=ID_FILE_FINDAD
Command11=ID_PREV_PANE
Command12=ID_EDIT_COPY
Command13=ID_EDIT_PASTE
Command14=ID_EDIT_CUT
Command15=ID_EDIT_UNDO
CommandCount=15

[MNU:IDR_MAINFRAME (Neutral (Default))]
Type=1
Class=CMainFrame
Command1=ID_SETTINGS_PRINTERTYPE
CommandCount=1

[MNU:IDR_GRIDMENU (Neutral (Default))]
Type=1
Class=CGCLPrintView
CommandCount=0

[TB:"IDR_NAVBAR" (English (U.S.))]
Type=1
Class=?
CommandCount=0

[TB:IDR_NAVBAR (English (U.S.))]
Type=1
Class=?
Command1=ID_RECORD_LAST
Command2=ID_RECORD_NEXT
Command3=ID_RECORD_PREV
Command4=ID_RECORD_FIRST
CommandCount=4

[DLG:IDD_FINDID (Neutral (Default))]
Type=1
Class=CFindIDDlg
ControlCount=5
Control1=IDC_STATIC,static,1342308354
Control2=IDC_EID,edit,1350639746
Control3=IDC_PREV,button,1342275587
Control4=IDOK,button,1342242817
Control5=IDCANCEL,button,1342242816

[CLS:CFindIDDlg]
Type=0
HeaderFile=FindIDDlg.h
ImplementationFile=FindIDDlg.cpp
BaseClass=CDialog
Filter=D
LastObject=CFindIDDlg
VirtualFilter=dWC

[DLG:IDD_FINDAD (Neutral (Default))]
Type=1
Class=CFindADDlg
ControlCount=5
Control1=IDC_STATIC,static,1342308354
Control2=IDC_EAC,edit,1350639746
Control3=IDC_PREV,button,1342275587
Control4=IDOK,button,1342242817
Control5=IDCANCEL,button,1342242816

[CLS:CFindADDlg]
Type=0
HeaderFile=FindADDlg.h
ImplementationFile=FindADDlg.cpp
BaseClass=CDialog
Filter=D
LastObject=CFindADDlg
VirtualFilter=dWC

[DLG:IDD_CUSTOMER]
Type=1
Class=CCustomersDlg
ControlCount=25
Control1=IDC_STATIC,static,1342308352
Control2=IDC_STATIC,static,1342308352
Control3=IDC_STATIC,static,1342308352
Control4=IDC_STATIC,static,1342308352
Control5=IDC_STATIC,static,1342308352
Control6=IDC_STATIC,static,1342308352
Control7=IDC_STATIC,static,1342308352
Control8=IDC_STATIC,static,1342308352
Control9=IDC_STATIC,static,1342308352
Control10=IDC_STATIC,static,1342308352
Control11=IDC_ID,static,1342177282
Control12=IDC_NAME,static,1342177282
Control13=IDC_ADDRESS,static,1342177282
Control14=IDC_ADDRESSCODE,static,1342177282
Control15=IDC_PDATE,static,1342177282
Control16=IDC_PCON,static,1342177282
Control17=IDC_FREQUENCY,static,1342177282
Control18=IDC_QTYPE,static,1342177282
Control19=IDC_DCODE,static,1342177282
Control20=IDC_DATE,static,1342177282
Control21=IDOK,button,1342242817
Control22=IDC_STATIC,static,1342308352
Control23=IDC_STATIC,static,1342308352
Control24=IDC_SERIAL,static,1342177282
Control25=IDC_QUANT,static,1342177282

[CLS:CCustomersDlg]
Type=0
HeaderFile=CustomersDlg.h
ImplementationFile=CustomersDlg.cpp
BaseClass=CDialog
Filter=D
VirtualFilter=dWC
LastObject=IDC_ID

[CLS:CPrintConfDlg]
Type=0
HeaderFile=PrintConfDlg.h
ImplementationFile=PrintConfDlg.cpp
BaseClass=CDialog
Filter=D
LastObject=IDC_CHKPAUSE
VirtualFilter=dWC

[DLG:IDD_MSG (Neutral (Default))]
Type=1
Class=CMsgDlg
ControlCount=3
Control1=IDOK,button,1342242817
Control2=IDC_MESSAGE,static,1342177282
Control3=IDCANCEL,button,1342242816

[CLS:CMsgDlg]
Type=0
HeaderFile=MsgDlg.h
ImplementationFile=MsgDlg.cpp
BaseClass=CDialog
Filter=D
LastObject=IDC_MESSAGE
VirtualFilter=dWC

[DLG:IDD_ABOUTBOX (Neutral (Default))]
Type=1
Class=CAboutDlg
ControlCount=7
Control1=IDC_STATIC,static,1342308481
Control2=IDC_STATIC,static,1342308353
Control3=IDOK,button,1342373889
Control4=IDC_STATIC,static,1342308353
Control5=IDC_STATIC,static,1342308353
Control6=IDC_STATIC,static,1342308353
Control7=IDC_STATIC,static,1342177294

[CLS:CSplashWnd]
Type=0
HeaderFile=Splash.h
ImplementationFile=Splash.cpp
BaseClass=CWnd

[TB:IDR_MAINFRAME (Neutral (Default))]
Type=1
Class=?
Command1=ID_APP_ABOUT
Command2=ID_PRINT_CURRENTITEM
Command3=ID_SENDTOZ4M
Command4=ID_FILE_TITLES
Command5=ID_SEL_END
Command6=ID_SEL_START
Command7=ID_FILE_PRINTLIST
Command8=ID_FILE_DELCONTENTS
Command9=ID_FILE_SORTONAD
Command10=ID_FILE_SORTONID
Command11=ID_FILE_GENIDS
Command12=ID_FILE_INSERTDLG
Command13=ID_FILE_LOADLABELFILE
Command14=ID_FILE_OPEN
CommandCount=14

[DLG:IDD_PRINTDLG (Neutral (Default))]
Type=1
Class=CPrintConfDlg
ControlCount=29
Control1=IDOK,button,1342242817
Control2=IDCANCEL,button,1342242816
Control3=IDC_STATIC,button,1342177287
Control4=IDC_STATIC,static,1342308352
Control5=IDC_STATIC,static,1342308352
Control6=IDC_STATIC,button,1342177287
Control7=IDC_STATIC,static,1342308352
Control8=IDC_STATIC,static,1342308352
Control9=IDC_FROMID,static,1350697473
Control10=IDC_TOID,static,1350697473
Control11=IDC_FROMAC,static,1350697473
Control12=IDC_TOAC,static,1350697473
Control13=IDC_CHKPAUSE,button,1342242819
Control14=IDC_EPAUSEN,edit,1484857474
Control15=IDC_SPIN1,msctls_updown32,1342177594
Control16=IDC_STATIC,static,1342308352
Control17=IDC_CPORT,combobox,1344340227
Control18=IDC_STATIC,button,1342177287
Control19=IDC_DARKNESS,msctls_trackbar32,1342242825
Control20=IDC_STATIC,button,1342177287
Control21=IDC_STATIC,static,1342308352
Control22=IDC_STATIC,static,1342308352
Control23=IDC_STATIC,static,1342308352
Control24=IDC_STATIC,static,1342308352
Control25=IDC_CPRINTERSPEED,combobox,1344339971
Control26=IDC_LABELTYPE,button,1342308361
Control27=IDC_LABELTYPE2,button,1342177289
Control28=IDC_LABELTYPE3,button,1342177289
Control29=IDC_LABELTYPE4,button,1342177289

[DLG:IDD_PATHS (Neutral (Default))]
Type=1
Class=CPathsDlg
ControlCount=5
Control1=IDC_STATIC,static,1342308352
Control2=IDC_EMDB,edit,1342179456
Control3=IDC_CHANGE,button,1342242816
Control4=IDOK,button,1342242817
Control5=IDCANCEL,button,1342242816

[CLS:CPathsDlg]
Type=0
HeaderFile=PathsDlg.h
ImplementationFile=PathsDlg.cpp
BaseClass=CDialog
Filter=D
LastObject=CPathsDlg
VirtualFilter=dWC

[DLG:IDD_CUSTOMER (Unknown language: 0x29, 0x1)]
Type=1
Class=?
ControlCount=25
Control1=IDC_STATIC,static,1342308352
Control2=IDC_STATIC,static,1342308352
Control3=IDC_STATIC,static,1342308352
Control4=IDC_STATIC,static,1342308352
Control5=IDC_STATIC,static,1342308352
Control6=IDC_STATIC,static,1342308352
Control7=IDC_STATIC,static,1342308352
Control8=IDC_STATIC,static,1342308352
Control9=IDC_STATIC,static,1342308352
Control10=IDC_STATIC,static,1342308352
Control11=IDC_ID,static,1342177282
Control12=IDC_NAME,static,1342177282
Control13=IDC_ADDRESS,static,1342177282
Control14=IDC_ADDRESSCODE,static,1342177282
Control15=IDC_PDATE,static,1342177282
Control16=IDC_PCON,static,1342177282
Control17=IDC_FREQUENCY,static,1342177282
Control18=IDC_QTYPE,static,1342177282
Control19=IDC_DCODE,static,1342177282
Control20=IDC_DATE,static,1342177282
Control21=IDOK,button,1342242817
Control22=IDC_STATIC,static,1342308352
Control23=IDC_STATIC,static,1342308352
Control24=IDC_SERIAL,static,1342177282
Control25=IDC_QUANT,static,1342177282

[DLG:IDD_TITLES (Neutral (Default))]
Type=1
Class=CTitlesDlg
ControlCount=6
Control1=IDC_STATIC,static,1342308352
Control2=IDC_ECOMPANY,edit,1350631552
Control3=IDC_STATIC,static,1342308352
Control4=IDC_EREGION,edit,1350631552
Control5=IDOK,button,1342242817
Control6=IDCANCEL,button,1342242816

[CLS:CTitlesDlg]
Type=0
HeaderFile=TitlesDlg.h
ImplementationFile=TitlesDlg.cpp
BaseClass=CDialog
Filter=D
VirtualFilter=dWC
LastObject=CTitlesDlg

[DLG:IDD_PRINTPROGRESSDLG]
Type=1
Class=CPrintProgressDlg
ControlCount=7
Control1=IDC_PRINTPROGRESS,msctls_progress32,1350565888
Control2=IDC_SNOWPRINTING,static,1342308353
Control3=IDC_SPEEDSLIDER,msctls_trackbar32,1342242817
Control4=IDC_STATIC,static,1342308352
Control5=IDC_PAUSE,button,1342242817
Control6=IDCANCEL,button,1342242816
Control7=IDC_BACK,button,1476460544

[CLS:CPrintProgressDlg]
Type=0
HeaderFile=PrintProgressDlg.h
ImplementationFile=PrintProgressDlg.cpp
BaseClass=CDialog
Filter=D
LastObject=IDC_BACK
VirtualFilter=dWC

[DLG:IDD_PRINTREPDLG (Neutral (Default))]
Type=1
Class=CRprtprnDlg
ControlCount=2
Control1=IDC_STATIC,static,1342312961
Control2=IDC_STITLE,static,1342312961

[MNU:IDR_PRNRPMENU (Neutral (Default))]
Type=1
Class=?
CommandCount=0

[CLS:CRprtprnDlg]
Type=0
HeaderFile=RprtprnDlg.h
ImplementationFile=RprtprnDlg.cpp
BaseClass=CDialog
Filter=D
VirtualFilter=dWC
LastObject=IDC_STITLE

[DLG:IDD_INSERTCUSTOMER (Neutral (Default))]
Type=1
Class=CManualReadDlg
ControlCount=12
Control1=IDC_STATIC,static,1342308352
Control2=IDC_FIELD1,edit,1342251136
Control3=IDC_STATIC,static,1342308352
Control4=IDC_FIELD2,edit,1342251136
Control5=IDC_STATIC,static,1342308352
Control6=IDC_FIELD3,edit,1342251136
Control7=IDC_STATIC,static,1342308352
Control8=IDC_FIELD4,edit,1342242944
Control9=IDC_STATIC,static,1342308352
Control10=IDC_FIELD5,edit,1342242944
Control11=IDOK,button,1342242817
Control12=IDCANCEL,button,1342242816

[CLS:CManualReadDlg]
Type=0
HeaderFile=ManualReadDlg.h
ImplementationFile=ManualReadDlg.cpp
BaseClass=CDialog
Filter=D
VirtualFilter=dWC

[DLG:IDD_GENIDS (Neutral (Default))]
Type=1
Class=CGenIDsDlg
ControlCount=7
Control1=IDC_STATIC,static,1342308352
Control2=IDC_FROM,edit,1350639744
Control3=IDC_STATIC,static,1342308352
Control4=IDC_TO,edit,1350639744
Control5=IDOK,button,1342242817
Control6=IDCANCEL,button,1342242816
Control7=IDC_STATIC,static,1342308352

[CLS:CGenIDsDlg]
Type=0
HeaderFile=GenIDsDlg.h
ImplementationFile=GenIDsDlg.cpp
BaseClass=CDialog
Filter=D
VirtualFilter=dWC
LastObject=CGenIDsDlg

[DLG:IDD_PRINTNOZPLDLG (Neutral (Default))]
Type=1
Class=CPrintConfNoZPLDlg
ControlCount=23
Control1=IDOK,button,1342242817
Control2=IDCANCEL,button,1342242816
Control3=65535,button,1342177287
Control4=65535,static,1342308352
Control5=65535,static,1342308352
Control6=65535,button,1342177287
Control7=65535,static,1342308352
Control8=65535,static,1342308352
Control9=IDC_FROMID,static,1350697473
Control10=IDC_TOID,static,1350697473
Control11=IDC_FROMAC,static,1350697473
Control12=IDC_TOAC,static,1350697473
Control13=IDC_CHKPAUSE,button,1342242819
Control14=IDC_EPAUSEN,edit,1484857474
Control15=IDC_SPIN1,msctls_updown32,1342177594
Control16=65535,button,1342177287
Control17=65535,button,1342177287
Control18=65535,static,1342308352
Control19=IDC_CPRINTERSPEED,combobox,1344339971
Control20=IDC_LABELTYPE,button,1342308361
Control21=IDC_LABELTYPE2,button,1342177289
Control22=IDC_LABELTYPE3,button,1476395017
Control23=IDC_LABELTYPE4,button,1476395017

[CLS:CPrintConfNoZPLDlg]
Type=0
HeaderFile=PrintConfNoZPLDlg.h
ImplementationFile=PrintConfNoZPLDlg.cpp
BaseClass=CDialog
Filter=D
LastObject=65535
VirtualFilter=dWC

[DLG:IDD_PRINTDLG (Neutral (Default) - A)]
Type=1
Class=CPrintConfDlg
ControlCount=29
Control1=IDOK,button,1342242817
Control2=IDCANCEL,button,1342242816
Control3=IDC_STATIC,button,1342177287
Control4=IDC_STATIC,static,1342308352
Control5=IDC_STATIC,static,1342308352
Control6=IDC_STATIC,button,1342177287
Control7=IDC_STATIC,static,1342308352
Control8=IDC_STATIC,static,1342308352
Control9=IDC_FROMID,static,1350697473
Control10=IDC_TOID,static,1350697473
Control11=IDC_FROMAC,static,1350697473
Control12=IDC_TOAC,static,1350697473
Control13=IDC_CHKPAUSE,button,1342242819
Control14=IDC_EPAUSEN,edit,1484857474
Control15=IDC_SPIN1,msctls_updown32,1342177594
Control16=IDC_STATIC,static,1342308352
Control17=IDC_CPORT,combobox,1344340227
Control18=IDC_STATIC,button,1342177287
Control19=IDC_DARKNESS,msctls_trackbar32,1342242825
Control20=IDC_STATIC,button,1342177287
Control21=IDC_STATIC,static,1342308352
Control22=IDC_STATIC,static,1342308352
Control23=IDC_STATIC,static,1342308352
Control24=IDC_STATIC,static,1342308352
Control25=IDC_CPRINTERSPEED,combobox,1344339971
Control26=IDC_LABELTYPE,button,1342308361
Control27=IDC_LABELTYPE2,button,1342177289
Control28=IDC_LABELTYPE3,button,1342177289
Control29=IDC_LABELTYPE4,button,1342177289

[DLG:IDD_PRINTYPE (Neutral (Default))]
Type=1
Class=CLabelPrinterType
ControlCount=4
Control1=IDOK,button,1342242817
Control2=IDCANCEL,button,1342242816
Control3=IDC_RPRINTYPE,button,1342308361
Control4=IDC_RPRINTYPE2,button,1342177289

[CLS:CLabelPrinterType]
Type=0
HeaderFile=LabelPrinterType.h
ImplementationFile=LabelPrinterType.cpp
BaseClass=CDialog
Filter=D
LastObject=CLabelPrinterType
VirtualFilter=dWC

