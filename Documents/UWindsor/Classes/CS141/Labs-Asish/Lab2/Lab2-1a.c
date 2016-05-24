//
//  Title: Lab2-1a.c
//  Date: July 13, 2013
//  Name: Ryan Pearson
//  ID: 103965059
//  Program: read 20 integers into an array of size 100 and return non duplicated values in order
//

#include <stdio.h>
#include "printarray.h"
#include "setArray.h"
#define SIZE 100
#define COUNT 20

int
main(void)
{
    int BA[SIZE], x, y;             // declare array and counter variable, and entry variable
    
    set1dArray(BA, SIZE);           // set all elements to zero
    
    // enter numbers and assign appropriate element to 1. perform check on user input
    for (y = 0; y < COUNT; y++) {
        do{
            printf("Please enter number %d between 0 and 99: ", y+1);
            scanf("%d", &x);
        }while (x < 0 || x > 99);
        // if element not set to one, then change to one
        if (BA[x] == 0)
            BA[x] = 1;
    }
    
    Print1dArrayE1(BA, SIZE, 0);            // print array from function
    return 0;
}