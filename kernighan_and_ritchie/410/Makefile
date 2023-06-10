# -*- Makefile -*-

clean:
	rm -rf *.o test run

run: run.c sol.o
	gcc -o run run.c sol.o -pedantic -ansi -Wall -Wextra -Wfloat-equal -O2 -lm

test: test.c sol.c
	gcc -o test test.c sol.c -pedantic -ansi -Wall -Wextra -Wfloat-equal -O2 -lm
