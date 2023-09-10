#ifndef LIVRE_H
#define LIVRE_H


#include <iostream>
#include <ostream>
#include <string>
#include<fstream>

#include "Media.h"

using namespace std;

class LIVRE : public Media
{   
    private:

    string  nb_page;
    string  collection;
    string  annee_pub;
    string  RESUME;

    public :

    LIVRE();
    virtual void ajouter();
      
    virtual void detailler();
    virtual bool contient(string recherche);
    virtual void sauvegarder(ostream &os);
    virtual istream& charger(istream &is);
    ~LIVRE();
};

#endif