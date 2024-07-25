#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SYMBOLS 100

typedef struct {
    char name[20];
    int address;
} Symbol;

Symbol symbolTable[MAX_SYMBOLS];
int symbolCount = 0;

void addToSymbolTable(char* name, int address) {
    if (symbolCount < MAX_SYMBOLS) {
        strcpy(symbolTable[symbolCount].name, name);
        symbolTable[symbolCount].address = address;
        symbolCount++;
    } else {
        printf("Symbol table is full. Cannot add more symbols.\n");
    }
}

void printSymbolTable() {
    printf("Symbol Table:\n");
    printf("Name\tAddress\n");
    for (int i = 0; i < symbolCount; i++) {
        printf("%s\t%d\n", symbolTable[i].name, symbolTable[i].address);
    }
}

int main() {
    // Your C program code goes here

    // Example usage:
    addToSymbolTable("variable1", 100);
    addToSymbolTable("variable2", 200);
    addToSymbolTable("variable3", 300);

    printSymbolTable();

    return 0;
}

// Function to parse the input C program and extract symbols
void parseCProgram(char* program) {
    // Your code to parse the program and extract symbols goes here
    // You can use string manipulation functions like strtok, strstr, etc.
    // Iterate through the program and identify symbols, then call addToSymbolTable function to add them to the symbol table
}

// Read the input C program from a file
char* readCProgramFromFile(char* filename) {
    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        printf("Failed to open file: %s\n", filename);
        return NULL;
    }

    fseek(file, 0, SEEK_END);
    long fileSize = ftell(file);
    fseek(file, 0, SEEK_SET);

    char* program = (char*)malloc(fileSize + 1);
    if (program == NULL) {
        printf("Failed to allocate memory for program\n");
        fclose(file);
        return NULL;
    }

    fread(program, 1, fileSize, file);
    program[fileSize] = '\0';

    fclose(file);

    return program;
}

int main() {
    char* filename = "/C:/Users/vijay/Documents/22BCB0134/sem5/CD/input.c";
    char* program = readCProgramFromFile(filename);
    if (program != NULL) {
        parseCProgram(program);
        printSymbolTable();
        free(program);
    }

    return 0;
}