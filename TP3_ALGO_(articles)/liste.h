	#ifndef LISTE
	#define LISTE 

	#include <stdlib.h>
	#include <stdio.h>

	//----------------------------------

	typedef struct article
	{
		char nom[50];
		int prix;
		struct article *next;
	}article;


	typedef struct liste
	{
		article *firstElement;
	}liste;

	//--------------------------------
	//prototypes

	liste *initialisation(liste *l);

	article *saisirArticle(article *objet); 

	void afficher(liste *l);

	void ajout(liste *l);

	void supprimer(liste *l);

	liste triPrix(liste *l);


	#endif