//
//  triangles.c
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
    while (counter <= 4)
    {

    for (int x = 1; x <= 10; x++)
    {
        if(counter == 1)
        {
            for (int y = x; y >= 1; y--)
                printf("%s", "*");
        }
        else if (counter == 2)
        {
            for (int y = x; y <= 10; y++)
                printf("%s", "*");
        }
        else if (counter == 3)
        {

            for (int s = (x - 1); s > 0; s--)
                printf("%s", " ");
            for (int y = x; y <= 10; y++)
                printf("%s", "*");
            
        }
        else if (counter == 4)
        {
            for (int s = (x + 1); s <= 10; s++)
                printf("%s", " ");
            for (int y = x; y >= 1; y--)
                printf("%s", "*");
        }
        puts("");
        
    }
        counter++;
    }
    
    puts("You Rock.");
    return 0;
}