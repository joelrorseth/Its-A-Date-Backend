//
//  7.9.c
//  
//
//  Created by Ryan Pearson on 1.5.13.
//
//

#include <stdio.h>
#define SIZE 5

int
main(void)
{
    unsigned int values[SIZE];
    unsigned int *vPtr;
    //vPtr = values;
    vPtr = &values[0];
    
    for (int x = 0; x < SIZE; x++) {
        values[x] = (x + 1) * 2;
    }
    
    
    for (int x = 1; x <= SIZE; x++) {
        printf("%d array subscript\n", values[x]);
    }
    
    puts("");
    
    for (int x = 1; x <= SIZE; x++) {
        printf("%d pointer subscript\n", vPtr[x]);
    }
    
    puts("");
    
    for (int x = 1; x <= SIZE; x++) {
        printf("%d pointer offset\n", *(vPtr + x));
    }
    
    puts("");
    
    for (int x = 1; x <= SIZE; x++) {
        printf("%d pointer offset w/ array name\n", *(values + x));
    }
    puts("");
    
    printf("%d\n%d\n%d\n%d\n", values[4], *(values + 4), vPtr[4], *(vPtr + 4));
    
    // 1002506 for part i.
    // 1002502 which is 2.
    
    return 0;
}