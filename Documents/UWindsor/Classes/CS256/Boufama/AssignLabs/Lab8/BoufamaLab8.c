#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include<stdlib.h>
#include<time.h>

int getRandomInteger(int n){
    srand(time(NULL));  // initialize a seed
    return(rand() % n + 1);
}
void action(){};    // four-player game
void child(char *);
int main(int argc, char *argv[]){
    pid_t pids[5];
    char  pidNames[5][10]={"TATA", "TITI", "TOTO", "TUTU"};
    struct sigaction newAction, oldAction;
    int index;
    
    
    printf("This is a 4-players game with a referee\n");
    for(index=1; index<=4; index++)
        if((pids[index]=fork()) == 0) child(pidNames[index]);
    
    sleep(1);
    newAction.sa_handler = action;
    sigemptyset (&newAction.sa_mask);
    newAction.sa_flags = 0;
    sigaction (SIGUSR1, &newAction, &oldAction);
    while(1){
        index = getRandomInteger(4);
        printf("\nReferee: %s plays\n\n", pidNames[index]);
        kill(pids[index], SIGUSR1);
        pause();
    }
}
void child(char *s){
    int points=0;
    int dice;
    int n=10;
    struct sigaction newAction, oldAction;
    
    newAction.sa_handler = action;
    sigemptyset (&newAction.sa_mask);
    sigaction (SIGUSR1, &newAction, &oldAction);
    while(1){
        pause();        // block myself
        printf("%s: playing my dice\n", s);
        dice = getRandomInteger(n);
        printf("%s: got %d points\n", s, dice);
        points+=dice;
        printf("%s: Total so far %d\n\n", s, points);
        sleep(3);
        if(points >= 100){
            printf("%s: game over I won\n", s);
            kill(0, SIGTERM);
        }
        kill(getppid(), SIGUSR1);
    }
}