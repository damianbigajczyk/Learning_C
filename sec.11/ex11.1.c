#include <stdio.h>

void test(char *tab, int n)
{
	for(int i = 0; i < n; i++) {
		*(tab + i) = getchar();
	}
}

int main(int argc, char* argv[])
{
	char array[5];

	test(array, 5);

	for(int i = 0; i < 5; i++) {
		printf("%d) %c %d\n", i,  *(array + i), *(array + i));
	}


	return 0;
}
