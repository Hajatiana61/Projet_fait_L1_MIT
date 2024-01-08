#include "stdio.h"
#include "stdlib.h"
#include "string.h"

char* DetermineNB(char* texte, long long nombre);

char* inferieurfolo(char* texte,long long nombre);
char* inferieurZato(char* texte,long long nombre);
char* inferieurArivo(char* texte,long long nombre);
char* inferieurAlina(char* texte,long long nombre);
char* inferieurEtsy(char* texte,long long nombre);
char* inferieurTapitrisa(char* texte,long long nombre);
char* Tapitrisa(char* texte,long long nombre);
char* lavotrisa(char* texte,long long nombre);

void unit_diz(long long nb, long long* a, long long* b);
int detective(long long nb, long long* rest,long long p);
int puiss(int down, int up);

char* lectureU(char* texte,long long nb);
char* lectureD(char* texte,long long nb);
char* lectureC(char* texte,long long nb);
char* lectureM(char* texte,long long nb);
char* lectureM2(char* texte,long long nb);
char* lectureQua(char* texte,long long nb);
char* lectureQuint(char* texte,long long q1, long long q2, long long q3);

char* vakitenyU(long long isa);
char* vakitenyD(long long isa);
char* vakitenyC(long long isa);
char* vakitenyM(long long isa);
char* vakitenyM2(long long isa);
char* vakitenyQua(long long isa);
char* vakitenyQuint();

int main(){
/*-----------------------------------------------------------------------------------------------------------------*/
	long long nombre=12;				/// configuration ( faut changer )
/*-----------------------------------------------------------------------------------------------------------------*/

	char* texte=malloc(800);
	texte="";
	
	
	printf("\nle nombre est %lld\n\n", nombre);
	
	texte=DetermineNB(texte,nombre);
	
	printf("\n\n Lecture:\n\n>> ");
	printf(" %s", texte);
	
	return 0;
}

char* DetermineNB(char* texte, long long nombre)
{
	if(nombre<10)
	{
		texte=inferieurfolo(texte,nombre);
	}
	
	if(nombre>9 && nombre<100)
	{
		texte=inferieurZato(texte,nombre);
		
	}
	
	
	if(nombre>99 && nombre<puiss(10,3))
	{
		texte=inferieurArivo(texte,nombre);
		
	}
	
	if(nombre>999 && nombre<puiss(10,4))
	{
		texte=inferieurAlina(texte,nombre);
		
	}
	
	if(nombre>9999 && nombre<puiss(10,5))
	{
		texte=inferieurEtsy(texte,nombre);
		
	}
	if(nombre>99999 && nombre<puiss(10,6))
	{
		texte=inferieurTapitrisa(texte,nombre);
		
	}
	
	if(nombre>999999 && nombre<puiss(10,9))
	{
		texte=Tapitrisa(texte,nombre);

	}
	
	if(nombre>999999999)
	{
		texte=lavotrisa(texte,nombre);
		
	}
	
	return texte;
	
}

char* lavotrisa(char* texte,long long nombre)
{
	long long infLavotrisa=0;
	long long supLavotrisa=0;
	
	
	
	supLavotrisa=detective(nombre, &infLavotrisa, puiss(10,9));
	
	//printf("\n valeur : %lld \n", supLavotrisa);
	
	if(infLavotrisa==0)
	{
		texte=DetermineNB(texte, supLavotrisa);
		sprintf(texte,"%s lavotrisa", texte);
	}
	if(infLavotrisa!=0)
	{
		char* tmp=malloc(800);
		char* tmp2=malloc(800);
		
		texte=DetermineNB(texte, supLavotrisa);
		
		tmp=DetermineNB(tmp, infLavotrisa);
		
		sprintf(texte,"%s sy %s lavotrisa",tmp, texte);
	}
	
	return texte;
}

