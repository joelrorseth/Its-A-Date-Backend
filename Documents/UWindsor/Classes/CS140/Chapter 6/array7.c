//
//  array7.c
//  
//
//  Created by Ryan Pearson on 1.5.13.
//
//

#include <stdio.h>
#define SIZE 5

void mArray(int b[], size_t size);
int mElement(int e);

int
main(void)
{
    int a[SIZE] = {0, 1, 2, 3, 4};   // array
    size_t i;                       // counter
    
    // show original output
    puts("");
    
    for (i = 0; i < SIZE; i++) {
        printf("Array[%zu] is %d\n", i, a[i]);
    }
    
    puts("\nEffects of array by reference:\n");
    
    mArray(a, SIZE);
    
    // show modified output
    
    for (i = 0; i < SIZE; i++) {
        printf("Array[%zu] is %d\n", i, a[i]);
    }
    
    printf("\n\nThe value of a[3] is %d\n\n", a[3] );
    
    a[3] = mElement(a[3]);
    
    printf("The value of a[3] after modified element function is %d\n\n", a[3]);
    puts("This is because elements only transfer copies, not reference!\n");
    
    return 0;
}

void mArray(int b[], size_t size)
{
    for (unsigned int j = 0; j < size; j++) {
        b[j] *= 2;
    }
    
}

int mElement(int e)
{
    printf("The value of a[3] within the function is: %d"
           "\nBut...\n", e * 2);
    return e * 2;
    
}