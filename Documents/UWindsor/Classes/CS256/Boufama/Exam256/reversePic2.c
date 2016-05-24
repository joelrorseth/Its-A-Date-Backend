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
    while (fgetc(fp1) != EOF)
        size++;
    
    // rewind pointer of input file
    rewind(fp1);

    // scan header information and supply it in new file
    fscanf(fp1, "%s%d%d%d", code1, &height, &width, &code);
    fprintf(fp2, "%s\n%d %d\n%d\n", code1, height ,width, code);
    printf("%ld-fp1\n", ftell(fp1));
    printf("%ld-fp1\n", ftell(fp2));
    // move pointer in file 1 to corresponding position to start reading
    // this sets pointer in appropriate position corresponding to fp2
    // not sure why this would be 2 bytes not 1
    fseek(fp1, 2, SEEK_CUR);
    
    // rewind and offset size to proper size of file.
    rewind(fp2);
    fseek(fp2, size, SEEK_CUR);

    //initialize buffer now that you know the size
    char buffer[1];
    
    // offset file to end of file, reset size and write in reverse
    // using fseek to reset pointer for writing to output file
    while (!feof(fp1)) {
        fseek(fp2, -1, SEEK_CUR);
        fread(buffer, 1, 1, fp1);
        fwrite(buffer, 1, 1, fp2);
        fseek(fp2, -1, SEEK_CUR);
    }

    return 0;
}