# -*- Makefile -*-

clean:
	rm -rf *.o test run

sol.o: sol.c
	gcc -c sol.c -pedantic -ansi -Wall -Wextra -Wfloat-equal -O2 -lm

run: run.c sol.o
	gcc -o run run.c sol.o -pedantic -ansi -Wall -Wextra -Wfloat-equal -O2 -lm

test: test.c sol.o
	gcc -o test test.c sol.o -pedantic -ansi -Wall -Wextra -Wfloat-equal -O2 -lm
