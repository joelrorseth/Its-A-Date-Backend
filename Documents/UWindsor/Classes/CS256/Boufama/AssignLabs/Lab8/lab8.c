/*
 *  Lab 8
 *  Ryan Pearson
 *  March 18, 2014
 *
 */

#include <unistd.h>
#include <signal.h>
#include <sys/signal.h>
#include <stdlib.h>
#include <time.h>
#include <stdio.h>

int getRandomInteger(int n){
    srand(time(NULL));  // initialize a seed
    return(rand() % n + 1);
}
void action(){};    // four-player game
void action2(){printf("Hey there!\n");}
void child(char *, struct sigaction);
int main(int argc, char *argv[])
{
    pid_t pid[4];
    int random, i=0;
    struct sigaction sa;
    sa.sa_handler = &action2;
    sa.sa_flags = SA_RESTART;
    sigemptyset(&sa.sa_mask);
    sigaddset(&sa.sa_mask,SIGUSR1);
    sigaddset(&sa.sa_mask, SIGTSTP);
    char *name[4]={"TOTO", "TITI", "TATA", "TUTU"};
    
    printf("This is a 4-players game with a referee\n");
    for (; random<5; random++)
        if ((pid[random]=fork())==0)
            child(name[random], sa);
    
    sleep(1);
    sigaction(SIGUSR1, &sa, NULL);
    //signal(SIGTSTP, SIG_IGN);           // causes the control Z signal to be ignored.
    while(1){
        random=rand()%4;
        printf("\nReferee: %s plays\n\n", name[random]);
        kill(pid[random], SIGUSR1);
        pause();
    }
}
void child(char *s, struct sigaction sa){
    int points=0;
    int dice;
    int n=10;
    //signal(SIGUSR1, action);  // register handler
    sigaction(SIGUSR1, &sa, NULL);
    //signal(SIGTSTP, SIG_IGN);
    while(1){
        pause();        // block myself
        printf("%s: playing my dice\n", s);
        dice = getRandomInteger(n);
        printf("%s: got %d points\n", s, dice);
        points+=dice;
        printf("%s: Total so far %d\n\n", s, points);
        sleep(3);
        if(points >= 25){
            printf("%s: game over I won\n", s);
            kill(0, SIGTERM);
        }
        kill(getppid(), SIGUSR1);
    }
}