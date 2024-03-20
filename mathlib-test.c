#include <stdio.h>
#include <math.h>
#include <unistd.h>
#include <stdlib.h>
#include "mathlib.h"

#define OPTIONS "pi:aebmrvnsh"

// BEGIN code from Darrell Long
int main(int argc, char **argv) {

	double pi = M_PI;
	double euler = exp(1.0);
	double e_approx = 0;
	double pi_approx = 0;
	double sqrt_approx = 0;
	double diff = 0;
	double actual_root = 0;
	int s = 0, e_case = 0, b = 0, m = 0, r = 0, v = 0, n = 0;
	int opt = 0;
	
	FILE *out;
	
	while ((opt = getopt(argc, argv, OPTIONS)) != -1) {
		switch (opt) {
		case 'p':
			printf("-p option.\n");
			break;
		case 'i':
			printf("-i option: %s is parameter.\n", optarg);
			break;

		// END code from Darrell Long
	
		case 'a':

			e_case = 1;
			b = 1;
			m = 1;
			r = 1;
			v = 1;
			n = 1;
			
			// case e
			e_approx = e();
                        diff = absolute(e_approx - euler);

                        printf("e() = %16.15lf", e_approx);
                        printf(" M_E = %16.15lf", euler);
                        printf(" diff = %16.15lf\n", diff);

			// case b
			pi_approx = pi_bbp();
                        diff = absolute(pi_approx - pi);

                        printf("pi_bbp() = %16.15lf", pi_approx);
                        printf(" M_PI = %16.15lf", pi);
                        printf(" diff = %16.15lf\n", diff);

			// case m
			pi_approx = pi_madhava();
                        diff = absolute(pi_approx - pi);

                        printf("pi_madhava() = %16.15lf", pi_approx);
                        printf(" M_PI = %16.15lf", pi);
                        printf(" diff = %16.15lf\n", diff);

			// case r
			pi_approx = pi_euler();
                        diff = absolute(pi_approx - pi);

                        printf("pi_euler() = %16.15lf", pi_approx);
                        printf(" M_PI = %16.15lf", pi);
                        printf(" diff = %16.15lf\n", diff);

			// case v
			pi_approx = pi_viete();
                        diff = absolute(pi_approx - pi);

                        printf("pi_viete() = %16.15lf", pi_approx);
                        printf(" M_PI = %16.15lf", pi);
                        printf(" diff = %16.15lf\n", diff);

			// case n
			
			for (double i = 0; i < 10; i+=0.1) {
                        sqrt_approx = sqrt_newton(i);
                        actual_root = sqrt(i);
                        diff = absolute(sqrt_approx - actual_root);

                        printf("i: %0.1lf", i);
                        printf(" sqrt_newton() = %16.15lf", sqrt_approx);
                        printf(" sqrt = %16.15lf", actual_root);
                        printf(" diff = %16.15lf\n", diff);

                        }
                        
                        // case h

			break;

		case 'e':
			
			e_case = 1;
			
			e_approx = e();
			diff = absolute(e_approx - euler);

                        printf("e() = %16.15lf", e_approx);
                        printf(" M_E = %16.15lf", euler);
                        printf(" diff = %16.15lf\n", diff);			
                        break;

		case 'b':
		
			b = 1;

			pi_approx = pi_bbp();
			diff = absolute(pi_approx - pi);

                        printf("pi_bbp() = %16.15lf", pi_approx);
                        printf(" M_PI = %16.15lf", pi);
                        printf(" diff = %16.15lf\n", diff);

                        break;

		case 'm':
			
			m = 1;
			
			pi_approx = pi_madhava();
			diff = absolute(pi_approx - pi);

                        printf("pi_madhava() = %16.15lf", pi_approx);
                        printf(" M_PI = %16.15lf", pi);
                        printf(" diff = %16.15lf\n", diff);

                        break;

		case 'r':
		
			r = 1;
		
			pi_approx = pi_euler();
			diff = absolute(pi_approx - pi);

                        printf("pi_euler() = %16.15lf", pi_approx);
                        printf(" M_PI = %16.15lf", pi);
                        printf(" diff = %16.15lf\n", diff);

                        break;

		case 'v':
		
			v = 1;

			pi_approx = pi_viete();
			diff = absolute(pi_approx - pi);

                        printf("pi_viete() = %16.15lf", pi_approx);
                        printf(" M_PI = %16.15lf", pi);
                        printf(" diff = %16.15lf\n", diff);

                        break;

		case 'n':
		
			out = fopen("newton.dat", "w");
			n = 1;

			for (double i = 0; i < 10; i+=0.1) {
			sqrt_approx = sqrt_newton(i);
			actual_root = sqrt(i);
			diff = absolute(sqrt_approx - actual_root);

			printf("i: %0.1lf", i);
			printf(" sqrt_newton() = %16.15lf", sqrt_approx);
                        printf(" sqrt = %16.15lf", actual_root);
                        printf(" diff = %16.15lf\n", diff);
                        
                        fprintf(out, "approx_sqrt: %16.15lf sqrt: %16.15lf\n", sqrt_approx, actual_root);

			}
			
			fclose(out);
			
                        break;

		case 's':
			s = 1;

			break;

		case 'h':
		
			printf("-a: runs all functions\n-e: runs e.c\n-b: runs bbp.c\n-m: runs madhava.c\n-r: runs euler.c\n-v: runs viete.c\n-n: runs newton.c\n-s: prints computed terms\n");
			break;
		}
		
		if (s == 1 && e_case == 1) {
			printf("e() terms: %d\n", e_terms());
		}
		
		if (s == 1 && b == 1) {
			printf("pi_bbp() terms: %d\n", pi_bbp_terms());
		}
		
		if (s == 1 && m == 1) {
			printf("pi_madhava() terms: %d\n", pi_madhava_terms());
		}
		
		if (s == 1 && r == 1) {
			printf("euler() terms: %d\n", pi_euler_terms());
		}
		
		if (s == 1 && v == 1) {
			printf("pi_viete() terms: %d\n", pi_viete_factors());
		}
		
		if (s == 1 && n == 1) {
			printf("sqrt_newton() terms: %d\n", sqrt_newton_iters());
		}
	}

	return 0;

}
