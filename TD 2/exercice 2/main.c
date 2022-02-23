		#include <stdio.h>
		#include <stdlib.h>

		#define MAX 2

		/* structure eleve ; */
		typedef struct eleve
		{
			char prenom[30];
			char nom[20];
			int numero;
			float matiere1,matiere2,matiere3,matiere4,matiere5;

		}eleve;
		/* prototypes ... */
		void saisi(eleve *tab , int taille);
		void affichage(eleve tab[], int taille);
			
			/* fonction principale */
		int main(int argc, char const *argv[])   
		{
			eleve tab[MAX];
			int teff = MAX;

				saisi(tab,teff);
				printf("\n");
				affichage(tab,teff);

			return 0;
		}

		/* fonction de saisi ...*/
		void saisi(eleve *tab , int taille)
		{
			eleve personne;
			int i;

			for ( i = 0; i < taille; ++i)
			{	 /* Saisi d'informations */
				printf("\n");
				printf("Entrer le prenom de l-eleve     :  "); 	scanf("%s",personne.prenom);
				printf("Entrer le nom de l-eleve     	:  ");	scanf("%s",personne.nom);
				printf("Entrer le numero de l-eleve     :  ");	scanf("%d",&personne.numero);
					/* saisi des notes */
				printf("Entrer la note de la matiere 1 : ");	scanf("%f",&personne.matiere1);
				printf("Entrer la note de la matiere 2 : ");	scanf("%f",&personne.matiere2);
				printf("Entrer la note de la matiere 3 : ");	scanf("%f",&personne.matiere3);
				printf("Entrer la note de la matiere 4 : ");	scanf("%f",&personne.matiere4);
				printf("Entrer la note de la matiere 5 : ");	scanf("%f",&personne.matiere5);
				tab[i] = personne;
			}
		}

		/* fontion d'affichage */
		void affichage(eleve tab[], int taille)
		{
			eleve personne;
			float moy;
			int i;

			for (i = 0; i < taille; ++i)
			{
				personne = tab[i];
				if ((personne.matiere1 != -1) && (personne.matiere2 != -1) && (personne.matiere3 != -1) && 
					(personne.matiere4 != -1) && (personne.matiere5 != -1))
				{
					moy = (personne.matiere1 + personne.matiere2 + personne.matiere3 + personne.matiere4 + personne.matiere5) / 5;
					printf("prenom 	: %s\n",personne.prenom );
					printf("Nom  : %s\n",personne.nom);
					printf("Moyenne : %.2f\n", moy);
				}
			}
		}

		