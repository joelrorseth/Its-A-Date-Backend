//Assign3 boufama

#include <stdio.h>
#include <stdlib.h>



int main(int argc, char *argv[]){
    FILE  *fd1, *fd2;
    char buffer[1000];
    int i, nbcols, nblines;
    
    if(((fd1 = fopen(argv[1], "rb")) == NULL) ||   // use "rb"/"wb" if under
       ((fd2 = fopen(argv[2], "wb")) == NULL)){    // Windows
        printf("Usage: %s <input image> <output image>\n", argv[0]);
        perror("Opening file ");
        exit(1);
    }
    
    fgets(buffer, 255, fd1);  // get rid of the P5
    printf("%s", buffer);
    fputs(buffer, fd2);
    
    fgets(buffer, 255, fd1);  // read image resolution, nblines and nbcols
    fputs(buffer, fd2);
    
    sscanf(buffer, "%d%d", &nblines, &nbcols);
    
    fgets(buffer, 255, fd1);  // get rid of 255
    fputs(buffer, fd2);
    
    
    for(i=1; i<=nblines; i++){
        fseek(fd1, -i*nbcols, SEEK_END);
        fread(buffer, nbcols, 1, fd1);
        fwrite(buffer, nbcols, 1, fd2);
    }         
    
    fclose(fd2);
    exit(0);
}