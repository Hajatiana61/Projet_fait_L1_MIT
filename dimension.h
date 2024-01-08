
#include <math.h>

int dimensionB2(int n){
	int dim=0, p=0;
	p=log(n)/log(2);
	dim = p+1;
	
	return dim;
}

int dimensionB3(int n){
	int dim=0, p=0;
	p=log(n)/log(3);
	dim = p+1;
	
	return dim;
}
