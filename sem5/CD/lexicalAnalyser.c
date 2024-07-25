#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LENGTH 10000
#define MAX_TOKENS 1000

typedef struct {
    char* tokens[MAX_TOKENS];
    int count;
} TokenList;

TokenList operators, identifiers, constants, keywords, special_symbols, format_specifiers;

bool isDelimiter(char chr)
{
    return (chr == ' ' || chr == '+' || chr == '-'
            || chr == '*' || chr == '/' || chr == ','
            || chr == ';' || chr == '%' || chr == '>'
            || chr == '<' || chr == '=' || chr == '('
            || chr == ')' || chr == '[' || chr == ']'
            || chr == '{' || chr == '}');
}

bool isOperator(char chr)
{
    return (chr == '+' || chr == '-' || chr == '*'
            || chr == '/' || chr == '>' || chr == '<'
            || chr == '=');
}

bool isValidIdentifier(char* str)
{
    return (str[0] != '0' && str[0] != '1' && str[0] != '2'
            && str[0] != '3' && str[0] != '4'
            && str[0] != '5' && str[0] != '6'
            && str[0] != '7' && str[0] != '8'
            && str[0] != '9' && !isDelimiter(str[0]));
}

bool isKeyword(char* str)
{
    const char* keywords[]
        = { "auto",    "break", "case",    "char",
            "const", "continue", "default", "do",
            "double", "else",    "enum",    "extern",
            "float", "for",    "goto",    "if",
            "int",    "long",    "register", "return",
            "short", "signed", "sizeof", "static",
            "struct", "switch", "typedef", "union",
            "unsigned", "void",    "volatile", "while" };
    for (int i = 0; i < sizeof(keywords) / sizeof(keywords[0]); i++) {
        if (strcmp(str, keywords[i]) == 0) {
            return true;
        }
    }
    return false;
}

bool isInteger(char* str)
{
    if (str == NULL || *str == '\0') {
        return false;
    }
    int i = 0;
    while (isdigit(str[i])) {
        i++;
    }
    return str[i] == '\0';
}

bool isFormatSpecifier(char* str)
{
    return (strcmp(str, "%d") == 0 || strcmp(str, "%f") == 0 ||
            strcmp(str, "%c") == 0 || strcmp(str, "%s") == 0 ||
            strcmp(str, "%p") == 0 || strcmp(str, "%x") == 0 ||
            strcmp(str, "%X") == 0 || strcmp(str, "%u") == 0 ||
            strcmp(str, "%ld") == 0 || strcmp(str, "%lf") == 0 ||
            strcmp(str, "%lu") == 0);
}

char* getSubstring(char* str, int start, int end)
{
    int subLength = end - start + 1;
    char* subStr = (char*)malloc((subLength + 1) * sizeof(char));
    strncpy(subStr, str + start, subLength);
    subStr[subLength] = '\0';
    return subStr;
}

void addToken(TokenList* list, char* token)
{
    if (list->count < MAX_TOKENS) {
        list->tokens[list->count] = strdup(token);
        list->count++;
    }
}

void lexicalAnalyzer(char* input)
{
    int left = 0, right = 0;
    int len = strlen(input);

    while (right <= len && left <= right) {
        if (!isDelimiter(input[right]))
            right++;

        if (isDelimiter(input[right]) && left == right) {
            if (isOperator(input[right])) {
                char op[2] = {input[right], '\0'};
                addToken(&operators, op);
            }
            else if (input[right] == '%') {
                // Check for format specifier
                char* subStr = getSubstring(input, right, right + 1);
                if (isFormatSpecifier(subStr)) {
                    addToken(&format_specifiers, subStr);
                    right++;
                } else {
                    addToken(&special_symbols, "%");
                }
                free(subStr);
            }
            else if (input[right] != ' ' && input[right] != '\n') {
                char symbol[2] = {input[right], '\0'};
                addToken(&special_symbols, symbol);
            }

            right++;
            left = right;
        }
        else if (isDelimiter(input[right]) && left != right
                 || (right == len && left != right)) {
            char* subStr = getSubstring(input, left, right - 1);

            if (isKeyword(subStr))
                addToken(&keywords, subStr);
            else if (isInteger(subStr))
                addToken(&constants, subStr);
            else if (isValidIdentifier(subStr)
                     && !isDelimiter(input[right - 1]))
                addToken(&identifiers, subStr);

            free(subStr);
            left = right;
        }
    }
}

void writeTokens(FILE* file, const char* category, TokenList* list)
{
    fprintf(file, "%s:\n", category);
    for (int i = 0; i < list->count; i++) {
        fprintf(file, "%s\n", list->tokens[i]);
    }
    fprintf(file, "\n");
}

void freeTokenList(TokenList* list)
{
    for (int i = 0; i < list->count; i++) {
        free(list->tokens[i]);
    }
}

int main()
{
    FILE *input_file, *output_file;
    char input[MAX_LENGTH] = {0};
    char temp[MAX_LENGTH];

    input_file = fopen("inputcode.txt", "r");
    if (input_file == NULL) {
        printf("Could not open input file.\n");
        return 1;
    }

    while (fgets(temp, MAX_LENGTH, input_file) != NULL) {
        strcat(input, temp);
    }
    fclose(input_file);

    lexicalAnalyzer(input);

    output_file = fopen("output.txt", "w");
    if (output_file == NULL) {
        printf("Could not create output file.\n");
        return 1;
    }

    writeTokens(output_file, "Operators", &operators);
    writeTokens(output_file, "Identifiers", &identifiers);
    writeTokens(output_file, "Constants", &constants);
    writeTokens(output_file, "Keywords", &keywords);
    writeTokens(output_file, "Special Symbols", &special_symbols);
    writeTokens(output_file, "Format Specifiers", &format_specifiers);

    fclose(output_file);

    freeTokenList(&operators);
    freeTokenList(&identifiers);
    freeTokenList(&constants);
    freeTokenList(&keywords);
    freeTokenList(&special_symbols);
    freeTokenList(&format_specifiers);

    printf("Lexical analysis complete. Results written to output.txt\n");

    return 0;
}