// Livre.cpp: implementation of the CLivre class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "Gestion_mediatheque.h"
#include "Livre.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CLivre::CLivre()
{

}

CLivre::~CLivre()
{

}

CLivre::CLivre(CString t,CString r,vector<CExemplaire> tab,UINT i, CString a) : COeuvre (t,r,tab)
{
isbn=i;
auteur=a;
}

UINT& CLivre::AtIsbn()
{
	return isbn;
}

CString& CLivre::AtAuteur()
{
	return auteur;
}

