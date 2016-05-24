//
//  Title: writeLines.c
//  Date: July 22, 2013
//  Name: Ryan Pearson
//  ID: 103965059
//  Program: write out lines- template supplied
//

/* writelines: write output lines */
void writelines(char *lineptr[], int nlines)
{
    int i;
    for(i = 0; i < nlines; i++)
        printf("%s\n", lineptr[i]);
}
