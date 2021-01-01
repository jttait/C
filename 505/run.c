#include <stdbool.h>
#include <stdio.h>
#include <time.h>
#include "sol.h"

int main()
{
   double n;
   double *pn;
   int r;

   pn = &n;

   r = getfloat(pn);

   printf("n: %f\n", n);
   printf("r: %d\n", r);

   return 0;
}
