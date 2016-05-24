//
//  interest.c
//  
//
//  Created by Ryan Pearson on 1.5.13.
//
//

#include <stdio.h>


int
main(void)
{
    // declare variables, set prin to enter loop
    float prin = 0, rate, interest;
    int days;
    
    // generate loop with sentinel value, prompt for variables
    while (prin != -1)
    {
        printf("%s", "Provide loan principle ( -1 to exit):");
        scanf("%f", &prin);
        // check for sentinel value, if not, get variables and provide interest
        if (prin != -1)
        {
            printf("%s", "Provide rate of interest in decimal form: ");
            scanf("%f", &rate);
            printf("%s", "Provide term of loan: ");
            scanf("%d", &days);
            interest = prin * rate * days / 365;
            printf("You have incurred $%.2f interest.\n", interest);
        }
        // sentinel value entered, start exit process.
        else
            puts("ahh... you wish to exit... ok.");
    }
    puts("Thanks for playing. Bye");
    return 0;
}