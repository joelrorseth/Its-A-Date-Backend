// lab Test one
// Problem 2
// prints 25 twice - why ?
// by changing the while -loop test as below this is pre-empted

#include <stdio.h>
#include <stdlib.h>

//function prototypes
struct tnode *addtree(struct tnode *, int );
void treeprint(struct tnode *);
struct tnode *talloc(void);

//tnode structure definition
struct tnode {
    int key ;
    struct tnode *left;
    struct tnode *right;
};

int main(void)
{
    struct tnode *root;
    int key;
    
    // read from a file
    FILE *fPtr;
    fPtr = fopen("inputList.txt","r");  // the data in the file can be put one integer per line
    // or all integers on one line
    
    if(fPtr == NULL) printf("file could not be opened\n");
    else {
        root = NULL;
        //while(!feof(fPtr)){  // This reads the last number twice; maybe the problem lies in
        // checking for the end of file before reding anything
        //fscanf(fPtr, "%d", &key);
        while(fscanf(fPtr, "%d", &key)!=EOF){  // this works correctly
            root  = addtree(root, key);
            // printf("Added key %d to the tree\n", key); // the last number is being added twice
        }
        treeprint(root);
    }
    fclose(fPtr);
    return 0;
}  // end of main

/*addtree:  add a  node with w, at or below p */
struct tnode *addtree(struct tnode *p, int key)
{
    
    if (p == NULL) { /* a new key has arrived */
        p = talloc();   /* make a new node */
        p-> key = key;
        p->left = p->right = NULL;
    }
    else if (p->key > key)
    /* insert into left subtree */
        p->left = addtree(p->left, key);
    else
        p->right= addtree(p->right, key);
    return p;
} // end of addtree

/*talloc  : make a tnode */
struct tnode *talloc(void)
{
    return (struct tnode *)malloc(sizeof(struct tnode));
} // end of tnode

/* treeprint: inorder printing of the nodes */
void treeprint(struct tnode *p)
{
    if (p != NULL) {
        treeprint(p->left);
        // printf("%d\n", p->key);
        treeprint(p->right);
        printf("%d\n", p->key);
    }
    return;
} // end of treeprint

