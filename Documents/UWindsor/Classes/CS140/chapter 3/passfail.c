//
//  passfail.c
//  
//
//  Created by Ryan Pearson on 1.5.13.
//
//

#include <stdio.h>

int
main()
{
    
    unsigned int passes = 0;// create pass variable
    unsigned int failures = 0;// create fail variable
    unsigned int student = 1;// use as counter
    int result;// variable to hold entry
    
    //repeat loop, force user to enter proper info.
    while (student <= 10)
    {
 
        printf("%s", "Enter result (1 = pass, 2 = fail): ");
        scanf("%d", &result);
        
        if (result == 2 || result ==1)
        {
            result == 1 ? passes++ : failures++;
            student++;
        }
        else
            puts("enter something useful");

    }
    
    printf("You have %u Passes.\n", passes);
    printf("You have %u Failures.\n", failures);
    
    puts ( passes > 8 ? "Bonus to Instructor!" : "Brutal!");
       // puts("Bonus to Instructor!");
    
    return 0;
}

