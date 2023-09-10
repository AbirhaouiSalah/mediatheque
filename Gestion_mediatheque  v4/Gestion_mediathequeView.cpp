// Gestion_mediathequeView.cpp : implementation of the CGestion_mediathequeView class
//

#include "stdafx.h"
#include "Gestion_mediatheque.h"

#include "Gestion_mediathequeDoc.h"
#include "Gestion_mediathequeView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CGestion_mediathequeView

IMPLEMENT_DYNCREATE(CGestion_mediathequeView, CFormView)

BEGIN_MESSAGE_MAP(CGestion_mediathequeView, CFormView)
	//{{AFX_MSG_MAP(CGestion_mediathequeView)
	ON_COMMAND(ID_ADH, OnAdh)
	ON_COMMAND(ID_OEUVRES, OnOeuvres)
	ON_COMMAND(ID_EMPRUNTER, OnEmprunter)
	ON_COMMAND(ID_RESTITUER, OnRestituer)

	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CFormView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CFormView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CFormView::OnFilePrintPreview)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CGestion_mediathequeView construction/destruction

CGestion_mediathequeView::CGestion_mediathequeView()
: CFormView(CGestion_mediathequeView::IDD)
{
	//{{AFX_DATA_INIT(CGestion_mediathequeView)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
	// TODO: add construction code here

}

CGestion_mediathequeView::~CGestion_mediathequeView()
{
}

void CGestion_mediathequeView::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CGestion_mediathequeView)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}

BOOL CGestion_mediathequeView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CFormView::PreCreateWindow(cs);
}

void CGestion_mediathequeView::OnInitialUpdate()
{
	CFormView::OnInitialUpdate();
	GetParentFrame()->RecalcLayout();
	ResizeParentToFit();

}

/////////////////////////////////////////////////////////////////////////////
// CGestion_mediathequeView printing

BOOL CGestion_mediathequeView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CGestion_mediathequeView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CGestion_mediathequeView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

void CGestion_mediathequeView::OnPrint(CDC* pDC, CPrintInfo* /*pInfo*/)
{
	// TODO: add customized printing code here
}

/////////////////////////////////////////////////////////////////////////////
// CGestion_mediathequeView diagnostics

#ifdef _DEBUG
void CGestion_mediathequeView::AssertValid() const
{
	CFormView::AssertValid();
}

void CGestion_mediathequeView::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}

CGestion_mediathequeDoc* CGestion_mediathequeView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CGestion_mediathequeDoc)));
	return (CGestion_mediathequeDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CGestion_mediathequeView message handlers

void CGestion_mediathequeView::OnAdh() 
{
	// TODO: Add your command handler code here
	CGestion_mediathequeDoc* pDoc=this->GetDocument();
	ASSERT_VALID(pDoc);
	pDoc->AtDlg_Adh().DoModal();
	pDoc->SetModifiedFlag(true);
}

void CGestion_mediathequeView::OnOeuvres() 
{
	// TODO: Add your command handler code here
	CGestion_mediathequeDoc* pDoc=this->GetDocument();
	ASSERT_VALID(pDoc);
	pDoc->AtDlg_Ouvr().DoModal();
}

void CGestion_mediathequeView::OnEmprunter() 
{
	// TODO: Add your command handler code here
	CGestion_mediathequeDoc* pDoc=this->GetDocument();
	ASSERT_VALID(pDoc);
	pDoc->AtDlg_Emp().ptr_dlgAdh=&pDoc->AtDlg_Adh();
	pDoc->AtDlg_Emp().ptr_dlgoeuv=&pDoc->AtDlg_Ouvr();
	pDoc->AtDlg_Emp().DoModal();
}

void CGestion_mediathequeView::OnRestituer() 
{
	// TODO: Add your command handler code here
	CGestion_mediathequeDoc* pDoc=this->GetDocument();
	ASSERT_VALID(pDoc);
	pDoc->AtDlg_Emp().ptr_dlgAdh=&pDoc->AtDlg_Adh();
	pDoc->AtDlg_Emp().ptr_dlgoeuv=&pDoc->AtDlg_Ouvr();
	pDoc->AtDlg_Emp().DoModal();
}


