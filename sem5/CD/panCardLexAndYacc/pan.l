%{
#include <stdio.h>
#include <string.h>
#include <ctype.h>  // For toupper()
#include "y.tab.h"  // Include the token definitions from Yacc
int isValidPAN = 0;  // Global variable to store validation result
%}

%%

([a-zA-Z]+)[ ]+([A-Z]{5}[0-9]{4}[A-Z]) {
    // Extract the name and PAN card number
    char name[100], pan[11];
    sscanf(yytext, "%s %s", name, pan);

    // Check if the last character of PAN matches the first letter of the name
    if (toupper(pan[9]) == toupper(name[0])) {
        isValidPAN = 1;  // Valid PAN card number
    } else {
        isValidPAN = 0;  // Invalid PAN card number
    }
    return VALID_PAN;  // Return token VALID_PAN to Yacc
}

.|\n { 
    isValidPAN = 0;  // Invalid format
    return VALID_PAN;  // Return token VALID_PAN to Yacc
}

%%

int yywrap() {
    return 1;
}
