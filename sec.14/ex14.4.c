#include <stdio.h>
#include "function.h"

int main (int argc, char *argv[])
{
	const struct customer Person[] = {
        	{{6,5,0,9,2,3,0,1,1,5,9}, "William", "James", "Acker"},
        	{{9,5,3,4,7,5,0,1,2,0,3}, "Aveline", "", "Axton"},
       	 	{{7,8,2,0,3,1,2,5,9,4,8}, "Harper", "Evelyn", "Brandon"}
	};
	
	displayPerson(&Person[0]);
	putchar('\n');
	displayPerson_2(Person);

	return 0;
}
