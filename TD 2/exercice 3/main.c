	#include <stdio.h>
	#include <stdlib.h>
	#include <stdbool.h>
	#include <string.h>

	#define TAILLE_MAX 5
	

	/* type enrigistrement */
	typedef struct date{
		int jour;
		int mois;
		int annee;
	}date;

	typedef struct EMPL
	{
		char prenom[20];
		char nom[10];
		date date_naiss;
		char matricule[10];
		char fonction[30];
		int  salaire;
	}EMPL;

	/*Prototypes...*/
		void saisi(EMPL *tab, int taille);
			void affichage(EMPL personne);
				void recherche(EMPL tab[] , int taille);
					void masse_sal(EMPL tab[], int taille);
				void echanger(EMPL *p1, EMPL *p2);
			void directeur(EMPL tab[], int taille);
		void menu(EMPL *TAB_EMPL, int teff);

	int main(int argc, char const *argv[])
	{
		EMPL TAB_EMPL[TAILLE_MAX];
		int teff = TAILLE_MAX;
			/*debut*/
		menu(TAB_EMPL,teff);

		return 0;
	}

	/*Procedure de saisi...*/
	void saisi(EMPL *tab, int taille)
	{	
		int i;
		EMPL personne;

		for (i = 0; i < taille; ++i)
		{
			printf("\n");
			printf("Entrer le prenom  		: "); 	scanf("%s", personne.prenom);
			printf("Entrer le nom  	  		: "); 	scanf("%s", personne.nom);
			/* saisi date_naissance */
			printf("Entrer la date de naissance  : "); 	
			scanf("%d %d %d", &personne.date_naiss.jour, &personne.date_naiss.mois, &personne.date_naiss.annee);
			
			printf("Entrer le matricule 	: "); 	scanf("%s", personne.matricule);
			printf("Entrer la fonction  	: "); 	scanf("%s", personne.fonction);
			printf("Entrer le salaire   	: "); 	scanf("%d", &personne.salaire);
			tab[i] = personne;
		}
	}

	/* procedure d'affichage */
	void affichage(EMPL personne)
	{
		printf("\n");
		printf("Prenom  : %s\n",personne.prenom );
		printf("Nom     : %s\n",personne.nom );
	 	printf("Date naissance  : %d / %d / %d \n",personne.date_naiss.jour,
	 		personne.date_naiss.mois,personne.date_naiss.annee);
	 	printf("matricule  : %s\n",personne.matricule );
	 	printf("Fonction   : %s\n",personne.fonction );
	 	printf("Salaire    : %d\n",personne.salaire );
	}

	/* procedure de menu...*/
	void menu(EMPL *TAB_EMPL, int teff)
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
			printf("1. SAISIR LES EMPLOYES\n");
			printf("2. RECHERCHER UN EMPLOYE \n");
			printf("3. TROUVER LA MASSE SALARIALE\n");
			printf("4. TROUVER LE DIRECTEUR\n");
			printf("0. QUITTER LA PROCEDURE..\n");
			printf("\n");
			printf("Entrer votre choix  : "); scanf("%d",&choix);

			switch(choix)
			{
				case 1 : saisi(TAB_EMPL,teff); 		printf("\n");
					break;
				case 2 : recherche(TAB_EMPL,teff);    printf("\n");
					break;
				case 3 : masse_sal(TAB_EMPL,teff);    printf("\n");
					break;
				case 4 : directeur(TAB_EMPL,teff);    printf("\n");
					break;
				case 0 : printf("Appuyer sur une  touche ... ");
					break;
			}

		}while(choix != 0);


	}

	/*Procedure  de recherche*/
	void recherche(EMPL tab[] , int taille)
	{
		bool test = false; /* var de test boolean */
		int i;
		char name[20];
		EMPL personne;

		printf("\n");
		printf("Entrer le prenom que vous voulez rechercher  :  "); scanf("%s",name);
			for ( i = 0; i < taille; ++i)
			{
				personne = tab[i];
					if ( strcmp(personne.prenom,name) == 0)
					{
						test = true;
					}
			}
			printf("\n");
			if (test == true)
			{
				printf("%s figure bien dans la liste des employes de l-entreprise ! \n",name);
			}
			else
			{
				printf("%s ne figure pas dans la liste des employes de l-entreprise ! \n",name);
			}
		
	}

	/* procedure pour calculer la masse salariale */
	void masse_sal(EMPL tab[], int taille)
	{
		int i;
		int somme = 0;
		int salaire = 0;
		EMPL personne;
		
		/*Debut*/

		for ( i = 0; i < taille; ++i)
		{
			personne = tab[i];
			somme += personne.salaire;
		}
		salaire = (somme / taille);
		printf("\n");
		printf("La masse salariale de l'entreprise est : %d FCFA\n",salaire );
		printf("\n");
	}

	/*procedure echanger*/
	void echanger(EMPL *p1, EMPL *p2)
	{
		EMPL temp;
		/**/
		temp = *p1;
		*p1  = *p2;
		*p2  = temp;
	}

	/* procedure pour trouver le directeur */
	void directeur(EMPL tab[], int taille)
	{
		EMPL personne;
		int i,j;
		/*debut*/
			for ( i = 0; i < taille-1; ++i)
			{
				for (j = taille-1; j > i; j--)
				{
					if (tab[j].salaire > tab[j-1].salaire)
					{
						echanger(&tab[j],&tab[j-1]);
					}
				}
			}
			personne = tab[0];
		printf("\n");
		affichage(personne);
	}