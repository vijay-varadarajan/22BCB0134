%{
#include <stdio.h>
#include <string.h>
int valid = 0;
%}

%%
^(http:\/\/|https:\/\/)?[a-zA-Z0-9]+([-.]{1}[a-zA-Z0-9]+)*\.[a-zA-Z]{2,5}(:[0-9]{1,5})?(\/.*)?$ {
    valid = 1;
}

.|\n { /* Ignore any other characters */ }

%%

int main() {
    printf("Enter a URL to validate:\n");
    yylex();
    if (valid) {
        printf("Valid URL\n");
    } else {
        printf("Invalid URL\n");
    }
    return 0;
}

int yywrap() {
    return 1;
}