#include <stdio.h>

#define months 12
#define years 5

int main(int argc, char* argv[])
{
	const float rain[years][months] =
	{
		{4.3,4.3,4.3,3.0,2.0,1.2,0.2,0.2,0.4,2.4,3.5,6.6},
		{8.5,8.2,1.2,1.6,2.4,0.0,5.2,0.9,0.3,0.9,1.4,7.3},
		{9.1,8.5,6.7,4.3,2.1,0.8,0.2,0.2,1.1,2.3,6.1,8.4},
		{7.2,9.9,8.4,3.3,1.2,0.8,0.4,0.0,0.6,1.7,4.3,6.2},
		{7.6,5.6,3.8,2.8,3.8,0.2,0.0,0.0,0.0,1.3,2.6,5.2}
	};
	int year, month;
	float podsuma, suma;

	printf(" ROK         OPADY (w calach)\n");
	for(year = 0, suma = 0; year < years; year++) {
		for(month = 0, podsuma = 0; month < months; month++) {
			podsuma += *(*(rain + year) + month);
		}

		printf("%5d %12.1f\n", 2000 + year, podsuma);
		suma += podsuma;
	}

	printf("Roczna srednia wynosi: %.1f cale\n\n", suma/years);
	printf("Srednie miesieczne:\n\n");
	printf(" Sty  Lut  Mar  Kwi  Maj  Cze  Lip  Sie  Wrz  Paz  Lis  Gru\n");

	for(month = 0; month < months; month++) {
		for(year = 0, podsuma = 0; year < years; year++) {
			podsuma += *(*(rain + year) + month);
		}

		printf("%4.1f ", podsuma/years);
	}
	printf("\n");

	return 0;
}
