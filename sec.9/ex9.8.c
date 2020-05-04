#include <stdio.h>

double power(double a, int b)
{
	double pow = 1;
	int i = 0;

	if (!b)
		return 1;
	if (!a)
		return 0;
	if (b < 0) {
		for(i = b; i < 0; i++)
			pow *= a;
		return 1/pow;
	} else {
		for(i =1; i <= b; i++)
			pow *= a;
		return pow;
	}
}

int main(int argc, char* argv[])
{
	printf("%.4lf\n", power(2, 4));
	printf("%.4lf\n", power(2, -4));
	printf("%.4lf\n", power(2, 0));
	printf("%.4lf\n", power(0, 4));
	printf("%.4lf\n", power(0, 0));

	return 0;
}
