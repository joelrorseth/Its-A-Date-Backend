//
//  ExamPic.c
//  
//
//  Created by Ryan Pearson on 04-04-2014.
//
//

#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <string.h>
#include <unistd.h>

int
main(int argc, char*argv[])
{

    char *buffer1, *buffer2, *code1;
    //char *code1;
    FILE *fp1, *fp2, *fp3, *fp4, *fp5, *fp6;
    int height, width, code;
    char start[17], blank[10];
    if(((fp1=fopen(argv[1], "rb"))==NULL) || ((fp2=fopen(argv[2], "rb"))==NULL)|| ((fp3=fopen(argv[3], "wb"))==NULL) || ((fp4=fopen(argv[4], "wb"))==NULL) || ((fp5=fopen(argv[5], "wb"))==NULL) || ((fp6=fopen(argv[6], "wb"))==NULL)){
        printf("No Open\n");
        return -1;
    }

    printf("here\n");
    // read both lines to set offset in file properly.
    // this is interpreted wrong, width actually comes first for these files
    fscanf(fp1, "%s%d%d%d", code1, &height, &width, &code);
    fscanf(fp2, "%s%d%d%d", code1, &height, &width, &code);

    // this block will put them side by side.
    width*=2;
    printf("%d-width\n", width);
    fprintf(fp3, "%s\n%d %d\n%d\n", code1, width , height, code);
    fprintf(fp5, "%s\n%d %d\n%d\n", code1, width , height, code);
    fprintf(stdout, "%s\n%d %d\n%d\n", code1, width , height, code);
    width/=2;
    printf("%d-width\n", width);
    char buffer[width];
    printf("made\n");
    while (!feof(fp1)) {
        fread(buffer, width, 1, fp1);
        fwrite(buffer, width, 1, fp3);
        fread(buffer, width, 1,fp2);
        fwrite(buffer, width, 1, fp3);
    }
    
    rewind(fp1);
    rewind(fp2);
    fscanf(fp1, "%s%d%d%d", code1, &height, &width, &code);
    fscanf(fp2, "%s%d%d%d", code1, &height, &width, &code);
    height*=2;
    fprintf(fp4, "%s\n%d %d\n%d\n", code1, width, height, code);
    fprintf(fp6, "%s\n%d %d\n%d\n", code1, width, height, code);
    height/=2;
    while (!feof(fp1)){
        fread(buffer, width, 1, fp1);
        fwrite(buffer, width, 1, fp4);
    }
    while (!feof(fp2)){
        fread(buffer, width, 1, fp2);
        fwrite(buffer, width, 1, fp4);
    }
    
    fclose(fp1);
    fclose(fp2);
    fclose(fp3);
    fclose(fp4);
    fclose(fp5);
    fclose(fp6);
    
    int fid1, fid2, fid3, fid4;
    
    fid1=open(argv[1], O_RDWR);
    fid2=open(argv[2], O_RDWR);
    fid3=open(argv[5], O_RDWR, 0777);
    fid4=open(argv[6], O_RDWR, 0777);
    
    // offset pointer past initial code in files for reading.
    lseek(fid1, 15, SEEK_SET);
    lseek(fid2, 15, SEEK_SET);
    //offset the
    printf("%lld\n", lseek(fid3, 525312, SEEK_SET));
    printf("%lld\n", lseek(fid4, 525312, SEEK_SET));
    printf("%lld\n", lseek(fid3, 16, SEEK_SET));
    printf("%lld\n", lseek(fid4, 16, SEEK_SET));
    buffer1=(char*) malloc(width);
    buffer2=(char*) malloc(width);
    
    //char buffer1[width], buffer2[width];
    
    while(read(fid1, buffer1, width)==width &&
          read(fid2,buffer2,width)==width){
        write(fid3,buffer1, width);
        write(fid3,buffer2, width);
    }
    
    // offset past the initial code in the files for reading.
    lseek(fid1, 15, SEEK_SET);
    lseek(fid2, 15, SEEK_SET);
    
    while(read(fid2, buffer1, width)==width)
        write(fid4, buffer1, width);
    while(read(fid1, buffer1, width)==width)
        write(fid4, buffer1, width);
    
}