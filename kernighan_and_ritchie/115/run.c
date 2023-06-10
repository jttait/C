/*
 * Exercise 1-15. Rewrite the temperature conversion program of Section 1.2 to
 * use a function for conversion.
 */

#include <stdio.h>
#include "sol.h"

int main()
{
   float fahr;

   fahr = LOWER;
   
   printf("\n-----------------------------------\n");
   printf("Fahrenheit-Celsius Conversion Table");
   printf("\n-----------------------------------\n");

   while (fahr <= UPPER) {
      printf("%3.0f %6.1f\n", fahr, ftoc(fahr));
      fahr = fahr + STEP;
   }
   printf("\n");
   return 0;
}
