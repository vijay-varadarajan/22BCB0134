#include <iostream>
#include <map>
#include <set>
#include <vector>
#include <sstream>
#include <algorithm>

using namespace std;

map<string, set<string>> first, follow;
map<string, vector<vector<string>>> productions;
vector<string> nonTerminals, terminals;
int numNonTerminals, numTerminals;
string startSymbol;

// Function to find the First set for a non-terminal
set<string> findFirst(const string& symbol) {
    if (!first[symbol].empty()) return first[symbol]; // If already computed

    set<string> result;

    for (auto& production : productions[symbol]) {
        for (auto& rhsSymbol : production) {
            if (find(terminals.begin(), terminals.end(), rhsSymbol) != terminals.end()) {
                result.insert(rhsSymbol);  // Terminal found
                break;
            }
            else if (rhsSymbol == "epsilon") {
                result.insert("epsilon");
                break;
            }
            else {
                set<string> firstOfSymbol = findFirst(rhsSymbol);
                result.insert(firstOfSymbol.begin(), firstOfSymbol.end());
                if (firstOfSymbol.find("epsilon") == firstOfSymbol.end()) {
                    break;
                }
            }
        }
    }

    first[symbol] = result;
    return result;
}

// Function to find the Follow set for a non-terminal
void findFollow(const string& symbol) {
    if (!follow[symbol].empty()) return;

    for (auto& productionPair : productions) {
        for (auto& production : productionPair.second) {
            for (int i = 0; i < production.size(); i++) {
                if (production[i] == symbol) {
                    if (i + 1 < production.size()) {
                        string nextSymbol = production[i + 1];
                        if (find(terminals.begin(), terminals.end(), nextSymbol) != terminals.end()) {
                            follow[symbol].insert(nextSymbol); // Next symbol is a terminal
                        } else {
                            set<string> firstNextSymbol = findFirst(nextSymbol);
                            follow[symbol].insert(firstNextSymbol.begin(), firstNextSymbol.end());
                            follow[symbol].erase("epsilon");

                            if (firstNextSymbol.find("epsilon") != firstNextSymbol.end() && productionPair.first != symbol) {
                                findFollow(productionPair.first);
                                follow[symbol].insert(follow[productionPair.first].begin(), follow[productionPair.first].end());
                            }
                        }
                    } else {
                        if (productionPair.first != symbol) {
                            findFollow(productionPair.first);
                            follow[symbol].insert(follow[productionPair.first].begin(), follow[productionPair.first].end());
                        }
                    }
                }
            }
        }
    }
}

int main() {
    cout << "Enter the number of non-terminals: ";
    cin >> numNonTerminals;
    cout << "Enter the number of terminals: ";
    cin >> numTerminals;

    cout << "Enter the non-terminals: ";
    for (int i = 0; i < numNonTerminals; i++) {
        string nt;
        cin >> nt;
        nonTerminals.push_back(nt);
    }

    cout << "Enter the terminals: ";
    for (int i = 0; i < numTerminals; i++) {
        string t;
        cin >> t;
        terminals.push_back(t);
    }

    cout << "Enter the start symbol: ";
    cin >> startSymbol;

    cin.ignore();  // To consume the newline character

    // Input grammar production rules
    cout << "Enter the production rules in the format 'LHS -> RHS':\n";
    for (int i = 0; i < numNonTerminals; i++) {
        string lhs, rhsLine;
        cout << "RHS of " << nonTerminals[i] << ": ";
        getline(cin, rhsLine);

        lhs = nonTerminals[i];
        istringstream iss(rhsLine);
        string rhsPart;
        while (getline(iss, rhsPart, ',')) {
            istringstream rhsStream(rhsPart);
            vector<string> rhsSymbols;
            string symbol;
            while (rhsStream >> symbol) {
                rhsSymbols.push_back(symbol);
            }
            productions[lhs].push_back(rhsSymbols);
        }
    }

    // Compute First sets
    for (const string& nt : nonTerminals) {
        findFirst(nt);
    }

    // Add "$" to the follow of the start symbol
    follow[startSymbol].insert("$");

    // Compute Follow sets
    for (const string& nt : nonTerminals) {
        findFollow(nt);
    }

    // Output First and Follow sets
    cout << "Non Terminal (NT)   First(NT)    Follow(NT)\n";
    for (const string& nt : nonTerminals) {
        cout << nt << "               { ";
        for (const string& f : first[nt]) {
            cout << f << " ";
        }
        cout << "}          { ";
        for (const string& f : follow[nt]) {
            cout << f << " ";
        }
        cout << "}\n";
    }

    return 0;
}
