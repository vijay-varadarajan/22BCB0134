#include <stdio.h>
#include <string.h>

int main(void)
{
    char s1[10], s2[5];
    printf("Enter original string: ");
    scanf("%s", s1);
    printf("Enter string to search: ");
    scanf("%s", s2);
    if (strstr(s1, s2))
        printf("successful");
    else
        printf("Unsuccessful");
}