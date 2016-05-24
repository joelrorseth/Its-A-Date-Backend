//
//  c1.c
//  
//
//  Created by Ryan Pearson on 04-06-2014.
//
//

#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>

int mycopy(char *destfile, char *srcfile);

int
main(void)
{
    int i = mycopy("donkey.txt", "client10.c");
    printf("%d is not neg if sucessful\n", i);
    return 0;
}

int mycopy(char *destfile, char *srcfile)
{
    int fid1, fid2, i;
    char ch[5];
    
    if(((fid1=open(srcfile, O_RDWR)==-1)) || ((fid2=open(destfile, O_CREAT|O_WRONLY|O_TRUNC, 0777))==-1))
        return -1;
    printf("one\n");
    while ((i=read(fid1,ch,5))>0){
        printf("hi\n");
        if(write(fid2, ch, i)!=i)
            return -1;
    }
    printf("two\n");
    
    if (i==-1) {
        return -1;
    }
    
    return 0;
}