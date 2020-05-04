#include <stdio.h>
#include <stdint.h>

#define hour 60

int main(int argc, char* argv[])
{
	uint32_t time = 0;
	uint16_t hours = 0;
	uint8_t minutes = 0;
	int i = 0;

	printf("Enter a time in minutes, please.\n");
	while (scanf("%d", &time) != 1) {
		puts("Wrong input, try again!");
		while(getchar() != '\n')
			continue;
	}

	i = time;

	while (i > 59)
	{
		i -= 60;
		hours++;
	}
	minutes = i;

	printf("time: %d min = %d h %d min\n", time, hours, minutes);

	return 0;
}
