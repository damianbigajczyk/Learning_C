#include <stdio.h>
#include "function.h"

int main(int argc, char* argv[])
{
	int year, month;
	double podsuma, suma;

	printf(" ROK         OPADY (w calach)\n");
	for(year = 0, suma = 0; year < years; year++) {
		for(month = 0, podsuma = 0; month < months; month++) {
			podsuma += *(*(rain + year) + month);
		}

		printf("%5d %12.1lf\n", 2000 + year, podsuma);
		suma += podsuma;
	}

	printf("Roczna srednia wynosi: %.1lf cale\n\n", suma/years);
	printf("Srednie miesieczne:\n\n");
	printf(" Sty  Lut  Mar  Kwi  Maj  Cze  Lip  Sie  Wrz  Paz  Lis  Gru\n");

	for(month = 0; month < months; month++) {
		for(year = 0, podsuma = 0; year < years; year++) {
			podsuma += *(*(rain + year) + month);
		}

		printf("%4.1lf ", podsuma/years);
	}
	printf("\n");

	return 0;
}
