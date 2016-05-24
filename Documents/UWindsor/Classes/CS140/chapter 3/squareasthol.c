//
//  squareasthol.c
//  
//
//  Created on 1.5.13.
//
//

#include <stdio.h>


int
main(void)
{
    // declare variables
    int x;
    int counterl = 1;// length
    int counterh = 1;// height
    
    // ask for size of hollow square
    printf("%s", "Please enter the size of your square: ");
    scanf("%d", &x);
    
    // iterate over loop printing height
    while (counterh <= x)
    {
        // iterate over loop printing rows, selecting to print space for center.
        while (counterl <= x)
        {
            if (counterh == 1 || counterh == x)
            {
                printf("%s", "*");
            }
            else
            {
                if (counterl == 1)
                    printf("%s", "*");
                else if (counterl == x)
                    printf("%s", "*");
                else
                    printf("%s", " ");
            }
            counterl++;
        }
        puts("");
        counterh++;
        counterl = 1;
    }
    
    return 0;
}