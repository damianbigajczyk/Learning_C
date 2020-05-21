#include <stdio.h>
#include "font.h"

int main(int argc, char **argv)
{
	unsigned long font = 0;
	int index;

	V_FONT wsk[] = {setType, setSize, setAlign, setBold, setItalic, setUnderline};

        font |= (F_CLEAR | S_CLEAR);	
	index = menu(&font);
	while (index >= 0 && index <= 5) {
		wsk[index](&font);
		index = menu(&font);
	}

	return 0;
}
