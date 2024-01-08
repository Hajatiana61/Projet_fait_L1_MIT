/*
Author: Hajatiana
Version: 1.0.0_HJ
created: 18/03/2023

*/

#include <stdio.h>
#include "determine.h"
#include "indice.h"
#include "donne.h"

//void Bissextile(int M, int Q);

int main(){
	printf("\tle jour de la semaine d`une date \n\n");
// donnees
	
	int day=1;		/// le jour de la semaine a trouver
	int J=37,		/// numero du jour 
		M=34,		/// le mois
		Q=2034,		/// l`annee
		K=473,		/// les deux derniers chiffres de l`annee
	    P=554 ;		/// les deux premiers chiffres de l`annee
	
	getData(&J,&M,&Q,&K,&P);
			
// Traitement
				/* Annee bissextile*/
	
	if((Q % 4) == 0 &&( Q % 100)!= 0 || (Q % 4 )== 0 && ( Q % 100 )==0 && (Q % 400)==0){
		
		if(M==1 || M==2){
			
			int Ksur4 = (K/4)-1;		/// les 2 derniers sur 4
			int M_id=78, Q_id=76;
		
			M_id= indice_Mois(M);
			Q_id= indice_siecle(P);
		
			int sum =0;
			sum= J+K+Ksur4+M_id+Q_id;
			day = sum % 7;
			
		}
	
		else{
			int Ksur4 = K/4;		/// les 2 derniers sur 4
			int M_id=78, Q_id=76;
		
			M_id= indice_Mois(M);
			Q_id= indice_siecle(P);
		
			int sum =0;
			sum= J+K+Ksur4+M_id+Q_id;
			day = sum % 7;
			
		}
			
	}	
		
	
				/* Annee non bissextile */
	
	if((Q % 4) != 0 ||(Q % 4)== 0 && ( Q % 100)==0 && (Q % 400) != 0){
		
		int Ksur4 = K/4;		/// les 2 derniers sur 4
		int M_id=78, Q_id=76;
		
		M_id= indice_Mois(M);
		Q_id= indice_siecle(P);
		
		int sum =0;
		sum= J+K+Ksur4+M_id+Q_id;
		day = sum % 7;
			
	}
			
// result	
	DetermineDay(day);

	return 0;	
	
}

