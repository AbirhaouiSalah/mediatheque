#ifndef REVUE_H
#define REVUE_H

#include <iostream>
#include <fstream>
#include <cstring>
#include <string>
using namespace std;

#include "LIVRE.h"


class REVUE : public LIVRE
{
 private:

     unsigned int nb_article;
     string liste_nom_article;  // les noms d'articles sont de la forme : Nom1.Nom2.Nom3... 
     string editeur;

 public:
     REVUE();
     void ajouter(void);
     void detailler(void);
     bool contient(string recherche);
     void sauvegarder(ostream &);
     istream& charger(istream &);
     ~REVUE();
};

#endif