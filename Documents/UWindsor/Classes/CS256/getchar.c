//
//  getchar.c
//  
//
//  Created by Ryan Pearson on 1.5.13.
//
//

#include <stdio.h>


int
main(void)
{
    char c;
    int ndigits, nwhite, nother;
    
    ndigits = nwhite = nother = 0;
    
    while ((c = getchar()) != EOF) {
        switch (c) {
            case '0':
            case '1':
            case '2':
            case '3':
            case '4':
            case '5':
            case '6':
            case '7':
            case '8':
            case '9':
                ndigits++;
                break;
            case ' ':
            case '\t':
            case '\n':
                nwhite++;
                break;
            default:
                nother++;
        }
    }
    printf("white space = %d, number of digits = %d, other = %d\n", nwhite, ndigits, nother);
    
    return 0;
}