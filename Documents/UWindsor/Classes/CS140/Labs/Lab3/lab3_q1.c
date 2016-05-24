//
//  lab3_q1.c
//  
//
//  Created by Ryan Pearson on 1.5.13.
//
//

#include <stdio.h>

int
main(void)
{
    int x = 0;                      // declare variable for evaluation
        
    // prompt user for input and scan
    printf("\nPlease enter an integer between 1 and 10: ");
    scanf("%d", &x);
        
    // validate answer and provide valid feedback
    if (x >= 1 && x <= 10)
        printf("%s", "You have entered a valid entry, Goodbye!\n\n");
    
    // provide invalid feedback
    else
        printf("%s", "You have entered an invalid entry!!!\n\n");
    
    
    return 0;
}
