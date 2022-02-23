#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define TAILLE_TAB 5

typedef struct client
{
	int code_client;
	char prenom[20];
	char nom[20];
	char adresse[20];
} client;

			/* PROTOTYPES*/

void affichage(client tab[]);
void echanger(client *p1 , client *p2);
void saisi(client tab[], int taille);

/*--------------------------------------------------*/

int main(void)
{
	client tab[TAILLE_TAB];
	int i,j,teff;

	teff = TAILLE_TAB;
 
	saisi(tab,teff);

	for (i = 0; i < TAILLE_TAB-1; ++i) /* Tri bulle */
	{
		for (j = TAILLE_TAB-1; j >= i+1; j--)
		{
			if (tab[j].prenom[1] < tab[j-1].prenom[1])
			{
				echanger(&tab[j],&tab[j-1]);
			}
			
		}
	} 

	printf("\n");
	affichage(tab);
	return 0;
}

void affichage(client tab[])
{
	int i;
	
	for ( i = 0; i < TAILLE_TAB; ++i){
		
		printf("Code client 	: %d \n",tab[i].code_client);
		printf("Prenom 		: %s \n",tab[i].prenom);
		printf("Nom 		: %s \n",tab[i].nom);
		printf("Adresse 	: %s \n",tab[i].adresse);
		printf("\n");
	}
}

void echanger(client *p1 , client *p2)
{
	client temp;

	temp   = *(p1);
	*(p1)  = *(p2);
	*(p2)  = temp;  
}

void saisi(client tab[], int taille)  /* procedure de saisi ... */
{
	char rep; 
	int i = 0;
	int compt;
	client personne;
 	
 	compt = 0;
	do
	{	
		printf("\n");
		printf("Entrer le code du client  	: ");
		scanf("%d",&personne.code_client);
		
		printf("Entrer le prenom du client   	: ");
		scanf("%s",personne.prenom);

		printf("Entrer le nom du client   	: ");
		scanf("%s",personne.nom);

		printf("Entrer l-adresse du client  	: ");
		scanf("%s",personne.adresse);

		tab[i] = personne; 
		i = i + 1; 
		compt++;

		printf("\n");
		printf("Voulez vous un autre enrigistrement ? o / n  : ");
		scanf("%s", &rep); 
		printf("\n");
		
	}while((rep == 'o') && (compt < taille));  /* probleme de compteur... */
}
