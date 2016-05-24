//
//  7.12.c
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

void shuffle(unsigned int wDeck[][FACES]);

void shuffle(unsigned int wDeck[][FACES])
{
    unsigned int row;
    unsigned int column;
    unsigned int card = 1;
    
    for (card = 1; card <= CARDS; card++)
    {
        do {
            row = rand() % SUITS;
            column = rand() % FACES;
            //printf("%d row\n%d column\n", row, column);
             //display blanks left while using random.
            //for (int x = 0; x < SUITS; x++) {
              //  for (int y = 0; y < FACES; y++) {
                //    printf("%d ", wDeck[x][y]);
                //}
                //puts("");
            //}
            //puts("\n\n");
        } while (wDeck[row][column] != 0);
        
        wDeck[row][column] = card;
    }
       /* for (int column = 0; column < FACES; column++) {
            for (row = 0; row < SUITS; row++) {
                wDeck[row][column] = card;
                card++;
            }
        }*/
    
    /*for (row = 0; row < SUITS; row++) {
        for (column = 0; column < FACES; column++) {
            wDeck[row][column] = card;
            card++;
        }
    }*/
    
}

void deal(unsigned int wDeck[][FACES], const char *wFace[], const char *wSuit[]);

void deal(unsigned int wDeck[][FACES], const char *wFace[], const char *wSuit[])
{
    void check (const int Deck[5], int *scr, int *highptr);
    void checkr (const int Deck[5], int *scr);
    void BubbleSort( int array[5]);
    size_t card;
    size_t row;
    size_t column;
    int columnarray[5];
    int rowarray[5];
    int holdarray[5];
    int i = 0;
    static int x = 1;
    static int y = 5;
    static int score1 = 0, score2 = 0;
    int *sc1ptr = &score1;
    int *sc2ptr = &score2;
    static int deal = 0;
    static int high1 = 0, high2 = 0;
    int *highptr1 = &high1;
    int *highptr2 = &high2;
    
    for (card = x; card <= y; card++) {
        for (row = 0; row < SUITS; row++) {
            for (column = 0; column < FACES; column++) {
                if (wDeck[row][column] == card) {
                    printf("%5s of %-8s\t%d\telement[%zd][%zd]\n", wFace[column], wSuit[row], wDeck[row][column], row, column);
                    columnarray[i] = column;
                    rowarray[i] = row;
                    i++;
                    
                }
            }
        }
    }

    for (i = 0; i < 5; i++) {
      printf("%d\t%d\n", rowarray[i], columnarray[i]);
    }
    
    if (deal == 0){
        check(columnarray, sc1ptr, highptr1);
        checkr(rowarray, sc1ptr);
        for (int i = 1; i < 5; i++) {
            holdarray[i] = columnarray[i];
        }
        x += 5;
        y += 5;
    }
    else
    {
        check(columnarray, sc2ptr, highptr2);
        checkr(rowarray, sc2ptr);
        printf("%d- Score 1\n", *sc1ptr);
        printf("%d- Score 2\n", score2);
    }
    if (score1 > score2 && deal == 1) {
        printf("Player 1 wins!\n\n");
    }
    else if (score2 > score1 && deal == 1) {
        printf("Player 2 wins!\n\n");
    }
    else if (score1 == score2 && deal == 1){
        if (*highptr1 == *highptr2) {
            i = 0;
            BubbleSort(columnarray);
            BubbleSort(holdarray);
            do
            {
                for (int x = 0; x < 5; x++) {
                    if (*highptr1 == holdarray[x]) {
                    *highptr1 = holdarray[x - 1];
                    }
                }
                    
                for (int x = 0; x < 5; x++) {
                    if (*highptr2 == columnarray[x]){
                        *highptr2 = columnarray[x-1];
                    }
                }
                i++;
            }while (*highptr1 == *highptr2 || i == 4);
            printf("%d- High1\n", *highptr1);
            printf("%d- High2\n", *highptr2);
        }
        if (*highptr1 < *highptr2) {
            printf("%d- High1\n", *highptr1);
            printf("%d- High2\n", *highptr2);
            printf("Player 2 wins!\n\n");
        }
        else if (*highptr2 < *highptr1){
            printf("%d- High1\n", *highptr1);
            printf("%d- High2\n", *highptr2);
            printf("Player 1 wins!\n\n");
        }
        else if (*highptr1 == *highptr2){
            printf("%d- High1\n", *highptr1);
            printf("%d- High2\n", *highptr2);
            printf("We have a draw!\n\n");
        }
    }
    deal++;
}


void check (const int Deck[5], int *scr, int *highptr)
{
    

    int pass, i, key, pair = 0;
    for (int x = 0; x < SUITS; x++)
    {
        if (Deck[x + 1] == (Deck[x] + 1)) {
            key++;
        }
            if(key == 4)
            {
                printf("You have a straight!\n\n");
                *scr = 5;
                return;
            }
    }
    
    int hold1, hold2 = 0;
    for (pass = 0; pass < 5; pass++)
    {
        key = 0;
        for (i = 0; i < 5; i++){
            if (Deck[pass] == Deck[i])
                key++;
        }
        if (key == 2)
        {
            pair++;
            if (hold1 == 0 && hold1 != Deck[pass]) {
                hold1 = Deck[pass];
            }
            else
                hold2 = Deck[pass];
        }
        if (key == 3)
        {
            printf("You have 3 of a kind!\n\n");
            *scr = 3;
            break;
        }
        if (key == 4) {
            printf("You have 4 of a kind!\n\n");
            *scr = 4;
            break;
        }

    }
    switch(pair){
        case 2:
            printf("You have a pair!\n\n");
            *scr = 1;
            break;
        case 4:
            printf("You have 2 pair!\n\n");
            *scr = 2;
            break;
    }
    
    for (int x = 0; x < 5; x++) {
        if (x == 0) {
            *highptr = Deck[x] +1;
        }
        else if(*highptr < Deck[x])
            *highptr = Deck[x] +1;
    }
}

void checkr (const int Deck[5], int *scr)
{
    
    int pass, i, key, pair = 0;

    for (pass = 0; pass < 5; pass++)
    {
        key = 0;
        for (i = 0; i < 5; i++){
            if (Deck[pass] == Deck[i])
                key++;
        }
        if (key == 5){
            printf("You have a flush!\n\n");
            *scr = 6;
        }
    }
    return;
}

/*
 Function: Sort array in designated order
 Input: one array, the size and integer order
 Output: nothing
 */
void BubbleSort( int array[5])
{
    int hold = 0;                   // holder variable
    
    for (int pass = 0; pass < 5; pass++)
    {
        hold = 0;       // re-initialize holder variable to check swap
        for(int x = 0; x < 5 - 1; x++)
        {
            if (array[x] > array[x + 1])
            {
                hold = array[x];
                array[x] = array[x + 1];
                array[x + 1] = hold;
            }
        }
        // kick out of loop if no swap
        if (hold == 0)
            return;
    }
}



int
main(void)
{
    const char *suits[SUITS] = {"Hearts", "Diamonds", "Clubs", "Spades"};
    const char *faces[FACES] = { "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten", "Jack", "Queen", "King", "Ace" };
    int pair, counter;
    int score;
    int *scptr;
    
    unsigned int deck[SUITS][FACES];
    
    for (int x = 0; x < SUITS; x++) {
        for (int y = 0; y < FACES; y++) {
            deck[x][y] = 0;
        }
    }
    
    srand(time(NULL));
    
    counter = 0;
    
    shuffle(deck);
    
    do {
        deal(deck, faces, suits);
        counter++;
    } while (counter < 2);
    
    
    return 0;
}