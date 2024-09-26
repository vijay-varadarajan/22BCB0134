%{
#include <stdio.h>
#include <stdlib.h>

int yylex();
void yyerror(const char *s);
extern int isValidPAN;  // Use the variable from Lex
%}

%token VALID_PAN  // Define token for valid PAN validation

%%

input:
    PAN_VALIDATION
    | PAN_VALIDATION '\n'
    ;

PAN_VALIDATION:
    VALID_PAN {
        if (isValidPAN) {
            printf("Valid PAN card number\n");
        } else {
            printf("Invalid PAN card number\n");
        }
    }
    ;

%%

void yyerror(const char *s) {
    fprintf(stderr, ".");
}

int main() {
    printf("Enter the first name followed by PAN card number (Example: John ABCDE1234J):\n");
    yyparse();  // Start parsing
    return 0;
}
