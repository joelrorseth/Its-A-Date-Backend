//
//  Title: Lab4a.c
//  Date: July 28, 2013
//  Name: Ryan Pearson
//  ID: 103965059
//  Program: 
//

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "stringdex.h"


int
main(void)
{
    char *a = "this this";
    char *b = "athis";
    //char a[20];
    //char b[20];
    int pass= 0;
    
    // this is not working!!! ARGH
    FILE * fptr;
    if ((fptr = fopen("test.txt", "r")) == NULL)
        puts("no file to read.");
    else{
        while (!feof (fptr)) {
            if (pass++ == 0)
                fgets(a, 20, fptr);
            else
                fgets(b, 20, fptr );
        }
    }
    printf("%s\n%s\n", a, b);
    // for question 1 part a
    strindex(a, b) >= 0 ? printf("Last occurance of string b in string a is at index %d\n", strindex(a, b)) : printf("No match!\n");
    
    // for question 1 part b
    strend(a, b) >= 0 ? printf("And it is the last word in the string.\n"): printf("But it is not the last word in the string.\n");
    
    return 0;
}