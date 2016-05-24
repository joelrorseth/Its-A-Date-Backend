//
//  string.c
//  
//
//  Created by Ryan Pearson on 1.5.13.
//
//

#include <stdio.h>
#include <string.h>

void foo(char* bar)
{
    char c[12];
    
    memcpy(c, bar, strlen(bar));
}

int main(int argc, char* argv[])
{
    foo(argv[i]);
        
    return 0;
}