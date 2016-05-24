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
    double total = 1000;
    int counter = 1;

    
    enum Status gameStatus; // give enum variable
    
    srand(time(NULL));      // randomize time
    printf("Let's get this started, you have $1000...\nPlace bet $");
    
    do
    {
            
        printf("Alright! Place your bet!\n$");
        scanf("%lf%c", &gl, &dummy);
        while (gl > total) {
            printf("I said your total was $%.2lf! Place bet. ", total);
            scanf("%lf%c", &gl, &dummy);
        }
        sum = rollDice();
    
        // return status of game
        switch (sum)
        {
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
        while (CONTINUE == gameStatus)
        {
            sum = rollDice();
        
            if (sum == myPoint)
                gameStatus = WON;

            else if (sum == 7)
                gameStatus = LOST;
            
        }
        if (gameStatus == WON)
        {
            //puts("Player Wins!");
            pcomments();
        }
        else if (gameStatus == LOST)
        {
            //puts("Player Looses!");
            gl *= (-1);
            ncomments();
        }
        
        // ask to play again
        printf("Would you like to play again?");
        scanf("%c%c", &yesno, &dummy);
        puts("");
        counter++;
        
        if (counter != 1)
            printf("You have $%.2lf left in the bank.\n", total + gl);
        
        total = wagering(gl, counter, total);
        
        if (total == 0)
            break;


        
    }while (yesno == 'Y' || yesno == 'y');
    
    if (total == 0)
        puts("Umm... i don't think so... your broke.\nGet your ass out of here.\n");
    else if (total < 500)
        printf("Well, at least your walking away with $%.2lf", total);
    else if (total < 1000)
        printf("You did better than most people... $%.2lf left.\n", total);
    else if (total < 1500)
        printf("Hey, not too bad! You have $%.2lf!\n", total);
    else if(total >= 1500)
        printf("Your an ace! Here's $%.2lf!\n", total);

    //printf("Your bank balance is: $%.2lf\n", total);
    
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


double
wagering(double bet, int count, double tot)
{

    if (count > 1)
    {
        tot += bet;
        //printf("You have $%.2lf remaining.FUNT\n", tot);
    }
    
    return tot;
}

void
pcomments(void)
{
    int comment = rand() % 6;
    switch (comment) {
        case 0:
            printf("Could this be a hot streak?!\n");
            break;
        case 1:
            printf("Nice Job! You Win!\n");
            break;
        case 2:
            printf("You got a horseshoe up your ass!\n");
            break;
        case 3:
            printf("Sweet!Winner!\n");
            break;
        case 4:
            printf("Winner Winner Chicken Dinner!\n");
            break;
        case 5:
            printf("WTF!!Your on a roll!\n");
            break;
        }
}

void
ncomments(void)
{
    int comment = rand() % 6;
    switch (comment) {
        case 0:
            printf("Player Loosses!\n");
            break;
        case 1:
            printf("HA HA HA! LOOSER!\n");
            break;
        case 2:
            printf("You got your ass handed to you!\n");
            break;
        case 3:
            printf("House wins!\n");
            break;
        case 4:
            printf("I love taking your money!\n");
            break;
        case 5:
            printf("Owned Bitch!!\n");
            break;
    }
}










