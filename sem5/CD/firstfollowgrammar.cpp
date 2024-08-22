#include<iostream>
#include<vector>
#include<map>
#include<set>
#include<string>

using namespace std;

map<char, set<char>> first;
map<char, set<char>> follow;
map<char, vector<string>> productions;
set<char> nonterminals;
set<char> terminals;

void calculateFirst(char nt) {
for(string prod: productions[nt]) {
for(char symbol: prod) {
if (terminals.find(symbol) != terminals.end()) {
first[nt].insert(symbol);
break;
} else if ( nonterminals.find(symbol) != nonterminals.end()) {
if (first[symbol].empty()) {
calculateFirst(symbol);
}
first[nt].insert(first[symbol].begin(), first[symbol].end());
if (first[symbol].find('e') == first[symbol].end()){
break;
}
}
}
}
map<char, set<char>> follow;
map<char, vector<string>> productions;
set<char> nonterminals;
set<char> terminals;

}

void calculateFollow(char nt) {
for(auto&[lhs, rhs_list]: productions) {
for(string rhs: rhs_list) {
for(size_t i = 0; i < rhs.size(); ++i) {
if (rhs[i] == nt){
if (i+1 < rhs.size()){
char next = rhs[i+1];
if (terminals.find(next)!=terminals.end()) {
follow[nt].insert(next);
} else {
follow[nt].insert(first[next].begin(), first[next].end());
follow[nt].erase('e');
if (first[next].find('e') != first[next].end()){
follow[nt].insert(follow[lhs].begin(), follow[lhs].end());
}
}
} else {
follow[nt].insert(follow[lhs].begin(), follow[lhs].end());
}
}
}
}
}
}

int main(){
int num_non_terminals, num_terminals;
cout << "Enter number of non terminals: ";
cin >> num_non_terminals;
cout << "Enter the number of terminals: ";
cin >> num_terminals;

cout << "Enter the non terminals: ";
for(int i = 0; i < num_non_terminals; i++) {
char nt;
cin >> nt;
nonterminals.insert(nt);
first[nt] = set<char>();
follow[nt] = set<char>();
}

cout << "Enter the terminals: ";
for(int i = 0; i < num_terminals; i++) {
char t;
cin >> t;
terminals.insert(t);
}

int num_prods;
cout << "Enter the number of productions: ";
cin >> num_prods;

cout << "Enter the productions: " ;
for (int i= 0; i < num_prods; i++) {
string production;
cin >> production;
char lhs = production[0];
string rhs = production.substr(3);
productions[lhs].push_back(rhs);
}

follow[*nonterminals.begin()].insert('$');

for(char nt: nonterminals) {
calculateFirst(nt);
}

for(char nt: nonterminals) {
calculateFollow(nt);
}

cout << "\nFirst and follow sets: \n";
for (char nt: nonterminals){
cout << "First (" << nt << ") = ";
for (char ch: first[nt]) {
cout << ch << " ";
}
cout << "\n";

cout << "Follow (" << nt << ") = ";
for (char ch: follow[nt]) {
cout << ch << " ";
}
cout << "\n";
}

return 0;
}