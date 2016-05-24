//
//  fastc.c
//  
//
//  Created by Ryan Pearson on 1.5.13.
//
//

#include <stdio.h>

int
main(void)
{
    long counter = 1;
    int sec = 1;
    
    while (counter <= 1000000000)
    {
        if ((counter / 100000000) == 1)
        {
            printf("%d", sec);
            sec++;
            counter++;
        }
        else
            counter++;
    }
    
    
    return 0;
}