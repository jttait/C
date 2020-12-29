/*
 * Exercise 3-1. Our binary search makes two tests inside the loop, when one
 * would suffice (at the price of more tests outside). Write a version with only
 * one test inside the loop and measure the difference in runtime.
 */

#include <stdbool.h>
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <ctype.h>
#include "sol.h"

int binsearch1(int x, int v[], int n)
{
   int low, high, mid;

   low = 0;
   high = n - 1;

   while (low <= high) {
      mid = (low+high) / 2;
      if (x < v[mid])
         high = mid - 1;
      else if (x > v[mid])
         low = mid + 1;
      else
         return mid;
   }
   return -1;
}

int binsearch2(int x, int v[], int n)
{
   int low, high, mid;

   low = 0;
   high = n - 1;
   mid = (low+high)/2;

   while (low <= high) {
      mid = (low+high) / 2;
      if (x < v[mid])
         high = mid - 1;
      else /* x >= v[mid] */
         low = mid + 1;
   }
   if (v[low-1] == x)
      return low-1;
   return -1;
}

int getline2(char s[], int lim)
{
   int c, i;
   for (i = 0; i < lim - 1 && (c=getchar()) != EOF && c != '\n'; i++) {
      s[i] = c;
   }
   if (c == '\n') {
      s[i] = c;
      ++i;
   }
   s[i] = '\0';
   return i;
}

void copy(char to[], char from[])
{
   int i = 0;
   while ((to[i] = from[i]) != '\0') {
      ++i;
   }
}
