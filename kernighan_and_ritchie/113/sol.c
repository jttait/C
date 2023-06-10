/*
 * Exercise 1-13. Write a program to print a histogram of the lengths of words
 * in its input. It is easy to draw a histogram with the bars horizontal; a
 * vertical orientation is more challenging.
 */

#include <stdio.h>
#include <stdbool.h>

void print_histogram(int array[], int array_length);

int main()
{
   char c;
   int i;
   int current_word_length = 0;
   int word_lengths[10];
   bool inword = false;

   for (i = 0; i < 10; i++)
      word_lengths[i] = 0;

   while ((c = getchar()) != EOF) {
      if (c == ' ' && inword) {
         word_lengths[current_word_length]++;
         current_word_length = 0;
         inword = false;
      }
      else if (c != ' ' && c != '\n') {
         current_word_length++;
         inword = true;
      }
   }
   if (current_word_length != 0)
      word_lengths[current_word_length]++;

   print_histogram(word_lengths, 10);
   return 0;
}

void print_histogram(int array[], int array_length)
{
   int i, j;
   printf("\n");
   for (i = 1; i < array_length; i++) {
      printf("Words of length %d: ", i);
      for (j = 0; j < array[i]; j++) {
         printf("#");
      }
      printf("\n");
   }
}
