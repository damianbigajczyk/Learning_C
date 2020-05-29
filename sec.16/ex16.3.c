#include "dbg.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct polarCoordinates {
	float length;
	float angle;
};

struct cartesianCoordinates {
	float x;
	float y;
};

struct cartesianCoordinates *convert(const struct polarCoordinates *s);

int main(int argc, char **argv)
{
	check(argc > 2, "Usage: %s <length> <angle(degree)>", argv[0]);

	struct cartesianCoordinates *p_cc = NULL;
	struct polarCoordinates pc;

	pc.length = atof(argv[1]);
	pc.angle = atof(argv[2]);

	p_cc = convert(&pc);

	check(p_cc != NULL, "Function convert failed");

	printf("r = %.2f\nangle = %.2f degree\nx = %.2f\ny = %.2f\n",
			pc.length, pc.angle, p_cc->x, p_cc->y);
	free(p_cc);

	return 0;
error:
	if (p_cc)
		free(p_cc);
	return -1;
}

struct cartesianCoordinates *convert(const struct polarCoordinates *s)
{
	struct cartesianCoordinates *ps = malloc(sizeof(struct cartesianCoordinates));
	if (!ps)	
		return ps;
	ps->x = s->length * cos(s->angle);
	ps->y = s->length * sin(s->angle);
	return ps;
}
