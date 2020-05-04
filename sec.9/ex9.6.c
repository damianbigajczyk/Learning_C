#include <stdio.h>

void swap(double *px, double *py)
{
	double temp = *px;
	*px = *py;
	*py = temp;
}

void sort(double *px, double *py, double *pz)
{
	if (*px > *py)
		swap(px, py);
	if (*py > *pz)
		swap(py, pz);
	if (*px > *py)
		swap(px, py);

}

int main(int argc, char* argv[])
{
	double x = 0;
	double y = 1;
	double z = 2;

	while (scanf("%lf %lf %lf %*s", &x, &y, &z) == 3) {
		sort(&x, &y, &z);
		printf("%lf, %lf %lf\n", x, y, z);
	}


	return 0;
}
