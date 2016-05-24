//
//  asishinsertion.c
//  
//
//  Created by Ryan Pearson on 1.5.13.
//
//

#include <stdio.h>
#include <stdlib.h>
#define SIZE 20

void insertionA (int list[]);
void insertionD (int list[]);
void swap (int * x, int * y);


int
main(void)
{
    int numberlist[SIZE];
    int i, number;
    char order;
    
    printf("Please enter 20 integers: ");
    for(i = 0; i < 20; i++){
        
        if(!scanf("%d", &numberlist[i])){printf("Invalid input.\n"); return -1;}
    
    }
    scanf("%c", &order);
    printf("Would you like ascending or descending order? (a or d): ");
    if (!fscanf(stdin, "%c", &order)) { printf("Invalid Input\n"); return -1; }
    
    if (order == 'a')
        insertionA(numberlist);
    else if (order == 'd')
        insertionD(numberlist);
    else
        printf("Invalid selection.\n");
    
    
    return 0;
}

void insertionA (int list[])
{
    int i = 1;
    int j;
    int temp;
    
    while (i <= SIZE-1) {
        temp = list[i];
        j = i;
        while (j > 0 && list[j-1] > temp) {
            swap(&list[j], &list[j-1]);
            j = j-1;
        }
        ++i;
    }
    for (i = 0; i < SIZE; i++) {
        printf("%d ", list[i]);
    }
    printf("\n");
    
}

void insertionD (int list[])
{
    int j;
    int i = 1;
    
    while (i < SIZE) {
        //temp = list[i];
        j = i;
        while (j > 0 && list[j-1] < list[i]) {
            swap(&list[j], &list[j-1]);
            j--;
        }
        i++;
    }
    
    for (i = 0; i < SIZE; i++) {
        printf("%d ", list[i]);
    }
    printf("\n");
    
}

void swap (int *x, int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
    
}

