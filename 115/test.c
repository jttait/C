/*
 * Exercise 1-15. Rewrite the temperature conversion program of Section 1.2 to
 * use a function for conversion.
 */

#include <stdio.h>
#include <assert.h>
#include <math.h>
#include "sol.h"

define TOLERANCE 0.01

void test_ftoc(float f, float c);

int main()
{
   test_ftoc(0, -17.78);
   test_ftoc(100, 37.78);
   test_ftoc(200, 93.33);
   test_ftoc(300, 148.89);
   return 0;
}

void test_ftoc(float f, float c)
{
   assert((ftoc(f) - c) < TOLERANCE);
}
