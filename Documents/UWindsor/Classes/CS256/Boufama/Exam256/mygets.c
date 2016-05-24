//
//  mygets.c
//  
//
//  Created by Ryan Pearson on 04-10-2014.
//
//

#include <stdio.h>

char *mygets(char*s, int n, FILE *);
int
main(void)
{
    FILE *fp;
    int n=100;
    char buffer[n];
    
    printf("back- %s", mygets(buffer, n-1, stdin));
    return 0;
}

char *mygets(char *s, int n, FILE *fp)
{
    int i=0;
    fprintf(stderr, "Enter line: ");
    while ((s[i++]=fgetc(fp))!=-1 && i<n-1)
        if (s[i-1]=='\n')
            break;
        
    if (i==0 || ferror(fp))
        return NULL;
    
    s[i]='\0';
    return s;
    
    
}