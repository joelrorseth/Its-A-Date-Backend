//
//  Title: sorting
//  Date: July 22, 2013
//  Name: Ryan Pearson
//  ID: 103965059
//  Program: sorting and swapping program- template provided
//  Adjustments: allow descend/ascend sort and sort from multiple functions
//

void swap(char *lineptr[], int, int); // prototype
void bubbleSort( char *lineptr[], int size, int x )
{
    int select = 0;         // variable to choose sorting order
    if (x == 0) {           // flag user input so you can print for sort or not
        do{
            printf("Please choose:\n1.Ascending\n2.Descending\n");
            scanf("%d", &select);
        }while (select < 1 || select > 2);
    }
    unsigned int pass; // pass counter
    size_t j; // comparison counter
    // loop to control passes
    for ( pass = 0; pass < size - 1; ++pass ) {
        // loop to control comparisons during each pass
        for ( j = 0; j < size - 1; ++j ) {
            if (select == 1 || x == 1) {
                if(strcmp(lineptr[j], lineptr[j+1]) > 0)
                swap(lineptr, j, j+1);
            }
            else if ( select == 2 || x == 2){
                if(strcmp(lineptr[j], lineptr[j+1]) < 0)
                swap(lineptr, j, j+1);
            }
        }
    }
    // print sort if that was the option selected. Avoid if using max or min functions
    if (select > 0)
        writelines(lineptr, size);
}

/* Function: Swap pointers but not elements in array
 Input: double scripted array, 2 pointer locations
 Output: nothing, just swapping pointers */
void swap(char *lineptr[], int a, int b)
{
    char *line = lineptr[a];
    lineptr[a] = lineptr[b];
    lineptr[b] = line;
    
}