//Solution to Lab 5
// 03 August, 2013
// Author: Asish Mukhopadhyay
// works fine

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAXWORD 1000
#define BUFSIZE 100


struct tnode {
    char *word;
    int count ;
    struct tnode *left;
    struct tnode *right;
};

// prototypes
struct tnode *talloc(void);
//char *strdup(char *);  // this is probably defined in the standard library in a different  way
// so renaming it solved all problems
char  *dupStr(char *);
struct tnode *addtree(struct tnode *, char *);
void treeprint(struct tnode *);
void ungetch(int );
int getch(FILE *);
//int getword(FILE *, char *, int );
int getword(FILE *, char *, int );


int main(void)
{
    struct tnode *root;
    char word[MAXWORD];
    
    // read from a file
    FILE *fPtr;
    fPtr = fopen("inputTxt","r");
    
    if(fPtr == NULL) printf("file could not be opened\n");
    else {
        root = NULL;
        while (getword(fPtr, word, MAXWORD) != EOF)
            if(isalpha(word[0]))
                root  = addtree(root, word);
        treeprint(root);
    }
    return 0;
}

/*addtree:  add a  node with w, at or below p */
struct tnode *addtree(struct tnode *p, char *w)
{
    int cond;
    
    if (p == NULL) { /* a new word has arrived */
        p = talloc();   /* make a new node */
        //p->word = strdup(w);
        p->word = dupStr(w);
        p-> count = 1;
        p->left = p->right = NULL;
    }
    else if ((cond = strcmp(w, p->word)) == 0)
        p->count++;  /*repeated word */
    else if (cond < 0)   /* insert into left subtree */
        p->left = addtree(p->left, w);
    else
        p->right= addtree(p->right, w);
    return p;
}

/*talloc  : make a tnode */
struct tnode *talloc(void)
{
    return (struct node *)malloc(sizeof(struct tnode));
}

/* treeprint: inorder printing of the nodes */

void treeprint(struct tnode *p)
{
    if (p != NULL) {
        treeprint(p->left);
        printf("%4d %s \n", p->count, p->word);
        treeprint(p->right);
    }
    return;
}

/* get next word or character from input */
int getword(FILE *fPtr, char *word, int lim)
{
    /*declarations*/
    int c, getch(FILE *);
    //int c, fgetc(fPtr);
    void  ungetch(int);
    char *w = word;
    
    while (isspace((c = getch(fPtr)))) // skip spaces
        ;
    if (c != EOF)
        *w++ = c;
    if (!isalpha(c)) {
        *w = '\0';
        return c;
    } // end of if
    
    for (  ; --lim > 0; w++)
        if (!isalnum(*w = getch(fPtr))){
            ungetch(*w);
            break;
        } // end of if
    *w = '\0';
    return word[0];
} // end of getword


char buf[BUFSIZE]; /*bufffer for ungetch */
int bufp  =  0; /* next free position in buf */

//int getch(void) /* get a (possibly pushed back) character */
int getch(FILE *fPtr) /* get a (possibly pushed back) character */
{
    //return (bufp >0)  ?  buf[--bufp] :  getchar();
    return (bufp >0)  ?  buf[--bufp] :  fgetc(fPtr);
}

void ungetch(int c) /* push character back on inout */
{
    if (bufp  >=  BUFSIZE)
        printf("ungetch: too many characters \n");
    else
        buf[bufp++]  =  c;
}

//char *strdup(char *s) /*make a duplicate of s */
char *dupStr(char *s) /*make a duplicate of s */
{
    char *p;
    p = (char *) malloc(strlen(s) + 1); /* +1 for ‘\0’ */
    if (p!= NULL)
        strcpy(p,s);
    return p;
}
