//
//  array2.c
//  
//
//  Created by Ryan Pearson on 1.5.13.
//
//

#include <stdio.h>
#define RESPONSES_SIZE 10
#define FREQUENCY_SIZE 6

int
main(void)
{
    int frequency[FREQUENCY_SIZE] = {0};
    
    int responses[RESPONSES_SIZE] = {1,2,4,2,5,2,3,4};
    
    for (size_t answer = 0; answer < RESPONSES_SIZE; answer++) {
        ++frequency[responses[answer]];
    }
    
    printf("%s%17s\n", "Rating", "Frequency");
    
    for (size_t rating = 1; rating < FREQUENCY_SIZE; rating++) {
        printf("%zu%17d\n", rating, frequency[rating]);
    }
    
    return 0;
}