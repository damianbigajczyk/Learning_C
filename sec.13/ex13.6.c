#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define DL 10

char *getName(char *from, int nmem)
{
	char *result = NULL;
	char *here = NULL;

	result = fgets(from, nmem, stdin);
	if (result) {
		here = strchr(result, '\n');
		if (here) {
			*here = '\0';
		} else {
			while (getchar() != '\n') {}
		}
	}
	return result;
}

int main(int argc, char *argv[])
{
	FILE *in = NULL;
	FILE *out = NULL;

	int ch = '\0';
	int counter = 0;
	char file_s[DL];
	char file_d[DL];

	puts("Enter the name of file to reduce or press enter to exit.");
	while(getName(file_s, DL)) {
		if (*file_s == '\0')
			return 0;
		if (!(in = fopen(file_s, "r"))) {
			fprintf(stderr, "Failed to open file \"%s\"\nTry again!\n", file_s);
			continue;
		}
		break;
	}
	
	puts("Enter the name of reduced file or press enter to exit.");
	while (getName(file_d, DL)) {
		if (*file_d == '\0') {
			fclose(in);
			return 0;
		}
		if (!(out = fopen(file_d, "w"))) {
			fprintf(stderr, "Failed to open file \"%s\"\n", file_d);
			fclose(in);
			exit(EXIT_FAILURE);
		}
		break;
	}

	while ((ch = fgetc(in)) != EOF)
		if (!(counter++ % 3))
			fputc(ch, out);

	if (fclose(in) || fclose(out))
		fputs("Failed to close files\n", stderr);
	return 0;
}
