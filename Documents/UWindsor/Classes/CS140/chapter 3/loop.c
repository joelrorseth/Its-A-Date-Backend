//
//  loop.c
//  
//
//  Created by Ryan Pearson on 1.5.13.
//
//

#include <stdio.h>

int
main(void)
{
    //declare variables
    int x = 1, counter = 0;
    
    while (counter <= 9)
    {
        printf("%d   ", x);
        x++;
        counter++;
    }
    puts("");
    return 0;
}