//
//  Title: allocateStorage
//  Date: July 22, 2013
//  Name: Ryan Pearson
//  ID: 103965059
//  Program: Allocate storage from buffer- template provided
//

// allocate storage from buffer
#define ALLOCSIZE 10000 /* size of available space */
static char allocbuf[ALLOCSIZE];
static char *allocp = allocbuf;
char *alloc(int n) /* return pointer to n characters */
{
    
    if (allocbuf + ALLOCSIZE - allocp >= n){
        allocp += n;
        return allocp - n; /* the old p */
    } else
        return 0; /* not enough room */
}
