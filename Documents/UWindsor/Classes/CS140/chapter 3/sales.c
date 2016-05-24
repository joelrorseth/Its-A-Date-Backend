//
//  sales.c
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
    float sales = 0, com, pay;
    // implement loop and check for sentinel value
    while (sales != -1)
    {
        printf("%s", "Please provide total sales(-1 to exit): ");
        scanf("%f", &sales);
        // if sentinel loop not found do math for salary
        if (sales != -1)
        {
            com = (sales * .09);
            pay = 200 + com;
            printf("Salary is: $%.2f\n\n", pay);
        }
        // if sentinel found, done.
        else
            puts("Thanks for playing! Bye");
    }
}