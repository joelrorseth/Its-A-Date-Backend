//
//  mygets.c
//  
//
//  Created by Ryan Pearson on 2/6/2014.
//
//

#include <stdio.h>


int
main(void)
{
    
    FILE *fp;
    int i = 0;
    char buffer[100];
    if ((fp = fopen("output.txt", "r"))) {
        while ((buffer[i++] = fgetc(fp)) && i < 100){
            if (buffer[i-1] == '\n')
                break;
            if (feof(fp))
                break;
        }
        if (i -1 == 0){
            printf("return null\n");
            return -1;
        }
        printf("returning %s not null as actually stating.\n", buffer);
    }
    printf("return null\n\n");
    return 0;
}