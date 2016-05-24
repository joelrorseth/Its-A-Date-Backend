//
//  credit.c
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
    int acc = 1;
    float charges = 0, credit, bal, limit, nbal;
    // start system loop
    
    while (acc != -1)
    {
        // check for sentinel value
        printf("Enter account number, (-1 to exit)");
        scanf("%d", &acc);
    
        if ( acc != -1)
        {
            //acquire user info and calculate
            printf("Enter beginning balance: ");
            scanf("%f", &bal);
            printf("Enter total charges: ");
            scanf("%f", &charges);
            printf("Enter total credits: ");
            scanf("%f", &credit);
            printf("Enter credit limit: ");
            scanf(" %f", &limit);
            nbal = charges - credit + bal;
            
            // if new balance exceeds limit provide warning
            if (nbal > limit)
            {
                printf("Account:\t %d\n", acc);
                printf("Credit Limit:\t$%.2f\n", limit);
                printf("Balance:\t$%.2f\n", nbal);
                printf("Credit Limit Exceeded!\n");
                puts("");
            }
            
            // or continue on with next person
            else
                puts("");
            
        }
        // exit loop and say bye.
        else
            puts("Thanks for playing! Bye");
    }
    return 0;
}