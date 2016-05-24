//
//  array3.c
//  
//
//  Created by Ryan Pearson on 1.5.13.
//
//

#include <stdio.h>
#define SIZE 10             // define size

int
main(void)
{
    int n[SIZE] = { 19, 3, 15, 7, 11, 9, 13, 5, 17, 1 };
    size_t i;
    
    printf("\n%s%13s%17s\n", "Element", "Value", "Histogram");
    
    for (i = 0; i < SIZE; i++) {
        printf("%7zu%13d        ", i, n[i]);
        for (int j = 0; j < n[i]; j++)
            printf("%c", '*');
        puts("");
    }
    
    puts("");
    return 0;
}