#include <assert.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include <math.h>
#include "sol.h"


int main()
{
   int m;
   int d;

   month_day(1988, 60, &m, &d);
   assert(m == 2 && d == 29);

   assert(day_of_year(2000, 1, 1) == 1);

   printf("All tests passed.\n");

   return 0;
}
