/*
 * Exercise 4-10. An alternative organisation uses getline to read an entire
 * input line; this makes getch and ungetch unnecessary. Revise the calculator
 * to use this approach.
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
void push(double);
double pop(void);
void clear(void);
double peek(void);
double atof2(char s[]);
int handle_word(char s[]);
void swap(void);
void duplicate(void);
void multiply(void);
void add(void);
void subtract(void);
void modulus(void);
void sine(void);
void exponential(void);
void power(void);

void rpn(void)
{
   int i, j;
   int type;
   double op2;
   double op3;
   char s[MAXLINE];
   char t[MAXLINE];

   while (true) {
      getline2(s, MAXLINE);
      i = 0;
      while (s[i] != '\0') {
         /* skip leading whitespace */
         while (s[i] == ' ' || s[i] == '\t')
            i++;

         /* get next word */
         j = 0;
         while (s[i] != ' ' && s[i] != '\t' && s[i] != '\n' && s[i] != '\0') {
            t[j++] = s[i++];
         }
         t[j] = '\0';

         handle_word(t);

         if (s[i] == '\n') {
            handle_word("\n");
            i++;
         }
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

void multiply(void)
{
   push(pop() * pop());
}

void divide(void)
{
   float temp = pop();
   if (temp != 0.0)
      push(pop() / temp);
   else
      printf("error: zero divisor\n");
}

void add(void)
{
   push(pop() + pop());
}

void subtract(void)
{
   float temp = pop();
   push(pop() - temp);
}

void modulus(void)
{
   float temp = pop();
   if (temp != 0.0)
      push((int) pop() % (int) temp);
   else
      printf("error: zero divisor\n");
}

void sine(void)
{
   push(sin(pop()));
}

void exponential(void)
{
   push(exp(pop()));
}

void power(void)
{
   float temp = pop();
   push(pow(pop(), temp));
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

void swap(void)
{
   float temp1 = pop();
   float temp2 = pop();
   push(temp1);
   push(temp2);
}

void duplicate(void)
{
   float temp = pop();
   push(temp);
   push(temp);
}

int handle_word(char s[])
{
   int i = 0;
   float op2;

   if (s[0] == '*')
      multiply();
   else if (s[0] == '/')
      divide();
   else if (s[0] == '+' && !isdigit(s[1]))
      add();
   else if (s[0] == '-' && !isdigit(s[1]))
      subtract();
   else if (s[0] == '%')
      modulus();
   else if (strcmp(s, "sin") == 0)
      sine();
   else if (strcmp(s, "exp") == 0)
      exponential();
   else if (strcmp(s, "pow") == 0)
      power();
   else if (isdigit(s[0]))
      push(atof2(s));
   else if (strcmp(s, "peek") == 0)
      printf("\t%.8g\n", peek());
   else if (strcmp(s, "duplicate") == 0)
      duplicate();
   else if (strcmp(s, "swap") == 0)
      swap();
   else if (strcmp(s, "clear") == 0)
      clear();
   else if (strcmp(s, "lastprinted") == 0)
      push(var[26]);
   else if (s[0]=='s' && s[1]=='a' && s[2]=='v' && s[3]=='e' && s[5]=='\0')
      var[s[4]-'a'] = pop();
   else if (strlen(s) == 1 && islower(s[0]))
      push(var[s[0] - 'a']);
   else if (s[0] == '\n') {
      op2 = pop();
      var[26] = op2;
      printf("\t%.8g\n", op2);
   }
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
