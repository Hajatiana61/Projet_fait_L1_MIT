#include <stdio.h>

int indice_Mois(int M){
	int M_id=56;
	if(M==1 || M==10){
		M_id=0;	
	}
	if(M==5){
		M_id=1;	
	}
	if(M==8){
		M_id=2;	
	}
	if(M==2 || M==3 || M==11){
		M_id=3;	
	}
	if(M==6 ){
		M_id=4;	
	}
	if(M==9 || M==12){
		M_id=5;	
	}
	if(M==4 || M==7){
		M_id=6;
		
	}
	return M_id;
}

int indice_siecle(int P){
	int Q_id=88;
	int siecle = P+1;
	for(int i=0; i<1000; i+=4){
		if(siecle==i){
			Q_id=0;	
		}
		if(siecle==3+i){
			Q_id=2;	
		}
		if(siecle==2+i){
			Q_id=4;	
		}
		if(siecle==1+i){
			Q_id=6;
		}	
	}
	return Q_id;
}
