#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>
#include "function.h"

int loadString(char (*argv)[50])
{
	FILE *fp = fopen("file_1", "r");
	char ch = '\0';
	int i = 0;
	int j = 0;
	
	if (fp == NULL) {
		puts("Failed to open file: \"file_1\"");
		return -1;
	}

	while (((ch = fgetc(fp)) != EOF) && (i < 10)) {
		if (ch == '\n' || j == 48) {
			argv[i][j] = ch;
			argv[i][++j] = '\0';
			j = 0;
			i++;
		} else {	
			argv[i][j] = ch;
			j++;
		}
	}	
	if (fclose(fp))
		puts("failed to close file: \"file_1\"");
	return --i;
}
void menu(void)
{
	puts("********************* MENU **********************");
	puts("1) Display the original list of string");
	puts("2) Display strings in ASCII order");
	puts("3) Display strings depends on length (increase)");
	puts("4) Display string depends on first word's length");
	puts("5) The end");
}
int getLen(const char *s)
{
	int result = 0;

	while(isalpha(*s)) {
		++result;
		++s;
	}
	return result;
}
void showString(const char (*argv)[50], int n, int mode)
{
	bool swap = false;
	int i = 0;
	int times = n-1;
	char strings[10][50];
	char temp[50];	

	for (i = 0; i < 10; i++)
		strncpy(strings[i], argv[i], 49);

	switch (mode) {
		case 1:
			for (i = 0; i < n; i++)
				fputs(argv[i], stdout);
			break;
		case 2:
			do {
				for (i = 0, swap = false; i < times; i++) {
					if(strcmp(strings[i], strings[i+1]) > 0) {
						strcpy(temp, strings[i]);
						strcpy(strings[i], strings[i+1]);
						strcpy(strings[i+1], temp);
						swap = true;
					}
				}
				--times;
			} while (swap);
			for (i = 0; i < n; i++)
				fputs(strings[i], stdout);
			break;
		case 3:
			do {
				for (i = 0, swap = false; i < times; i++) {
					int firstLen = strlen(strings[i]);
					int secondLen = strlen(strings[i+1]);

					if(firstLen - secondLen > 0) {
						strcpy(temp, strings[i]);
						strcpy(strings[i], strings[i+1]);
						strcpy(strings[i+1], temp);
						swap = true;
					}
				}
				--times;
			} while (swap);
			for (i = 0; i < n; i++)
				fputs(strings[i], stdout);
			break;
		case 4:
			do {
				for (i = 0, swap = false; i < times; i++) {
					int firstLen = getLen(strings[i]);
					int secondLen = getLen(strings[i+1]);

					if(firstLen - secondLen > 0) {
						strcpy(temp, strings[i]);
						strcpy(strings[i], strings[i+1]);
						strcpy(strings[i+1], temp);
						swap = true;
					}
				}
				--times;
			} while (swap);
			for (i = 0; i < n; i++)
				fputs(strings[i], stdout);
			break;
		default:
			puts("I shouldn't be here");
	}
}
