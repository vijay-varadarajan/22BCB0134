%{
#include <stdio.h>
int count = 0;
%}

%%
[C][a-zA-Z][tT] {
    printf("Matching word: %s\n", yytext);
}
\n 
.  
%%

int main() {
    printf("Enter text:\n");
    yylex();
    return 0;
}