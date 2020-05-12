#include <stdio.h>
#include "function.h"

int main(int argc, char *argv[])
{
	struct student data[SIZE] = {
		{"William", "Acker"},
		{"Aveline", "Axton"},
		{"Harper", "Brandon"},
		{"Damian", "Bigajczyk"}
	};

	getGrade(&data[0]);
	countAvg(&data[0]);
	displayStudent(&data[0]);
	displayAvgAll(&data[0]);

	return 0;
}
