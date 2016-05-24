//
//  2darraysort.c
//  
//
//  Created by Ryan Pearson on 1.5.13.
// sort a 2D array using min selection
// by Ziad Kobti
// Jan 2004


// Includes
#include <stdio.h>


// Assume the array is of size SIZExSIZE
#define SIZE 3


// Main program routine
int main()
{
	// Declare a 2D array of equal dimensions and initialize it
	int A[SIZE][SIZE] = { {5, 2, 4},
        {3, 7, 1},
        {0, 9, 8}  };
    
	int r; 		// row index
	int c; 		// col index
	int rr; 	// sublist row index
	int cc; 	// sublist col index
	int minr;	// index (row) where min was found
	int minc;       // index (col) where min was found
	int temp; 	// swapping
    
    
	// Display the original array before sorting
	printf("Before:\n");
	for (r=0; r<SIZE; r++)
	{
		for (c=0; c<SIZE; c++)
		{
			printf("%d ", A[r][c]);
		}
		printf("\n");
	}
    
    
	// sort
	for (r=0; r<SIZE; r++)
	{
		for (c=0; c<SIZE; c++)
		{
			// for each element in the list A[r][c]
			// given the remaining sublist, find the smallest and swap it
            
			// let the current one be the minimum
			minr = r;
			minc = c;
            
			// search the sublist for a new min
			cc=c+1;
			for (rr=r; rr < SIZE; rr++, cc=0)
			{
				for (; cc < SIZE; cc++)
				{
					// found a new min
					if (A[rr][cc] < A[minr][minc])
					{
						minr = rr;
						minc = cc;
					}
				}
			}
            
			// swap min and current
			temp = A[r][c];
			A[r][c] = A[minr][minc];
			A[minr][minc] = temp;
		}
	}
    
    
	// Display the array after it is sorted to verify
	printf("\nAfter:\n");
	for (r=0; r<SIZE; r++)
	{
		for (c=0; c<SIZE; c++)
		{
			printf("%d ", A[r][c]);
		}
		printf("\n");
	}
    
    
	return 0;
}

/* Sample output:
 
 Before:
 5 2 4
 3 7 1
 0 9 8
 
 After:
 0 1 2 
 3 4 5 
 7 8 9 
 
 */