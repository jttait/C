#include <string.h>
#include <assert.h>
#include "sol.h"

int main()
{
   char testline[MAXLINE];

   assert(spaces_to_next_tabstop(0, 8) == 8);
   assert(spaces_to_next_tabstop(1, 8) == 7);
   assert(spaces_to_next_tabstop(2, 8) == 6);
   assert(spaces_to_next_tabstop(3, 8) == 5);
   assert(spaces_to_next_tabstop(4, 8) == 4);
   assert(spaces_to_next_tabstop(5, 8) == 3);
   assert(spaces_to_next_tabstop(6, 8) == 2);
   assert(spaces_to_next_tabstop(7, 8) == 1);
   assert(spaces_to_next_tabstop(8, 8) == 8);
   assert(spaces_to_next_tabstop(9, 8) == 7);

   strcpy(testline, "hello world");
   entab(testline);
   assert(strcmp(testline, "hello world") == 0);

   strcpy(testline, "hello         world");
   entab(testline);
   assert(strcmp(testline, "hello\t      world") == 0);

   return 0;
}
