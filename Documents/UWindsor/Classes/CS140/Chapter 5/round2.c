//
//  round2.c
//  
//
//  Created by Ryan Pearson on 1.5.13.
//
//

#include <stdio.h>
#include <math.h>

float tenths(float);
float hunds(float);

int
main(void)
{
    float x = 0;
    
    do {
        printf("Please enter floating point number: ");
        scanf("%f", &x);
        
        if (x != -1)
        {
        printf("Rounded to an int: %d\n", (int)x);
        printf("Rounded to tenths: %.1f\n", tenths(x));
        printf("Rounded to hundredths: %.2f\n", hunds(x));
        printf("Rounded to thousands: %.3f\n", x);
        }
        else
            continue;
            
    } while (x != -1);
    
    return 0;
}

float
tenths(float y)
{
    return floor(y * 10 + .5) / 10;
    
}

float
hunds(float y)
{
    return floor(y * 100 + .5) / 100;
    
}