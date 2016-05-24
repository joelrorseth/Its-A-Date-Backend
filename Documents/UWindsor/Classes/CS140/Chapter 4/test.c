//
//  test.c
//  
//
//  Created by Ryan Pearson on 1.5.13.
//
//

#include <stdio.h>

int
main(void)
{
    int code = 0;           // declare int
    int loop = 0;           // declare loop    
    
    do {
    // get 5 digits from user
    printf("Please enter a 5 digit code: ");
    scanf("%d", &code);
        
        // test valid code
    if (code < 10000 || code > 64999)
        printf("invalid code\n");
    else if ((code / 10000) < 1 || (code / 10000) > 6)
        printf("invalid code\n");
    else
    {
        code %= 10000;
    
        if ((code / 1000) < 1 || (code / 1000) > 6)
            printf("invalid code\n");
        else
        {
            printf("valid code\n");
            loop = 1;
        }
    }
        
    } while (loop == 0);
    
    // do math to calculate money
    code %= 1000;
    // provide feedback
    printf("your money is: $%.2f\n", (float)code / 100);
    
    
    
    return 0;
}