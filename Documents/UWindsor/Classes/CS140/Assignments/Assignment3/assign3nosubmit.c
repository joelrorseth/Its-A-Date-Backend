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
 Output- one integer (size of greatest match) */
int evaluate(const int answer[], int *a, const int cor[])
{
    int counter = 0;                    // variable to catch how many times correct sequence hit(for before variable)
    int positioni = 0;                  // variable to hold which position matched
    int countHold = 0;                  // largest count holder
    int i, x, y;                        // counter variables
    int before;                         //  variable to hold the previous matched element in array
    
    // loop to cycle over each starting point in sequence
    for (y = 0; y < *a; y++)
    {
        positioni = 0;                          // reset variables for each loop
        before = 0;                             // hold previous loop position to not go before value
        counter = 0;
        // loop over sequence linear as we can't sort to find most successive sequence
        for (x = y; x < *a; x++){
            for (i = 0; i < *a; i++){
                if (answer[x] == cor[i]){
                    // catch sequence prior to value already found if still after previous value in sequence
                    if (i < positioni && i >= before)
                        positioni = i;
                    else if (i >= positioni){           // set values and counter
                        before = positioni;
                        positioni = i;
                        counter++;
                        if(counter == 1)             // catch exception from 1st loop of sequence
                            before = positioni;
                    }
                }
            }
        }
        // hold highest value
        if (counter > countHold)
            countHold = counter;
    }
    return countHold;       // return highest value
}

int scanin(int response[SIZE], int *np, int correctKey[SIZE], int correct[100], int *xp);
/* Function: scan in responses from students and save largest correct sequence
 Input: two integer pointers, 3 arrays
 Output: one integer to signify loop termination*/
int scanin(int response[SIZE], int *np, int correctKey[SIZE], int correct[100], int *xp)
{
    int i;                              // counter variable
    // loop over student responses, use EOF to exit loop
    for (i = 0; i < *np; i++) {
        if(scanf("%d", &response[i]) == EOF)
            return -1;
    }
    // store largest sequence in array for final print.
    correct[*xp] = evaluate(response, np, correctKey);
    *xp += 1;
    return 0;
}

int
main(void)
{
    int x = 0;                                              // track number of tests evaluated
    int n = 0, i = 0, check = 0;                            // counter variables, check will get out of loop
    int correctKey[SIZE], response[SIZE], correct[100];     // answer arrays & correct array for up to 100 entry tracking
    
    // assign all array elements to zero
    for (i = 0; i < SIZE; i++) {correctKey[i] = 0; response[i] = 0;}
    
    for (i = 0; i < 100; i++) {correct[i] = 0;}
    
    // scan for list size, test for proper size
    do{
        scanf("%d", &n);
        if (n < 2 || n > 20)
            printf("%s\n", "Value must be between 2 and 20.");
    }while (n < 2 || n > 20);
    
    // scan for correct sequence
    for (i = 0; i < n; i++)
        scanf("%d", &correctKey[i]);
        
        // scan for response and test against correct sequence
        while ((check = scanin(response, &n, correctKey, correct, &x)) != -1 ){}
    
    // print results at this point only testing 1 at a time.
    for (i = 0; i < x; i++)
        printf("%d\n", correct[i]);
        
        return 0;
}


