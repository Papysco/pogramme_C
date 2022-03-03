#include <stdio.h>
#include <stdlib.h>
#include "voiture.h"

/*----------------------------------------------------------*/
	 voiture saisir(voiture car)
	 {
	 	printf("Entrer le modele de la voiture    : ");
	 	scanf("%s", car.modele);
	 	printf("Entrer le numero de matriculation : ");
	 	scanf("%d", &car.num_mat);
	 	printf("Entrer le nombre de kilometre     : ");
	 	scanf("%d", &car.nbr_km);
	 	printf("Entrer l-etat de la voiture 	  : ");
	 	scanf("%s", &car.etat);

	 	return car;
	 }
/*----------------------------------------------------------*/
	Liste *initialiser(Liste *liste)
	{
	 	voiture *car = malloc(sizeof(*car));

		/**/
			if (car == NULL)
			{
				exit(EXIT_FAILURE);
			}

		printf("\n");
		*car = saisir(*car);
		printf("\n");
		car->next = NULL;
		liste->first_element = car;

		return liste;
	}
/*----------------------------------------------------------*/
	Liste *ajouter(Liste *liste)
	{
	 	int rep;
	 	/**/
	 	printf("\n");
		 do
		 {
		 	voiture *car = malloc(sizeof(*car));
			 	if (car == NULL)
				 {
				 	exit(EXIT_FAILURE);
				 }

		 	*car = saisir(*car);
	 		car->next = liste->first_element;
	 		liste->first_element = car;
	 		printf("Voulez vous enrigistrer une nouvelle voiture,  1 / 0 : "); scanf("%d", &rep);
	 		printf("\n");
		 }while(rep == 1);
	 	
	 	return liste;
	}

/*----------------------------------------------------------*/

	void afficher(Liste *liste)
	{
		printf("Affichage\n");
		printf("*********\n");
		voiture *car = malloc(sizeof(*car));
		 if (car == NULL)
		 {
		 	exit(EXIT_FAILURE);
		 }

		car = liste->first_element;
		while(car != NULL)
		{
			printf("\n");
			printf("Modele : %s\n", car->modele);
			printf("Numero matriculation : %d\n", car->num_mat);
			printf("Nombre de km : %d km\n", car->nbr_km);
			printf("Etat : %c\n", car->etat);
			car = car->next;
		}
		
	}
/*----------------------------------------------------------*/
	bool is_empty_list(Liste *liste)
	{
		if (liste == NULL)
		{
			return true;
		}

		return false;
	}
/*----------------------------------------------------------*/
	void louer(Liste *liste)
	{
		int mat;
		bool trouve = false;
		voiture *car = malloc(sizeof(*car));
			if (car == NULL)
			{
				exit(EXIT_FAILURE);
			}
		/**/
		printf("\n");
		printf("Location\n");
		printf("********\n");
		printf("\n");
		printf("Entrer le numero d-immatriculation : ");
		scanf("%d", &mat);
		printf("\n");
		car = liste->first_element;

		while(car != NULL)
		{
			if ((car->num_mat == mat) && (car->etat == 'D'))
			{
				printf("La voiture est disponible !\n");
				printf("Elle est maintenant en location \n");
				car->etat = 'L';
				trouve = true;
				break;
			}
			else if ((car->num_mat == mat) && (car->etat == 'L'))
			{
				printf("Cette voiture est en ce moment en location !\n");
				trouve = true;
				break;
			}

			car = car->next;
		}

		if (!trouve)
		{
			printf("\n");
			printf("Cette voiture n-existe pas dans le parc !\n");
		}
	}

