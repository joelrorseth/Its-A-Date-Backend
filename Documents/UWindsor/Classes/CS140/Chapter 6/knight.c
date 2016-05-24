//
//  knight.c
//  
//
//  Created by Ryan Pearson on 1.5.13.
//
//

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define SIZE 8

enum move {NONVALID, VALID};
enum move orient;
int moves = 0;

int moving(int board[SIZE][SIZE]);

int moving(int board[SIZE][SIZE])
{
    int currentRow = 0;
    int currentColumn = 0;
    int moveNumber, loopcounter = 0;
    int counter = 1;
    int rowvar, colvar = 0;
    
    moveNumber = rand() % 8;
    board[currentRow][currentColumn] = 1;
    
    int horizontal[SIZE] = {2, 1, -1, -2, -2, -1, 1, 2};
    int verticle[SIZE] = {-1, -2, -2, -1, 1, 2, 2, 1};
    
    for (int x = 0; x < 64; x++)
    {
        moveNumber = rand() % 8;
        loopcounter = 0;
        
        do
        {
            orient = VALID;
            rowvar = currentRow + verticle[moveNumber];
            colvar = currentColumn + horizontal[moveNumber];
            
            // check if row variable is still on board
            if (rowvar < 0 || rowvar > 7) {
                printf(" non valid row\n");
                orient = NONVALID;
            }
            
            // check if column variable is still on board
            if (colvar < 0 || colvar > 7) {
                orient = NONVALID;
                printf("non valid column \n");
            }
            
            // check if board has already been changed to 1
            if (board[rowvar][colvar] == 1)
            {
                printf("Nonvalid location (= 1)\n");
                orient = NONVALID;
            }
            
            // check valid move and if initial time set to movenumber to zero to
            // go thru the list of moves to check validity.
            if (orient == NONVALID && loopcounter == 0)
                moveNumber = 0;
            
            // increase until you reach the final move then escape loop
            if (orient == NONVALID && loopcounter < 8)
                moveNumber++;
            loopcounter++;
            
        }while (orient == NONVALID && loopcounter != 8);
        
        // if valid assign new location and mark board as 1
        // print board to track results, reset counters and track loops
        printf("Valid!\nOut\n");
        if (orient == VALID)
        {
            currentRow += verticle[moveNumber];
            currentColumn += horizontal[moveNumber];
            board[currentRow][currentColumn] = 1;
            counter++;
            loopcounter = 0;
            //for (int x = 0; x < SIZE; x++) {
              //  for (int y = 0; y < SIZE; y++) {
                //    printf("%d ", board[x][y]);
                //}
                //puts("");
            //}
        }
        
        // if 64 moves not met with no more valid moves, return counter
        if (orient == NONVALID)
            return counter;
    
    }
    
    printf(" stopped at max counter = %d\n", counter);
    return counter;
    
}



int
main(void)
{
    srand(time(NULL));
    int board[SIZE][SIZE];
    int counter, tries = 0;
    int values[64];
    
    for (int x = 0; x < 64; x++) {
        values[x] = 0;
    }
    do
    //for (int x = 0; x < 10000; x++)
    {
    for (int x = 0; x < SIZE; x++) {
        for (int y = 0; y < SIZE; y++) {
            board[x][y] = 0;
        }
    }
        counter = moving(board);
        values[counter]++;
        tries++;
    }while(counter != 64);
    for (int x = 0; x < 64; x++) {
        printf("counter element[%d] = %d\n", x + 1, values[x]);
    }
    
    printf("%d- tries. Stopped- only nonvalid moves remain.\n", tries);
    
    for (int x = 0; x < SIZE; x++) {
        for (int y = 0; y < SIZE; y++) {
            printf("%d ", board[x][y]);
        }
        puts("");
    }
    return 0;
}