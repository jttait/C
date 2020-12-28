/*
 * Exercise 1-14. Write a program to print a histogram of the frequencies of
 * different characters in its input.
 */

#include <stdio.h>
#include <ctype.h>

void print_histogram(int array[], int array_length);

#define NUM_CHAR 26

int main()
{
   char c;
   int i;
   int characters[NUM_CHAR];

   for (i = 0; i < NUM_CHAR; i++)
      characters[i] = 0;

   while ((c = getchar()) != EOF)
      if (isalpha(c))
         characters[tolower(c)-'a']++;

   print_histogram(characters, NUM_CHAR);
   return 0;
}

void print_histogram(int array[], int array_length)
{
   int i, j;
   printf("\n");
   for (i = 1; i < array_length; i++) {
      printf("Character %c: ", i+'a');
      for (j = 0; j < array[i]; j++) {
         printf("#");
      }
      printf("\n");
   }
}
