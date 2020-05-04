#include <stdio.h>
#include <stdint.h>

void do_podst_n(uint32_t n, uint8_t choice)
{
	uint8_t r = n % choice;
	if (n >= choice)
		do_podst_n(n / choice, choice);
	putchar(48 + r);
}


int main(int argc, char **argv)
{
	do_podst_n(34, 2);
	putchar('\n');
	do_podst_n(34, 3);
	putchar('\n');
	do_podst_n(34, 4);
	putchar('\n');
	do_podst_n(34, 5);
	putchar('\n');
	do_podst_n(34, 6);
	putchar('\n');
	do_podst_n(34, 7);
	putchar('\n');
	do_podst_n(34, 8);
	putchar('\n');
	do_podst_n(34, 9);
	putchar('\n');
	do_podst_n(34, 10);
	putchar('\n');

	return 0;
}
