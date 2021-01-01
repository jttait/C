/*
 * Exercise 5-9. Rewrite the routines day_of_year and month_day with pointers
 * instead of indexing.
 */

#include <stdbool.h>
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include "sol.h"

static char daytab[2][13] = {
   {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
   {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31} 
};

int day_of_year(int year, int month, int day)
{
   int i;
   char *p = &daytab[0][0];

   if ((year%4 == 0 && year%100 != 0) || year%400 == 0) {
      p += 13;
   }
   p += 1;
   for (i = 1; i < month; i++) {
      day += *p;
      p++;
   }
   return day;
}

int month_day(int year, int yearday, int *pmonth, int *pday)
{
   char *p = &daytab[0][0];
   *pday = yearday;

   if ((year%4 == 0 && year%100 != 0) || year%400 == 0)
      p += 13;

   for (*pmonth = 1; *pday > *(p + *pmonth); (*pmonth)++) {
      *pday -= *(p + *pmonth);
   }

   return 0;
}
