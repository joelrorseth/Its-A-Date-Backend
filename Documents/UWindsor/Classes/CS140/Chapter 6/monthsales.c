//
//  monthsales.c
//  
//
//  Created by Ryan Pearson on 1.5.13.
//
//

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define SPEOPLE 5
#define PRODUCTS 6

void randomizeArray(int monthsales[][PRODUCTS]);
/*
 Function: Randomize array, days represents how many times// will sum elements
 input: Array and sizes
 output: nothing
 */
void randomizeArray(int monthsales[][PRODUCTS])
{
    int value, days = 0;
    int person, item;
    
    printf("How many days in the month? ");
    scanf("%d", &days);
    for (int a = 0; a < days; a++) {
        
        for(person = 1; person < 5; person++){
            for (item = 1; item < 6; item++) {
                value = rand() % 100;
                printf("value- %d, person %d, item %d\n", value, person, item);
                monthsales[person][item] += value;
            }
        }
    }
    puts("");
    return;
}

void printArray(int monthsales[][PRODUCTS]);
/* 
 Function: prints array with totals for columns and rows
 input: one array and size
 output: nothing.
 */
void printArray(int monthsales[][PRODUCTS])
{
    int i, x, total;
    for (i = 1; i < SPEOPLE; i++) {
        printf("%zd\t\t", i);
        total = 0;
        
        for (x = 1; x < PRODUCTS; x++) {
            printf("%d\t\t", monthsales[i][x]);
        }
        for (x = 1; x < PRODUCTS; x++) {
            total += monthsales[i][x];
        }
        printf("$%d", total);
        puts("");
    }
    
    for (int z = 1; z < PRODUCTS; z++) {
        if (z == 1) {
            printf("Product Total:\t");
        }
        total = 0;
        for (int a = 1; a <= SPEOPLE; a++) {
            if (a == 5) {
                printf("$%d\t\t", total);
            }
            total += monthsales[a][z];
        }
        
    }
    puts("");
}


int
main(void)
{
    size_t i, x;                        // counter
    int total, psum = 0;
    int days = 0;
    
    srand(time(NULL));
    
    int monthsales[SPEOPLE][PRODUCTS];
    
    //initialize array to zero
    for (i = 0; i < SPEOPLE; i++) {
        for (x = 0; x < PRODUCTS; x++) {
            monthsales[i][x] = 0;
        }
    }
    
    randomizeArray(monthsales);
    
    printf("Salesman\tProduct1\tProduct2\tProduct3\tProduct4\tProduct5\tSalesman Total\n");
    
    printArray(monthsales);
    
    return 0;
}