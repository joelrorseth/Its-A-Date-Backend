//
//  twenty.c
//  
//
//  Created by Ryan Pearson on 1.5.13.
//
//

#include <stdio.h>
#define SIZE 5

int
main(void)
{
    int numbers[SIZE]= {0};
    int holder = 0;
    int y = 0;
    
    for (int i = 0; i < SIZE; i++) {
        numbers[i] = 0;
    }
    
    printf("Please enter 20 integers between 10 and 100:\n");
    for (int i = 0; i < SIZE; i++)
    {
        do
        {
            scanf("%d", &holder);
            if (holder < 10 || holder > 100)
                printf("Between 10 and 100: ");
        } while (holder < 10 || holder > 100);
     
        for (int x = 0; x <= i; x++)
        {
            if (holder == numbers[x])
            {
                printf("YOU ALREADY TYPED THAT!\n");
                break;
            }
            else if (holder != numbers[x] && x == i)
            {
                for (y = 0; y <= i; y++)
                {
                    if (numbers[y] == 0 && holder != 0)
                    {
                        numbers[y] = holder;
                        holder = 0;
                        break;
                    }
                }
            }
        }
        
    }
    puts("Numbers not duplicated are:");
    for (y = 0; y < SIZE; y++) {
        if (numbers[y] != 0)
            printf("%d\t", numbers[y]);
        else
            continue;
    }
    puts("");
    return 0;
}