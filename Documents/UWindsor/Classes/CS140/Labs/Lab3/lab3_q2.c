//
//  lab3_q2.c
//  
//
//  Created by Ryan Pearson on 1.5.13.
//
//

#include <stdio.h>

int
main(void)
{
    
    char yn;                 // declare variable

        // ask user for yes or no
        printf("%s", "\nPlease answer with yes or no: ");
        yn = getchar();
    
        // check answer and provide feedback
        switch(yn)
        {
            case 'y':
            case 'Y':
                printf("%s", "You responded Yes!\n");
                break;
            
            case 'n':
            case 'N':
                printf("%s", "You responded No!\n");
                break;
                
            default:
                printf("%s", "Your entry is invalid!!!\n");
        }

    return 0;
}
