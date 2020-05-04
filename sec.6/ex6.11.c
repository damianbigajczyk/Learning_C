#include <stdio.h>

#define size 8

int main(int argc, char *argv[])
{
	int i = 0;
	int numbers[size];

	for(i = 0; i < size; i++) {
		printf("Enter your %d number: ", i + 1);
		scanf("%d", numbers + i);
	}
	putchar('\n');

	for(i = size - 1; i >= 0; i--)
		printf("%d) %d\n", i + 1, *(numbers + i));

	puts("The end");

	return 0;
}
