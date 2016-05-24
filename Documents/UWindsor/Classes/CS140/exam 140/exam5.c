//
//  exam5.c
//  
//
//  Created by Ryan Pearson on 1.5.13.
//
//

#include <stdio.h>
#include <string.h>
#define SIZE 20

int
main(void)
{
    char A[SIZE];
    int y, x = 0;
    
    printf("Please enter a string: ");
    scanf("%19s", A);
    
    y = strlen(A) -1;
    
    while (x < y) {
        if (A[x] != A[y]) {
            printf("Invalid\n");
            return 1;
        }
        x++;
        y--;
    }
    printf("Valid\n");
    
    return 0;
}