#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define DL 15

int main(int argc, char **argv)
{
	FILE *pf = NULL;
	char nameFile[DL];
	long position = 0;
	int ch = 0;

	fputs("Enter the name of file: ", stdout);
	while (scanf("%s", nameFile) != 1) {
		fputs("Wrong input, try again!\n", stdout);
		while (getchar() != '\n') {}
	}

	if (!(pf = fopen(nameFile, "r"))) {
		fprintf(stderr, "Failed to open file: \"%s\"\n", nameFile);
		exit(EXIT_FAILURE);
	}

	fputs("Enter the position in file: ", stdout);
	while ((scanf("%ld", &position) == 1) && (position >= 0)) {
		if (fseek(pf, position, SEEK_SET)) {
			fputs("Too far, try again!\n", stdout);
			continue;
		}
		while ((ch = fgetc(pf)) != '\n')
			fputc(ch, stdout);
		fputc(ch, stdout);
		rewind(pf);
		fputs("Enter the position in file: ", stdout);
	}
	if (fclose(pf))
		fprintf(stderr, "Failed to close file: \"%s\"\n", nameFile);

	return 0;
}
