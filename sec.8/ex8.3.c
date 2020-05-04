#include <stdio.h>
#include <ctype.h>
#include <stdint.h>

int main(int argc, char* argv[])
{
	uint16_t lowerLetters = 0;
	uint16_t upperLetters = 0;
	uint16_t others = 0;
	int ch = '\0';

	while ((ch = getchar()) != EOF) {
		if (isalpha(ch)) {
			if (isupper(ch)) {
				upperLetters++;
			} else {
				lowerLetters++;
			}
		} else {
			others++;
		}


	}
	printf("upperLetters: %hd, lowerLetters: %hd and others: %hd\n",\
			upperLetters, lowerLetters, others);

	return 0;
}
