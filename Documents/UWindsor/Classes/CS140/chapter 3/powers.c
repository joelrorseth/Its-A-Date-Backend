//
//  powers.c
//  
//
//  Created by Ryan Pearson on 1.5.13.
//
//

#include <stdio.h>

int
main(void)
{
    //declare variables
    int n = 1;
    // print headline
    puts("N\t10*N\t100*N\t1000*N");
    puts("");
    // loop thru chart for examples
    while (n <= 10)
    {
        printf("%d\t%d\t%d\t%d\n", n, n * 10, n * 100, n * 1000);
        n++;
    }
    
    return 0;
}