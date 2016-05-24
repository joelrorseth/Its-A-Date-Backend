//
//  put.c
//  
//
//  Created by Ryan Pearson on 1.5.13.
//
//

#include <stdio.h>


int
main(void)
{
    char d[20][20];
    int y = 0;
    
    while (!feof(stdin)) {
        fscanf(stdin, "%19s", d[y]);
        y++;
    }
    puts("");
    for (int x = 0; x < y; x++) {
        fprintf(stdout, "%s\n", d[x]);
    }
    
    puts(".");
    return 0;
}