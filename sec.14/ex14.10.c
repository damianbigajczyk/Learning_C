#include <stdio.h>
#include <math.h>

void recast(double *source, double *destiny, int n, double (*fw)(double));
void show(double *tab, int n);
double add(double a);
double power(double a);

int main(int argc, char **argv)
{
	double source[] = {1, 2.3, 2.5, 6.8, 0};
	double destiny[5];
	
	fputs("Source[5] =\t\t", stdout);
	show(source, sizeof(source)/sizeof(double));
	fputs("Destiny[5] =\t\t", stdout);
	show(destiny, sizeof(destiny)/sizeof(double));

	recast(source, destiny, sizeof(source)/sizeof(double), add);
	fputs("Add: Destiny[5] =\t", stdout);
	show(destiny, sizeof(destiny)/sizeof(double));

	recast(source, destiny, sizeof(source)/sizeof(double), power);
	fputs("Power: Destiny[5] =\t", stdout);
	show(destiny, sizeof(destiny)/sizeof(double));

	recast(destiny, destiny, sizeof(source)/sizeof(double), sqrt);
	fputs("Sqrt: Destiny[5] =\t", stdout);
	show(destiny, sizeof(destiny)/sizeof(double));

	recast(source, destiny, sizeof(source)/sizeof(double), sin);
	fputs("Sin: Destiny[5] =\t", stdout);
	show(destiny, sizeof(destiny)/sizeof(double));

	return 0;
}

void recast(double *source, double *destiny, int n, double (*fw)(double))
{
	for (int i = 0; i < n; i++)
		destiny[i] = (*fw)(source[i]);
}

void show(double *tab, int n)
{
	for (int i = 0; i < n; i++)	
		printf("%.2f\t", tab[i]);
	putchar('\n');
	putchar('\n');
}

double add(double a)
{
	return a+1;
}

double power(double a)
{
	return a*a;
}
