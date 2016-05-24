//
//  lab2_q3.c
//  
//
//  Created by Ryan Pearson on 1.5.13.
//
//

#include <stdio.h>


int
main(void)
{
    int a = 0;                  // declare integer number 1
    int b = 0;                  // declare second integer
    
    // prompt user for integers
    printf("Please enter two integers: ");
    scanf("%d%d", &a, &b);
    
    // evaluate if a is a multiple of b
    if ((a % b) == 0)
        printf("%d is a multiple of %d\n", a, b);
    else
        printf("%d is not a multiple of %d\n", a, b);
    
    return 0;
}