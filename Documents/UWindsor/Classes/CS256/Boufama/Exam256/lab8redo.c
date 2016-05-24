// lab8review

#include <unistd.h>
#include <signal.h>
#include <stdlib.h>
#include <time.h>
#include <stdio.h>

int getRandomInteger(int n){
    srand(time(NULL));  // initialize a seed
    return(rand() % n + 1);
}
void action(){};    // four-player game
void child(char *, struct sigaction);
int main(int argc, char *argv[]){
    
    pid_t pid[4];
    char *name[4]={"TOTO", "TITI", "TATA", "TUTU"};
    int random=0,i=0;
    // create structure for sigaction
    struct sigaction newAction, oldAction;
    // register handler to the new action
    newAction.sa_handler = &action;
    // clear the set
    sigemptyset(&newAction.sa_mask);
    // register items to catch
    sigaddset(&newAction.sa_mask, SIGTSTP);
    sigaddset(&newAction.sa_mask, SIGUSR1);
    // set signal options
    newAction.sa_flags = SA_RESTART;
    // call function to register sigaction
    sigaction(SIGUSR1, &newAction, &oldAction);
    
    printf("This is a 4-players game with a referee\n");
    for (; random<5; random++)
        if((pid[random]=fork())==0)
            child(name[random], newAction);
    
    sleep(1);
    while(1){
        random=rand()%4;
        printf("\nReferee: %s plays\n\n", name[random]);
        kill(pid[random], SIGUSR1);
        pause();
    }
}
void child(char *s, struct sigaction newAction){
    int points=0;
    int dice;
    int n=10;
    sigaction(SIGUSR1, &newAction, NULL);
    //signal(SIGUSR1, action);  // register handler
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