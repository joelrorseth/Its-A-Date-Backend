// Lab Test One
// Problem 1

#include <stdio.h>



int main(void)
{
    int i, j, k; // loop variables
    int numberOfRows;
    
    printf("Please input an odd positive integer - the number of rows:");
    scanf("%d", &numberOfRows);
    
    // print upper half
    // if x is the number of rows then (x-1)/2 rows are to be printed
    // if the rows are indexed from 0 to x-1 then the number of *'s top be printed
    // in the i-th row is 2i+1; that's why the third for is repeated these many times
    // the number of blanks to be prointed in the i-th row is x - i
    // that's why the second for is repeated these many times
    for (i = 0; i < (numberOfRows -1)/2 ; i++){
        for(j = 0; j < ((numberOfRows -1)/2 - i); j++) printf(" ");
        for (k = 0; k < (2*i+1); k++) printf("*");
        printf("\n");
    }
    
    // print middle line
    // the number of stars in the middle line is equal to the number of rows
    // hence this for is repeated these many times
    for(i = 0; i < numberOfRows; i++) printf("*");
    printf("\n");
    
    // print lower part
    // with repect to the middle row the number of stars in the next row
    // is reduce by 2; then again by 2 for the succeeding row and so on
    // the number of blanks printed increases by 1 as we count down to 0
    for (i = (numberOfRows -1)/2;  i > 0; i--){
        for(j = 0; j < ((numberOfRows -1)/2 - i) + 1; j++) printf(" ");
        for (k = 0; k < 2*i-1; k++) printf("*");
        printf("\n");
    }
    
}