#include <stdio.h>
#include <stdint.h>

int main(int argc, char* argv[])
{
	uint16_t x = 0;
	uint16_t evenNumbers = 0;
	uint16_t avgEven = 0;
	uint16_t avgOdd = 0;
	uint16_t oddNumbers = 0;


	while (scanf("%hu", &x) == 1) {
		if(x == 0)
			break;
		if(x % 2 == 0) {
			evenNumbers++;
			avgEven += x;
		} else {
			oddNumbers++;
			avgOdd += x;
		}
	}
	evenNumbers = (evenNumbers == 0) ? 1 : evenNumbers;
        oddNumbers = (oddNumbers == 0) ? 1 : oddNumbers;	
	printf("Even numbers: %d average: %d\nOdd numbers: %d average: %d\n",\
			evenNumbers, avgEven/evenNumbers, oddNumbers, avgOdd/oddNumbers);

	return 0;
}

