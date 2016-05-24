//
//  multiple.c
//  
//
//  Created by Ryan Pearson on 1.5.13.
//
//

#include <stdio.h>

int multiple (int a, int b);

int
main(void)
{
    int c = 0;
    int d = 0;
    
    printf("Please enter 2 integers for multiple checking: ");
    scanf("%d%d", &c, &d);
    
    if (multiple(c, d) == 1)
        printf("%d is a multiple of %d!\n", c, d);
    else
        printf("%d is not a multiple of %d!\n", c, d);
    
    return 0;
}

int
multiple(int a, int b)
{
    int test = b % a;
    if (test == 0)
        return 1;
    else
        return 0;
    
}