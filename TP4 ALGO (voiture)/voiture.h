#include <stdbool.h>
#ifndef __VOITURE_H__
#define __VOITURE_H__ 

/*----------------------------------------------------------*/
 // structure

 typedef struct voiture
 {
 	char modele[50];
 	int num_mat;  
 	int nbr_km;
 	char etat;  // etat dispo : D || etat location : L
 	struct voiture *next;
 }voiture;

 typedef struct Liste
 {
 	voiture *first_element;
 } Liste;


/*----------------------------------------------------------*/
 // Prototypes

 voiture saisir(voiture car);  			// saisir information dune voiture
 Liste *initialiser(Liste *liste); 		// initialiser une liste
 Liste *ajouter(Liste *liste); 			// ajouter un enrigistrement
 void afficher(Liste *liste);			// afficher la liste
 bool is_empty_list(Liste *liste); 		// tester si la liste est vide 
 void louer(Liste *liste); 				// louer une voiture
 void retour(Liste *liste); 			// retourner une voiture
 void etat_voiture(Liste *liste); 		// savoir etat dune voiture
 void etat_parc(Liste *liste); 			// savoir etat du parc

#endif