char* Tapitrisa(char* texte,long long nombre)
{
	long long infTapitrisa=0;
	long long quintFull=0;
	long long quint1=0,quint2=0,quint3=0;
	long long nb1=0, nb2=0;
	
	quint3=detective(nombre, &quintFull, puiss(10,8));
	nb1=nombre-(quint3*puiss(10,8));

	quint2=detective(nb1, &quintFull, puiss(10,7));
	nb2=nb1-(quint2*puiss(10,7));
	
	quint1=detective(nb2, &quintFull, puiss(10,6));
	
	
	quintFull=detective(nombre, &infTapitrisa, puiss(10,6));
	
	//printf("\n valeur %d", infTapitrisa);
	
	if(infTapitrisa==0)
	{
		texte=lectureQuint(texte,quint1, quint2, quint3);
	}
	if(infTapitrisa!=0)
	{
	
		if(infTapitrisa<100)
		{
			texte=inferieurZato(texte,infTapitrisa);
		}
	
		if(infTapitrisa>99 && infTapitrisa<puiss(10,3))
		{
			texte=inferieurArivo(texte,infTapitrisa);
		}
		
		if(infTapitrisa>999 && infTapitrisa<puiss(10,4))
		{
			texte=inferieurAlina(texte,infTapitrisa);
		}
		
		if(infTapitrisa>9999 && infTapitrisa<puiss(10,5))
		{
			texte=inferieurEtsy(texte,infTapitrisa);
		}
		if(infTapitrisa>99999 && infTapitrisa<puiss(10,6))
		{
			texte=inferieurTapitrisa(texte,infTapitrisa);
		}
		
		sprintf(texte,"%s sy", texte);
		texte=lectureQuint(texte,quint1, quint2, quint3);
	}	
	return texte;
}

char* inferieurTapitrisa(char* texte,long long nombre)
{
	long long infEtsy=0;
	int quadri=0;
	
	quadri=detective(nombre, &infEtsy, puiss(10,5));

	if(infEtsy==0)
	{
		texte=lectureQua(texte,quadri);
	}
	else
	{
	
		if(infEtsy<100)
		{
			texte=inferieurZato(texte,infEtsy);
		}
	
		if(infEtsy>99 && infEtsy<puiss(10,3))
		{
			texte=inferieurArivo(texte,infEtsy);
		}
		
		if(infEtsy>999 && infEtsy<puiss(10,4))
		{
			texte=inferieurAlina(texte,infEtsy);
		}
		if(infEtsy>9999 && infEtsy<puiss(10,5))
		{
			texte=inferieurEtsy(texte,infEtsy);
		}
		sprintf(texte,"%s sy", texte);
		texte=lectureQua(texte,quadri);
	}	
	return texte;
}

char* inferieurEtsy(char* texte,long long nombre)
{
	long long infAlina=0;
	long long millieme2=0;
	
	millieme2=detective(nombre, &infAlina, puiss(10,4));
	
	if(infAlina==0)
	{
		texte=lectureM2(texte,millieme2);
	}
	
	else
	{
		if(infAlina<100)
		{
			texte=inferieurZato(texte,infAlina);
		}
	
		if(infAlina>99 && infAlina<puiss(10,3))
		{
			texte=inferieurArivo(texte,infAlina);
		}
		
		if(infAlina>999 && infAlina<puiss(10,4))
		{
			texte=inferieurAlina(texte,infAlina);
		}
		
		sprintf(texte,"%s sy", texte);
		texte=lectureM2(texte,millieme2);
		
	}
	return texte;
}

char* inferieurAlina(char* texte,long long nombre)
{
	long long infArivo=0;
	long long millieme=0;
	
	millieme=detective(nombre, &infArivo, puiss(10,3));
	
	if(infArivo==0)
	{
		texte=lectureM(texte,millieme);
	}
	else
	{
		if(infArivo<100)
		{
			texte=inferieurZato(texte,infArivo);
		}
	
		if(infArivo>99 && infArivo<puiss(10,3))
		{
			texte=inferieurArivo(texte,infArivo);
		}
		
		sprintf(texte,"%s sy", texte);
		texte=lectureM(texte,millieme);
	}
	return texte;
}

char* inferieurArivo(char* texte,long long nombre)
{
	long long infZato=0;
	long long centaine=0;
	
	centaine=detective(nombre, &infZato, 100);
	
	if(infZato==0)
	{
		texte=lectureC(texte,centaine);
	}
	else
	{
		texte=inferieurZato(texte,infZato);
		
	
		if(centaine==1)
		{
		sprintf(texte,"%s amin'ny zato", texte);
		}
		if(centaine!=1)
		{
			sprintf(texte,"%s sy", texte);
			texte=lectureC(texte,centaine);
		}
	}
	return texte;
}

