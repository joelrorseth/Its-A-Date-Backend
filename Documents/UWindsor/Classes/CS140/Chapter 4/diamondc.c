//
//  diamondc.c
//  
//
//  Created by Ryan Pearson on 1.5.14.
//
//

#include <stdio.h>


int
main(void)
{
    
    int counter = 1;            // counter for tracking height
    int y1 = 0;                 // counter for tracking width leading portion
    int z1 = 0;                 // counter for tracking width trailing portion
    int size =0;                // size to be provided by user
    
    
    // get size from user, ensure cooperation.
    do
    {
        printf("Please provide an integer between 1 and 29: ");
        scanf("%d", &size);
        
        if (size < 3)
        {
            printf("%s", "Really, this will not show a diamond, you need 3 at least to create.");
            puts(" Try again.");
        }
            
    } while (size < 3 || size > 29);
    
    // evaluate number odd or even and start with odd number diamond
    if (size % 2 == 1)
    {
        // set size of diamond variables
        y1 = size / 2;
        z1 = size / 2;
    
        // perform loops odd diamond
        for (int x = 1; x <= size; x++)
        {
            // print first 1/2 of diamond
            if (counter <= (size / 2))
            {
                // draws leading portion of diamond
                for (int y = y1; y >= 1; y--)
                    printf("_");
                for (int z = 2; z <= counter; z++)
                    printf("*");
                
                printf("*");            // prints middle *
                
                // prints trailing part of diamond
                for (int z = 2; z <= counter; z++)
                    printf("*");
                for (int y = y1; y >= 1; y--)
                    printf("_");
                y1--;
            }
            
            // print middle line of diamond for odd numbers
            else if (counter == ((size / 2) + 1))
            {
                for (int x = 1; x <= size; x++)
                    printf("*");
            }
            
            // print remaining 1/2 of diamond
            else if (counter > (size / 2))
            {
                // draw leading portion of diamond in reverse
                for (int y = y1; y >= 0; y--)
                    printf("_");
                for (int z = z1; z >= 2; z--)
                    printf("*");
                
                printf("*");        // prints middle *
                
                // prints trailing part of diamond in reverse
                for (int z = z1; z >= 2; z--)
                    printf("*");
                for (int y = y1; y >= 0; y--)
                    printf("_");
                y1++;
                z1--;
            
            }
            counter++;
            puts("");
        
        }
    }
    
    // print even diamond
    else
    {
        // variables for even numbered diamond
        y1 = size / 2;
        z1 = size / 2;
        
        // perform loops to draw
        for (int x = 1; x <= size; x++)
        {
            // draw first half of diamond
            if (counter <= (size / 2))
            {
                // draw leading portion of diamond
                for (int y = y1; y >= 1; y--)
                    printf("_");
                for (int z = 2; z <= counter; z++)
                    printf("*");
                
                printf("*");        // draw middle *
                
                // draw trailing portion of diamond
                for (int z = 2; z <= counter; z++)
                    printf("*");
                for (int y = y1; y >= 1; y--)
                    printf("_");
                y1--;
            }
            
            // draw bottom half of diamond
            else if (counter > (size / 2))
            {
                // draw leading portion of diamond in reverse
                for (int y = y1; y >= 0; y--)
                    printf("_");
                for (int z = z1; z >= 2; z--)
                    printf("*");
                
                printf("*");        // draw middle *
                
                // draw trailing portion of diamond in reverse
                for (int z = z1; z >= 2; z--)
                    printf("*");
                for (int y = y1; y >= 0; y--)
                    printf("_");
                y1++;
                z1--;
            
            }
            counter++;
            puts("");
        
        }
    }
    return 0;
}