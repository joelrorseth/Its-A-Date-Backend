//
//  exam3.c
//  
//
//  Created by Ryan Pearson on 1.5.13.
//
//

#include <stdio.h>
#define SIZE 100

int
main(void)
{
    int array[SIZE];
    int num = 0;
    int x = 0;
    int n = 0;
    int counter = 0;
    FILE *fp;
    for (x = 0; x < SIZE; x++) {
        array[x] = 0;
    }
    
    fp = fopen("fib.txt", "r");
    if (fp == NULL) {
        fp = fopen("fib.txt", "w");
        fprintf(fp, "0 1 1");
        fclose(fp);
        printf("txt activated\n3 numbers\n");
        return 0;
    }

    else{
        
        x = 0;
        printf("Please enter n: ");
        scanf("%d", &n);
        while (!feof(fp)) {
            fscanf(fp, "%d", &num);
            array[x] = num;
            x++;
        }
        fclose(fp);
        
        x -= 1;

        while (n >= 0) {
            array[x + 1] = array[x] + array[x-1];
            n--;
            x++;
        }
        fp = fopen("fib.txt", "w");
        for (int y = 0; y < x; y++) {
            if (array[x - 1] == array[y]) {
                fprintf(fp, "%d", array[y]);
            }
            else
                fprintf(fp, "%d ", array[y]);
        }
        fclose(fp);
        printf("variable elements is %d\n", x);
    }
    return 0;
}