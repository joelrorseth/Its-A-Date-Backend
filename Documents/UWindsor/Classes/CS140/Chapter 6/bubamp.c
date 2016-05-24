//
//  bubamp.c
//  
//
//  Created by Ryan Pearson on 1.5.13.
//
//

#include <stdio.h>
#define SIZE 10

int
main(void)
{
    //int a[SIZE] = { 2, 4, 6, 8, 89, 12, 10, 68, 45, 37};
    int a[SIZE] = { 87, 2, 9, 7, 78, 10, 12, 65, 45, 11};
    int pass, redpass;
    size_t i;
    int hold, swap = 0;
    int j = 1;
    int var = SIZE -1;
    
    printf("Data original: ");
    for (i = 0; i < SIZE; i++) {
        printf("%4d", a[i]);
    }
    puts ("");
    redpass = SIZE -1;
    
    for (pass = 1; pass < SIZE; pass++) {
        printf("\nPass %d sort  ", pass);
        // print function
        for (i = 0; i < SIZE; i++)
            printf("%4d", a[i]);
        swap = 0;
        for (i = 0; i < var; i++) {
            do {
                hold = 0;
                if (a[i] > a[i + 1]) {
                    hold = a[i];
                    a[i] = a[i + 1];
                    a[i + 1] = hold;
                }
                i++;
                
            }while(a[i] != a[var]);
            printf("\n%d\n", var);
            var--;
            if (hold == 0)
                break;
        }
        if (hold == 0)
            break;

        redpass--;
    }
    
    printf("\nData sorted:   ");
    for (i = 0; i < SIZE; i++) {
        printf("%4d", a[i]);
    }
    puts("");
}