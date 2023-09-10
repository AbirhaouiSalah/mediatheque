// Exemplaire.cpp: implementation of the CExemplaire class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "Gestion_mediatheque.h"
#include "Exemplaire.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////


CExemplaire::CExemplaire()
{
	ptr= new COeuvre;
}

CExemplaire::CExemplaire(const CExemplaire& e)
{
	ref=e.ref;
	ptr=new COeuvre;
	*ptr=*e.ptr;
}

UINT& CExemplaire::AtRef()
{
	return ref;
}
CExemplaire::~CExemplaire()
{
	if(ptr) 
		delete [] ptr;
}

COeuvre& CExemplaire::AtPtr()
{
	return *ptr;
}