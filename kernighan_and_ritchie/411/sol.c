/*
 * Exercise 4-3. Given the basic framework, it's straightforward to extend the
 * calculator. Add the modulus (%) operator and provisions for negative
 * numbers.
 */

#include <stdbool.h>
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include "sol.h"

#define MAXOP 100
#define NUMBER '0'

void rpn(void);
int getop(char []);
void push(double);
double pop(void);
int getch(void);
double atof2(char s[]);

void rpn(void)
{
   int type;
   double op2;
   char s[MAXOP];

   while ((type = getop(s)) != EOF) {
      switch(type) {
         case NUMBER:
            push(atof2(s));
            break;
         case '+':
            push(pop() + pop());
            break;
         case '*':
            push(pop() * pop());
            break;
         case '-':
            op2 = pop();
            push(pop() - op2);
            break;
         case '/':
            op2 = pop();
            if (op2 != 0.0)
               push(pop() / op2);
            else
               printf("error: zero divisor\n");
            break;
         case '\n':
            printf("\t%.8g\n", pop());
            break;
         default:
            printf("error: unknown command %s\n", s);
            break;
      }
   }
}

#define MAXVAL 100
int sp = 0;
double val[MAXVAL];

void push(double f)
{
   if (sp < MAXVAL)
      val[sp++] = f;
   else
      printf("error: stack full, can't push %g\n", f);
}

double pop(void)
{
   if (sp > 0)
      return val[--sp];
   else {
      printf("error: stack empty\n");
      return 0.0;
   }
}

int getop(char s[])
{
   int i, c;
   static char buffer = EOF;

   while ((s[0] = c = getch()) == ' ' || c == '\t')
      ;
   s[1] = '\0';
   if (!isdigit(c) && c != '.')
      return c;
   i = 0;
   if (isdigit(c))
      while (isdigit(s[++i] = c = getch()))
         ;
   if (c == '.')
      while (isdigit(s[++i] = c = getch()))
         ;
   s[i] = '\0';
   if (c != EOF)
      buffer = c;
   return NUMBER;
}

#define BUFSIZE 100

char buf[BUFSIZE];
int bufp = 0;

int getch(void)
{
   return (bufp > 0) ? buf[--bufp] : getchar();
}

double atof2(char s[])
{
   double val, power, result;
   int i, sign, exp, expSign;
   for (i = 0; isspace(s[i]); i++)
      ;
   sign = (s[i] == '-') ? -1 : 1;
   if (s[i] == '+' || s[i] == '-')
      i++;
   for (val = 0.0; isdigit(s[i]); i++)
      val = 10.0 * val + (s[i] - '0');
   if (s[i] == '.')
      i++;
   for (power = 1.0; isdigit(s[i]); i++) {
      val = 10.0 * val + (s[i] - '0');
      power *= 10.0;
   }
   
   if (s[i] == 'e' || s[i] == 'E')
      i++;
   expSign = (s[i] == '-') ? -1 : 1;
   if (s[i] == '+' || s[i] == '-')
      i++;
   for (exp = 0; isdigit(s[i]); i++) {
      exp = 10 * exp + (s[i] - '0');
   }

   result = sign * val / power;

   if (exp)
      result *= pow(10, expSign * exp);

   return result;
}

int getline2(char s[], int lim)
{
   int c, i; for (i = 0; i < lim - 1 && (c=getchar()) != EOF && c != '\n'; i++) {
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
