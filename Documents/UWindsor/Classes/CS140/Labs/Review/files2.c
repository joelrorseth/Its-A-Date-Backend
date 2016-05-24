//
//  files2.c
//  
//
//  Created by Ryan Pearson on 1.5.13.
//
//

#include <stdio.h>


int
main(void)
{
    int x;
    int y;
    
    FILE *fptr = fopen("numbers.dat", "r");
    
    if (fptr == NULL) {
        printf("no dice\n");
    }
    else{
        fscanf(fptr, "%d%d", &x, &y);
        while (!feof(fptr)) {
            printf("%d %d\n", x, y);
            fscanf(fptr, "%d%d", &x, &y);
        }
    }
    
    fclose(fptr);
    return 0;
}