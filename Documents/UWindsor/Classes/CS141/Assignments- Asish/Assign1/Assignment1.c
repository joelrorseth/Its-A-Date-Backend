//
//  Assignment1.c
//  Date:   July 8, 2013
//  ID:     103965059
//  Name:   Ryan Pearson
//
//

#include <stdio.h>

int
main(void)
{
    int m = 0, n = 0, i = 0, i2 = 0;      // array variables and counter variables
    int xholder = -2;                    // initial row and initial column variable counter
    int base = 0;                        // sum holder
    
    printf("Please enter f[m, n]:");        //get size from user- assume proper input
    scanf("%d%d", &m, &n);
    
    printf("Would you like to complete this with method (1)\n");        // choose method of calculation
    printf("or method (2):");                                     // again, assuming proper input
    scanf("%d", &base);
    
    if (base == 1) {
        base = 0;                       // reset base for calculations
        int dvalue[m+1][n+1];           // create double scripted array
        dvalue[0][0] = 0;               // set 0,0 value
        // set initial row of elements in array
        for (i = 1; i <= n; i++) {
            dvalue[0][i] = base += xholder;
            xholder--;
        }

        xholder = 2;                    // reset xholder
        base = 0;                       // reset base
        
        // set initial column of elements
        for (i = 1; i <= m; i++) {
            dvalue[i][0] = (base += xholder);
            xholder++;
        }
        
        // calculate table
        for (i2 = 1; i2 <= m; i2++) {
            for (i = 1; i <= n; i++) {
                dvalue[i2][i] = dvalue[i2-1][i] + dvalue[i2][i-1];
            }
        }

        printf("Value: %d\n", dvalue[m][n]);        // return value at coordinates
        
    }
    
    else if (base ==2)
    {
        base = 0;                            // reset base for calculations
        int Value[n+1];                      // declare array of user size + 1
        Value[0] = 0;                        // set initial case.
        // set initial row of elements in array
        for (i = 1; i <= n+1; i++) {
            Value[i] = (base += xholder);
            xholder--;
        }
    
        base = 0;                           // reset base for vertical counter
        xholder = 2;                        // reset initial row counter variable
        // perform multiple loops to reset variable in array
        while (i2 < m) {
            for (i = 0; i <= n+1; i++)
            {
                if (i == 0)                 // reset initial column of row
                {
                    Value[i] = (base += xholder);
                    xholder++;
                }
                else                        // reset each element
                    Value[i] += Value[i-1];
            }
            i2++;                           // increment for loop
        }
        printf("Value: %d\n", Value[n]);        // return value
        return 0;
    }
}



