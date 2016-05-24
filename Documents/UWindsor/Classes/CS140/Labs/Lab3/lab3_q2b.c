//
//  lab3_q2b.c
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
    int loop = 0;           // declare loop variable

    
    while(loop == 0)
    {
        // ask user for yes or no
        printf("%s", "Please answer with yes or no: ");
        //scanf("%s", &yn);
        yn = getchar();

        // check answer and provide feedback
        if (yn == 'y' || yn == 'Y')
        {
            printf("%s", "You responded Yes!\n");
            loop = 1;
        }
        else if (yn == 'n' || yn == 'N')
        {
            printf("%s", "You responded No!\n");
            loop = 1;
        }
        else
            printf("%s", "Your entry is invalid!!!\n");
    }
    
    return 0;
}
