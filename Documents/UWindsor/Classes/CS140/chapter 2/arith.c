//
//  arith.c
//  
//
//  Created by Ryan Pearson on 1.5.13.
//
//

#include <stdio.h>

int
main(void)
{
    //declare variables
    int x, y;
    //prompt user for 2 ints
    printf("Provide two numbers:");
    scanf( "%d%d", &x, &y);
    //do math and return values
    printf("The sum of %d + %d is: %d,\n", x, y, x + y);
    printf("The product of %d x %d is: %d,\n", x, y, x * y);
    printf("The difference of %d - %d is: %d,\n", x, y, x - y);
    printf("The quotient of %d / %d is: %d,\n", x, y, x / y);
    printf("The modulus of %d and %d is: %d.\n", x, y, x % y);
    return 0; // finito
    
}