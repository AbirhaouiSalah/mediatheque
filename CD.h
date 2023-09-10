#ifndef _CLASS_CD_
#define _CLASS_CD_

#include <cstdlib>
#include <iostream>
#include <string>
#include<fstream>

#include "VHS.h"

using namespace std;

class CD : public VHS 
{
 private :

     int nb_piste;


 public :
      CD();
      void ajouter();
      void detailler();
      bool contient(string recherche);
      void sauvegarder(ostream &);
      istream& charger(istream &);
      ~CD();
};

#endif // _CLASS_CD_
