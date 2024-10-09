%{
#include <stdio.h>
#include <stdlib.h>
#include "y.tab.h"
%}

%%

[0-9]         { yylval = atoi(yytext); return NUM; }
"("           { return '('; }
")"           { return ')'; }
"+"           { return PLUS; }
"-"           { return MINUS; }
"*"           { return MULT; }
"/"           { return DIV; }
[ \t]+        { /* ignore whitespace */ }
\n            { return '\n'; }
.             { return yytext[0]; }

%%

int yywrap() {
    return 1;
}
