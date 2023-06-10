#include <iostream>

using namespace std;

class creditCardValidator{
    long long int cardNum;

    public:
        creditCardValidator(long long int num){
            cardNum = num;
        }

        bool Validate(long long int cardNum){
            int sum = 0, count = 0;
            cardNum /= 10;    // removing the check digit (last digit)
            
            while (cardNum > 0){
                int val = cardNum % 10;
                if (count % 2 != 0)
                    val *= 2;
                if (val > 9){
                    int lastdig = val % 10;
                    val /= 10;
                    val += lastdig;
                }
                count++;
                
                sum += val;
                cardNum /= 10;
            }
        
            if (sum % 10 == 0)
                return true;
            return false;
        }


        void displayResult(long long int cardNum){
            if (Validate(cardNum) == true)
                cout << "The credit card number is valid" << endl;
            else
                cout << "The credit card number is invalid" << endl;
        }
};


int main(void){
    long long int cardnumber;
    cout << "Enter credit card number: "; cin >> cardnumber;

    creditCardValidator num(cardnumber);
    
    num.displayResult(cardnumber);
    return 0;
}
