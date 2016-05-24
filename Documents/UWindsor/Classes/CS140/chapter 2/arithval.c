//
//  arithval.c
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
    int x, y, z;
    //ask user for 3 integers
    printf("Enter 3 numbers please:");
    scanf("%d%d%d", &x, &y, &z);
    //do math and show results
    printf("Sum is: %d,\n", x + y + z);
    printf("Average is: %d,\n", (x + y + z)/3);
    printf("Product is: %d,\n", x * y * z);
    //do comparisons and show results
        if ( x < y && x < z)
            printf("Smallest is %d,\n", x);
        if ( y < x && y < z)
            printf("Smallest is %d,\n", y);
        if ( z < x && z < y)
            printf("Smallest is %d,\n", z);
        if ( x > y && x > z)
            printf("Largest is %d.\n", x);
        if ( y > x && y > z)
            printf("Largest is %d.\n", y);
        if ( z > x && z > y)
            printf("Largest is %d.\n", z);
    return 0; // finito.
    
}