//
//  powerrec.c
//  
//
//  Created by Ryan Pearson on 1.5.13.
//
//

#include <stdio.h>

int power(int a, int b);

int
main(void)
{
    int x, y = 0;
    
    printf("Please provide x to the power of y: ");
    scanf("%d%d", &x, &y);
    
    printf("%d to the power of %d is: %d\n", x, y, power(x, y));
    
    return 0;
}

int
power(int a, int b)
{
    int total = 1;
    
    if (b >= 1)
        return a * (power(a, b-1));
    
    else
        return 1;
}