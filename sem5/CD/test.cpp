#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <sstream>
using namespace std;

// Function to find First of a given non-terminal
set<string> findFirst(string nonTerminal, map<string, vector<vector<string>>> &productions, map<string, set<string>> &firstSet) {
    // If the first set is already computed, return it
    if (!firstSet[nonTerminal].empty()) {
        return firstSet[nonTerminal];
    }

    // Iterate over all productions of the non-terminal
    for (auto &production : productions[nonTerminal]) {
        bool allNullable = true; // To track if all symbols in the production can derive epsilon

        for (string &symbol : production) {
            if (productions.find(symbol) == productions.end()) { // Terminal symbol
                firstSet[nonTerminal].insert(symbol);
                allNullable = false; // Terminal symbols cannot derive epsilon
                break;
            } else { // Non-terminal symbol
                set<string> firstOfSymbol = findFirst(symbol, productions, firstSet);
                firstSet[nonTerminal].insert(firstOfSymbol.begin(), firstOfSymbol.end());

                // Remove epsilon temporarily as we want to check the next symbol
                if (firstOfSymbol.find("ε") != firstOfSymbol.end()) {
                    firstSet[nonTerminal].erase("ε");
                } else {
                    allNullable = false;
                    break;
                }
            }
        }

        // If all symbols in the production can derive epsilon, add epsilon to the first set
        if (allNullable) {
            firstSet[nonTerminal].insert("ε");
        }
    }

    return firstSet[nonTerminal];
}
// Function to find Follow of a given non-terminal
void findFollow(string nonTerminal, map<string, vector<vector<string>>> &productions, map<string, set<string>> &firstSet, map<string, set<string>> &followSet) {
    for (auto &production : productions) {
        for (auto &rule : production.second) {
            for (size_t i = 0; i < rule.size(); ++i) {
                if (rule[i] == nonTerminal) {
                    if (i + 1 < rule.size()) {
                        string nextSymbol = rule[i + 1];
                        if (productions.find(nextSymbol) != productions.end()) {
                            set<string> firstOfNext = firstSet[nextSymbol];
                            if (firstOfNext.find("ε") != firstOfNext.end()) {
                                firstOfNext.erase("ε");
                                followSet[nonTerminal].insert(followSet[production.first].begin(), followSet[production.first].end());
                            }
                            followSet[nonTerminal].insert(firstOfNext.begin(), firstOfNext.end());
                        } else {
                            followSet[nonTerminal].insert(nextSymbol);
                        }
                    } else {
                        if (production.first != nonTerminal) {
                            followSet[nonTerminal].insert(followSet[production.first].begin(), followSet[production.first].end());
                        }
                    }
                }
            }
        }
    }
}

int main() {
    int numNonTerminals, numTerminals;
    cin >> numNonTerminals >> numTerminals;

    vector<string> nonTerminals(numNonTerminals);
    vector<string> terminals(numTerminals);

    for (int i = 0; i < numNonTerminals; ++i) {
        cin >> nonTerminals[i];
    }

    for (int i = 0; i < numTerminals; ++i) {
        cin >> terminals[i];
    }

    map<string, vector<vector<string>>> productions;

    string line;
    cin.ignore(); // to ignore the newline after the last terminal
    for (int i = 0; i < numNonTerminals; ++i) {
        getline(cin, line);
        istringstream iss(line);
        string lhs, arrow, temp;
        iss >> lhs >> arrow;

        vector<string> rhs;
        while (iss >> temp) {
            if (temp != "|") {
                rhs.push_back(temp);
            } else {
                productions[lhs].push_back(rhs);
                rhs.clear();
            }
        }
        productions[lhs].push_back(rhs);
    }

    map<string, set<string>> firstSet, followSet;
    
    // Compute the First sets
    for (auto &nonTerminal : nonTerminals) {
        findFirst(nonTerminal, productions, firstSet);
    }

    // Initialize Follow sets
    followSet[nonTerminals[0]].insert("$");
    
    // Compute the Follow sets
    for (int i = 0; i < 2; ++i) { // Iterate twice to ensure propagation
        for (auto &nonTerminal : nonTerminals) {
            findFollow(nonTerminal, productions, firstSet, followSet);
        }
    }

    // Output the results
    cout << "Non Terminal (NT) First(NT)        Follow(NT)\n";
    for (auto &nonTerminal : nonTerminals) {
        cout << nonTerminal << "         ";
        
        for (auto &symbol : firstSet[nonTerminal]) {
            cout << symbol << " ";
        }
        
        cout << "       ";
        
        for (auto &symbol : followSet[nonTerminal]) {
            cout << symbol << " ";
        }
        
        cout << endl;
    }

    return 0;
}