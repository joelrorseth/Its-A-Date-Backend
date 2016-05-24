//
//  Title: readLines
//  Date: July 22, 2013
//  Name: Ryan Pearson
//  ID: 103965059
//  Program: readline function provided for lab- template provided
//

#include <stdio.h>
#define MAXLEN 1000
int getlines(char *, int); // prototypes
char *alloc(int);
/* readlines: read input lines */
int readlines(char *lineptr[], int maxlines)
{
    int len, nlines;
    char *p, line[MAXLEN];
    nlines = 0;
    while((len = getlines(line, MAXLEN)) > 0)
        if (nlines >= maxlines || (p = alloc(len)) == NULL)
            return -1;
        else {
            line[len-1] = '\0'; /*delete newline symbol*/
            strcpy(p, line);
            lineptr[nlines++] = p;
        }
    return nlines;
}