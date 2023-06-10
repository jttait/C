int getline2(char s[], int lim);
void copy(char to[], char from[]);
int updateBrackets(char s[], char opening, char closing, int counter);
int updateQuotes(char s[], char quote, int counter);
int updateComments(char s[], int counter);

#define MAXLINE 1000
#define MAXLINES 100
