CC = clang
Cflags = -Wall -Wpedantic -Werror -Wextra
LIBFLAGS = -lm

all = mathlib-test

mathlib-test: mathlib-test.o e.o bbp.o madhava.o euler.o viete.o newton.o
	$(CC) -o $@ $^ $(LIBFLAGS)
	
%.o: %.c
	$(CC) $(CFLAGS) -c $<
	
clean:
	rm -f mathlib-test *.o test_data.dat e_data.dat bbp_data.dat madhava_data.dat euler_data.dat viete_data.dat newton_data.dat euler.dat bbp.dat madhava.dat euler.dat viete.dat newton.dat e_graph.pdf bbp_graph.pdf madhava_graph.pdf euler_graph.pdf viete_graph.pdf newton_graph.pdf
	
format:
	clang-format -i -style=file *.o [ch]
