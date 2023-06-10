#include <stdbool.h>
#include <stdio.h>
#include <time.h>
#include "sol.h"


int main()
{
   int nlines;
   char lines[MAXLINES][MAXLEN];
   char *lineptr[MAXLINES];

   printf("\nEnter lines to be sorted:\n");
   if ((nlines = readlines507(lineptr, MAXLINES, lines)) > 0) {
      qsort2(lineptr, 0, nlines-1);
      printf("\nSorted Lines:\n");
      writelines(lineptr, nlines);
      return 0;
   }
   else {
      printf("error: input too big to sort\n");
      return 1;
   }
}
