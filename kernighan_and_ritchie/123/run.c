#include <stdbool.h>
#include <stdio.h>
#include "sol.h"

int main()
{
   int i;
   int len;
   int linenumber;
   bool incomment;
   char line[MAXLINE];
   char output_lines[MAXLINES][MAXLINE];

   linenumber = 0;
   incomment = false;

   while ((len = getline2(line, MAXLINE)) > 0) {
      incomment = remove_line_comments(line, incomment);
      copy(output_lines[linenumber++], line);
   }

   for (i = 0; i < linenumber; i++) {
      printf("%s", output_lines[i]);
   }

   return 0;
}
