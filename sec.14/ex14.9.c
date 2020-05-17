#include <stdio.h>
#include <stdlib.h>
#include "colossus_2.h"

extern struct seat P102[SEATS];
extern struct seat P311[SEATS];
extern struct seat P444[SEATS];
extern struct seat P519[SEATS];

int main(int argc, char **argv)
{
	int ans;
	size_t sizePlane = sizeof(struct seat);
	struct seat *fly[4] = {P102, P311, P444, P519}; 
	const char *plane[] = {"P102.dot", "P311.dot", "P444.dot", "P519.dot"};
	FILE *pf = NULL;

	V_SEAT wf[] = {nFreeSeat, listFreeSeat, alphaFreeSeat, bookSeat, delBook, confirm}; 

	ans = initMenu();
	while (ans >= 0 && ans <=3) {
		int counter = 0;
		int index;
		int i;

		if (!(pf = fopen(plane[ans], "r+b"))) {
			if (!(pf = fopen(plane[ans], "w+b"))) {
				fprintf(stderr, "Failed to open file: \"%s\"\n", plane[ans]);
				exit(EXIT_FAILURE);
			}
			for (i = 0; i < SEATS; i++)
				fwrite(fly[ans] + i, sizePlane, 1, pf);
			rewind(pf);
		}


		while (counter < SEATS && (fread(fly[ans] + counter, sizePlane, 1, pf) == 1)) {
		      if(!counter) {
			      printf("***************** Fly %s ******************\n", plane[ans]);
			      printf("\t%-6s\t%4s\t%6s\t%-15s\t%-15s\n", "ID", "Free", "Confirm", "Name", "Surname");
		      }
		      printf("\t%-6s\t%2d\t%6d\t%-15s\t%-15s\n", (fly[ans]+counter)->id,
				      (fly[ans]+counter)->clear, (fly[ans]+counter)->confirmed,
				      (fly[ans]+counter)->name, (fly[ans]+counter)->surname);
		      counter++;
		}
		rewind(pf);	

		index = menu();
		while (index >=0 && index <= 5) {
			wf[index](fly[ans]);
			index = menu();
		}
		for (i = 0; i < SEATS; i++)
			fwrite(fly[ans] + i, sizePlane, 1, pf);
		if (fclose(pf))
			fprintf(stderr, "Failed to close file: \"%s\"\n", plane[ans]);
		ans = initMenu();
	}
	return 0;
}
