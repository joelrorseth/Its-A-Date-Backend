//
//  dboh.c
//  
//
//  Created by Ryan Pearson on 1.5.13.
//
//

#include <stdio.h>


int
main(void)
{
    int x = 0;          // declare variable for x
    int h256 = 0;
    /*int h128 = 0;
    int h64 = 0;
    int h32 = 0;
    int h16 = 0;
    int h8 = 0;
    int h4 = 0;
    int h2 = 0;
    int h1 = 0;*/
    int holder = 1;
    int value = 0;
    
    for (holder = 1; holder <= 256; holder++)
    {
        printf("\n%d\t\t- decimal\n", holder);
        printf("%o\t\t- octal\n", holder);
        printf("%X\t\t- hexadecimal\n", holder);
        x = holder;
        // compute binary equivalent way number 1
        /*h256 = x / 256;
        x %= 256;
        h128 = x / 128;
        x %= 128;
        h64 = x / 64;
        x %= 64;
        h32 = x / 32;
        x %= 32;
        h16 = x / 16;
        x %= 16;
        h8 = x / 8;
        x %= 8;
        h4 = x / 4;
        x %= 4;
        h2 = x / 2;
        x %= 2;
        h1 = x;
        
        printf("%d%d%d%d%d%d%d%d%d\t- binary\n", h256, h128, h64, h32, h16, h8, h4, h2, h1);*/
        
        
        // compute binary, this is much more efficient... thru loop.
        value = 256;
        
        for (int y = 0; y <= 8; y++)
        {
            h256 = x / value;
            printf("%d", h256);
            x %= value;
            value /= 2;
            
        }
        puts("\t- binary");
    }
    
    return 0;
}