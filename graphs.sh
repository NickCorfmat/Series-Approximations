#! /bin/bash

make clean && make mathlib-test # Rebuild the mathlib-test executable

./mathlib-test -e
awk '{print $2 " " $4}' e.dat > e_data.dat
rm e.dat

gnuplot << END
set terminal pdf
set output "e_graph.pdf"
set xlabel "iteration"
set ylabel "e"
set title "Taylor Series Approximation"
set zeroaxis
set xrange[1:17]
set yrange[0:3]
plot "e_data.dat" with lines lc "blue"
END

./mathlib-test -b
awk '{print $2 " " $4}' bbp.dat > bbp_data.dat
rm bbp.dat

gnuplot << END
set terminal pdf
set output "bbp_graph.pdf"
set xlabel "iteration"
set ylabel "pi"
set title "Bailey-Borwein-Plouffe Approximation"
set zeroaxis
set xrange[1:10]
set yrange[3.1:3.2]
plot "bbp_data.dat" with linespoints lc "red"
END

./mathlib-test -m
awk '{print $2 " " $4}' madhava.dat > madhava_data.dat
rm madhava.dat

gnuplot << END
set terminal pdf
set output "madhava_graph.pdf"
set xlabel "iteration"
set ylabel "pi"
set title "Madhava Series Approximation"
set zeroaxis
set xrange[1:27]
set yrange[3:3.5]
plot "madhava_data.dat" with lines lc "orange"
END

./mathlib-test -r
awk '{print $2 " " $4}' euler.dat > euler_data.dat
rm euler.dat

gnuplot << END
set terminal pdf
set output "euler_graph.pdf"
set xlabel "iteration"
set ylabel "pi"
set title "Euler's Solution Approximation"
set zeroaxis
set yrange[2.4:3.4]
set xrange[1:10000000]
set logscale x 10
plot "euler_data.dat" with lines lc "green"
END

./mathlib-test -v
awk '{print $2 " " $4}' viete.dat > viete_data.dat
rm viete.dat

gnuplot << END
set terminal pdf
set output "viete_graph.pdf"
set xlabel "iteration"
set ylabel "pi"
set title "Viete's Formula Approximation"
set zeroaxis
set xrange[1:23]
set yrange[2.8:3.2]
plot "viete_data.dat" with lines lc "purple"
END


./mathlib-test -n
awk '{print $2 " " $4}' newton.dat > newton_data.dat
rm newton.dat

gnuplot << END
set terminal pdf
set output "newton_graph.pdf"
set xlabel "math.h sqrt"
set ylabel "newton sqrt"
set title "Newton's Method Square Root Approximation"
set zeroaxis
set xrange[0:3]
set yrange[0:3]
plot "newton_data.dat" title "" lc rgb "navy" pt 7 ps 0.3
END
