; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CDlg_EmpRest
LastTemplate=CDialog
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "Gestion_mediatheque.h"
LastPage=0

ClassCount=9
Class1=CGestion_mediathequeApp
Class2=CGestion_mediathequeDoc
Class3=CGestion_mediathequeView
Class4=CMainFrame

ResourceCount=6
Resource1=IDR_MAINFRAME
Resource2=IDD_DLG_ADH
Class5=CAboutDlg
Resource3=IDD_ABOUTBOX
Class6=CDlg_Adh
Resource4=IDD_GESTION_MEDIATHEQUE_FORM
Class7=CDlg_Ouvr
Resource5=IDD_OEUVRE
Class8=CDlg_EmpRest
Class9=CDlg_Exe
Resource6=IDD_EMPR_REST

[CLS:CGestion_mediathequeApp]
Type=0
HeaderFile=Gestion_mediatheque.h
ImplementationFile=Gestion_mediatheque.cpp
Filter=N

[CLS:CGestion_mediathequeDoc]
Type=0
HeaderFile=Gestion_mediathequeDoc.h
ImplementationFile=Gestion_mediathequeDoc.cpp
Filter=N
BaseClass=CDocument
VirtualFilter=DC

[CLS:CGestion_mediathequeView]
Type=0
HeaderFile=Gestion_mediathequeView.h
ImplementationFile=Gestion_mediathequeView.cpp
Filter=D
LastObject=CGestion_mediathequeView
BaseClass=CFormView
VirtualFilter=VWC


[CLS:CMainFrame]
Type=0
HeaderFile=MainFrm.h
ImplementationFile=MainFrm.cpp
Filter=T
LastObject=IDC_EXEMPLAIRE




[CLS:CAboutDlg]
Type=0
HeaderFile=Gestion_mediatheque.cpp
ImplementationFile=Gestion_mediatheque.cpp
Filter=D

[DLG:IDD_ABOUTBOX]
Type=1
Class=CAboutDlg
ControlCount=4
Control1=IDC_STATIC,static,1342177283
Control2=IDC_STATIC,static,1342308480
Control3=IDC_STATIC,static,1342308352
Control4=IDC_STATIC,static,1342308352

[MNU:IDR_MAINFRAME]
Type=1
Class=CMainFrame
Command1=ID_FILE_NEW
Command2=ID_FILE_OPEN
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
Command16=ID_OEUVRES
Command17=ID_ADH
Command18=ID_EMPRUNTER
Command19=ID_RESTITUER
Command20=ID_APP_ABOUT
CommandCount=20

[ACL:IDR_MAINFRAME]
Type=1
Class=CMainFrame
Command1=ID_FILE_NEW
Command2=ID_FILE_OPEN
Command3=ID_FILE_SAVE
Command4=ID_FILE_PRINT
Command5=ID_EDIT_UNDO
Command6=ID_EDIT_CUT
Command7=ID_EDIT_COPY
Command8=ID_EDIT_PASTE
Command9=ID_EDIT_UNDO
Command10=ID_EDIT_CUT
Command11=ID_EDIT_COPY
Command12=ID_EDIT_PASTE
Command13=ID_NEXT_PANE
Command14=ID_PREV_PANE
CommandCount=14

[DLG:IDD_GESTION_MEDIATHEQUE_FORM]
Type=1
Class=CGestion_mediathequeView
ControlCount=5
Control1=IDC_STATIC,static,1342308352
Control2=IDC_STATIC,static,1342308352
Control3=IDC_STATIC,static,1342308352
Control4=IDC_STATIC,static,1342308352
Control5=IDC_STATIC,static,1342308352

[TB:IDR_MAINFRAME]
Type=1
Class=?
Command1=ID_FILE_NEW
Command2=ID_FILE_OPEN
Command3=ID_FILE_SAVE
Command4=ID_EDIT_CUT
Command5=ID_EDIT_COPY
Command6=ID_EDIT_PASTE
Command7=ID_FILE_PRINT
Command8=ID_APP_ABOUT
CommandCount=8

[DLG:IDD_DLG_ADH]
Type=1
Class=CDlg_Adh
ControlCount=24
Control1=IDC_MAT,edit,1350631552
Control2=IDC_NOM,edit,1350631552
Control3=IDC_PRENOM,edit,1350631552
Control4=IDC_AGE,edit,1350631552
Control5=IDC_ADR,edit,1350631552
Control6=IDC_EMAIL,edit,1350631552
Control7=IDC_PREV,button,1342242816
Control8=IDC_ADD,button,1342242816
Control9=IDC_MODIFY,button,1342242816
Control10=IDC_DELETE,button,1342242816
Control11=IDC_NEXT,button,1342242816
Control12=IDC_SEARCH,edit,1350631552
Control13=IDC_FIND,button,1342242816
Control14=IDC_LISTER,button,1342242816
Control15=IDC_STATIC,static,1342308352
Control16=IDC_STATIC,static,1342308352
Control17=IDC_STATIC,static,1342308352
Control18=IDC_STATIC,static,1342308352
Control19=IDC_STATIC,static,1342308352
Control20=IDC_STATIC,static,1342308352
Control21=IDC_STATIC,button,1342177287
Control22=IDC_STATIC,static,1342308352
Control23=IDC_STATIC,button,1342177287
Control24=IDC_LIST_ADH,SysListView32,1350631429

