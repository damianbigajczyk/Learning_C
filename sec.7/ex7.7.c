#include <stdio.h>
#include <stdint.h>

#define perHour 40
#define extra 1.5
#define first 0.15
#define second 0.2
#define third 0.25

int main(int argc, char* argv[])
{
	uint8_t hours = 0;
	uint16_t salary = 0;
	float tax = 0;

	if (argc != 2) {
		puts("Usage: ./ex7.7 <name>");
		goto error;
	}
	printf("Hi %s\nHow much hours have you worked?\n", argv[1]);
	scanf("%hhu", &hours);
	
	if (hours <= 40) {
		salary = hours * perHour;
		if(salary <= 1200) {
			tax = salary * first;
		} else if(salary  > 1200 && salary <= 1800) {
			tax = 1200 * first + (salary - 1200)*second;
		} else {
			tax = (1200 * first) + (600 * second) + ((salary - 1800) * third);
		}
	} else {
		salary = (40 * perHour) + ((hours - 40) * perHour * extra);
		if(salary <= 1800) {
			tax = 1200 * first + (salary - 1200)*second;
		} else {
			tax = (1200 * first) + (600 * second) + ((salary - 1800) * third);
		}
	}
	
	printf("1) Gross pay: %.2u$\n2) Take-Home pay: %.2f$\n3) Tax: %.2f$\n",
		       salary, salary - tax, tax);	

	return 0;

error: 
	return 1;
}
