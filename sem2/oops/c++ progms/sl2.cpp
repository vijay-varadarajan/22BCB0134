#include <iostream>
#include <cmath>

using namespace std;

double compIntr(double principal, double rate, double time) {
    double amt = principal * pow(1 + (rate / 100), time);
    return (amt - principal);
}

int main() {
    double principal, rate, time;
    
    cout << "Enter the principal amount: "; cin >> principal;
    
    cout << "Enter the interest rate: "; cin >> rate;
    
    cout << "Enter the time period (in years): "; cin >> time;
    
    double compintr = compIntr(principal, rate, time);
    
    cout << "Compound Interest: " << compintr << endl;
    cout << "Final amount: " << compintr + principal << endl;
    return 0;
}