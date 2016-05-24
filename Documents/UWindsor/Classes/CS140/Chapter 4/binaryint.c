//
//  binaryint.c
//  
//
//  Created by Ryan Pearson on 1.5.13.
//
//

#include <stdio.h>
#include <math.h>

int
main(void)
{
    int x = 0;              // declare variable
    int y = 1;
    int counter = 1;
    int value = 0;
    
    printf("Please provide an int so i can show you binary equivalent: ");
    scanf("%d", &x);
    
    if (y == x)
        puts("00000001\t-Binary!\n");
    else
    {
        y = 1;
        counter = 1;
        // evaluate how many positions in binary.
        do
        {
            y *= 2;
            counter++;
            printf("%d%d\n", y, counter);
        } while (y < x);
        
        for (int zero = 8; zero > counter; zero--)
            printf("%s", "0");
        
        int h256 = 0;
        
        for (int z = 0; z < counter; z++)
        {
            h256 = x / y;
            printf("%d", h256);
            x %= y;
            y /= 2;
            
        }
        puts("\t- binary");

        
    }
    return 0;
}