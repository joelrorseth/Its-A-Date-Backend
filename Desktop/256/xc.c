//
//  xc.c
//  
//
//  Created by Ryan Pearson on 05-05-2016.
//
//

#include <stdio.h>


int main(int argc, char *argv[]){
    FILE *f;
    char c;
    
    f=fopen(argv[1], "w");
    //setbuf(f, NULL);
    while ((c=getchar()) != EOF) {
        fputc(c, f);
        fflush(f);
    }
    
    
    
}