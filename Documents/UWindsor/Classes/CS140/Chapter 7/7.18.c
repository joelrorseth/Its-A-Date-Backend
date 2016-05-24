//
//  7.18.c
//  
//
//  Created by Ryan Pearson on 1.5.13.
//
//

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define SUITS 4
#define FACES 13
#define CARDS 52

void shuffle(unsigned int wDeck[][FACES],const char *wFace[], const char *wSuit[]);

void shuffle(unsigned int wDeck[][FACES],const char *wFace[], const char *wSuit[])
{
    unsigned int row;
    unsigned int column;
    unsigned int card;
    int x = 0;
    
    for (card = 1; card <= CARDS; card++)
    {
        do {
            row = rand() % SUITS;
            column = rand() % FACES;

            if (x < 5) {
                printf("%5s of %-8s\n", wFace[column], wSuit[row]);
                x++;
            }
        } while (wDeck[row][column] != 0);
        
        wDeck[row][column] = card;
    }
}

int
main(void)
{
    const char *suits[SUITS] = {"Hearts", "Diamonds", "Clubs", "Spades"};
    const char *faces[FACES] = {"Ace", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten", "Jack", "Queen", "King"};
    
    unsigned int deck[SUITS][FACES];
    
    for (int x = 0; x < SUITS; x++) {
        for (int y = 0; y < FACES; y++) {
            deck[x][y] = 0;
        }
    }
    
    srand(time(NULL));
    
    shuffle(deck, faces, suits);
    
    return 0;
}