char* inferieurZato(char* texte,long long nombre)
{
	
	long long unite=0,dizaine=0;
	
	unit_diz(nombre, &unite, &dizaine);
	
	if(unite!=0 )	//&& dizaine==0
	{
		texte=lectureU(texte,unite);
	}
	
	if(unite!=0 && dizaine!=0)
	{
		sprintf(texte,"%s amby", texte);
	}
	
	if(dizaine!=0)
	{
		texte=lectureD(texte,dizaine);
	}
	
	
	return texte;
}


char* inferieurfolo(char* texte,long long nombre)
{
	texte=lectureU(texte, nombre);
	
	return texte;
}

void unit_diz(long long nb, long long* a, long long* b)
{
	*b=nb/10;
	*a=nb-(*b)*10;
	
}

int detective(long long nb, long long* rest,long long p)
{
	long long a=0;
	
	a= nb/p;
	
	*rest=nb-(a*p);
	
	return a;
}

int puiss(int down, int up)
{
	int answer=1;
	if(up==0)answer=1;
	
	else
	{
			while(up!=0)
			{
				answer=answer*down;
					up--;
			}
	}
	
	return answer;
}

char* lectureU(char* texte,long long nb)
{
	char* vakiny=malloc(50);
	char* tmp=malloc(400);
	
	strcpy(tmp,texte);
	vakiny=vakitenyU(nb);
	strcat(tmp,vakiny);
	
	return tmp;
}
char* lectureD(char* texte,long long nb)
{
	char* vakiny=malloc(50);
	char* tmp=malloc(400);
	
	strcpy(tmp,texte);
	vakiny=vakitenyD(nb);
	strcat(tmp,vakiny);
	
	return tmp;
}

char* lectureC(char* texte,long long nb)
{
	char* vakiny=malloc(50);
	char* tmp=malloc(400);
	
	strcpy(tmp,texte);
	vakiny=vakitenyC(nb);
	
	strcat(tmp,vakiny);
	
	return tmp;
}

char* lectureM(char* texte,long long nb)
{
	char* vakiny=malloc(50);
	char* tmp=malloc(400);
	
	strcpy(tmp,texte);
	vakiny=vakitenyM(nb);
	
	strcat(tmp,vakiny);
	
	return tmp;
}
char* lectureM2(char* texte,long long nb)
{
	char* vakiny=malloc(50);
	char* tmp=malloc(400);
	
	strcpy(tmp,texte);
	vakiny=vakitenyM2(nb);
	
	strcat(tmp,vakiny);
	
	return tmp;
}

char* lectureQua(char* texte,long long nb)
{
	char* vakiny=malloc(50);
	char* tmp=malloc(400);
	
	strcpy(tmp,texte);
	vakiny=vakitenyQua(nb);
	
	strcat(tmp,vakiny);
	
	return tmp;
	
}

char* lectureQuint(char* texte,long long q1, long long q2, long long q3)
{
	char* vakiny=malloc(50);
	char* tmp=malloc(400);
	
	strcpy(tmp,texte);
	
	
	if(q1!=0 )
	{
		vakiny=vakitenyU(q1);
		strcat(tmp,vakiny);
		
	}
	if(q1!=0 && q2!=0)
	{
		sprintf(tmp,"%s amby", tmp);
	}
	
	if(q2!=0)
	{
		
		vakiny=vakitenyD(q2);
		strcat(tmp,vakiny);
		
	}
	
	if((q3==1 && q1!=0) || (q3==1 && q2!=0))
	{
		sprintf(tmp,"%s amin'ny zato", tmp);
		
	}
	if((q3!=1 && q3!=0 && q1!=0) || (q3!=1 && q3!=0 && q2!=0))
	{
		sprintf(tmp,"%s sy", tmp);
	}
	if(q3!=0 && q1==0 && q2==0)
	{
		vakiny=vakitenyC(q3);
		strcat(tmp,vakiny);
	}
	
	if((q3!=0 && q3!=1 && q1==0 && q2!=0) || (q3!=0 && q3!=1 && q2==0 && q1!=0 ))
	{
		vakiny=vakitenyC(q3);
		strcat(tmp,vakiny);
	}
	if((q3!=0 && q3!=1 && q1!=0 && q2!=0) || (q3!=0 && q3!=1 && q2!=0 && q1!=0))
	{
		vakiny=vakitenyC(q3);
		strcat(tmp,vakiny);
	}
	
	vakiny=vakitenyQuint();
	strcat(tmp,vakiny);
	
	return tmp;
}


