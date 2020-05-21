#include <stdio.h>
#include "function.h"

V_FONT wf[] = {setType, setSize, setAlign, setBold, setItalic, setUnderline};

int main(int argc, char **argv)
{
	int index;
	struct setFont font = { 1, 12 , LEFT, OFF, OFF, OFF};

	index = menu(&font);
	while (index >= 0 && index <= 5) {
		wf[index](&font);
		index = menu(&font);
	}

	return 0;
}
