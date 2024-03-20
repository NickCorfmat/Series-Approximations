#include <stdio.h>
#include "mathlib.h"

static int count = 0;

double pi_bbp(void) {

	FILE *out = fopen("bbp.dat", "w");

	double  k = 0, pi_approx = 0, factor = 1.0;

	for (int i = 1; i < 11; i++) {
		
		pi_approx += (1/factor)*((k*(120*k+151)+47)/(k*(k*(k*(512*k+1024)+712)+194)+15));
		factor *= 16;

		fprintf(out, "i: %d pi: %16.15lf\n", i, pi_approx);
		k++;
		count++;
	}

	fclose(out);

	return pi_approx;
}

int pi_bbp_terms() {
	return count;
}
