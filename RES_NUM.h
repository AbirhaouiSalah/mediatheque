#ifndef RES_NUM_H
#define RES_NUM_H

#include <iostream>
#include <fstream>
#include <cstring>
#include <string>
using namespace std;

#include "Media.h"

class RES_NUM : public Media
{
    
 private :
      string format;
      string taille;
      string path;

 public :
      RES_NUM();
      void ajouter(void);
      void detailler(void);
      bool contient(string recherche);
      void sauvegarder(ostream &);
      istream& charger(istream &);
      ~RES_NUM();

};
#endif