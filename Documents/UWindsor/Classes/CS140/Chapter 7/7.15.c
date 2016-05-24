//
//  7.15.c
//  
//
//  Created by Ryan Pearson on 1.5.13.
//
//

#include <stdio.h>
#define SIZE 10

void bubblesort(int array[], const size_t size);

void bubblesort(int array[], const size_t size)
{
    void swap(int * element1Ptr, int * element2Ptr);
    unsigned int pass;
    size_t j;
    
    for (pass = 0; pass < size -1; pass++)
    {
        for (j = 0; j < size -1; j++) {
            if (array[j] > array[j+1]) {
                swap(&array[j], &array[j+1]);
            }
        }
    }
}

void swap(int * element1Ptr, int * element2Ptr)
{
    int hold = 0;
    hold = *element1Ptr;
    *element1Ptr = *element2Ptr;
    *element2Ptr = hold;
    
    return;
    
}

int
main(void)
{
    int a[SIZE] = {2, 6, 4, 8, 10, 12, 89, 68, 45, 37};
    
    size_t i;
    
    puts("Data items in original order:");
    
    for (i = 0; i < SIZE; i++) {
        printf("%4d", a[i]);
    }
    
    bubblesort(a, SIZE);
    
    puts("\nData items sorted:");
    
    for (i = 0; i < SIZE; i++) {
        printf("%4d", a[i]);
    }
    puts("");
    
}