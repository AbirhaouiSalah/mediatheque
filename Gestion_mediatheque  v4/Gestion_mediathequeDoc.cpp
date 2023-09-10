// Gestion_mediathequeDoc.cpp : implementation of the CGestion_mediathequeDoc class
//

#include "stdafx.h"
#include "Gestion_mediatheque.h"

#include "Gestion_mediathequeDoc.h"



#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CGestion_mediathequeDoc

IMPLEMENT_DYNCREATE(CGestion_mediathequeDoc, CDocument)

BEGIN_MESSAGE_MAP(CGestion_mediathequeDoc, CDocument)
	//{{AFX_MSG_MAP(CGestion_mediathequeDoc)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CGestion_mediathequeDoc construction/destruction

CGestion_mediathequeDoc::CGestion_mediathequeDoc()
{
	// TODO: add one-time construction code here

}

CGestion_mediathequeDoc::~CGestion_mediathequeDoc()
{
}

BOOL CGestion_mediathequeDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CGestion_mediathequeDoc serialization

void CGestion_mediathequeDoc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		// TODO: add storing code here
		dlg_des_adh.save(ar);
	}
	else
	{
		// TODO: add loading code here
		dlg_des_adh.load(ar);
	}
}

/////////////////////////////////////////////////////////////////////////////
// CGestion_mediathequeDoc diagnostics

#ifdef _DEBUG
void CGestion_mediathequeDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CGestion_mediathequeDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CGestion_mediathequeDoc commands

CDlg_Adh& CGestion_mediathequeDoc::AtDlg_Adh()
{
	return this->dlg_des_adh;
}

CDlg_Ouvr& CGestion_mediathequeDoc::AtDlg_Ouvr()
{
	return this->dlg_des_ouevres;
}
CDlg_EmpRest& CGestion_mediathequeDoc::AtDlg_Emp()
{
	return this->dlgEmp;
}


