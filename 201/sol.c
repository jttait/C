/*
 * Exercise 2-1. Write a program to determine the ranges of char, short, int,
 * and long variables, both signed and unsigned, by printing appropriate values
 * from standard headers and by direct computation. Harder if you compute them:
 * determine the ranges of the various floating-point types.
 */

#include <stdio.h>
#include <limits.h>
#include <float.h>

char compute_char_max(void);

int main()
{
   printf("\n-------------------\n");
   printf("limits.h");
   printf("\n-------------------\n");
   printf("CHAR_MIN: %d\n", CHAR_MIN);
   printf("CHAR_MAX: %d\n", CHAR_MAX);
   printf("SHRT_MIN: %d\n", SHRT_MIN);
   printf("SHRT_MAX: %d\n", SHRT_MAX);
   printf("USHRT_MAX: %d\n", USHRT_MAX);
   printf("INT_MIN: %d\n", INT_MIN);
   printf("INT_MAX: %d\n", INT_MAX);
   printf("UINT_MAX: %u\n", UINT_MAX);
   printf("LONG_MIN: %ld\n", LONG_MIN);
   printf("LONG_MAX: %ld\n", LONG_MAX);
   printf("ULONG_MAX: %lu\n", ULONG_MAX);

   printf("\n-------------------\n");
   printf("float.h");
   printf("\n-------------------\n");
   printf("FLT_MIN: %f\n", FLT_MIN);
   printf("FLT_MAX: %f\n", FLT_MAX);
   printf("DBL_MIN: %f\n", DBL_MIN);
   printf("DBL_MAX: %f\n", DBL_MAX);
   printf("LDBL_MIN: %Lf\n", LDBL_MIN);
   printf("LDBL_MAX: %Lf\n", LDBL_MAX);

   printf("\n-------------------\n");
   printf("bit operations");
   printf("\n-------------------\n");
   printf("CHAR_MAX: %d\n", compute_char_max());

   return 0;
}

char compute_char_max(void)
{
   unsigned char c;
   c = ~(c & 0); /* set all bits to 1 */
   c >>= 1; /* fill MSB with 0 */
   return (char) c;
}
