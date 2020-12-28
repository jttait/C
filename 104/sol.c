/*
 * Exercise 1-4. Write a program to print the corresponding Celsius to
 * Fahrenheit table.
 */

#include <stdio.h>

#define LOWER 0
#define UPPER 300
#define STEP 20

int main()
{
   float fahr, celsius;

   celsius = LOWER;
   
   printf("\n-----------------------------------\n");
   printf("Celsius-Fahrenheit Conversion Table");
   printf("\n-----------------------------------\n");

   while (celsius <= UPPER) {
      fahr = ((9.0/5.0) * celsius) + 32.0;
      printf("%3.0f %6.1f\n", celsius, fahr);
      celsius = celsius + STEP;
   }
   printf("\n");
   return 0;
}
