/*
 * Exercise 2-1. Write a program to determine the ranges of char, short, int,
 * and long variables, both signed and unsigned, by printing appropriate values
 * from standard headers and by direct computation. Harder if you compute them:
 * determine the ranges of the various floating-point types.
 */

#include <stdio.h>
#include <limits.h>
#include <float.h>

char compute_char_min(void);
char compute_char_max(void);
unsigned char compute_uchar_max(void);
short compute_shrt_min(void);
short compute_shrt_max(void);
unsigned short compute_ushrt_max(void);
int compute_int_min(void);
int compute_int_max(void);
unsigned int compute_uint_max(void);
long compute_long_min(void);
long compute_long_max(void);
unsigned long compute_ulong_max(void);

int main()
{
   printf("\n-------------------\n");
   printf("limits.h");
   printf("\n-------------------\n");
   printf("CHAR_MIN: %d\n", CHAR_MIN);
   printf("CHAR_MAX: %d\n", CHAR_MAX);
   printf("UCHAR_MAX: %d\n", UCHAR_MAX);
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
   printf("char min: %d\n", compute_char_min());
   printf("char max: %d\n", compute_char_max());
   printf("unsigned char: %d\n", compute_uchar_max());
   printf("short min: %d\n", compute_shrt_min());
   printf("short max: %d\n", compute_shrt_max());
   printf("unsigned short max: %d\n", compute_ushrt_max());
   printf("int min: %d\n", compute_int_min());
   printf("int max: %d\n", compute_int_max());
   printf("unsigned int max: %u\n", compute_uint_max());
   printf("long min: %ld\n", compute_long_min());
   printf("long max: %ld\n", compute_long_max());
   printf("unsigned long max: %lu\n", compute_ulong_max());

   return 0;
}

char compute_char_min(void)
{
   unsigned char c;
   size_t num_bytes = sizeof(unsigned char);
   int num_bits = num_bytes * 8;
   c = 1; /* all bits 0 except least significant bit */
   c <<= (num_bits - 1);
   return (char) c;
}

char compute_char_max(void)
{
   unsigned char c;
   c = ~(c & 0); /* set all bits to 1 */
   c >>= 1; /* fill MSB with 0 */
   return (char) c;
}

unsigned char compute_uchar_max(void)
{
   unsigned char c;
   c = ~(c & 0); /* set all bits to 1 */
   return c;
}

short compute_shrt_min(void)
{
   unsigned short i;
   size_t num_bytes = sizeof(unsigned short);
   int num_bits = num_bytes * 8;
   i = 1; /* all bits 0 except least significant bit */
   i <<= (num_bits - 1);
   return (short) i;
}

short compute_shrt_max(void)
{
   unsigned short i;
   i = ~(i & 0); /* set all bits to 1 */
   i >>= 1; /* fill most significant bit with 0 */
   return (short) i;
}

unsigned short compute_ushrt_max(void)
{
   unsigned short i;
   i = ~(i & 0); /* set all bits to 1 */
   return i;
}

int compute_int_min(void)
{
   unsigned int i;
   size_t num_bytes = sizeof(unsigned int);
   int num_bits = num_bytes * 8;
   i = 1; /* all bits 0 except least significant bit */
   i <<= (num_bits - 1);
   return (int) i;
}

int compute_int_max(void)
{
   unsigned int i;
   i = ~(i & 0); /* set all bits to 1 */
   i >>= 1; /* fill most significant bit with 0 */
   return (int) i;
}

unsigned int compute_uint_max(void)
{
   unsigned int i;
   i = ~(i & 0); /* set all bits to 1 */
   return i;
}

long compute_long_min(void)
{
   unsigned long i;
   size_t num_bytes = sizeof(unsigned long);
   int num_bits = num_bytes * 8;
   i = 1; /* all bits 0 except least significant bit */
   i <<= (num_bits - 1);
   return (long) i;
}

long compute_long_max(void)
{
   unsigned long i;
   i = ~(i & 0); /* set all bits to 1 */
   i >>= 1; /* fill most significant bit with 0 */
   return (long) i;
}

unsigned long compute_ulong_max(void)
{
   unsigned long i;
   i = ~(i & 0); /* set all bits to 1 */
   return i;
}
