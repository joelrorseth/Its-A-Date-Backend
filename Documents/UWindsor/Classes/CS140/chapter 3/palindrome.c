//
//  palindrome.c
//  
//
//  Created by Ryan Pearson on 1.5.13.
//
//

#include <stdio.h>


int
main(void)
{
    //declare variables
    unsigned int x = 0, a = 0, b = 0, c = 0, d = 0, e = 0;
    unsigned int holder;
    int dvalue = 10000;
    int counter = 1;
    
    // prompt user for correct value
    while (x < 10000 || x > 99999)
    {
        printf("Please provide valid 5 digit number: ");
        scanf("%d", &x);
        if (x < 10000)
            puts("Stop being difficult.");
        if (x > 99999)
            puts("Now your just being rediculous.");
    }
    
    //loop over entry to separate values and assign new variables for each
    while (counter <= 5)
    {
        holder = x / dvalue;
        x %= dvalue;
        dvalue /= 10;
        if ( counter == 1)
            a = holder;
        if ( counter == 2)
            b = holder;
        if (counter == 3)
            c = holder;
        if (counter == 4)
            d = holder;
        else
            e = holder;
        counter++;
    }
    
    // test for palindrome
    if ( a == e && b == d)
        puts( "Palindrome Baby!!!");
    else
        puts ("No dice. This is not a palindrome.");
    
    return 0;
}