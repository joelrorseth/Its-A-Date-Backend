//
//  Title: Assign2BF
//  Date: July 15, 2013
//  Name: Ryan Pearson
//  ID: 103965059
//  Program: gather array from user and provide maximum sequence sum, end point and starting point
//

#include <stdio.h>

int
main(void)
{
    int maxSum = 0, len = 0, sum, j= 0, i = 0; // create variables for holders, increments etc.
    int start = 0, end = 0;                         // create holding start and end points
    
    // prompt user for valid entry
    while (len <= 0) {
        printf("Please enter the number of values you wish to enter greater than zero: ");
        scanf("%d", &len);
    }
    
    int entr[len];                  // create array for variables
    
    // loop over elements and insert user entry into array
    for(sum = 0; sum < len; sum++)
    {
        printf("Please enter Number %d: ", sum+1);
        scanf("%d", &entr[sum]);
    }
    
    sum = 0;                        // reset for counter variable
    
    // loop over each array element checking for max size, use increment to make new starting point
    do {
        sum += entr[j];
        if (sum > maxSum) {
            maxSum = sum;
            start = i;
            end = j;
        }
        if (sum < 0){
            i = j + 1;
            sum = 0;
        }
        j++;
    } while (j < len);
    
    // return values to user
    printf("\n%d- MaxSum\nStart at Entry %d\nEnd at Entry %d\n", maxSum, start+1, end+1);
    
    // return elements in range used for maxsum
    for (; start <= end; start++)
        printf("%d ", entr[start]);
    
    puts("");
    return 0;
}