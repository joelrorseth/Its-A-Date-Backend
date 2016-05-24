//
//  nameread.c
//  
//
//  Created by Ryan Pearson on 1.5.13.
//
//

#include <stdio.h>
#define SIZE 30


int
main(void)
{
    char namel[SIZE];
    char namef[SIZE];
    
    FILE *dataptr = fopen("names.dat", "r");
    
    if (dataptr == NULL) {
        printf("No files present.\n");
    }
    else{
        fscanf(dataptr, "%29s%29s", namel, namef);
        while (!feof(dataptr)) {
            fprintf(stdout, "%s %s\n", namel, namef);
            fscanf(dataptr, "%29s%29s", namel, namef);
        }
    }
    
    rewind(dataptr);
    
    fscanf(dataptr, "%29s%29s", namel, namef);
    while (!feof(dataptr)) {
        fprintf(stdout, "%s %s\n", namel, namef);
        fscanf(dataptr, "%29s%29s", namel, namef);
    }
    
    
    fclose(dataptr);
    
    return 0;
}