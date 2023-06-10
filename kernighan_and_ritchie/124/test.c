#include <assert.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "sol.h"

int main()
{
   char teststring[MAXLINE];
   int braces;
   int squareBrackets;
   int roundBrackets;
   int singleQuotes;
   int doubleQuotes;
   int comments;

   braces = 0;
   strcpy(teststring, "{ code }");
   braces = updateBrackets(teststring, '{', '}', braces);
   assert(braces == 0);

   squareBrackets = 0;
   strcpy(teststring, "[1,2,3]");
   squareBrackets = updateBrackets(teststring, '[', ']', squareBrackets);
   assert(squareBrackets == 0);

   roundBrackets = 0;
   strcpy(teststring, "int main()");
   roundBrackets = updateBrackets(teststring, '(', ')', roundBrackets);
   assert(roundBrackets == 0);

   singleQuotes = 0;
   strcpy(teststring, "' quoted '");
   singleQuotes = updateQuotes(teststring, '\'', singleQuotes);
   assert(singleQuotes == 2);

   doubleQuotes = 0;
   strcpy(teststring, "\" quoted \"");
   doubleQuotes = updateQuotes(teststring, '"', doubleQuotes);
   assert(doubleQuotes == 2);

   comments = 0;
   strcpy(teststring, "/* commented */");
   comments = updateComments(teststring, comments);
   assert(comments == 0);

   braces = squareBrackets = roundBrackets = singleQuotes = doubleQuotes = 0;
   comments = 0;
   strcpy(teststring, "int main() { /* all programs start with main */");
   braces = updateBrackets(teststring, '{', '}', braces);
   squareBrackets = updateBrackets(teststring, '[', ']', squareBrackets);
   roundBrackets = updateBrackets(teststring, '(', ')', roundBrackets);
   singleQuotes = updateQuotes(teststring, '\'', singleQuotes);
   doubleQuotes = updateQuotes(teststring, '"', doubleQuotes);
   comments = updateComments(teststring, comments);
   strcpy(teststring, "printf (\"hello, world\n\");");
   braces = updateBrackets(teststring, '{', '}', braces);
   squareBrackets = updateBrackets(teststring, '[', ']', squareBrackets);
   roundBrackets = updateBrackets(teststring, '(', ')', roundBrackets);
   singleQuotes = updateQuotes(teststring, '\'', singleQuotes);
   doubleQuotes = updateQuotes(teststring, '"', doubleQuotes);
   comments = updateComments(teststring, comments);
   strcpy(teststring, "return 0; }");
   braces = updateBrackets(teststring, '{', '}', braces);
   squareBrackets = updateBrackets(teststring, '[', ']', squareBrackets);
   roundBrackets = updateBrackets(teststring, '(', ')', roundBrackets);
   singleQuotes = updateQuotes(teststring, '\'', singleQuotes);
   doubleQuotes = updateQuotes(teststring, '"', doubleQuotes);
   comments = updateComments(teststring, comments);
   assert(braces == 0); 
   assert(squareBrackets == 0);
   assert(roundBrackets == 0);
   assert(singleQuotes % 2 == 0);
   assert(doubleQuotes % 2 == 0);
   assert(comments == 0);

   printf("All tests passed.\n");

   return 0;
}
