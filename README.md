Nicolas Corfmat
ncorfmat
1890805
Assignment 2: A Little Slice pi

--------------------
DESCRIPTION

This program approximates the values of e, pi, and square roots using the user-defined functions e(), pi_bbp(), pi_madhava(), euler(), pi_viete(), and sqrt_newton(), and compares them to their counterparts found using math.h functions. These results are then printed and further represented by graphs.

BUILD

To build, run 'make' or 'make all' on the terminal command line within the assignment 2 directory. This creates'mathlib-test, e, bbp, madhava, euler, viete, newton' executable files which can then be run.

CLEAN

Running 'make clean' will remove the all the executable (.o) files, all the data files, and previously generated PDF graphs from the assignment 2 directory.

RUNNING

To run, type './mathlib-test' followed by any one of these arguments: -a, -e, -b, -m, -r, -v, -n, -s, -h). Running any single one of these arguments (except -s and -h), will print their approximated values, the math.h values, and their differences, and display them on the terminal. -a runs all the functions (except -s and -h). Any argument (except -s and -h) followed by -s will display a new line on the terminal denoting the number of iterations it took to yield the approximation. Typing -h will simply display a help message explaining the program's usage. Running './graphs.sh' in the command line will output six PDFs of the plots comparing the function's approximations.

---------------------
