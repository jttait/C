/*
 * Exercise 1-5. Modify the temperature conversion program to print the table
 * in reverse order, that is, from 300 degrees to 0.
 */

#include <stdio.h>

#define LOWER 0
#define UPPER 300
#define STEP 20

int main()
{
   float fahr, celsius;

   fahr = UPPER;
   
   printf("\n-----------------------------------\n");
   printf("Fahrenheit-Celsius Conversion Table");
   printf("\n-----------------------------------\n");

   while (fahr >= LOWER) {
      celsius = (5.0/9.0) * (fahr - 32.0);
      printf("%3.0f %6.1f\n", fahr, celsius);
      fahr = fahr - STEP;
   }

   printf("\n");
   return 0;
}
