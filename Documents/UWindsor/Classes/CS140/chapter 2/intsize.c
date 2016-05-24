//
//  intsize.c
//  
//
//  Created by Ryan Pearson on 1.5.13.
//
//

#include <stdio.h>

int
main(void)
{
    // declare ints
    int x, y, z;
    // get ints from user
    printf("Please provide 3 integers:");
    scanf( "%d%d%d", &x, &y, &z);
    // evaluate and return answers
    if ( x > y && x > z)
        printf(" %d is the largest integer,\n", x);
    if ( y > x && y > z)
        printf(" %d is the largest integer,\n", y);
    if ( z > y && x < z)
        printf(" %d is the largest integer,\n", z);
    if ( x < y && x < z)
        printf(" %d is the smallest integer.\n", x);
    if ( y < x && y < z)
        printf(" %d is the smallest integer.\n", y);
    if ( z < y && x > z)
        printf(" %d is the smallest integer.\n", z);
    return 0;
}