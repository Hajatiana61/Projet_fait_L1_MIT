#include <stdio.h>

void converB2(int dim, int n){
	
	int rest[dim];
	printf("%d = ",n);
	for( int i=0; i < dim; i++){
		    
		rest[i] = n % 2;
		n = n/2;
			
	}
		

	for(int i=(dim-1); i >=0; i--){
		printf("%d ", rest[i]);
	
	}
}

void converB3(int dim, int n){
	
	int rest[dim];
	printf("%d = ",n);
	for( int i=0; i < dim; i++){
		    
		rest[i] = n % 3;
		n = n/3;
			
	}
		

	for(int i=(dim-1); i >=0; i--){
		printf("%d ", rest[i]);
	
	}
}
