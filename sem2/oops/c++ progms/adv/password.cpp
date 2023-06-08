#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>

using namespace std;

class PassGen {
private:
    int len;
    string pwd;

public:
    PassGen(int length) {
        len = length;
        pwd = "";
        generate();
    }

    void generate() {
        srand(time(nullptr));
        string chars = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
        int charsLen = chars.length();

        for (int i = 0; i < len; i++) {
            pwd += chars[rand() % charsLen];
        }
    }

    void display() {
        cout << "Generated Password: " << pwd << endl;
    }
};

int main() {
    int length;
    cout << "Enter the length of the password: ";
    cin >> length;

    PassGen pwd(length);
    pwd.display();

    return 0;
}
