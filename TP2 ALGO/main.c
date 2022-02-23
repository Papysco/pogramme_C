#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define max 50
	
	typedef struct date
		{
			int jour;
			int mois;
			int annee;
		}date;

	typedef struct idag
		{
			int DEP; // numero du departement
			int NUM; // numero de l-agence du departement
		}idag;

	typedef struct STAT
	{	
		char NASS[7]; // caracteres : numero de l-assure
		date DATE; 
		idag IDAG;
		char RESP; /* A:  P:  M:  I:  */
		int MT; /*montant depense*/

	}STAT;

		/*Prototypes*/
	void saisir_sinistre(STAT tab[]);
		void NOMMOY(STAT tab[]);
			void Affichage(STAT tab[]);
				void DEPRE(STAT tab[]);
			void SINASSU(STAT tab[]);
		void menu();
		/*variable globale*/
	int compt_tab = 0;
	STAT tab_STAT[max];

		/*fonction principale*/
	int main(int argc, char const *argv[])
	{
		
		/**/
		
		printf("\n");
		menu();
		printf("\n");

		return 0;
	}

	void saisir_sinistre(STAT tab[])
	{
		int rep;
		STAT sinistre;
		// int l;
		/**/
		printf("\n");
		printf("Saisi des sinistres : \n");
		printf("*******************\n");

	 /*	do{
			l++;
			printf("\n");
			printf("Entrer le numero de l'l-assure %d : ",l);
			scanf("%s",sinistre.NASS);
			// printf("Entrer la date du sinistre : ");
			// scanf("%d %d %d", &sinistre.DATE.jour, &sinistre.DATE.mois, &sinistre.DATE.annee);
			printf("Entrer le numero du departement  : ");
			scanf("%d",&sinistre.IDAG.DEP);
			// printf("Entrer le numero de l'agence du departement  : ");
			// scanf("%d",&sinistre.IDAG.NUM);
			// printf("Entrer la responsabilite de l'l-assure  : ");
			// scanf("%s",&sinistre.RESP);
			printf("Entrer le montant depense : ");
			scanf("%d",&sinistre.MT);
				compt_tab++;
				tab[l] = sinistre;
				
			printf("Voulez vous un nouveau enrigistrement ? o/n : ");
			scanf("%s",&rep);
		}while(rep == 'o');
	 */
		
		for ( int i = 0; i < max; ++i)
		{
			printf("\n");
			printf("Entrer le numero de l'assure %d  : ",i);
			scanf("%s",sinistre.NASS);
			printf("Entrer la date du sinistre : ");
			scanf("%d %d %d", &sinistre.DATE.jour, &sinistre.DATE.mois, &sinistre.DATE.annee);
			printf("Entrer le numero du departement  : ");
			scanf("%d",&sinistre.IDAG.DEP);
			printf("Entrer le numero de l'agence du departement  : ");
			scanf("%d",&sinistre.IDAG.NUM);
			printf("Entrer la responsabilite de l'l-assure  : ");
			scanf("%s",&sinistre.RESP);
			printf("Entrer le montant depense : ");
			scanf("%d",&sinistre.MT);
				compt_tab++;
				tab[i] = sinistre;
				
			printf("Voulez vous un nouveau enrigistrement ? 1 / 0 : ");
			scanf("%d",&rep);
			if (rep == 0){
				break;
			}
		}
	}

	/*calcule le nombre de sinistres et largent depense par sinistre*/
	void NOMMOY(STAT tab[]){
		int i, nbr_sinistre, somme = 0;
		float moy;
		STAT sinistre;
		/**/
		printf("\n");
		printf("calcule le nombre de sinistres et largent depense par sinistre: \n");
		printf("***************************************************************\n");
		nbr_sinistre = compt_tab;

		for (i = 0; i < compt_tab; ++i){
			sinistre = tab[i];
			somme += sinistre.MT;
		}
		printf("\n");
		printf("Le nombre de sinistre est : %d \n", nbr_sinistre);
		moy = (somme / compt_tab );
		printf("La moyenne depensee par sinistre est : %.2f \n", moy);
	}

	/*calcule le montant depense par annee*/
	void DEPANN(STAT tab[]){
		int i,somme = 0;
		STAT sinistre;
		/**/
		printf("\n");
		printf("Calcule le montant depense par annee : \n");
		printf("**************************************\n");
		for (i = 0; i < compt_tab; ++i){
			sinistre = tab[i];
			somme += sinistre.MT;
		}
		printf("\n");
		printf("La depensee des sinistres durant l'annee est : %d \n", somme );
	}

	/*calcule le nombre de declaration par assuree */ 
	void SINASSU(STAT tab[]){
		int i,j,l,cmpt;
		int k = 0;
		STAT sinistre, tab_sauv[compt_tab];
		bool trouve = false;

		/**/
		printf("\n");
		printf("Le nombre de sinistre par assure : \n");
		printf("*********************************\n");

		for (l = 0; l < compt_tab; ++l){
			sinistre = tab[l];

			for (i = 0; i < compt_tab; ++i){
				if (strcmp(sinistre.NASS, tab_sauv[i].NASS) == 0){
					trouve = true;
				}
			}

			if (trouve == false){
				strcpy(tab_sauv[k].NASS, sinistre.NASS);
				k = k + 1;
				cmpt = 0;
				for ( j = 0; j < compt_tab; ++j){
					if (strcmp(sinistre.NASS, tab[j].NASS) == 0){
						cmpt++;
					}
				}

				printf("%s : %d\n",sinistre.NASS, cmpt);
			}
		}
	}

	/*calcule les depenses par region */ 
	void DEPRE(STAT tab[]){
		int i,j,l;
		int somme = 0;
		int k = -1;
		STAT sinistre, tab_sauv[compt_tab];
		bool trouve = false;

		/**/
		printf("\n");
		printf("Les depenses par region : \n");
		printf("************************\n");

			for (i = 0; i < compt_tab; ++i){
				tab_sauv[i].IDAG.DEP = 0;
			}
		
		for (l = 0; l < compt_tab; ++l){
			sinistre = tab[l];

			for ( i = 0; i < compt_tab; ++i){
				if (sinistre.IDAG.DEP ==  tab_sauv[i].IDAG.DEP){
					trouve = true;
				}
			}

			if (trouve == false){
				k = k + 1;	somme = 0;
				tab_sauv[k].IDAG.DEP = sinistre.IDAG.DEP;
					
				for ( j = 0; j < compt_tab; ++j){
					if (sinistre.IDAG.DEP == tab[j].IDAG.DEP){
						somme = somme + tab[j].MT;
					}
				}

				printf("%d : %d\n",sinistre.IDAG.DEP, somme);
			}
			
		}
	}

	/*Affichage*/
	void Affichage(STAT tab[]){
		STAT sinistre;
		int i;
		/**/
		printf("\n");
		printf("Affichage: \n");
		printf("**********\n");
		printf("Taille du tableau : %d\n", compt_tab);

		for ( i = 0; i < compt_tab; ++i){
			sinistre = tab[i];
			printf("\n");
			printf("numero assure : %s\n", sinistre.NASS);
			printf("Date : %d/%d/%d \n", sinistre.DATE.jour,sinistre.DATE.mois,sinistre.DATE.annee);
			printf("Numero du departement : %d\n", sinistre.IDAG.DEP);
			printf("Numero de l-agence du departement : %d \n",sinistre.IDAG.NUM);
			printf("Responsabilite : %c\n",sinistre.RESP);
			printf("Montant : %d\n", sinistre.MT);
		}	
	}

	/*menu*/
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
			printf("1.ENRIGISTRER LES SINISTRES \n"); // ok
			printf("2.AFFICHER LES SINISTRES \n");	 // ok
			printf("3.CALCULER LE NOMBRES ET L-ARGENT DEPENSE PAR SINISTRES \n");  // ok
			printf("4.CALCULER LE MONTANT DEPENSE POUR CETTE ANNNEE \n");		  // ok
			printf("5.CALCULER LE NOMBRE DE DECLARATIONS PAR ASSURE \n");		 // ok
			printf("6.CALCULER LA DEPENSE PAR REGION\n"); 						// ok


			printf("0.QUITTER LA PROCEDURE..\n");
			printf("\n");
			printf("Entrer votre choix  : "); scanf("%d",&choix);

			switch(choix)
			{
				case 1 : saisir_sinistre(tab_STAT); 	printf("\n");
					break;
				case 2 : Affichage(tab_STAT);  		 	printf("\n");
					break;
				case 3 : NOMMOY(tab_STAT);				printf("\n");
					break;	
				case 4 : DEPANN(tab_STAT);				printf("\n");
					break;
				case 5 : SINASSU(tab_STAT);				printf("\n");
					break;
				case 6 : DEPRE(tab_STAT);				printf("\n");
					break;
				case 0 : printf("Appuyer sur une  touche ... ");
					break;
			}
		}while(choix != 0);
	}