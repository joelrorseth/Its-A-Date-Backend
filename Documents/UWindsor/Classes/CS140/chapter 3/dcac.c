//
//  dcac.c
//  
//
//  Created by Ryan Pearson on 1.5.13.
//
//

#include <stdio.h>

int
main(void)
{
    // declare variables
    float rad;// radius of circle
    float pi = 3.14159;// 3.14159 etc etc
    int counter = 0;
    
    // get rad from user
    printf("%s", "Please provide radius of circle: ");
    scanf("%f", &rad);
    
    // perform loop and provide answers
    while (counter <= 2)
    {
        if (counter == 0)
            printf("The diameter of your circle is: %.2f,\n", (rad * 2));
        if (counter == 1)
            printf("The circumference of your circle is: %.2f,\n", (pi * (rad * 2)));
        if (counter == 2)
            printf("The area of your circle is: %.2f.\n", (pi * (rad * rad)));
        counter++;
    }   
    
    return 0;
}