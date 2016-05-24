//
//  oddeven.c
//  
//
//  Created by Ryan Pearson on 1.5.13.
//
//

#include <stdio.h>

int
main(void)
{
    //declare variable
    int i;
    //ask for integer
    printf("Integer please:");
    scanf("%d", &i);
    //evaluate if odd or even and provide user the answer.
    if ( (i % 2) == 0)
        printf("You have provided an even number.\n");
    if ( (i % 2) != 0)
        printf("You have provided an odd number.\n");
    return 0;
}