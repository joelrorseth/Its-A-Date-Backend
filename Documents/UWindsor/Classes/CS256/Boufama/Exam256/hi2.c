//
//  hi2.c
//  
//
//  Created by Ryan Pearson on 04-12-2014.
//
//

#include <stdio.h>
#include <unistd.h>

int
main(void)
{
    int i;
    for(i=1; i<=4; i++)
        fork();
    printf("bye ");
    
    
}