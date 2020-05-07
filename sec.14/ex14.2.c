#include <stdio.h>
#include <stdint.h>
#include "function.h"

int main(int argc, char *argv[])
{
	char month[10];
	uint8_t day = 0;
	uint16_t year = 0;
	uint16_t days = 0;

	if (!(day = getDay()))
		return 0;
	if (!getMonth(month))
		return 0;
	if (!(year = getYear()))
		return 0;
	if (days = countDays(day, month, year))
		printf("%u days have passed since the beginning of the year\n", days);

	return 0;
}
