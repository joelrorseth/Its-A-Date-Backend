
/* PEARSON, Ryan
 *  ID: 103965059
 *  Lab Exercise #lab4_q3
 *  Date: Feb 12, 2013
 *  Purpose: get a number from user and print random values equivilant to number, use rand function to generate #'s
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>


int
main(void)
{
    int n = 0;                              // declare variable for use
    srand( time(NULL));                     // set seed for different random numbers
    
    
    // ask user for integer
    printf("Please enter an integer n between 1 and 10: ");
    scanf("%d", &n);
    
    // check if between 1 and 10
    
    if (n < 1 || n > 10)
        puts("Invalid input. Goodbye.");
    else
    {
        printf("%d random numbers between 1 and 49 are: ", n);
        for(int y = 1; y <= n; y++)
        {
            int random = rand() % 49 + 1;           // random values for an int
            printf("%d ", random);
        }
        
    }
    
    //new line...
    puts("");
    
    return 0;
}