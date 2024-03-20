#include <stdio.h>
#include "mathlib.h"

static int count = 0;

double pi_viete(void) {

	FILE *out = fopen("viete.dat", "w");

	double product = 1.0, previous_term = 0, current_term = 0, potential_pi = 0;

	for (int i = 1; i < 24; i++) {

		current_term = sqrt_newton(2 + previous_term);
		previous_term = current_term;
		product *= (current_term / 2);
		potential_pi = 2 / product;
		
		fprintf(out, "i: %d e: %16.15lf\n", i, potential_pi);

		count++;
	}
	
	fclose(out);

	return 2 / product;
}

int pi_viete_factors() {
	return count;
}
