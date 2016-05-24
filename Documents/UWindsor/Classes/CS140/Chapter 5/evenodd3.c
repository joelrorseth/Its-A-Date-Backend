//
//  evenodd3.c
//  
//
//  Created by Ryan Pearson on 1.5.13.
//
//

#include <stdio.h>

int even (int test);

int
main(void)
{
    int x;                  // declare variable for testing
    
    
    do
    {
        printf("Please enter an integer to test if it is even or odd: ");
        scanf("%d", &x);
        
        even(x);
        
        if (even(x) == 1)
            printf("Your integer is odd!\n");
        else if (x == -1)
            continue;
        else
            printf("Your integer is even!\n");
    } while (x != -1);
    
    return 0;
}

int
even(int test)
{
    return test % 2;
    
}