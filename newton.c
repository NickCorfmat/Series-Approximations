#include <stdio.h>
#include "mathlib.h"

static int count = 0;

double sqrt_newton(double x) {
	
	double z = 0.0, y = 1.0;

	// BEGIN code from Darrell Long

	while ( absolute(y - z) > EPSILON ) {
		z = y;
		y = 0.5 * (z + x / z);
		count++;
	}
	
	// END code from Darrell Long

	return y;
}

int sqrt_newton_iters(void) {
	return count;
}
