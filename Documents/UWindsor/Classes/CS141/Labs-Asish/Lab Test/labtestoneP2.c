//
//  labtest2.c
//  
//
//  Created by Ryan Pearson on 1.5.13.
//
//

#include <stdio.h>
#include <stdlib.h>

// structure definition
typedef struct root{
    struct root *left;
    int key;
    struct root *right;
}Root;

// function prototypes
Root * addtree (Root *, int);
void postorder(struct root * rptr);

int
main(void)
{
    FILE * fptr;    // pointer to file
    int input;      // user input variable
    Root * begin = NULL;
    if ((fptr = fopen("text.txt", "r")) == NULL){
        printf("No file");
        return -1;
    }
    else{
        // scan into tree
        while(!feof(fptr)){
            fscanf(fptr, "%d", &input);
            begin = addtree(begin, input);
        }
    }
    
    // print function with post order
    postorder(begin);
    fclose(fptr);
    return 0;
}

Root * addtree (Root * rptr, int input)
{
    // if tree node is null, create node 
    if (rptr == NULL) {
        // create new node and set contents
        rptr = malloc(sizeof(struct root));
        rptr->key = input;
        rptr->left = NULL;
        rptr->right = NULL;
    }
    else if (rptr->key > input)
        rptr->right = addtree(rptr->right, input);
    else
        rptr->left = addtree(rptr->left, input);
    
    return rptr;
    
}

// print items postorder until Null nodes are reached
void postorder(struct root * rptr)
{
    if (rptr != NULL) {
        postorder(rptr->left);
        postorder(rptr->right);
        printf("%d\n", rptr->key);
    }
}