/*----------------------------------------------------------*/
	void retour(Liste *liste)
	{

		int mat, km = 0;
		bool trouve = false;
		voiture *car = malloc(sizeof(*car));

			if (car == NULL)
			{
				exit(EXIT_FAILURE);
			}
		/**/
		printf("\n");
		printf("Retour\n");
		printf("********\n");
		printf("Entrer le numero d-immatriculation : ");
		scanf("%d", &mat);
		printf("\n");
		car = liste->first_element;

		while(car != NULL)
		{
			if ((car->num_mat == mat) && (car->etat == 'D'))
			{
				printf(" Erreur, La voiture est disponible !\n");
				trouve = true;
				break;
			}
			else if ((car->num_mat == mat) && (car->etat == 'L'))
			{
				printf("Cette voiture etait en location !\n");
				printf("Entrer le nombre de kilometre a ajouter : ");
				scanf("%d", &km);
				car->nbr_km = car->nbr_km + km;
				car->etat == 'D';
				trouve = true;
				break;
			}

			car = car->next;
		}

		if (!trouve)
		{
			printf("\n");
			printf("Cette voiture n-existe pas dans le parc !\n");
		}
	}
/*----------------------------------------------------------*/
	void etat_voiture(Liste *liste)
	{

		int mat;
		bool trouve = false;
		voiture *car = malloc(sizeof(*car));

			if (car == NULL)
			{
				exit(EXIT_FAILURE);
			}
		/**/
		printf("\n");
		printf("Etat\n");
		printf("****\n");
		printf("Entrer le numero d-immatriculation : ");
		scanf("%d", &mat);
		printf("\n");
		car = liste->first_element;

		while(car != NULL)
		{
			if ((car->num_mat == mat) && (car->etat == 'D'))
			{
				printf("La voiture est disponible !\n");
				trouve = true;
				break;
			}
			else if ((car->num_mat == mat) && (car->etat == 'L'))
			{
				printf("Cette voiture est en location !\n");
				trouve = true;
				break;
			}

			car = car->next;
		}

		if (!trouve)
		{
			printf("\n");
			printf("Cette voiture n-existe pas dans le parc !\n");
		}
	}
/*----------------------------------------------------------*/

	 void etat_parc(Liste *liste)
	 {

	 	int nbr = 0 , somme = 0;
	 	int cmpt_d = 0, cmpt_l = 0;
		 	voiture *car = malloc(sizeof(*car));

				if (car == NULL)
				{
					exit(EXIT_FAILURE);
				}

	 	/***************/
	 	printf("\n");
	 	printf("Etat du parc\n");
	 	printf("************\n");
	 	car = liste->first_element;


	 	while(car != NULL)
		{
			if (car->etat == 'D')
			{
				cmpt_d++;

			}
			else if (car->etat == 'L')
			{
				cmpt_l++;
			}

			somme += car->nbr_km;
			nbr++;
			car = car->next;
		}

		printf("Le nombre de voiture totale est      : %d \n", nbr);
		printf("Le nombre de kilometre moyen est     : %d km \n", (somme/nbr));
		printf("Le nombre de voiture en location est : %d \n", cmpt_l);
	 	printf("Le nombre de voiture disponible est  : %d \n", cmpt_d);
	 	printf("\n");
	 	printf("voiture disponible : \n");
	 	printf("******************\n");

	 	car = liste->first_element;
	 	while(car != NULL)
		{
			if (car->etat == 'D')
			{
				printf("\n");
				printf("Modele : %s\n", car->modele);
				printf("Numero matriculation : %d\n", car->num_mat);
				printf("Nombre de km : %d km\n", car->nbr_km);
				printf("Etat : %c\n", car->etat);

			}

			car = car->next;
		}

		printf("\n");
		printf("voiture en location : \n");
	 	printf("*******************\n");

	 	car = liste->first_element;
		while(car != NULL)
		{
			if (car->etat == 'L')
			{
				printf("\n");
				printf("Modele : %s\n", car->modele);
				printf("Numero matriculation : %d\n", car->num_mat);
				printf("Nombre de km : %d km\n", car->nbr_km);
				printf("Etat : %c\n", car->etat);
			}

			car = car->next;
		}
	 }