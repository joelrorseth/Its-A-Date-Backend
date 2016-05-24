//
//  circle.c
//  
//
//  Created by Ryan Pearson on 1.5.13.
//
//

#include <stdio.h>

int
main(void)
{
    //declare variables
    float rad, pi = 3.14159;
    // ask user for rad
    printf("Please provide radius for your circle:");
    scanf( "%f", &rad);
    // perform calculations and return values
    printf("The diameter would be: %.3f,\n", rad *2);
    printf("The circumference would be: %.3f,\n", pi * (rad * 2));
    printf("The area would be: %.3f.\n", pi * rad * rad);
    return 0; //finito.
    
}