// Cd.h: interface for the CCd class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_CD_H__B8D95DA2_65AC_4071_8D37_FB32AC63BD0B__INCLUDED_)
#define AFX_CD_H__B8D95DA2_65AC_4071_8D37_FB32AC63BD0B__INCLUDED_


#include "Oeuvre.h"

class CCd : public COeuvre
{
private :
UINT duree;
CString artiste;
public:
	CCd();
	virtual ~CCd();
	CCd(CString,CString,vector<CExemplaire>,UINT,CString);
	CString& AtArtiste();
	UINT& AtDuree();
};

#endif // !defined(AFX_CD_H__B8D95DA2_65AC_4071_8D37_FB32AC63BD0B__INCLUDED_)
