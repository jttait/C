#include <stdbool.h>
#include <stdio.h>
#include <time.h>
#include "sol.h"

#define ARRAY_LENGTH 100000
#define NUM_RUNS 1000000
#define TARGET 62000

int main()
{
   clock_t t;
   int i;
   int v[ARRAY_LENGTH];

   for (i = 0; i < ARRAY_LENGTH; i++)
      v[i] = i * 2;

   t = clock();
   for (i = 0; i < NUM_RUNS; i++)
      binsearch1(TARGET,v,ARRAY_LENGTH);
   t = clock() - t;
   printf("Time for binsearch1: %ld\n", t);

   t = clock();
   for (i = 0; i < NUM_RUNS; i++)
      binsearch2(TARGET,v,ARRAY_LENGTH);
   t = clock() - t;
   printf("Time for binsearch2: %ld\n", t);

   return 0;
}
