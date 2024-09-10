#include <iostream>
#include <cstring>
#include <cctype>

using namespace std;

char input[100];
int i = 0;
char l;

void E();
void E_();
void T();
void T_();
void F();

void match(char c) {
    if (l == c)
        l = input[++i];
    else {
        cout << "Invalid Input" << endl;
        exit(0);
    }
}

void E() {
    T();
    E_();
}

void E_() {
    if (l == '+') {
        match('+');
        T();
        E_();
    }
    // If E' is epsilon, do nothing (return without action)
}

void T() {
    F();
    T_();
}

void T_() {
    if (l == '*') {
        match('*');
        F();
        T_();
    }
    // If T' is epsilon, do nothing (return without action)
}

void F() {
    if (l == '(') {
        match('(');
        E();
        match(')');
    } else if (isalnum(l)) { // Match 'id' (considering id as a single character variable)
        match(l); // Consume the character
    } else {
        cout << "Invalid Input" << endl;
        exit(0);
    }
}

int main() {
    cout << "Enter the string to parse (end with $): ";
    cin >> input;

    l = input[i];
    E();

    if (l == '$')
        cout << "Parsing Successful" << endl;
    else
        cout << "Invalid Input" << endl;

    return 0;
}
