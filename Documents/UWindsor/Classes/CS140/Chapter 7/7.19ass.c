//
//  7.19.c
//  
//
//  Created by Ryan Pearson on 1.5.13.
//
//

#include <stdio.h>
#define SIZE 100
#define TEST 2

char test (char s1,  char s2);

char test (char s1,  char s2)
{
        while (s1 != '\0')
            ++s1;
        for (; (s1 = s2); ++s1, ++s2) ;
}

void swap (char *s1, char *s2);

void swap (char *s1, char *s2)
{
    while (*s1 != '\0')
        ++s1;
    for (; (*s1 = *s2); ++s1, ++s2) ;
    
}


int
main(void)
{
    char complete[SIZE/2][SIZE];
    char test1;
    char test2;
    int x = 0, y = 0, z = 0;
    
    do {
        // scan for # of values
        scanf("%d", &x);
        if (x != 0) {
            for (z = 0; z < x; z++) {
                scanf("%99s", complete[z]);
            }
        }
        for (y = 0; y < x - 1; y++) {
            test1 = test(complete[y], complete[y+1]);
            test2 = test(complete[y+1], complete[y]);
            if (test2 > test1) {
                swap(complete[y+1], complete[y]);
            }
        }
        
        for (z = 0; z < x; z++) {
            printf("%s", complete[z]);
        }
        puts("");
    } while (x != 0);

    return 0;
}