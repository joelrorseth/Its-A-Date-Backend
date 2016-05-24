//
//  righttriangle.c
//  
//
//  Created by Ryan Pearson on 1.5.13.
//
//

#include <stdio.h>

int
main(void)
{
    // declare 3 variables for the sides of triangle
    
    int a = 0;
    int b = 0;
    int c = 0;
    
    // prompt user for the sides of the triangle?
    
    printf("Please provide 3 integers: ");
    scanf("%d%d%d", &a, &b, &c);
    
    // evaluate numbers
    
    a *= a;
    b *= b;
    c *= c;
    
    // evaluate results and check for right angle triangle
    if (a > b && a > c)
    {
        (a == (b + c)) ? printf("This is a right angle triangle!\n") : printf("This could not be a right angle triangle.\n");
    }
    else if (b > a && b > c)
    {
        (b == (a + c)) ? printf("This is a right angle triangle!\n") : printf("This could not be a right angle triangle.\n");
    }
    else if (c > b && a < c)
    {
        (c == (b + a)) ? printf("This is a right angle triangle!\n") : printf("This could not be a right angle triangle.\n");
    }
    else
        printf("This could not be a right angle triangle.\n");
    
    
    return 0;
}