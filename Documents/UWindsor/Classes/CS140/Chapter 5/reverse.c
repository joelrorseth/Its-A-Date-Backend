//
//  reverse.c
//  
//
//  Created by Ryan Pearson on 1.5.13.
//
//

#include <stdio.h>

int reverse(int num);

int
main(void)
{
    // declare variable for number
    int number = 0;
    
    // ask user for integer
    printf("Please provide an integer: ");
    scanf("%d", &number);
    
    printf("Your number reversed is: %d\n", reverse(number));
    
    return 0;
}

int
reverse(int num)
{
    int rev = 0;
    int holder = 0;
    
    while (num != 0)
    {
        holder = num % 10;
        num /= 10;
        rev = (rev * 10) + holder;
    }
    return rev;
}