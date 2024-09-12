%%
"<"[^>]+">" {
    printf("HTML Tag: %s\n", yytext);
}
\n { /* New line */ }
.  { /* Ignore everything else */ }
%%

int main() {
    printf("Enter HTML content:\n");
    yylex();
    return 0;
}

int yywrap() {
    return 1;
}