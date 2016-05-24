// last accessed 31 july, 2013
// Written by Asish Mukhopadhyay, July 2013
// Linear Space Solution for Assignment 1
// Computing A(x-1, y) + A(x, y-1) iteratively

#include <stdio.h>
#include <stdlib.h>
#define min(a,b) ((a) < (b) ? (a):(b))

int main(void)
{
    int i,j; // loop variables
    
    int  m,n; // values input by the user; m+1 is the number of rows and
    // n+1 is the number of columns
    
    printf("Input a non-negative integer as the first argument: ");
    if(scanf("%u", &m) != 1) {printf("Invalid entry"); exit(1);}
    
    printf("\nInput another non-negative integer as the second argument: ");
    if(scanf("%u", &n)  != 1) {printf("Invalid entry"); exit(1);}
    printf("\n");
    
    // this is allocating space dynamically for an array of min(m,n) +1 integer values
    // not discussed in class
    
    int *b = calloc(min(m,n) + 1, sizeof(int));
    
    b[0] = 0; // this is really b[0,0], but we are ignoring the row/column index
    
    // we move row by row, if the number of columns is smaller than the
    // number of rows; else, column by column. In each case, we are simulating
    // filling up an (m+1) X (n+1) matrix, returning as the value of A(m.n) the
    //(m+1, n+1)-th entry of this 2-dimensional array
    
    
    if (m > n){
        for(j = 1; j <= n; j++)
            b[j] = b[j-1] - (j+1);  //  initilizing the 0th row, as we are dealing with
        // border elements
        
        // move to the next row
        
        for (i = 1; i <= m; i++) {
            b[0] = (i+1)+ b[0]; // initialize the first element, as we are dealing with a
            // border element
            for (j = 1; j <= n; j++) // fill in the rest of the elements
                b[j] = b[j] + b[j - 1];
        } // end outer for
        printf("The value of A[%d, %d] is %d \n", m, n, b[n]);
    } // case m > n
    else { // case m >= n
        for(j = 1; j <= m; j++)
            b[j] = b[j-1] +(j+1);  //  initilizing the 0th column, as we are dealing with
        // border elements
        
        // move to the next column
        
        for (i = 1; i <= n; i++) {
            b[0] = -(i+1)+ b[0]; // initialize the first element, as we are dealing with a
            // border element
            for (j = 1; j <= m; j++) // fill in the rest of the elements
                b[j] = b[j] + b[j - 1];
        } // end outer for
        printf("The value of A[%d, %d] is %d \n", m, n, b[m]);
    }
    
    free(b);
} // end of main