#include <stdio.h>

void copy_p2(double *source, double *destiny, double *end)
{
	while (source < end) {
		*destiny = *source;
		destiny++;
		source++;
	}
}
void show(double *tab, int n)
{
	for(int i = 0; i < n; i++)
		printf("%lf\t", *(tab + i));
	putchar('\n');
}

int main(int argc, char **argv)
{
	double array_1[] = {1, 2, 3, 4, 5, 6, 7};
	double array_2[3];
	
	show(array_1, sizeof(array_1)/sizeof(double));
	show(array_2, sizeof(array_2)/sizeof(double));

	copy_p2(array_1 + 2, array_2, array_1 + 5);

	show(array_1, sizeof(array_1)/sizeof(double));
	show(array_2, sizeof(array_2)/sizeof(double));


	return 0;
}
