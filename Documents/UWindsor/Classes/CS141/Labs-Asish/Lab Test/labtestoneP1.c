//
//  labtest1.c
//  
//
//  Created by Ryan Pearson on 1.5.13.
//
//

#include <stdio.h>

void drawdiamond(int);

int
main(void)
{
    int x;              // user input
    
    do {
        printf("Please enter an odd integer: ");
        scanf("%d", &x);
    } while ((x % 2) == 0);
   
    // draw diamond
    drawdiamond(x);
    return 0;
}

void drawdiamond(int size)
{
    int counter = 0;
    int y1 = size / 2;
    int z1 = size / 2;
    
    // perform loops to create diamond
    for (int x = 0; x < size; x++)
    {
        
        // broke up drawing the diamond into 1st half, middle, then tail half
        // print first 1/2 of diamond
        if (counter <= (size / 2))
        {
            // draws leading portion of diamond
            for (int y = y1; y >= 1; y--)
                printf("  ");
            for (int z = 1; z <= counter; z++)
                printf("* ");
            
            printf("* ");            // prints middle *
            
            // prints trailing part of diamond
            for (int z = 1; z <= counter; z++)
                printf("* ");
            y1--;
        }
        
        // print remaining 1/2 of diamond
        else if (counter > (size / 2))
        {
            // draw leading portion of diamond in reverse
            for (int y = y1; y >= -1; y--)
                printf("  ");
            for (int z = z1; z >= 2; z--)
                printf("* ");
            
            printf("* ");        // prints middle *
            
            // prints trailing part of diamond in reverse
            for (int z = z1; z >= 2; z--)
                printf("* ");
            y1++;
            z1--;
            
        }
        counter++;
        puts("");
        
    }
    return;
}