#include <stdio.h>

#define basic 100

int main(int argc, char *argv[])
{
	int year = 1;
	float Ewa = basic;
	float Kasia = basic;
	const float income = 0.1 * Ewa;

	do {
		Ewa += income;
		Kasia += (Kasia * 0.05);
		printf("After %d years Ewa has %.2f$\tKasia has %.2f$\n",
				year++, Ewa, Kasia);
	} while(Ewa > Kasia);

	return 0;
}
