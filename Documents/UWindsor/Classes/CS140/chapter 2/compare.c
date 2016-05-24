//
//  compare.c
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
    int x, y;
    //ask for 2 integers from user and acquire
    printf("Provide two integers please:");
    scanf("%d%d", &x, &y);
    //perform checks and return answer to user
        if ( x == y)
            puts ("These numbers are equal.\n");
        if ( x > y)
            printf("%d is larger\n", x);
        if ( y > x)
            printf("%d is larger\n", y);
    return 0; // finito
    
}