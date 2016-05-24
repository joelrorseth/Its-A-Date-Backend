//
//  multiples.c
//  
//
//  Created by Ryan Pearson on 1.5.13.
//
//

#include <stdio.h>

int
main(void)
{
    // declare variables
    int x, y;
    // ask user for 2 integers
    printf("Provide 2 integers please:");
    scanf( "%d%d", &x, &y);
    // verify if item is multiple and provide feedback
    if ( (y % x) == 0)
        printf("%d is a multiple of %d.\n", x, y);
    if ( (y % x) != 0)
        printf("%d is not a multiple of %d.\n)", x, y);
    return 0; // finito
}