//
//  5.3examreview.c
//  
//
//  Created by Ryan Pearson on 1.5.13.
//
//

#include <stdio.h>
#include <math.h>

int
main(void)
{
    printf("sqrt( 900.0) is %.2f\n", sqrt(900));
    printf("sqrt( 9.) is %.2f\n", sqrt(9));
    
    printf("cbrt (27) is %.2f\n", cbrt(27));
    printf("cbrt (-8) is %.2f\n", cbrt(-8));
    
    printf("exp (1) is %f\n", exp(1));
    printf("exp (2) is %f\n", exp(2));
    
    printf("log of 2.718282 is %.2f\n", log(2.718282));
    printf("log of 7.389056 is %.2f\n", log(7.389056));
    
    printf("Log 10(1) is %.2f\n", log10(1));
    printf("Log 10(10) is %.2f\n", log10(10));
    printf("Log 10(100) is %.2f\n", log10(100));
    
    printf("absolute value 13.5 is %.2f\n", fabs(13.5));
    printf("absolute value 13.5 is %.2f\n", fabs(0));
    printf("absolute value 13.5 is %.2f\n", fabs(-13.5));
    
    printf("round up ceiling 9.2 is %.2f\n", ceil(9.2));
    printf("round up ceiling -9.8 is %.2f\n", ceil(-9.8));
    
    printf("round down floor 9.2 is %.2f\n", floor(9.2));
    printf("round down floor -9.8 is %.2f\n", floor(-9.8));
    
    printf("2 to the power of 7 is %.2f\n", pow(2, 7));
    
    return 0;
}