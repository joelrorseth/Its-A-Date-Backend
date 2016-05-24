//
//  hanoi.c
//  
//
//  Created by Ryan Pearson on 1.5.13.
//
//

#include <stdio.h>

void generateMoves(int, int, int, int);

int main(void)
{
    int numberOfDisks;
    int pegA = 1;
    int pegB = 2;
    int pegC = 3;
    printf("Input the number of disks:");
    scanf("%d", &numberOfDisks);
    printf("\n");
    generateMoves(numberOfDisks, pegA, pegB, pegC);
    return 0;
}


void generateMoves(int numberOfDisks, int pegA, int pegB, int pegC)
{
    //if (numberOfPegs == 0) printf("This is the end of all moves \n");
    if (numberOfDisks == 0)
        return;
    else{
        generateMoves(numberOfDisks - 1, pegA, pegC, pegB);
        printf("Move disk from %d to %d\n\n", pegA, pegC);
        generateMoves(numberOfDisks - 1, pegB, pegA, pegC);
    }
}