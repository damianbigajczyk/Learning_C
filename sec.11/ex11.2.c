#include <stdio.h>

#define size 5

int main(int argc, char* argv[])
{
	char array[size];
	char ch = '\0';
	int i = 0;

	while (i < size && (ch = getchar()) != '\n' && ch != '\t' && ch != ' ') {
		*(array + i) = ch;
		i++;
	}

	for(i = 0; i < size; i++) {
		printf("%d) %c %d\n", i, *(array + i), *(array + i));
	}


	return 0;
}
