#include <stdbool.h>
#include <stdio.h>
#include <time.h>
#include "sol.h"

int main()
{
   int n;
   int *pn;
   int r;

   pn = &n;

   r = getint(pn);

   printf("n: %d\n", n);
   printf("r: %d\n", r);

   return 0;
}
