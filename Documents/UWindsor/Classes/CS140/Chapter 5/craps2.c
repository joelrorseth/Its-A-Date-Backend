//
//  craps.c
//  
//
//  Created by Ryan Pearson on 1.5.13.
//
//

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//enum status
enum Status {CONTINUE, WON, LOST};

int rollDice(void); // function prototype


int
main(void)
{
    int sum;                // set variable
    int myPoint;            // set variable
    int yesno = 1;

    
    enum Status gameStatus; // give enum variable
    
    srand(time(NULL));      // randomize time
    
    do{
        
        sum = rollDice();       // first roll
    
        
        // return status of game
        switch (sum) {
            case 7:
            case 11:
                gameStatus = WON;
                break;
            
            case 2:
            case 3:
            case 12:
                gameStatus = LOST;
                break;
                
            default:
                gameStatus = CONTINUE;
                myPoint = sum;
                printf("Point is %d\n", myPoint);
        }
    
        // if not won or lost repeat with new won lost rules
        while (CONTINUE == gameStatus){
            sum = rollDice();
        
            if (sum == myPoint)
                gameStatus = WON;
            else if (sum == 7)
                gameStatus = LOST;
            
        }
        if (gameStatus == WON)
            puts("Player Wins!");
        else
            puts("Player Looses!");
        
        // ask to play again
        printf("Would you like to play again?");
        scanf("%d", &yesno);
        //yesno = getchar();
        puts("");
        
        
    } while (yesno == 1);

    return 0;
}

int rollDice(void)
{
    int die1;
    int die2;
    int workSum;
    
    die1 = rand() % 6 + 1;
    die2 = rand() % 6 + 1;
    workSum = die1 + die2;
    
    printf("Player rolled a %d + %d = %d\n", die1, die2, workSum);
    return workSum;
}




