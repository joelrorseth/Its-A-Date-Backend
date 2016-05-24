//
//  Title: getLine.c
//  Date: July 22, 2013
//  Name: Ryan Pearson
//  ID: 103965059
//  Program: Getline function- supplied from template with modifications.
//

int getlines(char s[], int lim)
{
    int c, i;
    i = 0;
    while (--lim > 0 && (c = getchar()) != EOF && c != '\n')
        s[i++] = c;
    if (c == '\n')
        s[i++] = '\n';
    // this statement allows a double return escape clause
    if (s[0] == '\n')               // this line has been added
        return 0;                   // this line has been added
    s[i] = '\0';
    return i;
}

