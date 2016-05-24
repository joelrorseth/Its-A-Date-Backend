//
//  climits.c
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
    int accnum = 0;             // account number
    float crelim = 0;           // credit limit
    float bal = 0;              // balance of limit
    
    // repeat 3 times
    for (int counter = 1; counter <= 3; counter++)
    {
        // acquire variables
        printf("Provide account number please: ");
        scanf("%d", &accnum);
        printf("Provide current credit limit please: ");
        scanf("%f", &crelim);
        printf("Provide current balance please: ");
        scanf("%f", &bal);
        puts("");
        
        // reset limit and verify good standing
        // provide feedback to user
        crelim /= 2;
        if (crelim < bal)
        {
            printf("Account number: %d\n", accnum);
            printf("Your limit has been reduced to: $ %9.2f\n", crelim);
            printf("Your outstanding balance is: \t$ %9.2f\n", bal);
            printf("Kindly remit payments of: \t$ %9.2f\n", (bal - crelim + 100.));
            printf("An additional $100.00 has been added to your total to bring into good standing.\n");
            puts("");
        }
        else
        {
            printf("Account number: %d\n", accnum);
            printf("Your limit has been reduced to: $ %9.2f\n", crelim);
            printf("Your outstanding balance is: \t$ %9.2f\n", bal);
            printf("Your remaining credit is: \t$ %9.2f\n", (crelim - bal));
            puts("");
        }
    }
    
    return 0;
}