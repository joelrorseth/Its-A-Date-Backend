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
double wagering(double bet, int count, double tot);
void pcomments(void);
void ncomments(void);


int
main(void)
{
    int sum = 0;                // set variable
    int myPoint;            // set variable
    char yesno, dummy = '\0';
    double gl, holder = 0;
    //long int total = 1000;
    int counter = 1;
    long int winsArray[21];
    long int closs = 0;
    long int lossArray[21];
    
    for (sum = 0; sum < 21; sum++) {
        winsArray[sum]= 0;
        lossArray[sum]= 0;
    }

    
    enum Status gameStatus; // give enum variable
    
    
    srand(time(NULL));      // randomize time
    //printf("Let's get this started, you have $1000...\nPlace bet $");
    
    for (long int x = 0; x < 10000; x++)
    {
        
        sum = rollDice();
    
        // return status of game
        switch (sum)
        {
            case 7:
            case 11:
                gameStatus = WON;
                winsArray[1]++;
                printf("1 - counter initial\n");
                counter = 0;
                break;
            
            case 2:
            case 3:
            case 12:
                gameStatus = LOST;
                lossArray[1]++;
                break;
            
            default:
                gameStatus = CONTINUE;
                myPoint = sum;
                printf("Point is %d\n", myPoint);
                counter++;
        }
        // if not won or lost repeat with new won lost rules
        while (CONTINUE == gameStatus)
        {
            sum = rollDice();
            counter++;
            if (sum == myPoint)
            {
                gameStatus = WON;
                //printf("%d- counter\n", counter);
                if (counter > 20)
                {
                    winsArray[20]++;
                    counter = 0;
                }
                else
                {
                    winsArray[counter]++;
                    printf("%d -> counter ryan\n", counter);
                    counter = 0;
                }
            }

            else if (sum == 7)
            {
                gameStatus = LOST;
                if (counter > 20)
                {
                    lossArray[20]++;
                    counter = 0;
                }
                else
                {
                    lossArray[counter]++;
                    printf("%d -> counter ryan\n", counter);
                    counter = 0;
                }
            }
        }
    
    }
    for (sum = 1; sum < 21; sum++) {
        printf("Wins- %d roll. -> %ld\tLosses -> %ld\n", sum, winsArray[sum], lossArray[sum]);
    }
    long int totalloss, totalwins = 0;
    for (sum = 1; sum < 21; sum++) {
        totalwins += winsArray[sum];
        totalloss += lossArray[sum];
    }
    
    printf("%ld- Wins total\n%ldLosses total\n", totalwins, totalloss);
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
