#include <stdio.h>
#include <string.h>
#include <stdint.h>

uint32_t powerTen(uint8_t n);
int toNumber(const char *str);

int main(int argc, char *argv[])
{
	printf("%d\n", toNumber("1024"));
	printf("%d\n", toNumber("9560"));
	printf("%d\n", toNumber("10c25"));
	printf("%d\n", toNumber("0"));

	return 0;
}

uint32_t powerTen(uint8_t n)
{
	uint32_t result = 1;

	if (n == 0)
		return 1;
	return result *= 10 * powerTen(--n);
}

int toNumber(const char *str)
{
	uint8_t n = strlen(str);
	uint32_t number = 0;	

	while (*str != '\0') {
		if (*str >= 48 && *str <= 57) {
			number += (*str - 48) * powerTen(--n);
			str++;
		} else {
			return 0;
		}
	}
	return number;
}
