#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdint.h>
#include <limits.h>
#include "function.h"

const char *align[] = {"left", "center", "right"};
const char *turnFont[] = {"Off", "On"};

int convertBin(char *bin)
{
	size_t len = strlen(bin);
	printf("size: %ld\n", len);

	int number = 0;
	int i, n;
	
	if ( len >= 32) {
		number += (bin[len-1] == '1')? 1 : 0;
		for (i = len-2, n = 0; i > 0, n < 31; i--, n++)
			number += (bin[i] == '1')? (2 << n) : 0;
		number -= (2 << n);
	} else {
		number += (bin[len-1] == '1')? 1 : 0;
		for (i = len-2, n = 0; i >=0; i--, n++)
			number += (bin[i] == '1')? (2 << n) : 0;
	}
	return number;
}
void displayBinar(const char *bin)
{
	int i = 0;
	while (bin[i])
		putchar(bin[i++]);
	putchar('\n');
}
void bitwiseOp(const char *bin1, const char* bin2, char mode)
{
	int i = strlen(bin1);
	int j = strlen(bin2);
	int size = (i >= j)? i : j;
	char temp[size+1];
	char cpyBin1[size+1];
	char cpyBin2[size+1];
	memset(cpyBin1, '0', size-1);
	memset(cpyBin2, '0', size-1);
	strcpy(cpyBin1 + (size-i), bin1);
	strcpy(cpyBin2 + (size-j), bin2);	

	switch (mode) {
		case '2':
			printf("  %-s\n& %s\n  ", cpyBin1, cpyBin2);
			while (--size >= 0 )
				temp[size] = (0x1 & cpyBin1[size] & 0x1 & cpyBin2[size]) + 48;
			displayBinar(temp);
			break;
		case '3':
			printf("  %-s\n| %s\n  ", cpyBin1, cpyBin2);
			while (--size >= 0 )
				temp[size] = (0x1 & cpyBin1[size] | 0x1 & cpyBin2[size]) + 48;
			displayBinar(temp);
			break;
		case '4':
			printf("  %-s\n^ %s\n  ", cpyBin1, cpyBin2);
			while (--size >= 0 )
				temp[size] = (0x1 & cpyBin1[size] ^ 0x1 & cpyBin2[size]) + 48;
			displayBinar(temp);
			break;
		default:
			i = -1;
			printf("~(%s)\n  ", bin1);
			while (bin1[++i])
				putchar((bin1[i] == '0')? '1' : '0');
			putchar('\n');
			i = -1;
			printf("~(%s)\n  ", bin2);
			while (bin2[++i])
				putchar((bin2[i] == '0')? '1' : '0');
			putchar('\n');

	}

}

int countBiteOn(int number)
{
	int counter = 0;

	for( ; number != 0; number/=2)
		counter += number % 2;
	return counter;
}
_Bool getBit(int number, int n)
{
	return 0x1 & number >> n;
}
char turn(char ch, int n)
{
	_Bool temp;

	for (int i = 0; i < n; i++) {
		temp = 0x1 & (ch >> 7) + '0';	
		ch <<= 1;
		ch |= temp;
	}

	return ch;
}
int menu(struct setFont *font)
{
	char ch;

	printf("\t%4s\t%5s\t%6s\t%3c\t%3c\t%3c\n", "Type", "Size", "Align", 'B', 'I', 'U');
	printf("\t%d\t%d\t%6s\t%3s\t%3s\t%3s\n", font->type, font->size, align[font->align], turnFont[font->B],
			turnFont[font->I], turnFont[font->U]);
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
void setType(struct setFont *font)
{
	uint8_t type;

	puts("Enter the type of font:");
	while (scanf("%hhu", &type) != 1) {
		puts("Wrong input, try again!");
		while (getchar() != '\n') {}
	}
	while (getchar() != '\n') {}
	font->type &= CLEAR;
	font->type |= type;
}
void setSize(struct setFont *font)
{
	uint8_t size;

	puts("Enter the size of font:");
	while (scanf("%hhu", &size) != 1) {
		puts("Wrong input, try again!");
		while (getchar() != '\n') {}
	}
	while (getchar() != '\n') {}
	font->size &= CLEAR;
	font->size |= size;
}
void setAlign(struct setFont *font)
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
			font->align &= 0;
			break;
		case 'c':
			font->align &= 0;
			font->align |= 1;
			break;
		case 'r':	
			font->align &= 0;
			font->align |= 2;
			break;
	}
}
void setBold(struct setFont *font)
{
	font->B ^= ON;
}
void setItalic(struct setFont *font)
{
	font->I ^= ON;
}
void setUnderline(struct setFont *font)
{
	font->U ^= ON;
}
