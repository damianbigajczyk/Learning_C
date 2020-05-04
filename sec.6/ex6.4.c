#include <stdio.h>
#include <stdint.h>

int main(int argc, char *argv[])
{
	const uint8_t rows = 6;
	int i = 0;
	int j = 0;
	char ch = 'A';

	for(i = 0; i < rows; i++) {
		for(j = 0 ; j <= i ; j++, ch++)
			putchar(ch);
		putchar('\n');
	}

	return 0;
}
