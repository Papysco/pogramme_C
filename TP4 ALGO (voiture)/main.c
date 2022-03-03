#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "voiture.h"

// prototypes
void menu(Liste *liste);

int main(int argc, char const *argv[])
{
	Liste *liste = malloc(sizeof(*liste));

	printf("\n");

	menu(liste);
	
	return 0;
}

void menu(Liste *liste)
	{	
		int choix;
			/*debut*/
		printf("\n");
		do
		{
			printf("0000000000000000000000000000000000000\n");
			printf("		MENU	   		             \n");
			printf("0000000000000000000000000000000000000");
			printf("\n");
			printf("1.INITIALISER LA LISTE \n"); 
			printf("2.AJOUTER DES VOITURES \n");	 
			printf("3.AFFICHER LA LSITE \n");  
			printf("4.LOUER UNE VOITURE \n");		  
			printf("5.RETOURNER UNE VOITURE \n");		 
			printf("6.ETAT D-UNE VOITURE \n"); 						
			printf("7.ETAT DU PARC \n"); 	

			printf("0.QUITTER LA PROCEDURE..\n");
			printf("\n");
			printf("Entrer votre choix  : "); scanf("%d",&choix);

			switch(choix)
			{
				case 1 : liste = initialiser(liste); 		printf("\n");  // ok
					break;
				case 2 : liste = ajouter(liste);  	    	printf("\n");  // ok
					break;
				case 3 : afficher(liste);					printf("\n");  // ok
					break;	
				case 4 : louer(liste);						printf("\n");  // ok
					break;
				case 5 : retour(liste);						printf("\n");  // ok
					break;
				case 6 : etat_voiture(liste);				printf("\n");  // ok
					break;
				case 7 : etat_parc(liste);				printf("\n");  
					break;	
				case 0 : printf("Appuyer sur une  touche ... ");
					break;
			}
		}while(choix != 0);
	}