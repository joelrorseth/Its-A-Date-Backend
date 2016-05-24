/* PEARSON, Ryan
 *  ID: 103965059
 *  Lab Exercise #lab4_q1
 *  Date: Feb 12, 2013
 *  Purpose: ask for integer and provide "*" as feedback, give 3 tries
 */

#include <stdio.h>

int
main(void)
{
    int n = 0;                                      // declare int to get from user
    int counter = 3;                                // counter to keep track of incorrect answers
    
    
    // ask user for integer
    do
    {
        printf("Please enter an integer between 1 and 10: ");
        scanf("%d", &n);
        
        // check for correct answer provide feedback and countdown of tries left.
        if ((n < 1 || n > 10) && counter == 3)
        {
            printf("You have entered an invalid entry, %d attempts left, try again!\n", counter - 1);
            counter--;
        }
        else if ((n < 1 || n > 10) && counter == 2)
        {
            printf("You have entered an invalid entry, %d attempt left, try again!\n", counter - 1);
            counter--;
        }
        else if ((n < 1 || n > 10) && counter == 1)
        {
            printf("%s", "You have entered an invalid entry! Goodbye!\n");
            counter--;
        }
        
        // return proper response with *'s in loop
        else
        {
            printf("%d: ", n);
            for (int x = 1; x <= n; x++)
                printf("%s", "*");
            puts("");
            counter = 0;            //exit loop
        }
    }while (counter != 0);
    
    
    //reset counter
    counter = 3;
    puts("\n2nd run of the program using a switch\n");
    
    // alternate way of doing the problem with switch statement
    do
    {
        // ask user for int
        printf("Please enter an integer between 1 and 10: ");
        scanf("%d", &n);
        
        // validate answer, give back gramatically correct response or exit if user does not cooperate after 3 tries.
        if (n < 1 || n > 10)
        {
            switch (counter)
            {
                case 3:
                    printf("You have entered an invalid entry, %d attempts left, try again!\n", counter -1);
                    counter--;
                    break;
                case 2:
                    printf("You have entered an invalid entry, %d attempt left, try again!\n", counter -1);
                    counter--;
                    break;
                case 1:
                    printf("You have entered an invalid entry! Goodbye!");
                    counter--;
            }
        }
        
        // give proper results with *'s in loop
        else
        {
            printf("%d: ", n);
            for (int x = 1; x <= n; x++)
                printf("%s", "*");
            counter = 0;                    // exit loop
        }
    }while (counter != 0);
    
    // add a newline
    puts("");
    return 0;
}

