/*
Author: Hajatiana
Version: 1.0.0_HJ
created: 18/03/2023

*/

#include <stdio.h>
#include <ctype.h>
#include "dimension.h"
#include "conver.h"

void calcul(int n, int dim, int choix);
void choiceBase(int* choix,int* n);


int main(){
	printf("\tConversion d'un nombre decimal en base quelconque\n");
// donnee 
	int n=0,			/// le nombre a convertir 
		choix=0;		/// le choix de la base
	int dim=0;			/// la dimension du tableau
	
	
	choiceBase(&choix,&n);
	
// Traitement
	
	calcul( n, dim, choix);

	return 0;
}


void choiceBase(int* choix,int* n){
	do{
		printf("\nEntrer le nombre à convertir: ");scanf("%d", n); 
	}while( *n == isalpha(*n));
	do{
		printf(" \nEntrer le base : ");scanf("%d", choix);
		
	}while(*choix<2 || *choix>9 && *choix == isalpha(*choix));
	
	
}

void calcul(int n, int dim, int choix){
	
	if(choix == 2){
		printf("\n\t\t## CONVERSION EN BASE 2 ##\n\n");
		dim = dimensionB2(n);
		converB2(dim,n);
	}
	
	if(choix == 3){
		printf("\n\t\t## CONVERSION EN BASE 3 ##\n\n");
		dim = dimensionB3(n);
		converB3(dim,n);
	}
	
}

