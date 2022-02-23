#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct tableau
{
	char tableau[256];
}tableau;

/*prototype*/
void INITAB1(int nbr, int NOM[]);
void INITAB2(tableau UNITE[] , tableau DIX[], tableau CENT[]);
void traduction(int nbr);

 /****/
int  NOM[3];
tableau UNITE[10];
tableau DIX[10];
tableau CENT[10];

int main(int argc, char const *argv[])
{
	int nbr;
	/**/

	INITAB2(UNITE,DIX,CENT);
	/*printf("%s", CENT[2].tableau); printf("\n");*/

	printf("Entrer le nombre : ");scanf("%d",&nbr);
	printf("\n");

	traduction(nbr);

	/*
	INITAB1(nbr,NOM);
	printf("%d \n", NOM[0]);
	printf("%d \n", NOM[1]);
	printf("%d \n", NOM[2]);
	*/

	return 0;
}

/*procedure Initab */

void INITAB1(int nbr, int NOM[])
{
	int unite, dizaine, centaine;
	
	/**/

	centaine = nbr / 100;
	dizaine  = (nbr % 100) / 10;
	unite 	 = (nbr % 100) % 10;

	NOM[0] = centaine; 
	NOM[1] = dizaine;
	NOM[2] = unite;
}

/*procedure de remplissage*/
void INITAB2(tableau UNITE[] , tableau DIX[], tableau CENT[]) /**/
{
	
	/**/

	/*tab unite*/
	strcpy(&UNITE[0].tableau[256], " ");
	strcpy(&UNITE[1].tableau[256], " un" );
	strcpy(&UNITE[2].tableau[256], " deux");
	strcpy(&UNITE[3].tableau[256], " trois");
	strcpy(&UNITE[4].tableau[256], " quatre");
	strcpy(&UNITE[5].tableau[256], " cinq");
	strcpy(&UNITE[6].tableau[256], " six");
	strcpy(&UNITE[7].tableau[256], " sept");
	strcpy(&UNITE[8].tableau[256], " huit");
	strcpy(&UNITE[9].tableau[256], " neuf");
	

	/*tab dizaine*/
	strcpy(&DIX[0].tableau[256], " " );
	strcpy(&DIX[1].tableau[256], " dix");
	strcpy(&DIX[2].tableau[256], " vingt");
	strcpy(&DIX[3].tableau[256], " trente");
	strcpy(&DIX[4].tableau[256], " quarante");
	strcpy(&DIX[5].tableau[256], " cinquante");
	strcpy(&DIX[6].tableau[256], " soicente");
	strcpy(&DIX[7].tableau[256], " soicente dix");
	strcpy(&DIX[8].tableau[256], " quatre vingt");
	strcpy(&DIX[9].tableau[256], " quatre vingt dix");

	/*tab dizaine*/
	strcpy(&CENT[0].tableau[256], " ");
	strcpy(&CENT[1].tableau[256], " cent" );
	strcpy(&CENT[2].tableau[256], " deux cent");
	strcpy(&CENT[3].tableau[256], " trois cent");
	strcpy(&CENT[4].tableau[256], " quatre cent");
	strcpy(&CENT[5].tableau[256], " cinq cent");
	strcpy(&CENT[6].tableau[256], " six cent");
	strcpy(&CENT[7].tableau[256], " sept cent");
	strcpy(&CENT[8].tableau[256], " huit cent");
	strcpy(&CENT[9].tableau[256], " neuf cent");
}

/*procedure traduction*/
void traduction(int nbr)
{
	int i,j,k;
	/**/

	INITAB1(nbr,NOM);

	i = NOM[0];
	j = NOM[1];
	k = NOM[2];

	switch(nbr){
		case 11 : printf("La traduction du nombre %d est : onze\n",nbr);
		break;
		case 12 : printf("La traduction du nombre %d est : douze\n",nbr);
		break;
		case 13 : printf("La traduction du nombre %d est : treize\n",nbr);
		break;
		case 14 : printf("La traduction du nombre %d est : quatorze\n",nbr);
		break;
		case 15 : printf("La traduction du nombre %d est : quinze\n",nbr);
		break;
		case 16 : printf("La traduction du nombre %d est : seize\n",nbr);
		break;
		default : 	printf("La traduction du nombre %d est : %s%s%s ",nbr, CENT[i+1].tableau, DIX[j+1].tableau, UNITE[k+1].tableau );
	}


}