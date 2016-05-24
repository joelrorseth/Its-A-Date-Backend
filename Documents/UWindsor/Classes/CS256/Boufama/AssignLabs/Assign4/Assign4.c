//
//  Assign4r.c
//  Ryan Pearson
//  SID: 103965059
//  Date: 03-06-2014
//

#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>

pid_t myFork();
int readArgs(char *, char *[][20], int ampersand[20][20]);
void reset(char *[][20], int [20][20]);
int main(int argc, char *argv[]){
    pid_t pid;
    char line[255];
    char *argList[20][20];
    int status, amp[20][20], x=0, value, command, arg;
    
    // initialize pointer to double scripted arrays to NULL!!!
    // initialize amp array to 0
    // THIS CAUSED A TON OF PROBLEMS not being here!!!!
    reset(argList, amp);
    
    printf("This program executes commands/programs for you\n");
    while(1)
    {
        printf("Enter CTR-C to exit, or enter\n");
        printf("a program name with its arguments> ");
        fgets(line, 255, stdin);
        value=readArgs(line, argList, amp);
        
        for (command=0; command <= value; command++) {
            if((pid = myFork()) == -1){
                perror("impossible to fork");
                exit(1);
            }
            
            if(pid > 0){ // This is the parent
                if(amp[command][0]){ // Background execution
                    printf("Process [%d]\n", pid);
                    waitpid(pid, &status, WNOHANG);
                }
                else{
                    waitpid(pid, &status, 0);
                    printf("My child has terminated\n");
                }
            }
            else{ // this is the child
                if (argList[command][0]!=NULL){
                    printf("Executing %s %s\n", argList[command][0], amp[command][0] == 1 ? "in background\n" : "");
                    if(execvp(argList[command][0], argList[command])==-1){
                        perror("child Process");
                        exit(22);
                    }
                }
            }
        }
        // reset values in argList to NULL and values in amp array to 0
        reset(argList, amp);
    }
    exit(0);
}
pid_t myFork(){
    static int count=0;
    if(count++ <= 20)
        return(fork());
    else
        return(-1);
}
int readArgs(char *line, char *argList[][20], int ampersand[20][20]){
    
    if (strcmp(line, "\n")==0)
        return 0;
    
    int value=0;
    int argPos = 0;
    char *token;
    token = strtok(line, " \n");
    while (token!=NULL) {
        if (strcmp(token,";") == 0){
            argList[value][argPos] = NULL;
            ++value;
            argPos=0;
        }
        else if(strcmp(token, "&;")==0){
            ampersand[value++][0]=1;
            argPos=0;
        }
        else{
            // ensure enough room for \0
            argList[value][argPos]= (char *) malloc(strlen(token)+1);
            strcpy(argList[value][argPos],token);
            argList[value][argPos][strlen(token)]='\0';         // append \0 to end of string.
            
            // capture & attached to word and as single element, reset to null if attached to word
            if (argList[value][argPos][strlen(token)-1]=='&' || argList[value][argPos][strlen(token)-2]=='&'){
                if (strlen(token)==1)
                    ampersand[value-1][argPos-1]=1;
                else
                    ampersand[value][argPos]=1;
                // this checks if the & precedes a ; in token
                if (argList[value][argPos][strlen(token)-2]=='&')
                    argList[value][argPos][strlen(token)-2]='\0';
                else
                    argList[value][argPos][strlen(token)-1]='\0';
            }
            
            // if blank entry set to NULL else strcat appends 2nd arguement then \0 to string.
            if (strlen(argList[value][argPos])==0)
                argList[value][argPos++]=NULL;
            else
                strcat(argList[value][argPos++], "");
            
            // catch if ; is tied to end of word and reset counts.
            if (argList[value][argPos-1][strlen(token)-1]==';') {
                argList[value][argPos-1][strlen(token)-1]='\0';
                value++;
                argPos=0;
            }
        }
        token=strtok(NULL, " \n");
    }
    return(value);
}

// function to reset elements of arglist array and ampersand array.
// input both arrays and return nothing
void reset(char *argList[][20], int amp[20][20]){
    int command, arg;
    for (command = 0; command < 20; ++command)
        for (arg = 0; arg < 20; ++arg){
            if (argList[command][arg] != NULL)
                argList[command][arg]=NULL;
            amp[command][arg]=0;
        }
    
}