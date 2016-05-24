//
//  coins2.c
//  
//
//  Created by Ryan Pearson on 1.5.13.
//
//

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// enumeration constants
enum status {HEADS, TAILS};
enum status hort;
// function prototype
int coins(void);

int
main(void)
{
    srand( time (NULL));
    int tcounter = 0;
    int hcounter = 0;
    
    for (int x = 0; x <= 99; x++) {
        switch (coins()) {
            case HEADS:
                puts("Heads");
                hcounter++;
                break;
            case TAILS:
                puts("Tails");
                tcounter++;
                break;
        }
    }
    printf("The total \"Heads\" tosses were: %d\n", hcounter);
    printf("The total \"Tails\" tosses were: %d\n", tcounter);
    
    return 0;
}

int
coins(void)
{
    
    hort = rand() % 2;
    
    return hort;
    
}





