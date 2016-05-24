//
//  sum.c
//  
//
//  Created by Ryan Pearson on 1.5.13.
//
//

#include <stdio.h>

int
main(void)
{
    // declare variables
    unsigned int sum, x;
    x = 1;
    sum = 0;
    // perform while loop and calculations
    while ( x <= 10)
    {
        sum += x;
        x++;
    }
    printf("The sum is: %d\n", sum);
}