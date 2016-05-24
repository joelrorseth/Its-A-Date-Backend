//
//  array4.c
//  
//
//  Created by Ryan Pearson on 1.5.13.
//
//

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define FACE 7

int
main(void)
{
    unsigned int timesrolled [FACE] = {0};
    int face = 0;
    
    srand(time (NULL));
    
    
    for (unsigned int roll; roll < 6000000; roll++)
    {
        face = rand() % 6 + 1;
        ++timesrolled[face];
    }
    
    for (face = 1; face < FACE; face++) {
        printf("Face %zd rolled %u times\n", face, timesrolled[face]);
    }
    return 0;
}