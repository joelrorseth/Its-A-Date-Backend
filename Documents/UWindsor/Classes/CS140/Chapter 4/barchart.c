//
//  barchart.c
//  
//
//  Created by Ryan Pearson on 1.5.13.
//
//

#include <stdio.h>


int
main(void)
{
    int x = 0;              // declare x variable
    
    // start loop and count how many iterations
    for (int counter = 1; counter <= 5; counter++)
    {
        // prompt user for input
        printf("Please provide an integer between 1 and 30: ");
        scanf("%d", &x);
        
        //catch user for non valid integer, reset counter -1
        if (x < 1 || x > 30)
        {
            printf("That is not between 1 and 30...");
            counter--;
        }
        // print bar
        else
        {
            for (int y = 1; y <= x; y++)
            {
                printf("%s", "*");
            }
        }
        puts("");
    }
    
    return 0;
}