#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[])
{
	int i = 0;
	int wordLen = 0;
	char array[255];

	puts("Write something");
	while ((array[i] = getchar()) != '\n')
		i++;
	array[i] = '\0';
	
	wordLen = strlen(array);
	for(i = wordLen; i >= 0; i--)
		putchar(*(array + i));
	puts("\nThe end");

	return 0;
}
