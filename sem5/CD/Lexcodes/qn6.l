%{
#include <string.h>
int count = 0;
char word[50];

%}

%%
[a-zA-Z]+ {
    if (strcmp(yytext, word) == 0) {
        count++;
    }
}
\n { /* New line */ }
.  { /* Ignore everything else */ }
%%

int main() {
    printf("Enter the word to count: ");
    scanf("%s", word);
    yylex();
    printf("Frequency of word '%s': %d\n", word, count);
    return 0;
}

int yywrap() {
    return 1;
}