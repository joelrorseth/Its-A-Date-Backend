//
//  lab3.2.c
//  
//
//  Created by Ryan Pearson on 2/4/2014.
//
//

#include <stdio.h>
#include <string.h>


int
main(void)
{
    FILE *fpin, *fpout;
    char string[50];
    
    // my version
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

    fprintf(fpout, "%s\n", string);
    
    while (x-- > 1) {
        rewind(fpin);
        y= 0;
        while (y!=x) {
            fgets(string, 50, fpin);
            y++;
        }
        fprintf(fpout, "%s", string);
    }
    
    fclose(fpin);
    fclose(fpout);
    
    // version 2
    
    if ((fpin=fopen("directory.txt" , "r")) == NULL) {
        printf("No open\n");
        return -1;
    }
    if ((fpout=fopen("newdirectory.txt", "a")) == NULL) {
        printf("No open\n");
        return -1;
    }
    
    char line[100];
    x = ftell(fpin) - 1;
    fseek(fpin, 0, SEEK_END);
    int i = 0,z = 0;
    // this fixes the offset to proper index.
    
    fseek(fpin, 0, SEEK_END);
    while (fseek(fpin, --x, SEEK_END) != -1) {
        if ((line[i++]=fgetc(fpin)) == '\n') {
            while(i > -1){
                fprintf(fpout ,"%c", line[i]);
                line[i--]='\0';
            }
            i++;
        }
    }
    rewind(fpin);
    fgets(string, 50, fpin );
    fprintf(fpout, "\n%s\n", string);
    
    fclose(fpin);
    fclose(fpout);
    
    // version 3
    
    if ((fpin=fopen("directory.txt" , "r")) == NULL) {
        printf("No open\n");
        return -1;
    }
    if ((fpout=fopen("newdirectory.txt", "a")) == NULL) {
        printf("No open\n");
        return -1;
    }
    
    fseek(fpin, 0, SEEK_END);
    int size = ftell(fpin);
    printf("%d\n", size);
    int counter = 0;
    rewind(fpin);
    fseek(fpout, size, SEEK_SET);
    while (size > 0){
        fgets(string, 52, fpin);
        fseek(fpout, -strlen(string), SEEK_CUR);
        fprintf(fpout, "%s", string);
        fseek(fpout, -strlen(string), SEEK_CUR);
        size -= strlen(string);

    }

    fclose(fpin);
    fclose(fpout);
    return 0;
}