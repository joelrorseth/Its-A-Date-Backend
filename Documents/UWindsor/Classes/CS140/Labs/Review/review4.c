//
//  review4.c
//  
//
//  Created by Ryan Pearson on 1.5.13.
//
//

#include <stdio.h>
#include <time.h>
#include <stdlib.h>

void drawsquare(int *xptr);
void drawsquare(int *xptr)
{
    int y, z;
    
    for (y = 0; y < *xptr; y++) {
        for (z = 0; z < *xptr; z++) {
            printf("* ");
        }
        puts("");
    }
}

void drawtriangle(int *xptr);
void drawtriangle(int *xptr)
{
    int y, z;
    
    for (y = 1; y <= *xptr; y++) {
        z = 1;
        while (z <= y) {
            printf("*");
            z++;
        }
        puts("");
    }
    
    
    
}

int
main(void)
{
    int x = 0, y = 0, z = 0, loop = 3;
    char dummy;
    srand(time(NULL));
    
    
    
    do{
    printf("Please enter an integer between 1 and 10: ");
        scanf("%d", &x);
        loop--;
        if ((x < 1 && loop != 0) || (x > 10 && loop != 0))
        {
            printf("You have entered an invalid entry, %d attempts left, try again!\n", loop);
        }
        else if ((x < 1 && loop == 0) || (x > 10 && loop == 0))
        {
            printf("You have entered an invalid entry! Goodbye!\n");
        }
        else if(loop != 0){
            printf("%d: ", x);
            while (x != 0) {
                printf("*");
                x--;
            }
            puts("");
            loop = 0;
        }
    }while(loop != 0);
    
    printf("Please enter an integer for n and m (n<m): ");
    scanf("%d%d", &x, &y);
    
    if (x >= y) {
        printf("Invalid input. Goodbye.\n");
        return 1;
    }
    
    for (z = x; z <= y; z++) {
        printf("%d ", z);
    }
    puts("");
    
    // increment by 2
    z = x;
    if (z % 2 == 0) {
        z += 1;
    }
    for (; z <= y; z += 2)
        printf("%d ", z);
    puts("");
    
    
    // increment by 5
    z = x;
    
    if (z % 5 != 0){
        z = z + (5 - (z % 5));
    }
    for (; z <= y; z+=5) {
        printf("%d ", z);
    }
    puts("");
    // from y to x
    
    for (; y >= x; y--) {
        printf("%d ", y);
    }
    puts("");
    
    // question 3
    
    
    printf("Please enter a number between 1 & 10: ");
    scanf("%d", &x);
    
    if (x < 1 || x > 10) {
        printf("Invalid Input!");
        return 1;
    }
    
    for (y = 1; y <= x; y++) {
        printf("%d ", rand() % 49 + 1);
    }
    
    puts("");
    
    
    // draw shapes
    do {
    printf("Please enter an integer between 1 and 10: ");
    scanf("%d", &x);
    }while (x < 1 || x > 10);
    puts("\n\n");
    drawsquare(&x);
    puts("\n\n");
    drawtriangle(&x);
    puts("");
    return 0;
}