%{
#include <stdio.h>
#include <string.h>
int count_vowels(const char* str) {
    int count = 0;
    for (int i = 0; str[i] != '\0'; i++) {
        if (strchr("aeiouAEIOU", str[i])) {
            count++;
        }
    }
    return count;
}
%}

%%
[a-zA-Z]+ {
    if (count_vowels(yytext) >= 2) {
        printf("Word with at least two vowels: %s\n", yytext);
    }
}
\n { /* New line */ }
.  { /* Ignore everything else */ }
%%

int main() {
    printf("Enter text:\n");
    yylex();
    return 0;
}

int yywrap() {
    return 1;
}