#include<iostream>
using namespace std;

class Prime {
    int num;
    
    public:
        void setnum() {
            cout << "Enter a number: ";
            cin >> num;
        }

        int getnum() {
            return this -> num;
        }

        bool isPrime() {
            if(num <= 1) {
                return false;
            }
            for(int i = 2; i <= num/2; i++) {
                if(num % i == 0) {
                    return false;
                }
            }
            return true;
        }
};


int main() {
    Prime num;
    num.setnum();

    num.isPrime() ? cout << num.getnum() << " is a prime number." << endl : cout << num.getnum() << " is not a prime number." << endl;

    return 0;
}
