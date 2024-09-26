/*
To validate the PAN Number. The input should be stored in a text file. The valid
PAN Card number must satisfy the following conditions,
 It should be 10 characters long.
 The first five characters should be any upper case alphabets.
 The next four-characters should be any number from 0 to 9.
 The fifth character should be the first alphabet of the PAN card holder name.
 It should not contain any white spaces.
*/

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
    string pan;
    ifstream inputFile("input_pan.txt");

    if (!inputFile) {
        cout << "Error opening file" << endl;
        return 1;
    }

    string word1, word2;
    inputFile >> word1 >> word2;
    cout << word1 << " " << word2 << endl;
    pan = word2;

    inputFile.close();

    if (pan.length() != 10) {
        cout << "Invalid PAN Number" << endl;
        return 0;
    }

    for (int i = 0; i < 5; i++) {
        if (pan[i] < 'A' || pan[i] > 'Z') {
            cout << "Invalid PAN Number" << endl;
            return 0;
        }
    }

    if (pan[4] != word1[0]) {
        cout << "Invalid PAN Number" << endl;
        return 0;
    }

    for (int i = 5; i < 9; i++) {
        if (pan[i] < '0' || pan[i] > '9') {
            cout << "Invalid PAN Number" << endl;
            return 0;
        }
    }

    if (pan[9] < 'A' || pan[9] > 'Z') {
        cout << "Invalid PAN Number" << endl;
        return 0;
    }

    cout << "Valid PAN Number" << endl;

    return 0;
}