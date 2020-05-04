#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>

int main(int argc, char *argv[])
{
	uint8_t ammount = 0;
	char ch = '\0';
	bool flag = false;

	while ((ch = getchar()) != '#') {
		switch(ch) {
			case 'o':
				flag = true;
				break;
			case 't':
				if(flag) {
					ammount++;
					flag = false;
				}
				break;
			default:
				flag = false;
		}
	}
	printf("The \"ot\" showed %u times\n", ammount);
	puts("The end");

	return 0;
}
