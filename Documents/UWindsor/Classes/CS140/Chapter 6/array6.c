//
//  array6.c
//  
//
//  Created by Ryan Pearson on 1.5.13.
//
//

#include <stdio.h>

void staticarray(void);
void automaticarray(void);

int
main(void)
{
    
    puts("\n\nFirst call to each function");
    staticarray();
    automaticarray();
    
    puts("\n\nSecond call to each function");
    staticarray();
    automaticarray();
    
    return 0;
    
}

void staticarray(void)
{
    static int array1[3]= {0};
    
    // print initial values
    for (size_t i = 0; i < 3; i++) {
        printf("Array1[%zu] = %d   ", i, array1[i]);
    }
    puts("");
    // modify values
    for (size_t i = 0; i < 3; i++) {
        printf("Array1 modified[%zu] = %d   ", i, array1[i] += 5);
    }
    puts("");
}

void automaticarray(void)
{
    int array2[3]= {1, 2, 3};
    size_t i = 0;
    
    for (i = 0; i < 3; i++) {
        printf("Array2[%zu] = %d   ", i, array2[i]);
    }
    puts("");
    for (i = 0; i < 3; i++) {
        printf("Array2 modified[%zu] = %d   ", i, array2[i] *= 2);
    }
    puts("\n\n");
}

