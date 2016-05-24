//
//  coins.c
//  
//
//  Created by Ryan Pearson on 1.5.13.
//
//

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//enum status (HEADS, TAILS);

int coins(void);

int
main(void)
{
    // counter for coin tosses
    int hcounter = 0;
    int tcounter = 0;
    srand(time(NULL));
    
    // create loop to simulate coin toss
    for (int x = 0; x <=99 ; x++)
    {
        switch (coins())
        {
            case 0:
                printf("Heads\n");
                hcounter++;
                break;
            case 1:
                printf("Tails\n");
                tcounter++;
                break;
        }
    }
            printf("Total count for heads: %d\n", hcounter);
        printf("Total count for tails: %d\n", tcounter);
    
    return 0;
}

int
coins(void)
{
    int value = 0;
    
    value = rand() % 2;
    
    return value;
}





