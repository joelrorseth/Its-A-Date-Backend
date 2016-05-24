//
//  review3.c
//  
//
//  Created by Ryan Pearson on 1.5.13.
//
//

#include <stdio.h>



int
main(void)
{
    int x = 0, reverse = 0, holder = 0, loop = 0;
    char response, dummy;
    do
    {
    printf("Please enter an integer between 1 and 10: ");
    scanf("%d%c", &x, &dummy);
    
        if (x < 1 || x > 10){
            printf("You have entered an invalid entry!!!\n");
            loop = 0;
        }
        else{
            printf("You have entered a valid entry, Goodbye!\n");
            loop = 1;
        }
    }while (loop == 0);
    
    loop = 0;

    do {
        printf("Please answer with yes or no: ");
        scanf("%c%c", &response, &dummy);
        if (response == 'y' || response == 'Y') {
            printf("You responded Yes!\n");
            loop = 1;
        }
        else if (response == 'n' || response == 'N'){
            printf("You responded No!\n");
            loop = 1;
        }
        else
            printf("Invalid Entry!\n");
    }while (loop == 0);
    
    loop = 0;
    
    do{
        printf("Please enter a 4 or 5 digit integer palindrome: ");
        scanf("%d", &x);
        reverse = 0;
        if (x < 1000 || x > 99999)
            printf("Your entry is invalid!!!\n");
        else {
            holder = x;
            while (x != 0) {
                reverse = reverse * 10 + (x % 10);
                x /= 10;
            }
            
            if(reverse == holder){
                printf("%d is a palindrome!\n", holder);
                loop = 1;
            }
            else
                printf("%d is not a palindrome!\n", holder);
        }
    }while(loop == 0);
    
    
    
    return 0;
}