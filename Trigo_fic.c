#include "stdio.h"
#include "stdlib.h"
#include "math.h"

int main()
{
	FILE *fic = fopen("Trigo1.xlsx", "r+");
	
	double Angle_degree = 90;
	double Angle_radian = Angle_degree * M_PI / 180;
	double sinus_Value = sin(Angle_radian);
	double cosinus_Value = cos(Angle_radian);
	double tan_Value = tan(Angle_radian);

	char *Title =malloc(sizeof(char)*100);

	sprintf(Title,";;>>Tableau Trigonometrie<<;;");
	fputs(Title, fic);
	fputc('\n',fic);
	
	sprintf(Title,"Angle_degree;COS;SIN;TAN");
	fputs(Title, fic);
	fputc('\n',fic);

	fprintf(fic,"%.2f;%.4f;%.4f;%.4f", Angle_degree, cosinus_Value, sinus_Value, tan_Value);
	fputc('\n',fic);

	fclose(fic);

}
