// Oeuvre.cpp: implementation of the COeuvre class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "Gestion_mediatheque.h"
#include "Oeuvre.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

COeuvre::COeuvre()
{

}

COeuvre::~COeuvre()
{

}

COeuvre::COeuvre(CString t,CString r,vector<CExemplaire> tab)
{
	Exemplaires=tab;
	titre=t;
	resume=r;
}

CString& COeuvre::AtResume()
{
	return resume;
}
CString& COeuvre::AtTitre()
{
	return titre;
}


vector<CExemplaire>& COeuvre::AtExemplaire()
{
	return Exemplaires;
}