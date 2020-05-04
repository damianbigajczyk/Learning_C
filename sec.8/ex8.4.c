#include <stdio.h>
#include <ctype.h>
#include <stdint.h>
#include <stdbool.h>

int main(int argc, char *argv[])
{
	char ch = '\0';
	uint32_t letter = 0;
	uint32_t words = 0;
	bool flag = false;

	while ((ch = getchar()) != EOF) {
		if (isalpha(ch)) {
			letter++;
			flag = true;
		} else {
			if (flag) {
				words++;
				flag = false;
			}
		}

	}		

	printf("Words = %u\tLetter = %u\n", words, letter);
	printf("The average of letter in one word is equal to %.2f\n", (float)letter/words);

	return 0;
}
