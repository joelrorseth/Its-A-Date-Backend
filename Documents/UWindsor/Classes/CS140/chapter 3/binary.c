//
//  binary.c
//  
//
//  Created by Ryan Pearson on 1.5.13.
//
//

#include <stdio.h>

int
main(void)
{
    // declare variables
    int ans, a = 0, b = 0, c = 0, d = 0, e = 0;
    int holder = 0;
    int counter = 1;
    int dvalue = 10000;
    
    //prompt user for binary 5 digit number
    while ( ans > 11111)
    {
    printf("Please provide binary (up to) 5 digit number: ");
    scanf("%d", &ans);
        if(ans > 11111)
            puts("Don't be an ass. I said 5 binary digits!");
    }
    
    // loop over 5 digits to receive individual digits
    while (counter <= 5)
    {
        holder = ans / dvalue;
        ans %= dvalue;
        dvalue /= 10;
        // evaluate values used
        if (counter == 1)
            holder == 1 ? (a = 16) : (a = 0);
        if (counter == 2)
            holder == 1 ? (b = 8) : (b = 0);
        if (counter == 3)
            holder == 1 ? (c = 4) : (c = 0);
        if (counter == 4)
            holder == 1 ? (d = 2) : (d = 0);
        if (counter == 5)
            holder == 1 ? (e = 1) : (e = 0);
        counter++;
    }
    // print number
    printf("Number from Binary is: %d\n", (a + b + c + d + e));
    
    return 0;
}