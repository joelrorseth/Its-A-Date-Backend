//
//  Assign3Rah.c
//  
//
//  Created by Ryan Pearson on 2/10/2014.
//
//

/****
 Given a grid of integers of size m x n, where m and n could be any positive integers,
 this C program can create m children so that each child i, (1 <= i <= m), can compute
 the sum of each row m_i of n numbers. Once all children have computed their respective
 sums, the waiting parent will calculate the average of the sums and display the result.
 
 Written by: Quazi Rahman, Feb. 2013.
 ****/
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>

void generate_grid(char *fileName);
void child_sum(int count, int cols, FILE *inFile, FILE *outFile);
void parent_average(int rows, FILE *outFile);

int main(int argc, char *argv[])
{
    int count, rows, cols, pid, sum, status;
    FILE *inFile, *outFile;
    
    generate_grid(argv[1]);
    
    if((inFile = fopen(argv[1], "r")) == NULL ||
       (outFile = fopen(argv[2], "w+")) == NULL)
    {
        perror("file openning error");
        exit(EXIT_FAILURE);
    }
    
    fscanf(inFile, "%d%d", &rows, &cols);
    
    for( count = 1; count <= rows; count++)
    {
        if( (pid = fork()) == -1 )
        {
            perror("fork error");
            exit(EXIT_FAILURE);
        }
        
        else if( pid == 0 ) // child process
        {
            child_sum(count, cols, inFile, outFile);
        }
        else                // parent process
        {
            wait(&status);
            parent_average(rows, outFile);
            exit(EXIT_SUCCESS);
        }
    }
    
    fclose(inFile);
    fclose(outFile);
}


void generate_grid(char *fileName)
{
    FILE *fp;
    int i, j, rows, cols, max;
    
    printf("Enter grid sizes and max_number: ");
    scanf(" %d%d%d", &rows, &cols, &max);
    
    if((fp = fopen(fileName, "w")) == NULL)
    {
        printf("Problem creating file %s\n", fileName);
        exit(0);
    }
    
    srand(time(NULL));
    
    fprintf(fp, "%d %d\n", rows, cols);
    
    for( i = 0; i < rows; i++ )
    {
        for( j = 0; j < cols; j++ )
        {
            fprintf(fp, "%d ", rand() % max);
        }
        
        fprintf(fp, "\n");
    }
    
    fclose(fp);
}

void child_sum(int count, int cols, FILE *inFile, FILE *outFile)
{
    int j, sum, value;
    sum = 0;
    for(j = 0; j < cols; j++)
    {
        fscanf(inFile, "%d", &value);
        sum += value;
    }
    fprintf(outFile, "Child %d Sum = %d\n", count, sum);
    
    fflush(inFile);
    fflush(outFile);
}

void parent_average(int rows, FILE *outFile)
{
    int i, total;
    char *ptrEqual, buffer[100];
    
    rewind(outFile);
    
    total = 0;
    for(i = 0; i < rows; i++)
    {
        fgets(buffer, 99, outFile);
        ptrEqual = strchr(buffer, '=');
        total += atoi(ptrEqual + 1);
    }
    
    fprintf(outFile, "Parent Average = %.2f\n", (float)total/rows);
    
    fflush(outFile);
}