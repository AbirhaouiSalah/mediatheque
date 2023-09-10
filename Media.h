#ifndef _CLASS_MEDIA_
#define _CLASS_MEDIA_

#include <cstdlib>
#include <iostream>
#include <string>
#include<fstream>


using namespace std;

class Media
{
 protected :
      string type;
      string etat;
      string titre;
      string auteur;
      string nombre_total;
      string nombre_restant;
      int nb_total;
      int nb_restant;
      unsigned int ID;


 public:
      Media();
      virtual void gen_ID(unsigned int id);
      virtual unsigned int get_id(void); // =0; pour definir une methode virtuele pure maison a pas reussi a le faire
      virtual void ajouter(void);
      
      virtual void detailler(void);
      void lister(void);
      virtual bool contient(string recherche);
      virtual void sauvegarder(ostream &);
      virtual istream& charger(istream &);
      virtual ~Media();
     
};

#endif // _CLASS_MEDIA_
