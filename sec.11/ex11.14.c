#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

double power(double a, int b)
{
	if (b == 1)
		return a;
	return a * power(a, --b);
}

int main(int argc, char *argv[])
{
	if (argc < 3) {
		puts("USAGE: podstawa(double) wykladnik(int)");
		return 0;
	}
	if (isdigit(atof(argv[1]))) {
		puts("YES");
	} else {
		puts("NO");
	}
			
	printf("%f\n", power(atof(argv[1]), atoi(argv[2])));

	return 0;
}
