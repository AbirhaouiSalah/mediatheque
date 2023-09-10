// Cd.cpp: implementation of the CCd class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "Gestion_mediatheque.h"
#include "Cd.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CCd::CCd()
{

}

CCd::~CCd()
{

}

CCd::CCd(CString t,CString r,vector<CExemplaire> tab,UINT d,CString a) : COeuvre (t,r,tab)
{
duree=d;
artiste=a;
}

CString& CCd::AtArtiste()
{
	return artiste;
}

UINT& CCd::AtDuree()
{
	return duree;
}

