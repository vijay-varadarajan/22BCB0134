#include <iostream>
using namespace std;

class Ascii {
    char character;

public:
    void setCharacter(char c){
        this -> character = c;
    } 
    
    int Asciivalue(){
        return int(character);
    } 
};

int main() {
    Ascii convert; char input;

    cout << "Enter a character: "; cin >> input;
    convert.setCharacter(input);
    
    cout << "Ascii value of " << input << " is " << convert.Asciivalue() << endl;
    return 0;
}