	#include <stdio.h>
	#include <stdlib.h>
	#include <string.h>

	#define MAX 2

	typedef struct DATE
	{
		int jour;
		int mois;
		int annnee;
	}date;

	typedef struct Tnotes
		{
		
			/*	int matiere1; algo        
			 *	int matiere2; algebre    
			 *	int matiere3; analyse     
			 *	int matiere4; electricite 
			 *	int matiere5; statistique 
			*/
			int matiere[5];			
		}Tnotes;

	typedef struct ETUDIANT
	{
		char prenom[40];
		char nom[20];
		date date_naiss;
		/*Tnotes note;*/
	}etudiant;

	/*var global*/
	etudiant CLASSSE[MAX]; 	/*tableau etudiant*/
	Tnotes NOTE[MAX]; 		/*tableau de note */
	float Tmoyenne[MAX]; 	/*tableau moyenne */

	/*prototypes*/
		void saisi(etudiant tab[]);
			void saisi_note(Tnotes tab[]);
				void calcul_moy(Tnotes tab_note[], float Tmoyenne[]);
					void menu();
				void echanger_etu(etudiant *p1, etudiant *p2);
			void echanger_note(Tnotes *t1, Tnotes *t2);
		void resultat(etudiant tab_etudiant[], Tnotes tab_note[]);

		/*fonction principale*/
	int main(int argc, char const *argv[])
	{
		/**/
		printf("\n");
		menu();

		return 0;
	}

	/*Procedure de saisi les informations des etudiants*/
	void saisi(etudiant tab[])
	{
		int i;
		etudiant p1;
		/**/
		for ( i = 0; i < MAX; ++i)
		{
			printf("\n");
			printf("Entrer le prenom de l'etudiant %d : ",i+1); scanf("%s", p1.prenom);
			printf("Entrer le nom de l'etudiant : ");    scanf("%s", p1.nom);
			printf("Entrer la date de naissace  : ");    
			scanf("%d %d %d", &p1.date_naiss.jour, &p1.date_naiss.mois, &p1.date_naiss.annnee);
			tab[i] = p1;
		}
	}

	/*procedure de saisi des notes */
	void saisi_note(Tnotes tab[])
	{
		int i,j;
		Tnotes t1;
		/**/

		printf("\n");
		printf("INFO\n");
		printf("-----\n");
		printf("note 1 == Algorithme\n");
        printf("note 2 == Algebre\n");
        printf("note 3 == Analyse\n");
        printf("note 4 == Electricite\n");
        printf("note 5 == Statistique\n");

		for ( i = 0; i < MAX; ++i)
		{
			printf("\n");
			printf("Entrer les notes de l-etudiant %d ! ",i+1);printf("\n");
			for ( j = 0; j < 5; ++j)
			{
				printf("Entrer la note %d : ", j+1);
				scanf("%d", &t1.matiere[j]); 
			}
			tab[i] = t1;
		}
	}

	/*procedure de calcul de moyenne*/
	void calcul_moy(Tnotes tab_note[], float Tmoyenne[])
	{
		int i,j;
		float moy;
		int somme;
		Tnotes t1;
		/**/

		for ( i = 0; i < MAX; ++i)
		{	
			t1 = tab_note[i];
			somme = 0; moy = 0;
			
			for ( j = 0; j < 5; ++j)
			{
				somme += t1.matiere[j];
			}
			
			moy = somme / 5;
			Tmoyenne[i] = moy;
		}
		printf("\n");
		printf("Le tableau des moyennes a ete bien rempli !\n");
		printf("\n");
	}

	
	/*procedure echanger etudiant*/
	 void echanger_etu(etudiant *p1, etudiant *p2)
	 {
	 	etudiant tmp;
	 	/**/
	 	tmp = *p1;
	 	*p1 = *p2;
	 	*p2 = tmp;
	 }

	 /*procedure echanger note*/
	 void echanger_note(Tnotes *t1, Tnotes *t2)
	 {
	 	Tnotes tmp;
	 	/**/
	 	tmp = *t1;
	 	*t1 = *t2;
	 	*t2 = tmp;
	 }

	 /*procedure pour donner les meilleurs notes des eleves*/
	void resultat(etudiant tab_etudiant[], Tnotes tab_note[])
	{
		int i,j;
		/*Tnotes t1;
		etudiant p1;*/

		/*classement algorithme*/

		for ( i = 0; i < MAX; ++i)
			{
				for (j = MAX-1; j > i; j--)
				{
					if (tab_note[j].matiere[0] > tab_note[j-1].matiere[0])
					{
						echanger_note(&tab_note[j], &tab_note[j-1]);
						echanger_etu(&tab_etudiant[j], &tab_etudiant[j-1]);
					}
				}
			}

		/*Affichage algorithme*/
		printf("\n");
		printf("Ordre de merite en Algorithme ! \n");
		printf("--------------------------------\n");
		for ( i = 0; i < MAX; ++i)
		{
			printf("\n");
			printf("prenom  : %s \n",tab_etudiant[i].prenom);
			printf("Note    : %d \n",tab_note[i].matiere[0]);

		}

		/*classement ALGEBRE*/

		for ( i = 0; i < MAX; ++i)
			{
				for (j = MAX-1; j > i; j--)
				{
					if (tab_note[j].matiere[1] > tab_note[j-1].matiere[1])
					{
						echanger_note(&tab_note[j], &tab_note[j-1]);
						echanger_etu(&tab_etudiant[j], &tab_etudiant[j-1]);
					}
				}
			}

		/*Affichage ALGEBRE*/
		printf("\n");
		printf("Ordre de merite en Algebre ! \n");
		printf("--------------------------------\n");
		for ( i = 0; i < MAX; ++i)
		{
			printf("\n");
			printf("prenom  : %s \n",tab_etudiant[i].prenom);
			printf("Note    : %d \n",tab_note[i].matiere[1]);

		}

		/*classement ANALYSE*/

		for ( i = 0; i < MAX; ++i)
			{
				for (j = MAX-1; j > i; j--)
				{
					if (tab_note[j].matiere[2] > tab_note[j-1].matiere[2])
					{
						echanger_note(&tab_note[j], &tab_note[j-1]);
						echanger_etu(&tab_etudiant[j], &tab_etudiant[j-1]);
					}
				}
			}

		/*Affichage ANALYSE*/
		printf("\n");
		printf("Ordre de merite en Analyse ! \n");
		printf("--------------------------------\n");
		for ( i = 0; i < MAX; ++i)
		{
			printf("\n");
			printf("prenom  : %s \n",tab_etudiant[i].prenom);
			printf("Note    : %d \n",tab_note[i].matiere[2]);

		}

		/*classement electricite*/

		for ( i = 0; i < MAX; ++i)
			{
				for (j = MAX-1; j > i; j--)
				{
					if (tab_note[j].matiere[3] > tab_note[j-1].matiere[3])
					{
						echanger_note(&tab_note[j], &tab_note[j-1]);
						echanger_etu(&tab_etudiant[j], &tab_etudiant[j-1]);
					}
				}
			}

		/*Affichage electricite*/
		printf("\n");
		printf("Ordre de merite en Electricite ! \n");
		printf("--------------------------------\n");
		for ( i = 0; i < MAX; ++i)
		{
			printf("\n");
			printf("prenom  : %s \n",tab_etudiant[i].prenom);
			printf("Note    : %d \n",tab_note[i].matiere[3]);

		}


		/*classement Statistique*/

		for ( i = 0; i < MAX; ++i)
			{
				for (j = MAX-1; j > i; j--)
				{
					if (tab_note[j].matiere[4] > tab_note[j-1].matiere[4])
					{
						echanger_note(&tab_note[j], &tab_note[j-1]);
						echanger_etu(&tab_etudiant[j], &tab_etudiant[j-1]);
					}
				}
			}

		/*Affichage statistique*/

		printf("\n");
		printf("Ordre de merite en Statistique ! \n");
		printf("--------------------------------\n");
		for ( i = 0; i < MAX; ++i)
		{
			printf("\n");
			printf("prenom  : %s \n",tab_etudiant[i].prenom);
			printf("Note    : %d \n",tab_note[i].matiere[4]);

		}


	}

	/*procedure menu*/
	void menu()
		{	
			int choix;
				/*debut*/
			printf("\n");
			do
			{
				printf("0000000000000000000000000000000000000000000000000000000\n");
				printf("	        	MENU	   		                       \n");
				printf("0000000000000000000000000000000000000000000000000000000");
				printf("\n");
				printf("1. SAISIR LES INFORMATION DES ETUDIANTS \n");
				printf("2. SAISIR LES NOTES DES ETUDIANTS \n");
				printf("3. REMPLIRE AUTOMATIQUEMENT LE TABLEAU DES MOYENNES \n");
				printf("4. DONNER LES RESULTAT PAR ORDRE DE MERITE \n");				
				printf("0. QUITTER LA PROCEDURE..\n");
				printf("\n");
				printf("Entrer votre choix  : "); scanf("%d",&choix);

				switch(choix)
				{
					case 1 :  saisi(CLASSSE); 	 printf("\n");
						break;
					case 2 :  saisi_note(NOTE);   printf("\n");
						break;
					case 3 :  calcul_moy(NOTE,Tmoyenne);   printf("\n");
						break;
					case 4 :  resultat(CLASSSE,NOTE);   printf("\n");
						break;
					case 0 : printf(" Fin du programme..."); printf("\n");
						break;
				}

			}while(choix != 0);
		}
