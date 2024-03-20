#include <stdio.h>
#include "mathlib.h"

static int count = 0;

double pi_madhava(void) {

	FILE *out = fopen("madhava.dat", "w");

	double k = 0, pi_approx = 0, factor = 1.0;
	double sqrt_twelve = sqrt_newton(12.0);

	for (int i = 1; i < 28; i++) {
		pi_approx += sqrt_twelve*((1/factor)/((2*k)+1));
		factor *= -3;
		
		fprintf(out, "i: %d e: %16.15lf\n", i, pi_approx);

		k++;
		count++;
	}
	
	fclose(out);

	return pi_approx;
	
}

int pi_madhava_terms() {
	return count;
}
