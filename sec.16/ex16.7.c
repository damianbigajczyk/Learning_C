#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>

void showArray(const double *tab, int n);
double *newArray(int n, ...);

int main(int argc, char **argv)
{
	double *w1, *w2;
	w1 = newArray(5, 1.2, 2.3, 3.4, 4.5, 5.6);
	w2 = newArray(4, 100.0, 20.00, 8.08, -1890.0);

	showArray(w1, 5);
	showArray(w2, 4);

	free(w1);
	free(w2);

	return 0;
}
void showArray(const double *tab, int n)
{
	for (int i = 0; i < n; i++)
		printf("%.2f\t", *(tab+i));
	putchar('\n');
}
double *newArray(int n, ...)
{
	double *wsk = malloc(n * sizeof(double));
	va_list ap;
	va_start(ap, n);
	for (int i = 0; i < n; i++)
		*(wsk + i) = va_arg(ap, double);
	va_end(ap);
	return (wsk) ? wsk : NULL;
}
