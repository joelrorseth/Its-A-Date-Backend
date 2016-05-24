//
//  Title: Lab3-1
//  Date: July 21, 2013
//  Name: Ryan Pearson
//  ID: 103965059
//  Program: Use arrays to perform various functions on this item
//

#include <stdio.h>
#include <string.h>
#include "printarray.h"
#include "DisplayMenu.h"

//void sort (const char *suits[4], int order);
//void sort (const char *suits[4], int order)
void swap (int *e1, int *e2);
void swap (int *e1, int *e2)
{
    int *hold = e1;
    e1 = e2;
    e2 = hold;
}
    
int
main(void)
{
    char choice;            // user selection variable
    char *suit[5] = { "Hearts", "Diamonds", "Clubs", "Spades", "                        " };
    char element1[1][100];
    char element2[] = "Diamonds";
    //void (*function[1])(const char *[], int) = { sort };
    // Display menu
    printf("Before:\n");
    for (int x = 0; x < 4; x++) {
        printf("%s\n", suit[x]);
    }
    for (int pass = 1; pass < 4; pass++) {
        for (int x = 0; x < 4; x++) {
            printf("%d\n",(strcmp(suit[x], suit[x+1])));
            if (strcmp(suit[x], suit[x+1]) > 0){
                element1 = suit[x];
                suit[x] = suit[x+1];
                suit[x+1] = element1;
            }
        }
    }

    for (int x = 0; x < 4; x++) {
        printf("%s\n", suit[x]);
    }
    
    printf("\nAfter:\n%s\n%s\n", suit[0], suit[1], suit[2], suit[3]);

    do  {
        DisplayMenuLab3();
        printf("Please enter your selection: ");
    }while ((choice = getchar()) != 'g');
    
    
    return 0;
}
