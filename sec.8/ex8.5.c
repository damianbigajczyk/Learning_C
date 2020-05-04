#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
#include <ctype.h>

bool getAnswer(void)
{
	char ch = getchar();

	while (getchar() != '\n') {}
	while (ch != 't' && ch != 'n' && ch != 'T' && ch != 'N') {
		puts("Wrong input, enter 't' or 'n', please:");
		ch = getchar();
		while (getchar() != '\n') {}
	}

	ch = tolower(ch);
	return (ch == 't') ? 1 : 0;
}


int main(int argc, char *argv[])
{
	bool guessing = true;
	uint8_t shots = 0;
	uint8_t number = 50;
	uint8_t add = number / 2;
	
	puts("Choose a number from 1 to 100 and I will try guess it.");
	puts("Enter 't' if i guess or 'n' if I haven't.");
	
	while (guessing) {
		printf("Is it %hhu?\n", number);
		if (getAnswer()) {
			shots++;
			break;
		} else {
			shots++;
			printf("Is it larger than %hhu?\n", number);
			add = (add == 1) ? 1 : add/2;
			number += (getAnswer()) ? add : -add;
		}
	}

	printf("I knew it!!!\n%hhu is your number and I needed %hhu attempts to finally guess it\n", number, shots);
		
	return 0;
}
