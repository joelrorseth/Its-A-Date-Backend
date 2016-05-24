//
//  vla.c
//  
//
//  Created by Ryan Pearson on 1.5.13.
//
//

#include <stdio.h>

void print1DArray (int size, int arr [size]);
void print2DArray (int row, int col, int arr[row] [col]);

int
main(void)
{
    int arraySize;
    int row1, col1, row2, col2;
    
    printf("%s", "Enter size of a one-dimensional array: ");
    scanf("%d", &arraySize);
    
    printf("%s", "Enter number of rows and colums in a 2-D array: ");
    scanf("%d%d", &row1, &col1);
    
    printf("%s", "Enter number of rows and columns in another 2-D array: ");
    scanf("%d%d", &row2, &col2);
    
    int array[arraySize];
    int array2D1[row1][col1];
    int array2D2[row2][col2];
    
    printf("\nsizeof(array) yields array size of %ld bytes.\n", sizeof(array));
    
    // 1D array element assignment
    for (int i = 0; i < arraySize; i++) {
        array[i] = i * i;
    }
    
    // 2D1 array element assignment
    for (int i = 0; i < row1; i++) {
        for (int j = 0; j < col1; j++) {
            array2D1[i][j] = i + j;
        }
    }
    
    // 2D2 array element assignment
    for (int i = 0; i < row2; i++) {
        for (int j = 0; j < col2; j++) {
            array2D2[i][j] = i + j;
        }
    }
    
    puts("\nOne dimensional array.\n");
    print1DArray(arraySize, array);
    
    puts("\nTwo dimensional array.\n");
    print2DArray(row1, col1, array2D1);
    
    puts("\nTwo dimensional array.\n");
    print2DArray(row2, col2, array2D2);
    
    return 0;
    
}


void print1DArray (int size, int array[size])
{
    for (int i = 0; i < size; i++) {
        printf("Array[%d] = %d\n", i, array[i]);
    }
    
}

void print2DArray (int row, int col, int array[row] [col])
{
    for (int i = 0; i < row; i++) {
        //printf("Row[%d]", i)
        for (int j = 0; j < col; j++) {
            printf("Array[%d][%d] = %d ", i, j, array[i][j]);
        }
        puts("");
    }
    
    
}