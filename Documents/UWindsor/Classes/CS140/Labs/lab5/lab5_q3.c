//
//  lab5_q3.c
//  
//
//  Created by Ryan Pearson on 1.5.13.
//
//

#include <stdio.h>

int Sum(int n);                                 // function prototype

int
main(void)
{
    int x = 0;                              // initialize variable
    
    // prompt user for number
    printf("Please enter a positive integer n: ");
    
    // check for valid number, insist on right number
    do
    {
        scanf("%d", &x);
        if(x < 0)
            puts("I said positive! Please re-enter!");
    }while (x < 0);
    // print out the result and test it's valitity.
    printf("Sum(%d) = ", x);
    
    for(int y = x; y > 1; y--)
            printf("%d+", y);
    
    printf("1 = %d\n", Sum(x));
    
    return 0;
}


int
Sum(int n)
{
    // calculate sum using recursion.
    if (n == 1)
        return 1;
    else
        return n + (Sum (n-1));
}