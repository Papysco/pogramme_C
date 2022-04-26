	#include <stdio.h>
	#include <stdlib.h>
	#include <string.h>
	#include "liste.h"

	// file articles 
	// -----------------------------------------

	article *saisirArticle(article *objet)
	{
		printf("Entrer le nom de l'article  : ");
		scanf("%s", objet->nom);
		printf("Entrer le prix de l'article : ");
		scanf("%d", &objet->prix);

		return objet;
	}

	//-----------------------------------------

	liste *initialisation(liste *l)
	{	
		// liste *l = malloc(sizeof(*l));
		article *objet = malloc(sizeof(*objet));
		/**/

		if (objet ==  NULL)
		{
			exit(EXIT_FAILURE);
		}

		objet = saisirArticle(objet);
		objet->next = NULL;
		l->firstElement = objet;

		return l;	
	}


	// -----------------------------------------
	// ajout dun article !

	void ajout(liste *l) {

		int rep = 1;

		do {
				article *objet = malloc(sizeof(*objet));
						
					if (objet == NULL) {
						exit(EXIT_FAILURE);
					}

				objet = saisirArticle(objet);
				objet->next = l->firstElement;
				l->firstElement = objet;

				printf("Voulez vous enrigistrer un nouveau article ? (1 : 0) : ");
				scanf("%d", &rep);
				printf("\n");
		}while(rep == 1);
		
	}


	void afficher(liste *l) {
		printf("\n");
		printf("AFFICHAGE\n");
		printf("*********\n");

		if (l == NULL)
		{
			printf("La liste est vide !\n");
			return;
		}

		article *objet = malloc(sizeof(*objet));

		objet = l->firstElement ;

		do{
			printf("\n");
			printf("Nom de l'article  : %s", objet->nom);printf("\n");
			printf("Prix de l'article : %d", objet->prix);
			objet = objet->next;
			printf("\n");
		}while(objet != NULL);

	}

// ----------------------------------------------------

	void supprimer(liste *l)
	{
		int rep = 1;
		// int echap = 0;
		char nomArticle[30];
		article *objet;
		article *objet2;

		printf("\n");
		printf("SUPPRESSION\n");
		printf("***********\n");

		do {
			printf("Entrer le nom de l'article que vous voulez supprimer : ");
			scanf("%s", nomArticle);

			objet = l->firstElement ;
				
				// while(echap == 0) 	// test du premier maillon 
				// {
				// 	echap = 1;
				// }

				if(strcmp(objet->nom, nomArticle) == 0)
				{
					// l->firstElement = objet->next;
					free(l->firstElement);
					printf("La liste est maintenant vide ! \n");
					return;
				}
				else{
					objet2 = l->firstElement;
					objet = objet2->next;

					while(objet != NULL){

						if(strcmp(objet->nom, nomArticle) == 0)
						{
							objet2->next = objet->next;
							free(objet);
							printf("Cette element est supprime ! \n");
							break;
						}

						objet = objet->next;
						objet2 = objet2->next;
					}
				}

			printf("Voulez vous supprimer une autre article ? : (1 : 0) ");
			scanf("%d", &rep);
		}while(rep == 1);
	}	


	liste triPrix(liste *l) {

		printf("Tri par le prix\n");
		printf("****************\n");

		article *objet;

		
	}



