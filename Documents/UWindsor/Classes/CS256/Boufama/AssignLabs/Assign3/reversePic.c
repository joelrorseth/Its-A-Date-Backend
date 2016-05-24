//
//  reversePic.c
//  SID: 103965059
//  Name: Ryan Pearson
//  Date: 2/10/2014
//

#include <stdio.h>

int
main(int argc, char *argv[])
{
    // check before do anything for proper input.
    if (argc != 3) {
        printf("Usage: reversePic <inputFileName> <ouputFileName>\n");
        return -1;
    }
    
    // create variables
    FILE *fp1, *fp2;
    char code1[5];
    int size=0, code, width, height;
    
    // open file pointers
    if (((fp1 = fopen(argv[1], "rb")) == NULL) ||
                ((fp2 = fopen(argv[2], "wb")) == NULL)){
        printf("No open la file.\n");
        return -1;
    }
    
    // get size of picture to offset fp2
    while (!feof(fp1)){
        fgetc(fp1);
        size++;
    }
    
    // rewind pointer of input file
    rewind(fp1);
    
    // scan header information and supply it in new file
    fscanf(fp1, "%s%d%d%d", code1, &height, &width, &code);
    fprintf(fp2, "%s\n%d %d\n%d\n", code1, height ,width, code);
    printf("%d\n", width);
    
    //initialize buffer now that you know the size
    char buffer[width];
    
    // offset file to end of file, reset size and write in reverse
    // using fseek to reset pointer for writing to output file
//    fseek(fp2, size, SEEK_SET);
//    size=0;
//    while (!feof(fp1)) {
//        size-=width;
//        fseek(fp2, size, SEEK_END);
//        fread(buffer, width, 1, fp1);
//        fwrite(buffer, width, 1, fp2);
//    }
    
    // this is Dr Boufama's code(gives same size.
    for(int i=1; i<=height; i++){
        fseek(fp1, -i*width, SEEK_END);
        fread(buffer, width, 1, fp1);
        fwrite(buffer, width, 1, fp2);
    }
    return 0;
}