#include <stdio.h>

int main(int argc, char* argv[])
{
	char ch = '\0';
	int i = 0;
	int size = 0;
	char array[100];

	while ((ch = getchar()) != '#') {
		if(ch == '\n') {
			continue;
		}
		array[i++] = ch;
	}

	size = i;

	for(i = 0; i < size ; i++) {
		printf("%c='%d'", array[i], (int)(array[i]));
		((i != 0) && ((i+1)%8 == 0))? printf("\n") : printf("\t");
	}
	putchar('\n');

	return 0;
}
