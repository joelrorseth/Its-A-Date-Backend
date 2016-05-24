//
//  lab2_q4.c
//  
//
//  Created by Ryan Pearson on 1.5.13.
//
//

#include <stdio.h>

int
main(void)
{
    int num = 0;                    // declare variable for user
    int a = 0;                      // holder for first number
    int b = 0;                      // holder for second number
    int c = 0;                      // holder for third number
    int d = 0;                      // holder for forth number
    int e = 0;                      // holder for fifth number
    int holder = 0;                 // to keep the original number
    char ans = 'Y';
    
    // prompt user for number
    //printf("Please enter a five digit number: ");
    //scanf("%d", &num);
    
     check for 5 digits
    while (num > 99999 || num < 10000)
    {
        printf("Please enter a five digit number: ");
        scanf("%d", &num);
    
        while (ans == 'Y')
        {
            while (ans != 'Y' && ans != 'N')
                printf("Come on, answer my question with Y or N\n");
            
            printf("Please enter a five digit number: ");
            scanf("%d", &num);
            
            // separate the number into each separate 5 digits
    
            holder = num;
    
            a = num / 10000;
            e = num % 10000;
            b = e / 1000;
            num = e % 1000;
            c = num / 100;
            e = num % 100;
            d = e / 10;
            e = num % 10;
    
            // return results to user
            printf("The digits of %d are: %d %d %d %d %d\n", holder, a, b, c, d, e);
    
            printf("Would you like to try again? ");
            scanf("%s", &ans);
        
        }
        
    //}
    
    printf("Goodbye!\n");
    return 0;
}