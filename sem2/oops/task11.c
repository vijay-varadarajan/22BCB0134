#include<stdio.h>
#include<string.h>

int main(void)
{
    // Get string input from user and store it in an array
    char str[20];
    printf("Enter a string: ");
    scanf("%s", str);

    // Printing the length of the string using strlen
    int length = strlen(str);
    printf("\nLength of string: %d\n", length);

    // Copy str to str2 using strcpy
    char str2[20];
    strncpy(str2, str, 5);
    printf("\nOriginal string, str: %s\nCopied string, str2: %s\n", str, str2);

    // Concatenate str to the end of newstr using strcat
    char newstr[10] = "Hello, ";
    printf("\nConcatenated string: %s\n", strcat(newstr, str));
}