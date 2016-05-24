//
//  righttri.c
//  
//
//  Created by Ryan Pearson on 1.5.13.
//
//

#include <stdio.h>


int
main(void)
{
    int total = 0;      // total counter
    int v1 = 0;         // side 1 sq
    int v2 = 0;         // side 2 sq
    int ht = 0;         // side hypo total
    
    
    // do math and provide feedback
    for (int side1 = 1; side1 <= 500; side1++)
    {
        v1 = side1 * side1;
        for (int side2 = 1; side2 <= 500; side2++)
        {
            v2 = side2 * side2;
            for (int hypo = 1; hypo <= 500; hypo++)
            {
                ht = hypo * hypo;
                if (ht == (v1 + v2))
                    total++;
            }
        }
    }
    
    printf("The total number of triangles are: %d\n", total);
    return 0;
}