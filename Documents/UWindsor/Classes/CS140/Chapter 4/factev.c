//
//  factev.c
//  
//
//  Created by Ryan Pearson on 1.5.13.
//
//

#include <stdio.h>

int
main(void)
{
    int sum = 1;
    int z = 1;
    int counter = 0;            // variable for aligning tabs
    
    for (int x = 1; x <= 5; x++)
    {
        for (int y = 1; y <= x; y++)
        {
            
            printf("%d\t", y);
        }
        
        while (z <= x)
        {
            sum *= z;
            z++;
        }
        
        counter = x;
        
        while (counter <= 4)
        {
            printf("\t");
            counter++;
        }
        
        printf("total = $ %3.2f\n\n", (float)sum);
        sum = 1;
        z = 1;
    }
    
    
    return 0;
}