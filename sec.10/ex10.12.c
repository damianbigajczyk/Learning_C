#include <stdio.h>

float average(const float (*rain)[12], int n)
{
	float sum = 0;

	for(int i = 0; i < n; i++) {
		for(int j = 0; j < 12; j++)
			sum += *(*(rain + i) + j);
	}

	return sum;
}
void smallAvg(const float (*rain)[12], int n)
{
	float sum = 0;
	for(int i = 0; i < 12; i++) {
		for(int j = 0; j < n; j++) {
			sum += *(*(rain + j) + i);
		}
		printf("%4.1f ", sum/n);
		sum = 0;
	}
}

int main(int argc, char* argv[])
{
	float rain[5][12] =
	{
		{4.3,4.3,4.3,3.0,2.0,1.2,0.2,0.2,0.4,2.4,3.5,6.6},
		{8.5,8.2,1.2,1.6,2.4,0.0,5.2,0.9,0.3,0.9,1.4,7.3},
		{9.1,8.5,6.7,4.3,2.1,0.8,0.2,0.2,1.1,2.3,6.1,8.4},
		{7.2,9.9,8.4,3.3,1.2,0.8,0.4,0.0,0.6,1.7,4.3,6.2},
		{7.6,5.6,3.8,2.8,3.8,0.2,0.0,0.0,0.0,1.3,2.6,5.2}
	};

	printf(" ROK         OPADY (w calach)\n");
	printf("Roczna srednia wynosi: %.1f cale\n\n", average(rain, 5)/5);
	printf("Srednie miesieczne:\n\n");
	printf(" Sty  Lut  Mar  Kwi  Maj  Cze  Lip  Sie  Wrz  Paz  Lis  Gru\n");

	smallAvg(rain, 5);

	printf("\n");

	return 0;
}
