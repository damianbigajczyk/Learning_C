#include <stdio.h>

const double C = 273.16;
const double F = 32.0;

void Temperature(double farenh)
{
	printf("%.2lfF = %.2lfC = %.2lfK\n", farenh, 5.0/9.0 *(farenh - F), (5.0/9.0 *(farenh - F)) + C);
}

int main(int argc, char* argv[])
{
	int rc = 0;
	double farenh = 0;

	do {
		printf("Enter a temperature in Fahrenheits, please: ");
		rc = scanf("%lf", &farenh);

		if (rc != 1) {
			break;
		}

		Temperature(farenh);

	} while(1);
	puts("The end");

	return 0;
}
