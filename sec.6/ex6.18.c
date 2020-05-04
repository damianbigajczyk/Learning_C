#include <stdio.h>
#include <stdint.h>

#define basic 5

int main(int arc, char *argv[])
{
	uint8_t friends = basic;
	int i = 1;

	while (friends < 150) {
		friends -= i;
		friends *= 2;
		printf("After %d weeks Professor has %u friends\n", i++, friends);
	}

	return 0;
}
