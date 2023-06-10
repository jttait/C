/*
 * Exercise 1-17. Write a program to print all input lines that are longer than
 * 80 characters.
 */

#include <stdio.h>

#define MAXLINE 1000
#define MAXLINES 100
#define LENGTH 80

int getline2(char line[], int maxline);
void copy(char to[], char from[]);

int main()
{
   int i, len;
   int num_long_lines = 0;
   char line[MAXLINE];
   char long_lines[MAXLINES][MAXLINE];

   while ((len = getline2(line, MAXLINE)) > 0) {
      if (len > LENGTH) {
         copy(long_lines[num_long_lines], line);
         num_long_lines++;
      }
   }
   if (num_long_lines > 0) {
      printf("\nLong lines: \n");
      for (i = 0; i < num_long_lines; i++) {
         printf("%s", long_lines[i]);
      }
   }
   return 0;
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
