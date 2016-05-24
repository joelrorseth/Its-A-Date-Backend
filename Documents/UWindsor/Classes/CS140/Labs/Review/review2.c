//
//  review2.c
//  
//
//  Created by Ryan Pearson on 1.5.13.
//
//

#include <stdio.h>


int
main(void)
{
    int numbers[5] = {0};
    int x = 0, max = 0, min = 0;
    
    printf("Please enter five integers: ");
    for (x = 0; x < 5; x++) {
        scanf("%d", &numbers[x]);
    }
    
    for (x = 0; x < 5; x++) {
        if (x == 0) {
            max = numbers[x];
            min = numbers[x];
        }
        else if(numbers[x] < min)
            min = numbers[x];
        else if(numbers[x] > max)
            max = numbers[x];
    }
    
    printf("The Max is: %d\nThe Min is: %d\n", max, min);
    
    printf("Please enter an integer: ");
    scanf("%d", &x);
    (x % 2)== 1 ? printf("%d is odd!\n",x) : printf("%d is even!\n", x);
    
    printf("Please enter two integers: ");
    scanf("%d%d", &max, &min);
    (max % min)==0 ? printf("%d is a multiple of %d\n", max, min) :
    printf("%d is not a multiple of %d\n", max, min);
    
    char yesno = 'Y';
    char dummy;
    do
    {
        printf("Please enter a five digit number: ");
        scanf("%d", &x);
        
        printf("The digits of %d are: ", x);
        max = 10000;
        
        while (x != 0) {
            printf("%d\t", (x / max));
            x %= max;
            max /= 10;
        }
        puts("");
        printf("Would you like to try again? \n");
        scanf("%c%c",&dummy, &yesno);
    }while (yesno == 'Y');
    
    
    return 0;
}