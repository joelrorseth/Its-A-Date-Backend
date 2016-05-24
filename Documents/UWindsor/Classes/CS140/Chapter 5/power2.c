//
//  power2.c
//  
//
//  Created by Ryan Pearson on 1.5.13.
//
//

#include <stdio.h>

long int power(int a, int b);

int
main(void)
{
    int x, y = 0;
    
    printf("Please provide x to the power of y: ");
    scanf("%d%d", &x, &y);
    
    printf("The value of %d x to the power of %d y is: %ld\n", x, y, power(x, y));
    
    return 0;
}

long int
power(int a, int b)
{
    //int value = 0;
    if (b <= 0)
        return 1;
    else
        return ( a * power(a, b-1));
}