[CLS:CDlg_Adh]
Type=0
HeaderFile=Dlg_Adh.h
ImplementationFile=Dlg_Adh.cpp
BaseClass=CDialog
Filter=D
LastObject=IDC_LIST_ADH
VirtualFilter=dWC

[DLG:IDD_OEUVRE]
Type=1
Class=CDlg_Ouvr
ControlCount=48
Control1=IDC_TITRE,edit,1350631552
Control2=IDC_RESUME,edit,1350631552
Control3=IDC_RADIO_LIVRE,button,1342242825
Control4=IDC_RADIO_CD,button,1342242825
Control5=IDC_VALID,button,1342242816
Control6=IDC_ISBN,edit,1350631552
Control7=IDC_AUTEUR,edit,1350631552
Control8=IDC_LREF1,edit,1350631552
Control9=IDC_LREF2,edit,1350631552
Control10=IDC_LREF3,edit,1350631552
Control11=IDC_DUREE,edit,1350631552
Control12=IDC_ARTISTE,edit,1350631552
Control13=IDC_CREF1,edit,1350631552
Control14=IDC_CREF2,edit,1350631552
Control15=IDC_CREF3,edit,1350631552
Control16=IDC_AJOUT,button,1342242816
Control17=IDC_LISTER,button,1342242816
Control18=IDC_PREV,button,1342242816
Control19=IDC_MODIF,button,1342242816
Control20=IDC_SUPP,button,1342242816
Control21=IDC_NEXT,button,1342242816
Control22=IDC_PREVC,button,1342242816
Control23=IDC_MODIFC,button,1342242816
Control24=IDC_SUPPC,button,1342242816
Control25=IDC_STATIC,static,1342308352
Control26=IDC_STATIC,static,1342308352
Control27=IDC_STATIC,static,1342308352
Control28=IDC_STATIC,button,1342177287
Control29=IDC_STATIC,button,1342177287
Control30=IDC_STATIC,static,1342308352
Control31=IDC_STATIC,static,1342308352
Control32=IDC_STATIC,static,1342308352
Control33=IDC_STATIC,button,1342177287
Control34=IDC_LIST_L,SysListView32,1350631429
Control35=IDC_LIST_C,SysListView32,1350631429
Control36=IDC_STATIC,button,1342177287
Control37=IDC_STATIC,static,1342308352
Control38=IDC_FIND,edit,1350631552
Control39=IDC_SEARCH,button,1342242816
Control40=IDC_STATIC,static,1342308352
Control41=IDC_STATIC,static,1342308352
Control42=IDC_NEXTC,button,1342242816
Control43=IDC_STATIC,static,1342308352
Control44=IDC_STATIC,static,1342308352
Control45=IDC_STATIC,static,1342308352
Control46=IDC_STATIC,static,1342308352
Control47=IDC_STATIC,static,1342308352
Control48=IDC_STATIC,static,1342308352

[CLS:CDlg_Ouvr]
Type=0
HeaderFile=Dlg_Ouvr.h
ImplementationFile=Dlg_Ouvr.cpp
BaseClass=CDialog
Filter=D
LastObject=CDlg_Ouvr
VirtualFilter=dWC

[DLG:IDD_EMPR_REST]
Type=1
Class=CDlg_EmpRest
ControlCount=13
Control1=IDC_COM_ADH,combobox,1344339970
Control2=IDC_LISTExe,listbox,1352728833
Control3=IDC_COMB_EMPL,combobox,1344340226
Control4=IDC_EMPRUNTL,button,1342242816
Control5=IDC_COMB_EMPC,combobox,1344340226
Control6=IDC_EMPRUNTC,button,1342242816
Control7=IDC_COMB_RES,combobox,1344340226
Control8=IDC_REST,button,1342242816
Control9=IDC_STATIC,static,1342308352
Control10=IDC_STATIC,static,1342308352
Control11=IDC_STATIC,button,1342177287
Control12=IDC_STATIC,button,1342177287
Control13=IDC_STATIC,button,1342177287

[CLS:CDlg_EmpRest]
Type=0
HeaderFile=Dlg_EmpRest.h
ImplementationFile=Dlg_EmpRest.cpp
BaseClass=CDialog
Filter=D
LastObject=IDC_LISTExe
VirtualFilter=dWC

[CLS:CDlg_Exe]
Type=0
HeaderFile=Dlg_Exe.h
ImplementationFile=Dlg_Exe.cpp
BaseClass=CDialog
Filter=D
LastObject=IDC_REF
VirtualFilter=dWC

