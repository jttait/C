#include <assert.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "sol.h"

int main()
{
   char teststring[MAXLINE];
   bool testbool;

   testbool = false;
   strcpy(teststring, "no comment");
   testbool = remove_line_comments(teststring, testbool);
   assert(strcmp(teststring, "no comment") == 0);

   testbool = false;
   strcpy(teststring, "this is a /*comment*/");
   testbool = remove_line_comments(teststring, testbool);
   assert(strcmp(teststring, "this is a ") == 0);

   testbool = true;
   strcpy(teststring, "comment*/ but this appears");
   testbool = remove_line_comments(teststring, testbool);
   assert(strcmp(teststring, " but this appears") == 0);

   testbool = false;
   strcpy(teststring, "multiline comment /*");
   testbool = remove_line_comments(teststring, testbool);
   assert(strcmp(teststring, "multiline comment ") == 0);
   assert(testbool == true);
   strcpy(teststring, "this does not show */");
   testbool = remove_line_comments(teststring, testbool);
   assert(testbool == false);
   assert(strcmp(teststring, "") == 0);

   return 0;
}
