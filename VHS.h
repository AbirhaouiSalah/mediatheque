#ifndef _CLASS_VHS_
#define _CLASS_VHS_

#include <cstdlib>
#include <iostream>
#include <string>
#include<fstream>

#include "Media.h"

using namespace std;

class VHS : public Media

{

 private:
      string duree;
      string maison_production;


 public :
      VHS();
      virtual void ajouter(void);
      virtual void detailler(void);
      virtual bool contient(string recherche);
      virtual void sauvegarder(ostream &);
      istream& charger(istream &);
      ~VHS();

};

#endif // _CLASS_VHS_
