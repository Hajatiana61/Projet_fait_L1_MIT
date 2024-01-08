#include <stdio.h>
#include <stdlib.h>
void getNmax(int* digit,int* max);
void data(int *digit);

int main(){
	int *digit;			/// variable pour les nombres a etudier
	int* max;			/// les nombres 2 superieurs
	max=malloc(2*(sizeof(int)));
	digit=malloc(4*(sizeof(int)));
	
	printf("\t\t\t#__ Deux nombres superieurs __#\n\n");
	data(digit);		/// saisis des nombres a etudier
	
	getNmax(digit,max);
	
	return 0;
}

void data(int *digit){
	printf("Entrer les nombres a etudier:\n\n");
	for(int i=0; i<4;i++){
		printf("digit[%d]: ", i);scanf("%d", (digit+i));
	}
}


void getNmax(int* digit,int* max){
	
	int point=0;			/// Indice pour detecter le 1er nombre superieur
	
	*max=0;					/// Place du nombre sup1
	for(int i=0; i<4; i++){
			if(*(digit+i) > *max){
				*max=*(digit+i);
				point=i;
			}
	}
	
	*(max+1)=0;				/// Place du nombre sup2
	for(int i=0; i<4; i++){
		if(i!=point && *(digit+i) > *(max+1)){
			*(max+1)=*(digit+i);
		}
	}
	

	printf("\n %d et %d sont les plus grands nombres \n",*max, *(max+1));
}
