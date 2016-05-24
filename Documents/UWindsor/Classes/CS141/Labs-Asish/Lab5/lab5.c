//
//  Title: lab5.c
//  Date: July 30, 2013
//  Name: Ryan Pearson
//  ID: 103965059
//  Program: read in a text file and sort the occurance of each word
//

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#define MAXLENGTH 1000
#define SIZE 500

// struct definition
typedef struct tnode{
    char *word;
    int freq;
    struct tnode *left;
    struct tnode *right;
}Values;

// function prototypes
void breakline (char *, int, Values **Values1, int *);
void addword (char *begin, char * end, Values **Values1, int *);
struct tnode * addtree(Values * p, char *w);
struct tnode *talloc(void);
void postorder(struct tnode *p);
void preorder(struct tnode *p);
void inorder(struct tnode *p);

int
main(void)
{
    char line[MAXLENGTH];

    Values * tnode = NULL;          // create list array of structs
    int listsize = 0;
    
    FILE * fptr;
    if ((fptr = fopen("Words", "r")) == NULL){
        printf("No file.\n");
        return -1;
    }
    
    // reads the text into one string array, changes newlines to '\0''s
    while (fgets(line, MAXLENGTH, fptr)){
        breakline(line, strlen(line), &tnode, &listsize);
    }
    // reset stdin and loop over printing order for user
    fclose(stdin);
    freopen("/dev/tty", "r", stdin);
    do{
        printf("Would you like:\n1.Preorder\n2.Inorder\n3.Postorder\n4.Exit\n");
        if(!scanf("%d", &listsize)){
            fclose(stdin);
            freopen("/dev/tty", "r", stdin);
            printf("Invalid Input. Try again!\n");
        }
        switch (listsize) {
            case 1:
                preorder(tnode);
                break;
            case 2:
                inorder(tnode);
                break;
            case 3:
                postorder(tnode);
                break;
            default:
                break;
        }
    }while (listsize != 4);
    
    fclose(fptr);

    return 0;
}
// use state's to go in and out of words and separate them
void breakline ( char * lineb, int length, Values **Values1, int *listsize)
{
    int state = 1;                      // catch whitespace at beginning of line
    char *endword = lineb;
    char *startword = lineb;
    
    // loop over string going in and out of states to separate words
    while (endword != lineb + length){
        switch (state) {
            case 0:
                if (!isalpha(*endword)){
                    addword(startword, endword, Values1, listsize);
                    state = 1;
                }
                break;
            case 1:
                if (isalpha(*endword)){
                    startword = endword;
                    state = 0;
                }
        }
        endword++;
    }
}


// print elements to screen one at a time using pointer to beginning and end of word
void addword (char *begin, char * end, Values **Values1, int *listsize)
{
    int wordsize = end - begin;             // get size of word
    char *buffer;                           // holder for word
    buffer = malloc(sizeof(wordsize));      // allocate space for word in buffer variable

    strncpy(buffer, begin, wordsize);       // copy the word into buffer
    buffer[wordsize] = '\0';                // assign final element of array to '\0'
    
    // add values to tree
    *Values1 = addtree(*Values1, buffer);
    
}

/* Function: create the tree, add new struct, or increment frequency of existing element
 Input: one char * variable and pointer to the structure
 Output: pointer to structure */
struct tnode * addtree(Values * p, char * w)
{
    int cond;
    if (p == NULL) {
        /* a new word has arrived */
        p = malloc(sizeof(struct tnode));
        /* make a new node */
        // allocate memory to the variable word in new node
        p->word = calloc(1, 100);
        strcpy (p->word , w);
        p->freq = 1;
        p->left = p->right = NULL;
    }
    else if ((cond = strcmp(w, p->word)) == 0)
        p->freq++;
    /*repeated word */
    else if (cond < 0)
    /* insert into left subtree */
        p->left = addtree(p->left, w);
    else
        p->right= addtree(p->right, w);
    return p;
}

/* Function: preorder printing of the nodes
 Input: pointer to struct
 Output: nothing */
void preorder(struct tnode *p)
{
    if (p != NULL) {
        printf("%4d %s \n", p->freq, p->word);
        preorder(p->left);
        preorder(p->right);
    }
}

/* Function: inorder printing of the nodes 
 Input: pointer to struct
 Output: nothing */
void inorder(struct tnode *p)
{
    if (p != NULL) {
        inorder(p->left);
        printf("%4d %s \n", p->freq, p->word);        
        inorder(p->right);
    }
}

/* Function: postorder printing of the nodes 
 Input: Pointer to struct
 Output: nothing */
void postorder(struct tnode *p)
{
    if (p != NULL) {
        postorder(p->left);
        postorder(p->right);
        printf("%4d %s \n", p->freq, p->word);
    }
}