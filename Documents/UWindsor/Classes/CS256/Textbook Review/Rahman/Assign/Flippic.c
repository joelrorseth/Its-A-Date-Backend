//
//  fliprah.c
//  
//
//  Created by Ryan Pearson on 2/10/2014.
//
//

#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE *in, *out;
    int i, j, width_pix, height_pix, color;
    
    char header[20];
    
    unsigned char pix;
    
    if( (in = fopen("m1-2.pgm", "rb")) == NULL ||
       (out = fopen("flipped_image.pgm", "wb")) == NULL )
    {
        printf("problem openning image files\n");
        exit(0);
    }
    
    fscanf(in, " %s%d%d%d", header, &width_pix, &height_pix, &color);
    fprintf(stdout, "%s\n%d %d\n%d\n", header, width_pix, height_pix, color);
    fprintf(out, "%s\n%d %d\n%d\n", header, width_pix, height_pix, color);
    
    fseek(in, 0, SEEK_END);
    for(i = 0; i < height_pix; i++)
    {
        fseek(in, -width_pix, SEEK_CUR);
        for(j = 0; j < width_pix; j++)
        {
            fread(&pix, 1, 1, in);
            //fseek(in, -1, SEEK_CUR);
            fwrite(&pix, 1, 1, out);
            //fseek(in, -1, SEEK_CUR);
        }
        fseek(in, -width_pix, SEEK_CUR);
    }
    
    fclose(in);
    fclose(out);
    
    return 0;
}