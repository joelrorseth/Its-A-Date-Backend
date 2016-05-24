//
//  lab5_q1.c
//  
//
//  Created by Ryan Pearson on 1.5.13.
//
//

#include <stdio.h>

int Max(int a, int b);
/* Function to return largest integer
* input: 2 integers
* output: largest int
*/


int
main(void)
{
    int x, y = 0;
    
    printf("Please enter 2 integers: ");
    scanf("%d%d", &x, &y);
    
    printf("Max(%d, %d) has returned %d\n", x, y, Max(x, y));
    
    return 0;
}

int Max(int a, int b)
{
    if (a < b) 
        return b;
    else
        return a;
}