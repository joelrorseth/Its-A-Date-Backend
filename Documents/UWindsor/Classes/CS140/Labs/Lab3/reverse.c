//
//  reverse.c
//  
//
//  Created by Ryan Pearson on 2.5.13.
//
//

#include <stdio.h>

int
main(void)
{
    int x = 0;
    int holder = 0;
    int reverse = 0;
    int y = 0;
    
    printf("Provide 5 digit int: ");
    scanf("%d", &x);
    
    holder = x;
    // reverse int
     while ( x != 0)
     {
         y = x % 10;
         reverse = (reverse * 10) + y;
         x = x /10;
         
     }
    
    printf(" Reversed is: %d\n", reverse);
    
    //printf("%d\n", holder);
    
    if (reverse == holder)
        puts("Palindrome!");
    else
        puts("no dice");
    
    return 0;
}