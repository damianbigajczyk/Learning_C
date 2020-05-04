#include <stdio.h>
#include <stdint.h>

void Fibonacci(uint8_t n)
{
	uint8_t preprevious = 0;
	uint8_t previous = 1;
	if (!n) {
		printf("%hhu\n", preprevious);
	} else if (n == 1) {
		printf("%hhu\t%hhu\n", preprevious, previous);
	} else {
		printf("%hhu\t%hhu\t", preprevious, previous);
		while (n-- > 2) {
			uint8_t next = preprevious + previous;
			printf("%hhu\t", next);
			preprevious = previous;
			previous = next;
		}
	}
	putchar('\n');
}

int main(int argc, char **argv)
{
	Fibonacci(13);
	return 0;
}
