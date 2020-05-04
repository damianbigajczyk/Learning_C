#include <stdio.h>
#include <ctype.h>
#include <stdint.h>
#include <stdbool.h>

int main(int argc, char *argv[])
{
	uint16_t words = 0; 
	uint16_t upper = 0; 
	uint16_t lower = 0; 
	uint16_t numbers = 0;
	uint16_t space = 0;
	bool flag = false;
	char ch = '\0';
	FILE *fp = fopen("tekst.txt", "r");

	if (fp == NULL)
		return 0;

	while ((ch = getc(fp)) != EOF) {
		if (isalpha(ch)) {
			if (isupper(ch)) {
				upper++;
			} else {
				lower++;
			}
			flag = true;
		} else if (isdigit(ch)) {
				numbers++;
				if (flag) {
					words++;
					flag = false;
				}
		} else if (isspace(ch)) {
			space++;
			if (flag) {
				words++;
				flag = false;
			}
		} else {
			words++;
			flag = false;
		}
	}
	fclose(fp);
	printf("%d %d %d %d %d\n", words, upper, lower, numbers, space);
	return 0;
}
