#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdint.h>
#include "font.h"

const char *align[] = {"left", "center", "right"};
const char *turnFont[] = {"Off", "On"};

int menu(unsigned long *font)
{
	char ch;

	printf("\t%4s\t%5s\t%6s\t%3c\t%3c\t%3c\n", "Type", "Size", "Align", 'B', 'I', 'U');
	printf("\t%ld\t%ld\t%6s\t%3s\t%3s\t%3s\n", (*font & F_CLEAR) >> 12, (*font & S_CLEAR) >> 5, 
			align[(*font & A_CLEAR) >> 3], turnFont[(*font & BOLD) >> 2],
			turnFont[(*font & ITALIC) >> 1], turnFont[*font & UNDERLINE]);
	puts("a) change font\tb) change size\t\tc) change align");
	puts("d) switch Bold\te) switch Italic\tf) switch Underline\nk) Exit");

	ch = tolower(getchar());
	while (getchar() != '\n') {}
	while (!strchr("abcdefk", ch)) {
		puts("Enter a, b, c, d, e, f or k");
		ch = tolower(getchar());
		while (getchar() != '\n') {}
	}
	return ch - 97;
}
void setType(unsigned long *font)
{
	uint8_t type;

	puts("Enter the type of font:");
	while (scanf("%hhu", &type) != 1) {
		puts("Wrong input, try again!");
		while (getchar() != '\n') {}
	}
	while (getchar() != '\n') {}
	*font &= ~F_CLEAR;
	*font |= (type << 12 & F_CLEAR);
}
void setSize(unsigned long *font)
{
	uint8_t size;

	puts("Enter the size of font:");
	while (scanf("%hhu", &size) != 1) {
		puts("Wrong input, try again!");
		while (getchar() != '\n') {}
	}
	while (getchar() != '\n') {}
	*font &= ~S_CLEAR;
	*font |= (size << 5 & S_CLEAR);
}
void setAlign(unsigned long *font)
{
	char ch;
	puts("Choose align:\nl) left\tc) center\tr) right");
	ch = tolower(getchar());
	while (getchar() != '\n') {}
	while (!strchr("lcr", ch)) {
		puts("Enter l, c or r");
		ch = tolower(getchar());
		while (getchar() != '\n') {}
	}
	switch (ch) {
		case 'l':
			*font &= ~A_CLEAR;
			break;
		case 'c':
			*font &= ~A_CLEAR;
			*font |= A_CENTER;
			break;
		case 'r':	
			*font &= ~A_CLEAR;
			*font |= A_RIGHT;
			break;
	}
}
void setBold(unsigned long *font)
{
	*font ^= BOLD; 
}
void setItalic(unsigned long *font)
{
	*font ^= ITALIC;
}
void setUnderline(unsigned long *font)
{
	*font ^= UNDERLINE;
}

