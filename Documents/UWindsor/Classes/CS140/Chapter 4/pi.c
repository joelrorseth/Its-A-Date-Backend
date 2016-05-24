//
//  pi.c
//  
//
//  Created by Ryan Pearson on 1.5.13.
//
//

#include <stdio.h>

int
main(void)
{
    float denom = 3;          // declare denom
    
    float pi = 4;         // initial pi value
    int counter = 1;    // counter
    float value = 0;      // amount
    
    
    for (int x = 1; x < 1000000; x++)
    {
        
        if (counter % 2 == 1)
        {
            value = (4 / denom) * (-1);
            denom += 2;
            counter++;
        }
        
        else
        {
            value = (4/ denom);
            denom += 2;
            counter++;
        }
        
        
        pi += value;
    }
    printf("%.8f\n",pi );
    return 0;
}