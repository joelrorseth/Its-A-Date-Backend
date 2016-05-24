//
//  round1.c
//  
//
//  Created by Ryan Pearson on 1.5.13.
//
//

#include <stdio.h>
#include <math.h>

float number (float);           // function prototype

int
main(void)
{
    float x = 0;        // declare int
    
    // repeat loop asking for floating point decimal
    do {
        
    printf("Please enter a floating point number: ");
    scanf("%f", &x);
        if (x != -1)
        {
            printf(" You provided %.2f, rounding to the nearest decimal will give you ", x);
            printf("%.2f.\n", number(x));       // use math function in a call
            puts("\"-1\" to exit!");               // eof to exit.
        }
    }while (x != -1);
    
    return 0;
}


// function to perform to the nearest.

float number(float y)
{
     return floor(y + .5);
}