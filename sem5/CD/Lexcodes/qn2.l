%{
#include <stdio.h>
#include <string.h>
int operators = 0, identifiers = 0, keywords = 0, specialSymbols = 0;
char *keywords_list[] = {"int", "return", "if", "else", "for", "while", "float", "double", "char"};
int isKeyword(char *word) {
    for (int i = 0; i < sizeof(keywords_list)/sizeof(char*); i++) {
        if (strcmp(word, keywords_list[i]) == 0)
            return 1;
    }
    return 0;
}
%}

%%
"+"|"-"|"*"|"/"|"="   { operators++; }
[a-zA-Z_][a-zA-Z0-9_]* {
    if (isKeyword(yytext)) {
        keywords++;
    } else {
        identifiers++;
    }
}
"(" | ")" | "{" | "}" | ";" | ","  { specialSymbols++; }
.  
\n 
%%

int main() {
    printf("Enter the C code:\n");
    yylex();
    printf("Operators: %d\nIdentifiers: %d\nKeywords: %d\nSpecial Symbols: %d\n", operators, identifiers, keywords, specialSymbols);
    return 0;
}

int yywrap() {
    return 1;
}