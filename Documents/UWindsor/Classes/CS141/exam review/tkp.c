//
//  tkp.c
//  
//
//  Created by Ryan Pearson on 1.5.13.
//
//

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int
main(void)
{
    char *s = "Ryan_Pearson";
    char ptr[100];
    char s1[100];
    strcpy (s1, s);
    char *first = malloc(100 * sizeof(char));
    char *last = malloc (100 * sizeof(char));
    int count = 0;
    first = strtok(s1, "_");
    
    while (first != NULL) {
        printf("%s\n", first);
        first = strtok(NULL, "_");
        if(count++ == 0)
            last = first;
        
    }
    sprintf(ptr, "%s %s", last, first);
    printf("%s\n", ptr);
    return 0;
}