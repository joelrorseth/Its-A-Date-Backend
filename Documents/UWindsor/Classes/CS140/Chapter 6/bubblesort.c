//
//  bubble sort.c
//  
//
//  Created by Ryan Pearson on 1.5.13.
//
//

#include <stdio.h>
#define SIZE 10

// function prototype
// bubble(int b[], int c);


int
main(void)
{
    int a[SIZE] = {10, 9, 24, 24, 25, 91, 8, 4, 42, 102};
    size_t i;
    int hold;
    
    // unsorted array
    printf("%s", "\nUnsorted array:\n");
    for (i = 0; i < SIZE; i++) {
        printf("Array[%zu] = %d\n", i, a[i]);
    }
    puts("");
    
    for (int pass = 1; pass < SIZE; pass++)
    {printf("\nPass %d", pass);
        for (int i = 0; i < SIZE -1; i++)
        {
            if (a[i] > a[i + 1])
            {
                hold = a[i];
                a[i] = a[i + 1];
                a[i + 1] = hold;
            }
        }
    }

    // sorted array
    printf("\nSorted Array:\n");
    for (i = 0; i < SIZE; i++)
        printf("Array[%zu] = %d\n", i, a[i]);
}