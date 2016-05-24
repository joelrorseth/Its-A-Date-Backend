//
//  name.c
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
    
    FILE *dataptr = fopen("names.dat", "a");
    
    if (dataptr == NULL) {
        printf("No such file.\n");
    }
    else{
        puts("Please enter last name, followed by a space or return then first name");
        printf(":");
        scanf("%29s%29s", namel, namef);
        while (!feof(stdin)) {
            fprintf(dataptr, "%s, %s\n", namel, namef);
            printf(":");
            scanf("%29s%29s", namel, namef);
        }
    }
    
    fclose(dataptr);
    return 0;
}