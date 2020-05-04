#include <stdio.h>
#include <stdlib.h>

#define DL 15

int main(int argc, char *argv[])
{
	FILE *wp = NULL;
	char name[DL] = {'\0'};
	int ch = 0;
	unsigned long counter = 0;

	puts("Enter the name of file:");
	while (!(scanf("%s", name))) {
			puts("Wrong input, try again!");
			while (getchar() != '\n') {}
	}

	if (!(wp = fopen(name, "r"))) {
		fprintf(stderr, "Failed to open \"%s\".\n", name);
		exit(EXIT_FAILURE);
	}

	while ((ch = getc(wp)) != EOF) {
		putc(ch, stdout);
		counter++;
	}

	if (fclose(wp))
		fprintf(stdout, "Failed to close \"%s\".\n", name);
	
	fprintf(stdout, "The file named \"%s\" contains %lu signs.\n", name, counter);

	return 0;
}
