//
//  hare.c
//  
//
//  Created by Ryan Pearson on 1.5.13.
//
//

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define SIZE 70

void movehare(int *harptr);

void movehare(int *harptr)
{
    int move = rand() % 10 + 1;
    switch (move) {
        case 1:
        case 2:
            *harptr += 0;
            break;
        case 3:
        case 4:
            *harptr += 9;
            break;
        case 5:
            *harptr -= 12;
            break;
        case 6:
        case 7:
        case 8:
            *harptr += 1;
            break;
        case 9:
        case 10:
            *harptr -= 2;
    }
    
}

void movetort(int *torptr);

void movetort(int *torptr)
{
    int move = rand() % 10 + 1;
    switch (move) {
        case 1:
        case 2:
        case 3:
        case 4:
        case 5:
            *torptr += 3;
            break;
        case 6:
        case 7:
            *torptr -= 6;
            break;
        case 8:
        case 9:
        case 10:
            *torptr += 1;
    }
    
}

int
main(void)
{
    srand(time(NULL));
    int hill[SIZE];
    int x;
    int finish = 0;
    int hare = 1;
    int tort = 1;
    int *hareptr = &hare;
    int *tortptr = &tort;
    int harecounter = 0;
    int tortcounter = 0;
    for (int y = 0; y < 100; y++) {
        hare = 1;
        tort = 1;
        finish = 0;
    printf("BANG!!!\nAND THEY'RE OFF!!!\n");
    do {
        movehare(hareptr);
        if (*hareptr < 1)
            *hareptr = 1;
        //printf("%d hare\n", hare);
        movetort(tortptr);
        if (*tortptr < 1)
            *tortptr = 1;
        //printf("%d tortoise\n", tort);
        
        for (x = 0; x < SIZE; x++) {
            if (hare == x && tort == x)
                printf("%s", "OUCH!");
            else if (hare == x)
                printf("%s", "H ");
            else if (tort == x)
                printf("%s", "T ");
            else
                printf("%s", "_ ");
        }
        puts("");
        if (hare > SIZE){
            finish = 1;
            printf("Hare wins.\n");
            harecounter++;
        }
        if (tort > SIZE){
            finish = 1;
            printf("Tortoise wins.\n");
            tortcounter++;
        }
    } while (finish != 1);
        printf("%d- hare\n", harecounter);
        printf("%d- tortoise\n", tortcounter);
    }
    return 0;
}