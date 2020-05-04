#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(int argc, char *argv[])
{
	int i = 0;
	int number = 0;	
	int count[10] = {0};

	srand(time(NULL));

	for(i = 0; i < 1000; i++) {
		number = rand() % 10 + 1;
		count[number-1]++;
	}
	for(i = 0; i < 10; i++)
		printf("%d - %d\n", i+1, count[i]);


	return 0;
}
