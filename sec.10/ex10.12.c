#include <stdio.h>
#include "function.h"

int main(int argc, char* argv[])
{
	printf(" ROK         OPADY (w calach)\n");
	printf("Roczna srednia wynosi: %.1f cale\n\n", average(rain, 5)/5);
	printf("Srednie miesieczne:\n\n");
	printf(" Sty  Lut  Mar  Kwi  Maj  Cze  Lip  Sie  Wrz  Paz  Lis  Gru\n");

	smallAvg(rain, 5);

	printf("\n");

	return 0;
}
