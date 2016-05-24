//
//  lab3.2.c
//  
//
//  Created by Ryan Pearson on 2/4/2014.
//
//

#include <stdio.h>


int
main(void)
{
    FILE *fpin, *fpout;
    char string[50];
    
    if ((fpin=fopen("directory.txt" , "r")) == NULL) {
        printf("No open\n");
        return -1;
    }
    if ((fpout=fopen("newdirectory.txt", "w")) == NULL) {
        printf("No open\n");
        return -1;
    }
    
    int x = 0, y = 0;
    
    while (!feof(fpin)) {
        fgets(string, 50, fpin);
        x+=1;
    }
    
    while (!feof(fpin)) {
        fgets(string, 50, fpin);
    }
    
    fprintf(fpout, "%s\n", string);
    
    fseek(fpin, -2L, SEEK_CUR);
    //printf("%s", fgets(string, 50, fpin));
    
    while (x-- > 1) {
        rewind(fpin);
        y= 0;
        while (y!=x) {
            fgets(string, 50, fpin);
            y++;
        }
        fprintf(fpout, "%s", string);
    }
    
    
    
    return 0;
}