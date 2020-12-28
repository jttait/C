/*
 * Exercise 1-15. Rewrite the temperature conversion program of Section 1.2 to
 * use a function for conversion.
 */

#include <stdio.h>
#include "sol.h"

float ftoc(float fahrenheit)
{
   return (5.0/9.0) * (fahrenheit - 32.0);
}
