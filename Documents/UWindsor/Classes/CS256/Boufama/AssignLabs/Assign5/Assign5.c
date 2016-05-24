//
//  Assign5.c
//  Name: Ryan Pearson
//  SID: 103965059
//  Date: 03-11-2014
//

#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <sys/signal.h>
#include <sys/wait.h>
#include <time.h>

void action(){};
void child(char *, int *);
void printStatus(char*, int, int*);
int totalCheck(char*, int*, int*);

int main(int argc, char *argv[]){
    int i=6, total=0, roll=0;
    static int pchild1=0, pchild2=0, pchild3=0;
    pid_t pid1, pid2, pid3;
    FILE *fp;

    // ignore SIGINT(control C) and SIGTSTP (control Z)
    signal(SIGINT, SIG_IGN);
    signal(SIGTSTP, SIG_IGN);
    
    printf("Hello this is a 2-players game with a referee\n");
    printf("Please enter the winning total: ");
    scanf("%d", &total);
    
    if((pid1=fork()) == 0)
        child("TOTO", &pchild1);
    
    if((pid2=fork()) == 0)
        child("TITI", &pchild2);
    
    if((pid3=fork()) == 0)
        child("DIDI", &pchild3);
    
    while(1){
        // use sleep in code to ensure txt file is created
        // by child before it is looked for by parent process
        // scan int from value.txt file created by child
        // TOTO's code
        printf("\nReferee: TOTO plays\n\n");
        kill(pid1, 16);
        signal(16, action);
        sleep(1);
        if ((fp=fopen("value.txt", "r"))==NULL) {
            perror("Invalid file read open");
            exit(1);
        }
        fscanf(fp, "%d\n", &roll);
        pchild1+=roll;
        printStatus("TOTO", roll, &pchild1);
        fclose(fp);
        
        if(totalCheck("TOTO", &pchild1, &total));
        pause();
        
        // TITI's code
        printf("\nReferee: TITI plays\n\n");
        kill(pid2, 16);
        signal(16, action);
        sleep(1);
        if ((fp=fopen("value.txt", "r"))==NULL) {
            perror("Invalid file read open");
            exit(1);
        }
        fscanf(fp, "%d\n", &roll);
        pchild2+=roll;
        printStatus("TITI", roll, &pchild2);
        fclose(fp);
        
        if(totalCheck("TITI", &pchild2, &total));
        pause();
        
        // DIDI's code
        printf("\nReferee: DIDI plays\n\n");
        kill(pid3, 16);
        signal(16, action);
        sleep(1);
        if ((fp=fopen("value.txt", "r"))==NULL) {
            perror("Invalid file read open");
            exit(1);
        }
        fscanf(fp, "%d\n", &roll);
        pchild3+=roll;
        printStatus("DIDI", roll, &pchild3);
        fclose(fp);
        
        if(totalCheck("DIDI", &pchild3, &total));
        pause();
    }
}

void child(char *s, int *points){
    int dice;
    long int ss=0;
    FILE *fp;
    
    while(1){
        signal(16, action);
        pause();
        printf("%s: playing my dice\n", s);
        srand(time(NULL));
        dice = rand()%10+1;
        //dice =(int) time(&ss)%10 + 1; // use other code so more random
        if ((fp=fopen("value.txt", "w"))==NULL) {
            perror("Invalid file write open");
            exit(1);
        }
        fprintf(fp, "%d\n", dice);
        fclose(fp);
        sleep(2);
        kill(getppid(), 16);
    }
}

// function to print totals
void printStatus(char *name, int roll, int *total){
    printf("%s: got %d point%s\n", name, roll, roll>1?"s":"");
    printf("%s: Total so far %d\n",name, *total);
}

// function to track total, declare winner and terminate program
int totalCheck(char *name, int *ctotal, int *total){
    if (*ctotal>=*total) {
        printf("%s: game over I won\n", name);
        remove("value.txt");
        kill(0, SIGTERM);
    }
    return 0;
}