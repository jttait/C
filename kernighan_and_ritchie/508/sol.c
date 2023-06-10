/*
 * Exercise 5-8. There is no error checking in day_of_year or month_day. Remedy
 * this defect.
 */

#include <stdbool.h>
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include "sol.h"

bool is_valid_month(int m);
bool is_valid_day(int d);
bool is_valid_yearday(int yearday, int leap);

static char daytab[2][13] = {
   {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
   {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31} 
};

int day_of_year(int year, int month, int day)
{
   int i, leap;

   if (!is_valid_month(month)) {
      printf("error: month must be between 1 and 12!\n");
      return -1;
   }
   if (!is_valid_day(day)) {
      printf("error: day must be between 1 and 31!\n");
      return -1;
   }

   leap = (year%4 == 0 && year%100 != 0) || year%400 == 0;
   for (i = 1; i < month; i++)
      day += daytab[leap][i];
   return day;
}

int month_day(int year, int yearday, int *pmonth, int *pday)
{
   int i, leap;
   leap = (year%4 == 0 && year%100 != 0) || year%400 == 0;

   if (!is_valid_yearday(yearday, leap)) {
      printf("error: yearday must be between 1 and 365 or 366 in a leap year!\n");
      return -1;
   }

   for (i = 1; yearday > daytab[leap][i]; i++)
      yearday -= daytab[leap][i];
   *pmonth = i;
   *pday = yearday;
   return 0;
}

bool is_valid_month(int m)
{
   return (m >= 1 && m <= 12);
}

bool is_valid_day(int d)
{
   return (d >= 1 && d <= 31);
}

bool is_valid_yearday(int yearday, int leap)
{
   if (leap) {
      return (yearday >= 1 && yearday <= 366);
   }
   else {
      return (yearday >= 1 && yearday <= 365);
   }
}
