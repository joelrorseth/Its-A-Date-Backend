//
//  shapes.c
//  
//
//  Created by Ryan Pearson on 1.5.13.
//
//

#include <stdio.h>
void side(int s1, int c1);
void triangle(int s1, int c1);
void rectangle(int s1, int c1);
void diamond(int s1, int c1);

int
main(void)
{
    int side1 = 0;              // variable for side
    int fill;
    
    printf("Please provide a character: ");
    fill = getchar();
    
    printf("Please give size: ");
    scanf("%d", &side1);
    
    //printf("Please provide a character: ");
    //fill = getchar();
    
    side(side1, fill);
    triangle(side1, fill);
    rectangle(side1, fill);
    diamond(side1, fill);
    
    return 0;
}


void
side(int s1, int c1)
{
    for (int x = 1; x <= s1; x++)
    {
        for (int y = 1; y <= s1; y++)
        {
            printf("%c ", c1);
        }
        puts("");
    }
    
    puts("");
}

void
triangle(int s1, int c1)
{
    int counter = 1;
    
    for (int x = 1; x <= s1; x++)
    {
        for (int y = 1; y <= counter; y++)
        {
            printf("%c ", c1);
        }
        puts("");
        counter++;
    }
    puts("");
    
}

void
diamond(int s1, int c1)
{
    if (s1 % 2 == 1)
    {
        // set size of diamond variables
        int y1 = s1 / 2;
        int z1 = s1 / 2;
        int counter =1;
    
        // perform loops odd diamond
        for (int x = 1; x <= s1; x++)
        {
            // print first 1/2 of diamond
            if (counter <= (s1 / 2))
            {
                // draws leading portion of diamond
                for (int y = y1; y >= 1; y--)
                    printf("_");
                for (int z = 2; z <= counter; z++)
                    printf("%c", c1);
            
                printf("%c", c1);            // prints middle *
            
                // prints trailing part of diamond
                for (int z = 2; z <= counter; z++)
                    printf("%c", c1);
                for (int y = y1; y >= 1; y--)
                    printf("_");
                y1--;
            }
        
            // print middle line of diamond for odd numbers
            else if (counter == ((s1 / 2) + 1))
            {
                for (int x = 1; x <= s1; x++)
                    printf("%c", c1);
            }
        
            // print remaining 1/2 of diamond
            else if (counter > (s1 / 2))
            {
                // draw leading portion of diamond in reverse
                for (int y = y1; y >= 0; y--)
                    printf("_");
                for (int z = z1; z >= 2; z--)
                    printf("%c", c1);
            
                printf("%c", c1);        // prints middle *
            
                // prints trailing part of diamond in reverse
                for (int z = z1; z >= 2; z--)
                    printf("%c", c1);
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
        int y1 = s1 / 2;
        int z1 = s1 / 2;
        int counter = 1;
    
        // perform loops to draw
        for (int x = 1; x <= s1; x++)
        {
            // draw first half of diamond
            if (counter <= (s1 / 2))
            {
                // draw leading portion of diamond
                for (int y = y1; y >= 1; y--)
                    printf("_");
                for (int z = 2; z <= counter; z++)
                    printf("%c", c1);
            
                printf("%c", c1);        // draw middle *
            
                // draw trailing portion of diamond
                for (int z = 2; z <= counter; z++)
                    printf("%c", c1);
                for (int y = y1; y >= 1; y--)
                    printf("_");
                y1--;
            }
        
            // draw bottom half of diamond
            else if (counter > (s1 / 2))
            {
                // draw leading portion of diamond in reverse
                for (int y = y1; y >= 0; y--)
                    printf("_");
                for (int z = z1; z >= 2; z--)
                    printf("%c", c1);
            
                printf("%c", c1);        // draw middle *
            
                // draw trailing portion of diamond in reverse
                for (int z = z1; z >= 2; z--)
                    printf("%c", c1);
                for (int y = y1; y >= 0; y--)
                    printf("_");
                y1++;
                z1--;
            
            }
            counter++;
            puts("");
        
        }

    }
}

void
rectangle(int s1, int c1)
{
    for (int x = 1 ; x <= s1; x++)
    {
        for (int y = 1; y <= s1 * 2; y++)
        {
            printf("%c ", c1);
        }
        puts("");
    }
    
    puts("");
}













