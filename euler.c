#include <stdio.h>
#include "mathlib.h"


static int count = 0;

double pi_euler(void) {

	FILE *out = fopen("euler.dat", "w");

	double sum = 0, potential_pi = 0;

	for (long k = 1; k < 10000000; k++) {
	
		sum += 1.0 / (k * k);
	
		potential_pi = sqrt_newton(6.0 * sum);
	
		if (k > 1000 && (k % 1000) == 0) {
			fprintf(out, "i: %ld e: %16.15lf\n", k, potential_pi);
			}
		if (k <= 1000) {
			fprintf(out, "i: %ld e: %16.15lf\n", k, potential_pi);
			}
	
		count++;
	
	}
	
	fclose(out);

	return sqrt_newton(6.0 * sum);

}


int  pi_euler_terms() {
	return count;
}
