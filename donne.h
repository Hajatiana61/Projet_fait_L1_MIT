#include <stdio.h>
#include <ctype.h>

void getData(int* J, int* M, int* Q,int* K,int *P){
	
	printf(" Entrer le jour: ");scanf("%d", J);
	printf(" Entrer le mois: ");scanf("%d", M);
	printf(" Entrer l'annee: ");scanf("%d", Q);
	printf(" \nEntrer les deux premiers chiffres de l'annee precedent:   ");scanf("%d",P);
	printf(" Entrer les deux derniers chiffres de l'annee precedent:  ");scanf("%d",K);
	
	
	printf("\nAlors, le jour de la date: \n\t%d / %d / %d\n",* J,* M,* Q);
	
}
