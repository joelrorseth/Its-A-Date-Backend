//
//  math.c
//  
//
//  Created by Ryan Pearson on 1.5.13.
//
//

#include <stdio.h>
#include <math.h>

void instruct(void);

int
main(void)
{
    // declare x
    int x = 1;
    
    instruct();
    
    // demonstrate the square root function
    printf("Square root of 900 is %.1lf\n", sqrt(x * 900) );
    printf("Square root of 9 is %.1lf\n\n", sqrt(9.0));
    
    // demonstrate cube root
    printf("Cube root of 27 is %.1lf\n", cbrt(27));
    printf("Cube root of -8 is %.1lf\n\n", cbrt(-8));
    
    // demonstrate exponential function
    printf("exponential function e to the 1 is %lf\n", exp(1));
    printf("exponential function x to the 2 is %lf\n\n", exp(2));
    
    // demonstrate natural log of x(base e)
    printf("natural log of base e is %.1lf\n", log (2.718282));
    printf("natural log of base e is %.1lf\n\n", log (7.389056));
    
    // demonstrate natural log of x(base 10)
    printf("natural log of base 10 is %.1lf\n", log10(1.0));
    printf("natural log of base 10 is %.1lf\n", log10(10.0));
    printf("natural log of base 10 is %.1lf\n\n", log10(100.0));
    printf("natural log of base 2 is %.1lf\n\n", log2 (16));
    
    // absolute value
    
    printf("absolute value of 13.5 is %.1lf\n", fabs(13.5));
    printf("absolute value of 0.0 is %.1lf\n", fabs(0.0));
    printf("absolute value of -13.5 is %.1lf\n\n", fabs(-13.5));
    
    // ceiling an int
    printf("ceiling rounding 9.2 is %.1lf\n", ceil (9.2));
    printf("ceiling rounding -9.8 is %.1lf\n\n", ceil (-9.8));
    
    // floor rounding
    printf("floor rounding 9.2 is %.1lf\n", floor(9.2));
    printf("floor rounding -9.2 is %.1lf\n\n", floor(-9.2));
    
    // pow function
    printf("2 raised to power 7 is %.1lf\n", pow(2, 7));
    printf("9 raised to power of .5 is %.1lf\n\n", pow(9, .5));
    
    // remainder of x/y
    printf("remainder 5/2 is %.4lf\n\n", fmod(5, 2));
    
    // sohcahtoa
    
    printf("sin of 0 is %.1lf\n", sin(0));
    printf("cos of 0 is %.1lf\n", cos(0));
    printf("tan of 0 is %.1lf\n", tan(0));
    
    printf("Thank god this question is done.\n\n");
    instruct ();
    
    return 0;
}

void
instruct (void)
{
    
    puts("\n\nThis is to test a function in the file");
    puts("Calling function...\n");
    puts("Hi! Now go back to your program...\n\n");
    return;
}