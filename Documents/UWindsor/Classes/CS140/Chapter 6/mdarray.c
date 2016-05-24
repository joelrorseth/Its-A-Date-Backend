//
//  mdarray.c
//  
//
//  Created by Ryan Pearson on 1.5.13.
//
//

#include <stdio.h>

void printArray(int a[][3]);

int
main(void)
{
    int array1[2][3]= { {1, 2, 3}, {4, 5, 6}};
    int array2[2][3]= { 1, 2, 3, 4, 5};
    int array3[2][3]= { {1, 2}, {4}};
    
    puts("Values in array1 by row are:");
    printArray(array1);
    
    puts("Values in array2 by row are:");
    printArray(array2);
    
    puts("Values in array3 by row are:");
    printArray(array3);
    
    return 0;
}

void printArray(int a[][3])
{
    for (int i = 0; i < 2; i++) {
        printf("Row %d->\t", i);
        for (int j = 0; j < 3; j++) {
            printf("%d\t", a[i][j]);
        }
        puts("");
    }
    
    
}