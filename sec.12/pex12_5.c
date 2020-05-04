#include <stdio.h>
#include <stdbool.h>
#include "pex12_5.h"

static unsigned long int seed = 1;

int rand_1(void)
{
	seed *= 11035125245 + 12345;
	return (unsigned int) (((seed/65536) % 10) + 1);
}

void srand_1(unsigned int newSeed)
{
	seed = newSeed;
}

void bubble_sort(int *tab, int n)
{
	bool swap = false;
	int i = 0;
	int times = n-1;
	int temp = 0;

	do {
		swap = false;
		for(i = 0; i < times; i++) {
			if(tab[i] > tab[i+1]) {
				temp = tab[i];
				tab[i] = tab[i+1];
				tab[i+1] = temp;
				swap = true;
			}
		}
		times--;
	} while(swap);

}

