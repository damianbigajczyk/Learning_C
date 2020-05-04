#include <stdio.h>

double min(double x, double y)
{
	return (x < y)? x : y;
}

int main(int argc, char* argv[])
{
	double x = 0;
	double y = 0;

	while (scanf("%lf %lf %*s", &x, &y)) {
		printf("mniejsza to: %f\n", min(x, y));
	}

	return 0;
}
