

#include <stdio.h>
#include <unistd.h>

void another(void);

int main(void)
{
    int i=0;
    char line[100]="Hello\n";
    while(line[i] != NULL){
        putchar(line[i++]);
        sleep(1);
    }
    //hello this is a change to my file.

    another();
    
}

void another(void)
{
    int i=0;
    char line[100]="Hello, my name is donkey\n";
    while (line[i]!=NULL) {
        putchar(line[i++]);
        fflush(stdout);
        sleep(1);
    }
}