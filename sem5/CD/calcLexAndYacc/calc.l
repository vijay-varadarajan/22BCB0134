%{
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "y.tab.h"  // Include Yacc definitions
%}

%%

[A-Z]       { yylval = yytext[0]; return VAR; }
[0-9]+      { yylval = atoi(yytext); return NUM; }
"="         { return ASSIGN; }
"+"         { return PLUS; }
"-"         { return MINUS; }
"*"         { return MULT; }
"/"         { return DIV; }
[ \t]+      { /* Ignore whitespace */ }
\n          { return '\n'; }
.           { return yytext[0]; }

%%

int yywrap() {
    return 1;
}