//
//  main2.c
//  
//
//  Created by Ryan Pearson on 1.5.13.
//
//

#include <stdio.h>

int
main(void)
{
    int c;
    
    if ( (c = getchar()) != EOF)
    {
        main();
        printf("%c", c);
    }

}