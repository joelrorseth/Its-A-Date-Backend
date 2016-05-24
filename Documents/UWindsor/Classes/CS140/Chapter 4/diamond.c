//
//  diamond.c
//  
//
//  Created by Ryan Pearson on 1.5.13.
//
//

#include <stdio.h>


int
main(void)
{
    int counter = 1;
    int y1 = 5;
    int z1 = 5;
    
    
    for (int x = 1; x < 10; x++)
    {
        if (counter <= 5)
        {
            for (int y = y1; y > 1; y--)
                printf("_");
            for (int z = 2; z <= counter; z++)
                printf("*");
            printf("*");
            for (int z = 2; z <= counter; z++)
                printf("*");
            for (int y = y1; y > 1; y--)
                printf("_");
            y1--;
        }
        
        else if (counter > 5)
        {
            for (int y = y1; y >= 0; y--)
                printf("_");
            for (int z = z1; z > 2; z--)
                printf("*");
            printf("*");
            for (int z = z1; z > 2; z--)
                printf("*");
            for (int y = y1; y >= 0; y--)
                printf("_");
            y1++;
            z1--;
            
        }
        counter++;
        puts("");
        
        
    }
    return 0;
}