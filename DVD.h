#ifndef DVD_H
#define DVD_H

#include <iostream>
#include <fstream>
#include <cstring>
#include <string>

#include "VHS.h"

using namespace std;

class DVD : public VHS
{
    public:
    
    DVD();
    void ajouter(void);
    void detailler(void);
    bool contient(string recherche);
    void sauvegarder(ostream &os);
    istream& charger(istream &is);
    ~DVD();

    private :

    int  nb_piste;
};

#endif