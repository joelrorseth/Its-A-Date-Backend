//
//  factorial2c.c
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
    int exp = 1;
    int val = 1;
    int holder1;
    
    // ask user for number
    printf("Please provide a number to estimate: ");
    scanf("%f", &x);
    

    

    while ( i <= x)
    {
        val = i;
        exp = 1;
        holder1 = 1;
        while (exp <= i)
        {
            holder1 *= val;
            exp++;
        }
        num *= i;
        i++;
        holder += (holder1 / num);
    }
    
    printf("%Lf\n", holder);
}