#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "sol.h"

#define MAXLINES 5000

int main(int argc, char **argv)
{
   int nlines;
   char *lineptr[MAXLINES];
   int n = 10;

   if (argc == 2) {
      n = atoi(argv[1]);
   }

   if ((nlines = readlines(lineptr, MAXLINES)) > 0) {
      printf("The last %d lines of input are\n", n);
      tail(lineptr, n, nlines);
      return 0;
   }
   else {
      printf("input too big\n");
      return 1;
   }
}
