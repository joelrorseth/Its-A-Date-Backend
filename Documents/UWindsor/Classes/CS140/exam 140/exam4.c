//
//  exam4.c
//  
//
//  Created by Ryan Pearson on 1.5.13.
//
//

#include <stdio.h>
#define SIZE 10
//1 2 3 4 5
//2 3 4

// check if string is within another string.

int
main(void)
{
    int A[SIZE];
    int B[SIZE];
    int x, y, na, nb, hold = 0, counter = 0;
    
    for (x = 0; x < SIZE; x++) {
        A[x] = 0;
        B[x] = 0;
    }
    printf("Enter size of 1st array: ");
    scanf("%d", &na);
    for (x = 0; x < na; x++) {
        scanf("%d", &A[x]);
    }
    
    printf("Enter size of 2nd array: ");
    scanf("%d", &nb);
    for (x = 0; x < nb; x++) {
        scanf("%d", &B[x]);
    }
    
    for (x = 0; x < nb; x++) {
        for (y = 0; y < na; y++) {
            if (B[x] == A[y]) {
                if (y == 0) {
                    hold = y;
                    counter++;
                }
                else if (hold > y) {
                    printf("Invalid\n");
                    return 1;
                }
                else{
                    hold = y;
                    counter++;
                }
                    
            }
        }
    }
    if (counter == nb) {
        printf("Valid\n");
    }
    else
        printf("Invalid\n");
    
    return 0;
}