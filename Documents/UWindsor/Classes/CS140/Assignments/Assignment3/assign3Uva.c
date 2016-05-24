// THIS IS THE UVA INTERPRETATION OF THE PROBLEM. ANSWERS WILL BE DIFFERENT FOR THE QUESTION
// AS THERE IS A DIFFERENT WAY OF TAKING ELEMENT POSITION INTO THE ALGORITHM.
// THIS WAS LIKELY NOT REQUIRED FOR THIS ASSIGNMENT BUT IT WAS A QUICK SWITCH TO DEMONSTRATE
// HOW THE CODE COULD WORK DIFFERENTLY.
// THIS SECTION AND ANSWERS THEREAFTER WILL LIKELY NOT BE PART OF THE GRADING AND THEREFORE
// I HAVE NOT COMMENTED ANYTHING IN THIS INTERPRETATION OTHER THAN THE COUPLE LINES OF CODE THAT WAS
// DIFFERENT FROM THE CLASS EXAMPLE.
#include <stdio.h>
#define SIZE 20

int evaluate(const int answer[], int *a, const int cor[]);

int evaluate(const int answer[], int *a, const int cor[])
{
    int counter, positioni, countHold = 0;
    int x, y, i;                                                
    int before;
    
    for (y = 1; y <= *a; y++)
    {
        positioni = 0;
        before = 0;
        counter = 0;
        
        for (x = y; x <= *a; x++){
            for (i = 1; i <= *a; i++){
                if (answer[x] == cor[i]){
       
                    if (i < positioni && i >= before)
                        positioni = i;
                    else if (i >= positioni){          
                        before = positioni;
                        positioni = i;
                        counter++;
                    }
                }
            }
        }

        if (counter > countHold)
            countHold = counter;
    }
    return countHold;      
}

int
main(void)
{
    int n = 0, i = 0, hold = 0;
    int correctKey[SIZE], response[SIZE];                
    
    for (i = 0; i < SIZE; i++) {correctKey[i] = 0; response[i] = 0;}
    
    do{
        scanf("%d", &n);
        if (n < 2 || n > 20)
            puts("Invalid number!");
    }while( n < 2 || n > 20);
    
    // this is the first change required for UVA interpretation.
    for (i = 1; i <= n; i++) {
        scanf("%d", &hold);
        correctKey[hold] = i;
    }
    // This is the second change required for UVA interpretation.
    while(1){
        for (i = 1; i <= n; i++) {
            if(scanf("%d", &hold) == EOF)
                return 0;
            response[hold] = i;
        }
        printf("%d\n", evaluate(response, &n, correctKey));
    }
    return 0;
}