char* vakitenyU(long long isa)
{
	char* soratra=malloc(50);
	
	if(isa==0)soratra= " aotra";
	if(isa==1)soratra= " iraika";
	if(isa==2)soratra= " roa";
	if(isa==3)soratra= " telo";
	if(isa==4)soratra= " efatra";
	if(isa==5)soratra= " dimy";
	if(isa==6)soratra= " enina";
	if(isa==7)soratra= " fito";
	if(isa==8)soratra= " valo";
	if(isa==9)soratra= " sivy";
	
	return soratra;
	
}

char* vakitenyD(long long isa)
{
	char* soratra=malloc(50);
	
	
	if(isa==1)soratra= " folo";
	if(isa==2)soratra= " roapolo";
	if(isa==3)soratra= " telopolo";
	if(isa==4)soratra= " efapolo";
	if(isa==5)soratra= " dimapolo";
	if(isa==6)soratra= " enipolo";
	if(isa==7)soratra= " fitopolo";
	if(isa==8)soratra= " valopolo";
	if(isa==9)soratra= " sivifolo";
	
	return soratra;
	
}
char* vakitenyC(long long isa)
{
	char* soratra=malloc(50);
	
	if(isa==1)soratra= " zato";
	if(isa==2)soratra= " roanjato";
	if(isa==3)soratra= " telonjato";
	if(isa==4)soratra= " efajato";
	if(isa==5)soratra= " dimanjato";
	if(isa==6)soratra= " eninjato";
	if(isa==7)soratra= " fitonjato";
	if(isa==8)soratra= " valonjato";
	if(isa==9)soratra= " sivinjato";
	
	return soratra;
}

char* vakitenyM(long long isa)
{
	char* soratra=malloc(50);
	
	if(isa==1)soratra= " arivo";
	if(isa==2)soratra= " roa arivo";
	if(isa==3)soratra= " telo arivo";
	if(isa==4)soratra= " efatra arivo";
	if(isa==5)soratra= " dimy arivo";
	if(isa==6)soratra= " enina arivo";
	if(isa==7)soratra= " fito arivo";
	if(isa==8)soratra= " valo arivo";
	if(isa==9)soratra= " sivy arivo";
	
	return soratra;
}

char* vakitenyM2(long long isa)
{
	char* soratra=malloc(50);
	
	if(isa==1)soratra= " iray alina";
	if(isa==2)soratra= " roa alina";
	if(isa==3)soratra= " telo alina";
	if(isa==4)soratra= " efatra alina";
	if(isa==5)soratra= " dimy alina";
	if(isa==6)soratra= " enina alina";
	if(isa==7)soratra= " fito alina";
	if(isa==8)soratra= " valo alina";
	if(isa==9)soratra= " sivy alina";
	
	return soratra;
}

char* vakitenyQua(long long isa)
{
	char* soratra=malloc(50);
	
	if(isa==1)soratra= " iray Etsy";
	if(isa==2)soratra= " roa Etsy";
	if(isa==3)soratra= " telo Etsy";
	if(isa==4)soratra= " efatra Etsy";
	if(isa==5)soratra= " dimy Etsy";
	if(isa==6)soratra= " enina Etsy";
	if(isa==7)soratra= " fito Etsy";
	if(isa==8)soratra= " valo Etsy";
	if(isa==9)soratra= " sivy Etsy";
	
	return soratra;
}

char* vakitenyQuint()
{
	return " tapitrisa";
}

/*if(nombre!=10 || nombre!=20 || nombre!=30 || nombre!=40 || nombre!=50 || nombre!=60 || nombre!=70 || nombre!=80 || nombre!=90 || nombre!=100)
	{
		printf("\nle nombre est %d\n\n", nombre);*/
