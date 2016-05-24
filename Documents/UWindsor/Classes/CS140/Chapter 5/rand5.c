//
//  rand5.c
//  
//
//  Created by Ryan Pearson on 1.5.13.
//
//

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int
main(void)
{
    srand (time(NULL));           // set randomization
    int a = rand() % 2 + 1;
    int b = rand() % 100 + 1;
    int c = rand() % 10;
    int d = rand() % 12 + 1000;
    int e = rand() % 3 - 1;
    int f = rand() % 15 - 3;          // declare int for questions
    //int g = (rand() % 10 + 2 ) / 2 * 2;
    //int h = (rand() % 10 + 1 ) / 2 * 2 + 3;
    int g;
    int h;
    int j;
    
        printf("a. -> %d\n", a);
        printf("b. -> %d\n", b);
        printf("c. -> %d\n", c);
        printf("d. -> %d\n", d);
        printf("e. -> %d\n", e);
        printf("f. -> %d\n\n", f);
        printf("g. -> %d\n\n", g);
    for (int i = 1; i <= 100; i++)
    {
        g = (rand() % 10 + 2) /2 *2;
        printf("g. -> %d\n\n", g);
    }

    for (int i = 1; i <= 100; i++)
    {
        h = (rand() % 5) *2 +3;
        printf("h. -> %d\n\n", h);
    }
    for (int i = 1; i <= 100; i++)
    {
        j = (rand() % 5) * 4 + 6;
        printf("j. -> %d\n\n", j);
    }
    return 0;
}