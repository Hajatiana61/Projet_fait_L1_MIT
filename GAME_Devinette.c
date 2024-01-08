#include <stdio.h>
#include <stdlib.h>
#include <time.h>


int main(){
	printf("\t\t\tJEU DE DEVINETTE\n\n");
	printf("#Instruction du jeu:\n Deviner le nombre choisi par l'ordinateur, \n tel que le nombre soit entre 1 et 100\n\n \t§Vous avez 7 tentatives§\n\n");
/// Données
	int c=1;

	int nb=0,			/// le nombre choisi par le systeme
		guess=0,  		/// la tentative
		tour=0;			/// le nombre de tour
	do{
		srand(time(NULL));
		nb=(1+ (int)(100.0*rand() / (RAND_MAX +1.0)));
	/*printf("nb= %d\t", nb);*/
/// Traitement
		do{
			printf("\nDevinner le nombre : ");
			scanf("%d", &guess);
		
			if(guess<nb){
				printf("\nLe nombre est trop petit\n");
			}
			if(guess>nb){
				printf("\nLe nombre est trop grand\n");
				}
			if(guess==nb){
				printf("\n Bravo ! Le nombre à deviner est %d\n",nb);
			}
		
			tour=tour+1;
	
		
		
		}while(guess!=nb && tour<7);
	
	
		if(guess!=nb){
			printf("\n\nPerdu !!!\n");
		}
	
		printf("Continuer ?  0. non  /  1. oui\n");scanf("%d", &c);
		system("clear");
	
	}while(c==1);
	
		printf("\tMerci d'avoir joue\n");
		return 0;
		
}


