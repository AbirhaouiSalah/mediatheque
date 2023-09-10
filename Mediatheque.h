#ifndef Mediatheque_h
#define Mediatheque_h

#include <iostream>
#include <fstream>
#include <cstring>
#include <string>

#include "Media.h"

#include "CD.h"
#include "DVD.h"
#include "LIVRE.h"
#include "RES_NUM.h"
#include "REVUE.h"
#include "VHS.h"

using namespace std;

class Mediatheque

{


    public :

        Mediatheque();
        ~Mediatheque();

        void ADD (string);                    // .cette commande lancera la procédure permettant de créer une nouvelle ressource 
                                        // en fonction du type spécifié en paramètre.
       
        bool LOAD(const string &);      // .charger un fichier un fichier contenant les ressources disponibles dans la médiathèque.
                                        // La contenu de ce fichier viendra remplacer les données actuellement chargées dans l’outil.
       
        void SAVE(const string &);      // .cette commande permet à l’utilisateur de sauvegarder les données actuellement dans l’outil
                                        // dans le fichier dont le nom est spécifié en paramètre. Le format de sauvegarde des données
                                        // est laissé à votre discrétion

        unsigned int SEARCH(string);    // .cette fonction permet de rechercher dans la base de données les documents contenant la 
                                        // chaîne de caractères spécifiée en paramètre. Les résultats issus de la recherche 
                                        // rem- placeront temporairement la base de données courante pour faire en sorte que si 
                                        // l’utilisateur lance une seconde recherche elle ne s’appliquera que sur les résultats 
                                        // de la première recherche (recherche incrémentale).

        void CLEAR(void);                   // .cette commande permet de réinitialiser la base de données courante après une recherche. 
                                        // Si l’utilisateur emploie cette commande après avoir effectué une recherche alors, 
                                        // les résultats sont détruits et la future recherche s’appliquera à l’ensemble 
                                        // des ressources disponibles dans la média- thèque.

        void LIST(void);                // .cette fonction permet d’afficher de manière compacte les données contenues dans la base de données. 
                                        // Si une recherche a été lancée, alors cette commande ne doit afficher que 
                                        // les résultats de la recherche précédemment lancée.
        
        void SHOW_ID(unsigned int);     // .cette fonction doit permettre d’afficher les informations détaillées sur 
                                        //  une ressource précise contenue dans la médiathèque. Le paramètre passé lors de 
                                        //  l’appel de la procédure utilise un identifiant unique que doit posséder toute 
                                        //  ressource appartenant à la médiathèque (identifiant de l’objet par exemple => attribut static).

        void DELET_ID(unsigned int);    // .cette méthode permet de supprimer une ressource particulière appartenant à la médiathèque.
   

        void RESET();                   // .cette dernière méthode permet de supprimer toutes les ressources contenues dans la bibliothèque.
       
        void HELP();                    // .afficher le manuel de commande de notre programme


        void rebuild(void);

    private :

        int id_session;

        Media **liste_ok;
        Media **liste_neg;
        /*
        vector<Media> liste_ok;
        vector<Media> liste_neg;         
        */

    	int *liste_undo;
        

        unsigned int taille_liste_ok;
        unsigned int taille_liste_neg;

    	unsigned int taille_liste_undo;

        void reorganize(void);
        unsigned int position_media(unsigned int);




};

#endif //Mediatheque_H