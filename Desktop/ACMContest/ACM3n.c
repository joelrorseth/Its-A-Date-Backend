//
//  ACM3n.c
//  
//
//  Created by Ryan Pearson on 2016-04-25.
//
//

#include <stdio.h>

int maxsum(unsigned int);
int maxsum(unsigned int max){

    int c=1;
    while(max!=1){
        if(max % 2 == 1){
            max=3*max+1;
            max >>= 1;
            c+=2;
        }
        else{
            max >>= 1;
            c++;
        }
    }
    return c;
}

int
main()
{
    unsigned int c, index, h, cmax, s, e;
    while(scanf("%d %d",&s,&e)!=EOF){
        if(s==0 || e==0)
            continue;
        
        if(e<s){
            h=s;
            s=e;
            e=h;
        }
        
        cmax=0;
        for(h=s; h<=e;h++){
            c=maxsum(h);
            if(cmax<c)
                cmax=c;
        }
        printf("%d %d %d\n", s, e, cmax);
    }
    return(0);
}