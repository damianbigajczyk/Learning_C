#include <stdio.h>
#include <stdint.h>

int main(int argc, char *argv[])
{
	const uint8_t rows = 6;

	int i = 0;
	char ch = 70; //F

	for(i = 0; i < rows; i++) {
		for(ch = 'F'; ch >= ('F' - i); ch--)
			putchar(ch);
		putchar('\n');
	}

	return 0;
}
