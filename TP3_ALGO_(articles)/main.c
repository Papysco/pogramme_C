#include <stdlib.h>
#include <stdio.h>
#include "liste.h"


// prototypes
	void menu(liste *myList);

int main(int argc, char const *argv[])
{
	 liste *myList = malloc(sizeof(*myList));

	printf("\n");

	menu(myList);

	return 0;
}



/*menu*/
	void menu(liste *myList)
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
			printf("1. INITIALISER LISTE DES ARTICLES \n"); 
			printf("2. AJOUTER DES ARTICLES\n");
			printf("3. AFFICHER LISTE DES ARTICLES\n");  
			printf("4. SUPPRIMER DES ARTICLES \n");		  
			printf("5. \n");		 
			printf("6. \n"); 				

			printf("0.QUITTER LA PROCEDURE..\n");
			printf("\n");
			printf("Entrer votre choix  : "); scanf("%d",&choix);

			switch(choix)
			{
				case 1 : myList = initialisation(myList); 	printf("\n");
					break;
				case 2 : ajout(myList) ;					printf("\n");
					break;
				case 3 : afficher(myList); 	printf("\n");
					break;	
				case 4 : supprimer(myList);	printf("\n"); 
					break;
				case 5 :  	printf("\n");
					break;
				case 6 : 	printf("\n");
					break;
				case 0 : printf("Appuyer sur une  touche ... ");
					break;
			}
		}while(choix != 0);
	}
