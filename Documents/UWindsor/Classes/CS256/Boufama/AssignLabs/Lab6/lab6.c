//
//  lab6.c
//  
//
//  Created by Ryan Pearson on 2014-03-01.
//
//

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>


int
main(void)
{
    int pid, status;
    float a=0, b=0, c=0, d=0;
    char op, op2;
    FILE *f;
    
    if((pid=fork()) == -1){
        perror("Fork error");
        exit(1);
    }
    
    if (pid>0) {                    // parent
        while(1){
            while((f=fopen("temp.txt", "r"))){
                fclose(f);
                sleep(1);
            }
            
            printf("Please enter 2 numbers and an operator: ");
            scanf("%f %f %c", &a, &b, &op);
            
            if ((f=fopen("temp.txt", "w"))!=NULL) {
                fprintf(f, "%f %f %c\n", a, b, op);
                fclose(f);
            }
            sleep(3);
        }
    }
    else{                           // child
        while(1){
            while((f=fopen("temp.txt", "r"))==NULL)
                sleep(1);
            fscanf(f,"%f %f %c", &c, &d, &op2);
            fclose(f);
            switch (op2) {
                case '+':
                    printf("%f-answer\n", c+d);
                    break;
                case '-':
                    printf("%f-answer\n", c-d);
                    break;
                case '*':
                    printf("%f-answer\n", c*d);
                    break;
                case '/':
                    printf("%f-answer\n", c/d);
            }
            unlink("temp.txt");
        }
        sleep(1);
    }
    
    return 0;
}