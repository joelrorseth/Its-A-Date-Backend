//
//  6.17.c
//  
//
//  Created by Ryan Pearson on 1.5.13.
//
//returns sum of 10 thru 1( elements are labeled starting at zero, so the 10th element in the array, (which is actually labelled 9th, is value 10)

#include <stdio.h>
#define SIZE 10

int whatisthis(const int b[], size_t p);

int
main(void)
{
    int x;
    
    int a[SIZE] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    x = whatisthis(a, SIZE);
    
    printf("Result %d\n", x);
    
    return 0;
}

int whatisthis(const int b[], size_t p)
{
    if (1 == p) {
        printf("last %d\n", b[0]);
        return b[0];
    }
    else
    {
        printf("%d\n", b[p-1]);
        return b [p-1] + whatisthis(b, p-1);
    }
    
    
}