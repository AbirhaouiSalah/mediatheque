// Gestion_mediathequeView.h : interface of the CGestion_mediathequeView class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_GESTION_MEDIATHEQUEVIEW_H__F66846FC_8232_417F_BF17_BAE87D160A18__INCLUDED_)
#define AFX_GESTION_MEDIATHEQUEVIEW_H__F66846FC_8232_417F_BF17_BAE87D160A18__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CGestion_mediathequeView : public CFormView
{
protected: // create from serialization only
	CGestion_mediathequeView();
	DECLARE_DYNCREATE(CGestion_mediathequeView)

public:
	//{{AFX_DATA(CGestion_mediathequeView)
	enum{ IDD = IDD_GESTION_MEDIATHEQUE_FORM };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA

// Attributes
public:
	CGestion_mediathequeDoc* GetDocument();

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CGestion_mediathequeView)
	public:
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	virtual void OnInitialUpdate(); // called first time after construct
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnPrint(CDC* pDC, CPrintInfo* pInfo);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CGestion_mediathequeView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CGestion_mediathequeView)
	afx_msg void OnAdh();
	afx_msg void OnOeuvres();
	afx_msg void OnEmprunter();
	afx_msg void OnRestituer();
	
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in Gestion_mediathequeView.cpp
inline CGestion_mediathequeDoc* CGestion_mediathequeView::GetDocument()
   { return (CGestion_mediathequeDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_GESTION_MEDIATHEQUEVIEW_H__F66846FC_8232_417F_BF17_BAE87D160A18__INCLUDED_)
