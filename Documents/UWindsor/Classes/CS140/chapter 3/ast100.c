//
//  ast100.c
//  
//
//  Created by Ryan Pearson on 1.5.13.
//
//

#include <stdio.h>

int
main(void)
{
    int counter = 2;
    int holder = 10;
    
    while (counter <= 100)
    {
        printf("%s", "*");
        counter++;
        
        if ((counter % holder) == 1)
        {
            printf("*\n");
            holder += 10;
            counter++;
        }
    }
    
    return 0;
}