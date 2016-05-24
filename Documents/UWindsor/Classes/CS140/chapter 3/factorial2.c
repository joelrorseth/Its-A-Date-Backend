//
//  factorial2.c
//  
//
//  Created by Ryan Pearson on 1.5.13.
//
//

#include <stdio.h>

int
main(void)
{
    float x = 0;          // user variable smaller than 19
    float num = 1;       // factorial
    long double holder = 1;     // in case needed
    float i = 1;          // holder
    
    // ask user for number
    printf("Please provide a number to estimate: ");
    scanf("%f", &x);
    
    while ( i <= x)
    {
        num *= i;
        i++;
        holder += (1 / num);
        
    }

    printf("%Lf\n", holder);
}