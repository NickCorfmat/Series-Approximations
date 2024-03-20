#include <stdio.h>
#include "mathlib.h"

static int count = 0;

double e(void) {
	FILE *out = fopen("e.dat", "w");
	
	double eulers_num = 0, previous_factor = 1.0, k = 0;

	for (int i = 1; i < 18; i++) {

		if (k == 0) {
			eulers_num += 1;

		} else {
			eulers_num += ( (1.0 / k ) * ( 1.0 / previous_factor));
			previous_factor *= k;
		}
		
		fprintf(out, "i: %d e: %16.15lf\n", i, eulers_num);
		

		count++;
		k++;

	}
	
	fclose(out);

	return eulers_num;
}

int e_terms() {
	return count;
}
