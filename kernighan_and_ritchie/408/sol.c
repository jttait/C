/*
 * Exercise 4-8. Suppose that there will never be more than one character of
 * pushback. Modify getch and ungetch accordingly.
 */

#include <stdbool.h>
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include "sol.h"

#define MAXOP 100

void rpn(void);
int getop(char []);
void push(double);
double pop(void);
void clear(void);
double peek(void);
int getch(void);
void ungetch(int c);
double atof2(char s[]);

void rpn(void)
{
   int type;
   double op2;
   double op3;
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
         case '%':
            op2 = pop();
            if (op2 != 0.0)
               push((int) pop() % (int) op2);
            else
               printf("error: zero divisor\n");
            break;
         case PEEK: /* print top element without popping */
            printf("\t%.8g\n", peek());
            break;
         case DUPLICATE: /* duplicate top element of stack */
            op2 = pop();
            push(op2);
            push(op2);
            break;
         case SWAP: /* swap top two elments */
            op2 = pop();
            op3 = pop();
            push(op2);
            push(op3);
            break;
         case CLEAR:
            clear();
            break;
         case SIN:
            push(sin(pop()));
            break;
         case POW:
            op2 = pop();
            push(pow(pop(), op2));
            break;
         case EXP:
            push(exp(pop()));
            break;
         case VARIABLE_PUSHED:
            printf("variable pushed to stack\n");
            break;
         case VARIABLE_SAVED:
            printf("variable saved\n");
            break;
         case LAST_PRINTED:
            printf("last printed pushed to stack\n");
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
double var[26];

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

void clear(void)
{
   sp = 0;
}

double peek(void)
{
   if (sp > 0)
      return val[sp-1];
   else {
      printf("error: stack empty\n");
      return 0.0;
   }
}

int getop(char s[])
{
   int i, c;

   while ((s[0] = c = getch()) == ' ' || c == '\t')
      ;
   s[1] = '\0';

   i = 0;
   if (!isdigit(c) && c != '.' && c != '-') {
      if (!islower(c)) {
         if (c == '\n')
            var[26] = peek();
         return c;
      }

      while (islower(s[++i] = c = getch()))
         ;
      s[i] = '\0';
      if (c != EOF)
         ungetch(c);

      if (strlen(s) == 1) {
         push(var[s[0] - 'a']);
         return VARIABLE_PUSHED;
      }
      else if (s[0]=='s' && s[1]=='a' && s[2]=='v' && s[3]=='e' && s[5]=='\0') {
         var[s[4]-'a'] = pop();
         return VARIABLE_SAVED;
      }
      else if (strcmp(s, "peek") == 0)
         return PEEK;
      else if (strcmp(s, "duplicate") == 0)
         return DUPLICATE;
      else if (strcmp(s, "swap") == 0)
         return SWAP;
      else if (strcmp(s, "clear") == 0)
         return CLEAR;
      else if (strcmp(s, "sin") == 0)
         return SIN;
      else if (strcmp(s, "exp") == 0)
         return EXP;
      else if (strcmp(s, "pow") == 0)
         return POW;
      else if (strcmp(s, "lastprinted") == 0) {
         push(var[26]);
         return LAST_PRINTED;
      }
   }

   i = 0;
   if (c == '-')
      s[++i] = c = getch();
      if (!isdigit(c)) {
         ungetch(c);
         return c;
      }
   if (isdigit(c))
      while (isdigit(s[++i] = c = getch()))
         ;
   if (c == '.')
      while (isdigit(s[++i] = c = getch()))
         ;
   s[i] = '\0';
   if (c != EOF)
      ungetch(c);
   return NUMBER;
}

/*#define BUFSIZE 100*/

char buffer = '\0';
/*int bufp = 0;*/

int getch(void)
{
   char temp;
   if (buffer == '\0')
      return getchar();
   else {
      temp = buffer;
      buffer = '\0';
      return temp;
   }
}

void ungetch(int c)
{
   buffer = c;
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
