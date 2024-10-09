%{
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX 100

int precedence(char);
void yyerror(const char *s);
int yylex(void);
void push(char);
char pop();
void convertToPostfix(char *);

char stack[MAX];
int top = -1;
char postfix[MAX];
int postfixIndex = 0;
extern char *yytext;  
%}

%token NUM
%token PLUS MINUS MULT DIV
%left PLUS MINUS
%left MULT DIV

%%

input:
    | input expr '\n' { printf("Postfix: %s\n", postfix); postfixIndex = 0; }
    ;

expr:
    expr PLUS expr { postfix[postfixIndex++] = ' '; postfix[postfixIndex++] = '+'; }
    | expr MINUS expr { postfix[postfixIndex++] = ' '; postfix[postfixIndex++] = '-'; }
    | expr MULT expr { postfix[postfixIndex++] = ' '; postfix[postfixIndex++] = '*'; }
    | expr DIV expr { postfix[postfixIndex++] = ' '; postfix[postfixIndex++] = '/'; }
    | '(' expr ')'  { /* do nothing */ }
    | NUM           { postfix[postfixIndex++] = ' '; postfix[postfixIndex++] = yytext[0]; }
    ;

%%

void yyerror(const char *s) {
    fprintf(stderr, "Error: %s\n", s);
}

int main() {
    printf("Enter infix expression:\n");
    yyparse();
    return 0;
}

int precedence(char symbol) {
    switch (symbol) {
        case '+':
        case '-': return 1;
        case '*':
        case '/': return 2;
        default: return 0;
    }
}
