#include <stdio.h>

int main(int argc, char* argv[])
{
	int sign = 0;

	while (getchar() != EOF) {
		sign++;
	}

	printf("number of marks: %d\n", sign);

	return 0;
}
