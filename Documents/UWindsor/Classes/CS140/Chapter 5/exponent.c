//
//  exponent.c
//  
//
//  Created by Ryan Pearson on 1.5.13.
//
//

#include <stdio.h>

int integerPower(int base, int exp);

int
main(void)
{
    int bs = 0;
    int xp = 0;
    
    do {
        printf("Please enter a base and positive non-zero exponent: ");
        scanf("%d%d", &bs, &xp);
    } while (xp < 1);
    
    printf("The base %d to the exponent %d is: %d\n\n", bs, xp, integerPower(bs, xp));
    return 0;
}


int
integerPower(int base, int exponent)
{
    int value = 1;
    for (int i = 1; i <= exponent; i++)
    {
        value *= base;
    }
    return value;
    
    
}