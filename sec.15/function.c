#include <stdio.h>
#include <string.h>
#include <limits.h>
#include "function.h"


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
