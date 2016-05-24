//
//  power.c
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
    unsigned int x, y;
    unsigned int i = 1;
    unsigned int power = 1;
    // request values for x and y from user
    printf("Please provide base x to the power of y:");
    scanf("%u%u", &x, &y);
    // perform loop to raise to the power of...
    while (i <= y)
    {
        power *= x;
        i++;
        printf("%u\n", power);// print result all along.
    }
    return 0; // finito.
}