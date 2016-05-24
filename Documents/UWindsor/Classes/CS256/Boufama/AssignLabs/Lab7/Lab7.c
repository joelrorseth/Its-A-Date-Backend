//
//  Assign5.c
//  
//
//  Created by Ryan Pearson on 03-11-2014.
//
//

#include <stdio.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include <time.h>

int getRandomInteger(int n){
    // use srand in function so it doesn't copy same values for each player.
    srand(time(NULL));
    return rand()%++n;

}
void action1(){
    printf("\nReferee: ");
}
void action2(){};
void child(char *);

int main(int argc, char *argv[]){
    pid_t pid1, pid2, pid3, pid4;
    //srand(time(NULL));                // don't use here, use in function
    
    printf("This is a 4-player game with a referee\n");
    if((pid1=fork()) == 0) child("TOTO");
    if((pid2=fork()) == 0) child("TITI");
    if((pid3=fork()) == 0) child("DODO");
    if((pid4=fork()) == 0) child("DIDI");
    
    sleep(1);
    signal(SIGUSR1, action1);
    while(1){
        printf("TOTO plays\n\n");
        kill(pid1, SIGUSR1);
        pause();
        printf("TITI plays\n\n");
        kill(pid2, SIGUSR1);
        pause();
        printf("DODO plays\n\n");
        kill(pid3, SIGUSR1);
        pause();
        printf("DIDI plays\n\n");
        kill(pid4, SIGUSR1);
        pause();
    }
}
void child(char *s){
    int points=0;
    int dice, n=10;
    
    while(1){
        signal(SIGUSR1, action2);  // block myself
        pause();
        printf("%s: playing my dice\n", s);
        dice = getRandomInteger(n);
        printf("%s: got %d points\n", s, dice);
        points+=dice;
        printf("%s: Total so far %d\n\n", s, points);
        sleep(1);
        if(points >= 25){
            printf("%s: game over I won\n", s);
            kill(0, SIGTERM);
        }
        kill(getppid(), SIGUSR1);
    }
}