//
//  lab3_q1b.c
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
    int loop = 0;                   // check loop
    
    do
        
    {
        
    // prompt user for input and scan
    printf("Please enter an integer between 1 and 10: ");
    scanf("%d", &x);
        
    // validate answer and provide valid feedback
    if (x >= 1 && x <= 10)
    {
        printf("%s", "You have entered a valid entry, Goodbye!\n\n");
        loop = 1;
    }
    // provide invalid feedback
    else
        printf("%s", "You have entered an invalid entry!!!\n\n");
    }while (loop == 0);
    
    return 0;
}
