//
//  exam2.c
//  
//
//  Created by Ryan Pearson on 1.5.13.
//
//

#include <stdio.h>
#include <string.h>


int
main(void)
{
    int a[] = {1, 3, 5, 9};
    int b[] =  {2, 4, 7, 8, 10, 12};
    int c[20];
    
    for (int x = 0; x < 20; x++) {
        c[x] = 0;
    }
    int hold;
    
    int y, x;
    for ( x = 0; x < 100; x++) {
        if (a[x] == '\0')
            break;
        else
            c[x] = a[x];
        }
    y = x;
    
    for ( x = 0; x < 100; x++) {
        if (b[x] == '\0')
            break;
        else
        {
            c[y] = b[x];
            y++;
        }
    }
    
    for ( x = 0; x < 10; x++) {
        for ( y = 0; y < 10; y++) {
            if (c[y] > c[y+1]) {
                hold = c[y];
                c[y] = c[y+1];
                c[y+1] = hold;
            }
        }
    }
    
    for (int x = 0; x < 10; x++) {
        printf("%d ", c[x]);
    }
    puts("");
    return 0;
}