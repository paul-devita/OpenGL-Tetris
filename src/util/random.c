#include "random.h"

void r_init() {
	srand(time(NULL));
}

int r_randomIntInRange(int lower, int upper) {
	int cieling = upper + lower;

	int result = rand() % cieling;

	result -= lower;

	return result;
}