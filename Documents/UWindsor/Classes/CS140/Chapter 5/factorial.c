//
//  factorial.c
//  
//
//  Created by Ryan Pearson on 1.5.13.
//
//

#include <stdio.h>

long int fact(int a);

int
main(void)
{
    int x = 0;
    
    printf("\nPlease provide the number for factorial: ");
    scanf("%d", &x);
    
    puts("");
    printf("The value of %d factorial is: %ld\n", x, fact(x));
    return 0;
}

long int
fact(int a)
{
    int sum = 0;
    int counter = 1;

    if (a <= 1)
    {
        printf("Factorial of 1 is just 1\n\n");
        return 1;
    }
        
    else
    {
        sum = (a * fact(a - 1));
        printf("Factorial of %d = ", sum);
        //for (counter = 1; counter <=a; counter++)
            //  printf(" ");
        int countdown = a;
        for (counter = 1; counter <= a; counter++)
        {
            
            if (counter < a)
                printf("%d * ", countdown);
            else
                printf("%d \nOR...\n", countdown);
            countdown--;
        }
        for (int tab = 1; tab < counter; tab++)
        {
            int holder = a;
            printf("%d * %d!\n", a, a - 1);
            a--;
            for (int over = 1; over <= tab; over++) {
                printf("    ");
            }
        }
        //printf("= %d", sum);
        printf("\n");
    }
                
    return sum;
}