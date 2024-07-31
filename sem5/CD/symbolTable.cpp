#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <unordered_map>
#include <memory>
#include <algorithm>

struct Symbol {
    std::string name;
    std::string type;
    std::string scope;
    int size;
    int address;
    int line_number;
};

class SymbolTable {
private:
    std::vector<std::unique_ptr<Symbol>> symbols;
    std::unordered_map<std::string, int> typeSizes = {
        {"int", 4},
        {"float", 4},
        {"char", 1},
        {"double", 8}
    };
    int currentAddress = 1000;
    std::string currentScope = "global";
    int currentLine = 0;

public:
    Symbol* allocate() {
        symbols.push_back(std::unique_ptr<Symbol>(new Symbol()));
        return symbols.back().get();
    }

    void free(Symbol* symbol) {
        auto it = std::find_if(symbols.begin(), symbols.end(),
            [symbol](const std::unique_ptr<Symbol>& s) { return s.get() == symbol; });
        if (it != symbols.end()) {
            symbols.erase(it);
        }
    }

    void set_attribute(Symbol* symbol, const std::string& attr, const std::string& value) {
        if (attr == "name") symbol->name = value;
        else if (attr == "type") {
            symbol->type = value;
            symbol->size = (value == "function") ? 0 : typeSizes[value];
            symbol->address = (value == "function") ? 0 : currentAddress;
            if (value != "function") currentAddress += symbol->size;
        }
        else if (attr == "scope") symbol->scope = value;
        else if (attr == "line_number") symbol->line_number = std::stoi(value);
    }

    std::string get_attribute(const Symbol* symbol, const std::string& attr) const {
        if (attr == "name") return symbol->name;
        if (attr == "type") return symbol->type;
        if (attr == "scope") return symbol->scope;
        if (attr == "size") return std::to_string(symbol->size);
        if (attr == "address") return std::to_string(symbol->address);
        if (attr == "line_number") return std::to_string(symbol->line_number);
        return "";
    }

    Symbol* lookup(const std::string& name) {
        auto it = std::find_if(symbols.begin(), symbols.end(),
            [&name](const std::unique_ptr<Symbol>& s) { return s->name == name; });
        return it != symbols.end() ? it->get() : nullptr;
    }

    void insert(const std::string& name, const std::string& type) {
        Symbol* symbol = allocate();
        set_attribute(symbol, "name", name);
        set_attribute(symbol, "type", type);
        set_attribute(symbol, "scope", currentScope);
        set_attribute(symbol, "line_number", std::to_string(currentLine));
    }

    void setScope(const std::string& scope) {
        currentScope = scope;
    }

    void printTable() {
        std::ofstream outputFile("output.txt");
        if (outputFile.is_open()) {
            outputFile << "NAME\tTYPE\tSCOPE\tSIZE\tADDRESS\tLINE" << std::endl;
            for (const auto& symbol : symbols) {
                outputFile << get_attribute(symbol.get(), "name") << "\t"
                           << get_attribute(symbol.get(), "type") << "\t"
                           << get_attribute(symbol.get(), "scope") << "\t"
                           << get_attribute(symbol.get(), "size") << "\t"
                           << get_attribute(symbol.get(), "address") << "\t"
                           << get_attribute(symbol.get(), "line_number") << std::endl;
            }
            outputFile.close();
        } else {
            std::cout << "Unable to open output file" << std::endl;
        }
    }

    void parseLine(const std::string& line) {
        std::istringstream iss(line);
        std::string word;
        currentLine++;

        while (iss >> word) {
            if (word == "int" || word == "float" || word == "char" || word == "double") {
                std::string name;
                iss >> name;
                if (name.back() == ';' || name.back() == ',') {
                    name.pop_back();
                }
                insert(name, word);
            } else if (word.find("(") != std::string::npos) {
                size_t nameEnd = word.find("(");
                std::string funcName = word.substr(0, nameEnd);
                insert(funcName, "function");
                setScope(funcName);
            } else if (word == "{") {
                setScope(currentScope + "_block");
            } else if (word == "}") {
                size_t lastUnderscore = currentScope.find_last_of("_");
                if (lastUnderscore != std::string::npos) {
                    currentScope = currentScope.substr(0, lastUnderscore);
                } else {
                    currentScope = "global";
                }
            }
        }
    }
};

int main() {
    SymbolTable symbolTable;
    std::ifstream inputFile("inputcode.txt");
    std::string line;

    if (inputFile.is_open()) {
        while (std::getline(inputFile, line)) {
            symbolTable.parseLine(line);
        }
        inputFile.close();
    } else {
        std::cout << "Unable to open input file" << std::endl;
        return 1;
    }

    symbolTable.printTable();
    return 0;
}