%{
#include <stdio.h>
int vowels = 0;     // Counter for vowels
int consonants = 0; // Counter for consonants
%}

%%

[aAeEiIoOuU]  { vowels++; }    // Match vowels and increment the vowel counter
[b-df-hj-np-tv-zB-DF-HJ-NP-TV-Z] { consonants++; }  // Match consonants and increment the consonant counter

.|\n  ;   // Ignore any other characters (e.g., numbers, spaces, punctuation)

%%

int main() {
    printf("Enter a string: ");
    yylex();  // Invoke the lexical analyzer to process the input
    printf("Number of vowels: %d\n", vowels);
    printf("Number of consonants: %d\n", consonants);
    return 0;
}

int yywrap() {
    return 1;  // Indicate the end of input
}
