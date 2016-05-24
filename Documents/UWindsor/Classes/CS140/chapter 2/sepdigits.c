//
//  sepdigits.c
//  
//
//  Created by Ryan Pearson on 1.5.13.
//
//

#include <stdio.h>

int
main(void)
{
    // declare variable and ask user for that variable
    int x;
    printf("Give 5 digit integer:");
    scanf("%d", &x);
    // establish breaks within the integer.
    printf("%d   ", (x / 10000));
    x = x % 10000;
    printf("%d   ", (x / 1000));
    x %= 1000;
    printf("%d   ", (x / 100));
    x %= 100;
    printf("%d   ", (x / 10));
    x %= 10;
    printf("%d\n", x);
    return 0; //finito.
}