//
//  sumodd.c
//  
//
//  Created by Ryan Pearson on 1.5.13.
//
//

#include <stdio.h>

int
main(void)
{
    int sum = 1;                // variable to store sum
    
    for (int x = 1; x <= 15; x += 2)
    {
        printf("%d\n", sum *= x);
        
    }
    
    return 0;
}
