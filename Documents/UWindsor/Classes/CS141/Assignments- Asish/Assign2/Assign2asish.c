// solution to linear search fpor max subsequence
// written by Asish Mukhopadhyay, 11 August, 2013

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#define SIZE 10

int main(void)
{
    int a[SIZE];
    int i, j, limit, sum, maxSum = 0;
    int start = 0, end = -1;
    int number;
    int  thisSum = 0;
    
    FILE *fPtr;
    fPtr = fopen("inputList", "w");
    
    
    srand(time(NULL));
    for (i = 0; i < SIZE; i++){
        number = rand() - 18000;  // this generates +ve and -ve integers
        fprintf(fPtr, "%d\n", number);
    }
    fclose(fPtr);
    
    // get input
    fPtr = fopen("inputList", "r");
    for (i = 0; i < SIZE ; i++){
        fscanf(fPtr, "%d", &number);
        a[i] = number;
    }
    
    // print sequence read to aid in visulaization
    printf("\nThe number of integers read is: %d\n\n", SIZE);
    printf("The sequence read in is:\n\n");
    for (i = 0; i < SIZE ; i++) printf("%8d", a[i]);
    printf("\n\n");
    
    // linear search
    for(int i = 0,j = 0; j < SIZE; j++){
        thisSum+=a[j];
        if(thisSum>maxSum)
        {
            maxSum = thisSum;
            start = i;
            end = j;
        }
        else if(thisSum<0)
        { 	i = j+1;
            thisSum=0;
        }
    }
    printf("A maximum subsequence starts at index: %d, ends at index: %d, and the maxSum is: %d\n", start, end, maxSum);
    fclose(fPtr);
} // end of main