#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define name 15

int main(int argc, char *argv[])
{
	FILE *f_s = NULL;
	FILE *f_d = NULL;
	
	char source[name];
	char destiny[name];
	int ch = 0;

	puts("Enter the name of source file:");

	while (!(scanf("%s", source)))
		puts("Wrong input, try again!");

	if (!(f_s = fopen(source, "r"))) {
		fprintf(stderr, "Failed to open file \"%s\"\n", source);
		exit(EXIT_FAILURE);
	}

	puts("Enter the name of destiny file:");

	while (!(scanf("%s", destiny)))
		puts("Wrong input, try again!");

	if (!(f_d = fopen(destiny, "w"))) {
		fprintf(stderr, "Failed to open file \"%s\"\n", destiny);
		fclose(f_s);
		exit(EXIT_FAILURE);
	}
	
	while ((ch = fgetc(f_s)) != EOF)
		fputc(toupper(ch), f_d);
	
	if (fclose(f_s))
		fprintf(stderr, "Failed to close file \"%s\"\n", source);

	if (fclose(f_d))
		fprintf(stderr, "Failed to close file \"%s\"\n", destiny);

	return 0;
}
