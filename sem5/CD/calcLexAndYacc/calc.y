%{
#include <stdio.h>
#include <stdlib.h>

int vars[26];  // Store values for variables (A-Z)

void yyerror(const char *s);
int yylex(void);
void handleDivisionByZero();
%}

%token VAR NUM
%token ASSIGN PLUS MINUS MULT DIV

%%

input:
    | input line
    ;

line:
    expr '\n'           { printf("Output -> %d\n", $1); }
    | VAR ASSIGN expr '\n' { vars[$1 - 'A'] = $3; }
    | '\n'              { /* ignore empty lines */ }
    ;

expr:
    NUM                 { $$ = $1; }
    | VAR               { $$ = vars[$1 - 'A']; }
    | expr PLUS expr    { $$ = $1 + $3; }
    | expr MINUS expr   { $$ = $1 - $3; }
    | expr MULT expr    { $$ = $1 * $3; }
    | expr DIV expr     {
                           if ($3 == 0) {
                               handleDivisionByZero();
                           } else {
                               $$ = $1 / $3;
                           }
                         }
    ;

%%

void yyerror(const char *s) {
    fprintf(stderr, "Error: %s\n", s);
}

void handleDivisionByZero() {
    printf("INVALID: Division by zero\n");
    exit(1);
}

int main() {
    printf("Enter expressions (e.g., A = 120):\n");
    yyparse();
    return 0;
}