//
//  squareast.c
//  
//
//  Created by Ryan Pearson on 1.5.13.
//
//

#include <stdio.h>


int
main(void)
{
    int x;
    int counterl = 1;
    int counterh = 1;
    
    printf("%s", "Please enter the size of your square: ");
    scanf("%d", &x);
    
    while (counterh <= x)
    {
        while (counterl <= x)
        {
                printf("%s", "*");
                counterl++;
        }
        puts("");
        counterh++;
        counterl = 1;
    }
    
    return 0;
}