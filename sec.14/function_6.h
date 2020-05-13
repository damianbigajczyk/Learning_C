#ifndef function_6_H_
#define function_6_H_

#define NAME 20

struct basketball {
	char name[NAME];
	char surname[NAME];
	__uint8_t throw_2;
	__uint8_t hit;
	__uint8_t assist;
	__uint8_t faul;
	float rate;
};

int getData(struct basketball *player);
void countEfficacity(struct basketball *player);
void showPlayer(const struct basketball *player);

#endif
