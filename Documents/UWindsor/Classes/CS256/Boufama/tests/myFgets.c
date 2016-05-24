//
//  myFgets.c
//  
//
//  Created by Ryan Pearson on 03-03-2014.
//
//

char *myFgets(char*, int n, FILE *);

char *myFgets(char *buff, int n, FILE *fp){
    int i =0;
    int ch;
    
    while (i < n-1 && (ch=fgetc(fp)!=-1)) {
        buff[i++]=ch;
        if (ch=='\n')
            break;
    }
    if (ferror(fp) || i==0) {
        return (NULL);
    }
    
    buff[i]=NULL;
    return(buff);
    
}

