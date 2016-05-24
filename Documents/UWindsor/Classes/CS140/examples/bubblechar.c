//
//  bubblechar.c
//  
//
//  Created by Ryan Pearson on 1.5.13.
/*
 BubbleSort:
 
 This program develops a function called BubbleSort that sorts a list of words.
 
 -A main function is supplied to test it as well.
 -A const parameter in the function is used to ensure that the function does NOT modify
 the paramter.
 
 Developed by: Ziad Kobti
 Last Revised: June 12, 2002
 
 */

#include <stdio.h>
#include <string.h>

void BubbleSort(char *S[], const int size);
void PrintList(char *S[], const int size);

int main()
{
    
    printf("[%d]\n\n", 8>=5<7);
    
    /* WordList terminates with the sentinel string value "done" */
    char *WordList[] = {"table", "chair", "train", "Table", "car"};
    
    printf("Initial List:\n");
    PrintList(WordList, 5);
    BubbleSort(WordList, 5);
    printf("Sorted List:\n");
    PrintList(WordList, 5);
    
    return 0;
}


void BubbleSort(char *S[], const int size)
{
    int pass;
    int j;
    char *tempPtr;
    
    for (pass=0; pass < size - 1; pass++)
    {
        for (j=0; j<size - 1; j++)
        {
            if (strcmp(S[j], S[j + 1]) > 0)
            {
                /* swap pointers */
                tempPtr = S[j];
                S[j] = S[j+1];
                S[j+1] = tempPtr;
            }
        }
    }
}

void PrintList(char *S[], const int size)
{
    int i;
    for (i = 0; i < size; i++)
    {
        printf("%d : %s\n", i, S[i]);
    }
}


/* OUTPUT
 Initial List:
 0 : table
 1 : chair
 2 : train
 3 : Table
 4 : car
 Sorted List:
 0 : Table
 1 : car
 2 : chair
 3 : table
 4 : train
 */
