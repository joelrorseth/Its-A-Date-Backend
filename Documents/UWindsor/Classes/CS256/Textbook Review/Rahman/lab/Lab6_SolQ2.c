//
//  Lab6_SolQ2.c
//  
//
//  Created by Ryan Pearson on 2/10/2014.
//
//

#include <unistd.h>
#include <signal.h>
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

//signal handler
void action(int signo) { /*Just accept the signal */ }

int roll_dice(){
    return rand() % 10 + 1;
}

void play_game(char *, int);

int main()
{
    pid_t pid1, pid2;
    
    struct sigaction act;
    
    act.sa_handler = action;        //register signal handler
    act.sa_flags = 0;               //with no option
    sigaction(SIGUSR1, &act, NULL);//no default action
    
    printf("\nThis is a 2-players game with a referee\n");
    if((pid1 = fork()) == 0) play_game("Player 1", 1);
    if((pid2 = fork()) == 0) play_game("Player 2", 2);
    
    sleep(1);
    
    while(1)
    {
        printf("Referee: Player 1 plays\n\n");
        
        kill(pid1, SIGUSR1);
        pause();
        
        printf("Referee: Player 2 plays\n\n");
        
        kill(pid2, SIGUSR1);
        pause();
        
    }
}

void play_game(char *name, int player_number)
{
    int points = 0;
    int dice;
    
    srand(time(NULL) + player_number);
    
    while(1)
    {
        pause();
        
        printf("%s: playing my dice\n", name);
        dice = roll_dice();
        printf("%s: got %d points\n", name, dice);
        points += dice;
        printf("%s: Total so far %d\n\n", name, points);
        
        sleep(2);
        
        if(points >= 40)
        {
            printf("%s: Game over, I won!\n", name);
            kill(0, SIGTERM);
        }
        
        kill(getppid(), SIGUSR1);
    }
}