//
//  scubes.c
//  
//
//  Created by Ryan Pearson on 1.5.13.
//
//

#include <stdio.h>

int
main(void)
{
    //print values and do math on the line
    printf("number\tsquare\tcube\n");
    printf("%d\t%d\t%d\n", 0,0,0);
    printf("%d\t%d\t%d\n", 1,1,1);
    printf("%d\t%d\t%d\n", 2, 2 * 2, 2 * 2 * 2);
    printf("%d\t%d\t%d\n", 3, 3 * 3, 3 * 3 * 3);
    printf("%d\t%d\t%d\n", 4, 4 * 4, 4 * 4 * 4);
    printf("%d\t%d\t%d\n", 5, 5 * 5, 5 * 5 * 5);
    printf("%d\t%d\t%d\n", 6, 6 * 6, 6 * 6 * 6);
    printf("%d\t%d\t%d\n", 7, 7 * 7, 7 * 7 * 7);
    printf("%d\t%d\t%d\n", 8, 8 * 8, 8 * 8 * 8);
    printf("%d\t%d\t%d\n", 9, 9 * 9, 9 * 9 * 9);
    printf("%d\t%d\t%d\n", 10, 10 * 10, 10 * 10 * 10);
    // finito.
    printf("\n\n");
    //display another means of doing the above
    printf("number\tsquare\tcube\n");
    
    int i;
    for (i = 0; i <= 10; i++)
        printf("%d\t%d\t%d\n", i, i * i, i * i * i);
    return 0; // finito.
    
}