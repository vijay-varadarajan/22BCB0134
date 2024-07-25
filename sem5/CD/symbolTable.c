#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_SYMBOL_LENGTH 50
#define MAX_TYPE_LENGTH 20
#define MAX_ATTR_LENGTH 100
#define TABLE_SIZE 100

typedef struct {
    char name[MAX_SYMBOL_LENGTH];
    char type[MAX_TYPE_LENGTH];
    char attributes[MAX_ATTR_LENGTH];
} Symbol;

typedef struct {
    Symbol* symbols;
    int size;
    int capacity;
} SymbolTable;

// Function prototypes
SymbolTable* allocate();
void free_table(SymbolTable* table);
Symbol* lookup(SymbolTable* table, const char* name);
void insert(SymbolTable* table, const char* name, const char* type);
const char* get_attribute(SymbolTable* table, const char* name);
void set_attribute(SymbolTable* table, const char* name, const char* attr);
void parse_file(SymbolTable* table, const char* filename);
void write_table(SymbolTable* table, const char* filename);

// Allocate a new symbol table
SymbolTable* allocate() {
    SymbolTable* table = (SymbolTable*)malloc(sizeof(SymbolTable));
    table->symbols = (Symbol*)malloc(TABLE_SIZE * sizeof(Symbol));
    table->size = 0;
    table->capacity = TABLE_SIZE;
    return table;
}

// Free the symbol table
void free_table(SymbolTable* table) {
    free(table->symbols);
    free(table);
}

// Look up a symbol in the table
Symbol* lookup(SymbolTable* table, const char* name) {
    for (int i = 0; i < table->size; i++) {
        if (strcmp(table->symbols[i].name, name) == 0) {
            return &table->symbols[i];
        }
    }
    return NULL;
}

// Insert a new symbol into the table
void insert(SymbolTable* table, const char* name, const char* type) {
    if (lookup(table, name) == NULL) {
        if (table->size >= table->capacity) {
            table->capacity *= 2;
            table->symbols = (Symbol*)realloc(table->symbols, table->capacity * sizeof(Symbol));
        }
        strcpy(table->symbols[table->size].name, name);
        strcpy(table->symbols[table->size].type, type);
        table->symbols[table->size].attributes[0] = '\0';
        table->size++;
    }
}

// Get the attributes of a symbol
const char* get_attribute(SymbolTable* table, const char* name) {
    Symbol* symbol = lookup(table, name);
    if (symbol != NULL) {
        return symbol->attributes;
    }
    return NULL;
}

// Set the attributes of a symbol
void set_attribute(SymbolTable* table, const char* name, const char* attr) {
    Symbol* symbol = lookup(table, name);
    if (symbol != NULL) {
        strcpy(symbol->attributes, attr);
    }
}

// Parse the input file and build the symbol table
void parse_file(SymbolTable* table, const char* filename) {
    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error opening file: %s\n", filename);
        return;
    }

    char line[256];
    while (fgets(line, sizeof(line), file)) {
        char* token = strtok(line, " \t\n;(){}");
        while (token != NULL) {
            if (strcmp(token, "int") == 0 || strcmp(token, "float") == 0 || 
                strcmp(token, "char") == 0 || strcmp(token, "double") == 0) {
                char* var_name = strtok(NULL, " \t\n;(){}");
                if (var_name != NULL) {
                    insert(table, var_name, token);
                }
            }
            token = strtok(NULL, " \t\n;(){}");
        }
    }

    fclose(file);
}

// Write the symbol table to an output file
void write_table(SymbolTable* table, const char* filename) {
    FILE* file = fopen(filename, "w");
    if (file == NULL) {
        printf("Error opening file for writing: %s\n", filename);
        return;
    }

    fprintf(file, "Symbol Name\tType\tAttributes\n");
    fprintf(file, "-----------------------------------\n");
    for (int i = 0; i < table->size; i++) {
        fprintf(file, "%s\t\t%s\t%s\n", 
                table->symbols[i].name, 
                table->symbols[i].type, 
                table->symbols[i].attributes);
    }

    fclose(file);
}

int main() {
    SymbolTable* table = allocate();

    // Parse input file
    parse_file(table, "inputcode.txt");

    // Example of setting attributes
    set_attribute(table, "x", "initialized");
    set_attribute(table, "y", "used in calculation");

    // Write symbol table to output file
    write_table(table, "symbol_table.txt");

    // Free the symbol table
    free_table(table);

    printf("Symbol table has been written to symbol_table.txt\n");

    return 0;
}