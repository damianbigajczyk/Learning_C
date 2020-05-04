#include <stdio.h>
#include <ctype.h>

int main(int argc, char* argv[])
{
	char ch = '\0';
	char choice = (argc > 1)? argv[1][1] : 'p';
	FILE *fp = fopen("tekst.txt", "r");

	if (fp == NULL) {
		puts("Failed to open file");
		return 0;
	}

	switch (choice) {
		case 'u':
			while ((ch = fgetc(fp)) != EOF) {
				if (isalpha(ch)) {
					fputc(toupper(ch), stdout);
				} else {
					fputc(ch, stdout);
				}
			}
			break;
		case 'l':
			while ((ch = fgetc(fp)) != EOF) {
				if (isalpha(ch)) {
					fputc(tolower(ch), stdout);
				} else {
					fputc(ch, stdout);
				}
			}
			break;
		default:
			while ((ch = fgetc(fp)) != EOF)
				fputc(ch, stdout);	
	}

	return 0;
}
