#include <stdbool.h>
#include <stdio.h>
#include "sol.h"

int main()
{
   char line[MAXLINE];
   int len;
   int braces = 0;
   int squareBrackets = 0;
   int roundBrackets = 0;
   int singleQuotes = 0;
   int doubleQuotes = 0;
   int comments = 0;

   while ((len = getline2(line, MAXLINE)) > 0) {
      braces = updateBrackets(line, '{', '}', braces);
      roundBrackets = updateBrackets(line, '(', ')', roundBrackets);
      squareBrackets = updateBrackets(line, '[', ']', squareBrackets);
      singleQuotes = updateQuotes(line, '\'', singleQuotes);
      doubleQuotes = updateQuotes(line, '"', doubleQuotes);
      comments = updateComments(line, comments);
   }

   if (braces != 0) { printf("Unbalanced braces!\n") ; }
   if (roundBrackets != 0) { printf("Unbalanced round brackets!\n"); }
   if (squareBrackets != 0) { printf("Unbalanced square brackets!\n"); }
   if (singleQuotes % 2 != 0) { printf("Unbalanced single quotes!\n"); }
   if (doubleQuotes % 2 != 0) { printf("Unbalanced double quotes!\n"); }
   if (comments != 0) { printf("Unbalanced comments!\n"); }

   return 0;
}
