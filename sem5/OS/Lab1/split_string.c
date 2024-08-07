// split given string into substrings c program

#include <stdio.h>
#include <string.h>

int main() {
    char str[100];
    printf("Enter a string: ");
    fgets(str, sizeof(str), stdin);
    str[strcspn(str, "\n")] = '\0';
    printf("The substrings are: \n");
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == ' ') {
            printf("\n");
        } else {
            printf("%c", str[i]);
        }
    }
    return 0;
}