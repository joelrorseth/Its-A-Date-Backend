//  Assign3.c
//  PEARSON, RYAN
//  STUDENT ID: 103965059
//  DATE April 5, 2013.
// I ATTEST THAT THIS IS SOLELY MY OWN WORK.
// History grading- find the longest combination (not necc. contiguous) of correct answers.

#include <stdio.h>
#define SIZE 20

int evaluate(const int answer[], int *a, const int cor[]);
/* Function- loop over answers to determine most correct sequence
 Input- 2 arrays and one integer pointer (the size of both arrays)
 Output- one integer (size of greatest matching list) */
int evaluate(const int answer[], int *a, const int cor[])
{
    int counter, countHold = 0;                  // sequence total, max sequence holder
    int x, y, i;                                 // counter variables
    int before, positioni;                       // hold current and previous element positions
    
    for (int y = 0; y < *a; y++)                 // loop to cycle over each starting point in sequence
    {
        positioni = 0;                          // reset variables for each loop
        before = 0;
        counter = 0;
        
        // loop over sequence linear as we can't sort to find most successive sequence
        for (x = y; x < *a; x++){
            for (i = 0; i < *a; i++){
                if (answer[x] == cor[i]){
                    // catch sequence prior to value already found if still after previous value in sequence
                    if (i < positioni && i >= before)
                        positioni = i;
                    else if (i >= positioni){    // set values and counter
                        before = positioni;
                        positioni = i;
                        counter++;
                    }
                }
            }
        }
        if (counter > countHold)                // hold highest value
            countHold = counter;
    }
    return countHold;                           // return highest value
}

int
main(void)
{
    int n = 0, i = 0;                                    // counter variables, n is number of elements
    int correctKey[SIZE], response[SIZE];                // arrays for tracking
    
    for (i = 0; i < SIZE; i++) {                         // assign all array elements to zero
        correctKey[i] = 0;
        response[i] = 0;
    }
    
    do{                                                  // scan for list size, ensure proper size
        scanf("%d", &n);
        if (n < 2 || n > 20)
            puts("Invalid number!");
    }while( n < 2 || n > 20);
    
    for (i = 0; i < n; i++)                              // scan for correct sequence
        scanf("%d", &correctKey[i]);
    
    // scan for response and test against correct sequence
    while(response[i] != EOF){
        // loop over student responses, use EOF to exit loop
        for (i = 0; i < n; i++) {
            if(scanf("%d", &response[i]) == EOF)
                return 0;
        }
        printf("%d\n", evaluate(response, &n, correctKey));   // print high sequence
    }
    return 0;
}