//
//  sevens.c
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
    int a = 0, b = 0, c = 0, d = 0, e = 0, x, holder, dvalue = 10000; //variables to store numbers
    int counter = 0; // track loop variable
    
    // get integer from user
    printf("Provide an integer up to 5 digits long: ");
    scanf("%d", &x);
    
    // separate numbers & establish variables a-e
    while ( counter <= 4 )
    {
        holder = x / dvalue;
        x %= dvalue;
        
            if (counter == 0)
                a = holder;
            if (counter == 1)
                b = holder;
            if (counter == 2)
                c = holder;
            if (counter == 3)
                d = holder;
            if (counter == 4)
                e = holder;
        dvalue /= 10;
        counter++;
    }
    
    printf("%d, %d, %d, %d, %d, %d\n", a, b, c, d, e, counter);
    
   // while (x != 1)
    //{
        // reset counter and verify if a-e has any "7's"
        counter = 0;
        if (a == 7)
            counter++;
        if (b == 7)
            counter++;
        if (c == 7)
            counter++;
        if (d == 7)
            counter++;
        if (e == 7)
            counter++;
  //      x = 1;
//    }
    
    printf("%d, %d, %d, %d, %d, %d\n", a, b, c, d, e, counter);
    
    // reply to user with proper result
    
    if (counter == 0)
        printf("%s", "You have no 7's in your integer.\n");
    else if (counter == 1)
        printf("You have %d 7 in your integer.\n", counter);
    else
        printf("You have %d 7's in your integer.\n", counter);
    
    return 0;
}