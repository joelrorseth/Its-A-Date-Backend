//
//  files.c
//  
//
//  Created by Ryan Pearson on 1.5.13.
//
//

#include <stdio.h>


int
main(void)
{
    int x = 0;
    int y = 0;
    
    FILE *fptr = fopen("numbers.dat", "w");
    
    if (fptr == NULL) {
        printf("no dice\n");
    }
    else{
        puts("Enter x and y: ");
        scanf("%d%d", &x, &y);
        while (!feof(stdin)) {
            fprintf(fptr, "%d %d\n", x, y);
            scanf("%d%d", &x, &y);
        }
    }
    fclose(fptr);
    puts("");
    fptr = fopen("numbers.dat", "r");
    
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
}