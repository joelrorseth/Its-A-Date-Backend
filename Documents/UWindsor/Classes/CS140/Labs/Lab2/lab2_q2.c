//
//  odd.c
//  
//
//  Created by Ryan Pearson on 1.5.13.
//
//

#include <stdio.h>

int
main(void)
{
    
    int a = 0;                  // declare variable for evaluation
    
    // prompt user for integer
    
    printf("Please enter an integer: ");
    scanf("%d", &a);
    
    // evaluate the number
    
    if ((a % 2) == 0)
        printf("%d is even!\n", a);
    else
        printf("%d is odd!\n", a);
    
    return 0;
}