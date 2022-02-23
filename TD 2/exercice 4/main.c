	#include <stdio.h>
	#include <stdlib.h>
	#include <string.h>

	#define TAILLE 100

	typedef struct contact
	{
		char prenom[20];
		char adress[20];
		 int numero;
	}contact;
	/*prototype*/
		void saisi(contact *tab , int *taille);
			void affichage(contact tab[] , int taille);
				void menu();
			void echanger(contact *t1, contact *t2);
		void inserer_sup(contact *tab , int *taille);
			
	/* variable globale */
		contact tab[TAILLE];
		int teff = 0;
	/*pricipale*/
	int main(int argc, char const *argv[])
	{
		
		/**/
		printf("\n");
		menu(tab);

		return 0;
	}

	/*procedure de saisi */
	void saisi(contact *tab , int *taille)
	{
		contact p1;
		int i;
		int teff;
		/* */
		printf("Entrer le nombre de contact a enrigistrer : ");
		scanf("%d", &teff);
		*taille = teff;

		for ( i = 0; i < *taille; ++i)
		{	
			printf("\n");
			printf("Entrer le prenom : "); scanf("%s", p1.prenom);  
			printf("Entrer l-adresse : "); scanf("%s", p1.adress);  
			printf("Entrer le numero : "); scanf("%d", &p1.numero); 
			tab[i] = p1;
		}
	}

	/* procedure affichage */
	void affichage(contact tab[] , int taille)
	{
		contact p1;
		int i;
		/**/
		printf("\n");
		printf("  REPERTOIRE   \n");
		printf("**************\n");

		for ( i = 0; i < taille; ++i)
		{
			p1 = tab[i];
			printf("\n");
			printf("Prenom  : %s\n",p1.prenom );
			printf("Adress  : %s\n",p1.adress );
	 		printf("Numero  : %d\n",p1.numero );
		}

	}
		
	/*procedure echanger*/
	void echanger(contact *t1, contact *t2)
	{
		contact temp;

		temp = *t1;
		*t1  = *t2;
		*t2  = temp;
	}

	/*procedure pour inserer ou supprimer un contact */
	void inserer_sup(contact *tab , int *taille)
	{
		int choix;
		int nbr = 0;
		int i,lenght;
		contact p1;
		char name[20];
		char rep;

		/**/
		lenght = *taille; printf("\n");
		printf("Voulez vous inserer ou supprimer un contact ? ");
		printf(" '1' : inserer / '2' : supprimer  : "); scanf("%d", &choix);

		if (choix == 1)
		{
			printf("Entrer le nombre  de contact a inserer : ");
			scanf("%d",&nbr);
			*taille += nbr;

				for ( i = lenght; i < *taille ; ++i)
				{
					printf("\n");
					printf("Entrer le prenom : "); scanf("%s", p1.prenom); 
					printf("Entrer l-adresse : "); scanf("%s", p1.adress);  
					printf("Entrer le numero : "); scanf("%d", &p1.numero); 
					tab[i] = p1;
				}
		}
		else if (choix == 2)
		{
			lenght = *taille;
			do
			{	printf("\n");
				printf("Entrer le prenom que vous voulez supprimer  :  ");
				scanf("%s", name);

				for ( i = 0; i < *taille; ++i)
				{	
					p1 = tab[i];
					if (strcmp(p1.prenom ,name) == 0)
					{
						echanger(&tab[i], &tab[lenght-1]);
						*taille -= 1;
					}
				}
				printf("\n");
				printf("Vouler supprimer un nouveau contact ?  o / n : "); scanf("%s",&rep);
			}while(rep != 'n');


		}
	}

	/* procedure de menu...     contact *tab, int *teff*/
		void menu()
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
				printf("1. SAISIR LES CONTACT\n");
				printf("2. AFFICHER LES CONTACT\n");
				printf("3. INSERER OU SUPPRIMER UN CONTACT \n");
				printf("0. QUITTER LA PROCEDURE..\n");
				printf("\n");
				printf("Entrer votre choix  : "); scanf("%d",&choix);

				switch(choix)
				{
					case 1 : saisi(tab,&teff); 		printf("\n");
						break;
					case 2 : affichage(tab,teff);    printf("\n");
						break;
					case 3 : inserer_sup(tab,&teff);    printf("\n");
						break;
					case 0 : printf("Appuyer sur une  touche ... ");
						break;
				}

			}while(choix != 0);


		}