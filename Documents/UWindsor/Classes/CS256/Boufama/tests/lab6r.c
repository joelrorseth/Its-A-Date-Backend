//
//  lab6r.c
//  
//
//  Created by Ryan Pearson on 03-05-2014.
//
//

#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

int
main(void)
{
    int pid;
    FILE *fp, fp1;
    float val1, val2;
    char ch;
    
    if((pid=fork()) == -1){
        perror("Fork error");
        exit(1);
    }
    
    if (pid>0) {
        while (1) {
            while ((fp=fopen("temp.txt", "r"))){
                fclose(fp);
                sleep(1);
            }
            
            printf("Please enter 2 numbers and an operator: ");
            scanf("%f %f %c", &val1, &val2, &ch);
            
            if((fp=fopen("temp.txt", "w"))!=NULL){
                fprintf(fp, "%f %f %c\n", val1, val2, ch);
                fclose(fp);
            }
            sleep(8);
        }
    }
    else{
        while (1) {
            while ((fp=fopen("temp.txt", "r"))==NULL)
                sleep(1);
            fscanf(fp, "%f %f %c", &val1, &val2, &ch);
            fclose(fp);
            
            switch (ch) {
                case '+':
                    printf("%f + %f = %f\n", val1, val2, val1 + val2);
                    break;
                case '-':
                    printf("%f - %f = %f\n", val1, val2, val1 - val2);
                    break;
                case '*':
                    printf("%f * %f = %f\n", val1, val2, val1 * val2);
                    break;
                case '/':
                    printf("%f / %f = %f\n", val1, val2, val1 / val2);
            }
            unlink("temp.txt");
        }
        sleep(1);
    }
    
    return 0;
}