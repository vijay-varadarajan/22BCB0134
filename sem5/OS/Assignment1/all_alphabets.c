// c program to print all alphabets from a-z

#include <stdio.h>

int main()
{
    char ch;
    for(ch = 'a'; ch <= 'z'; ch++)
    {
        printf("%c ", ch);
    }
    return 0;
}