#include <iostream>

using namespace std;

class Employee{
    float basic, hra, da, wagesPerHr, hrs, consPay;

    public:
        void set_details(){
            cout << "Basic: "; cin >> this -> basic;
            cout << "HRA: "; cin >> this -> hra;
            cout << "DA: "; cin >> this -> da;
            cout << "Wages per hour: "; cin >> this -> wagesPerHr;
            cout << "Number of hours: "; cin >> this -> hrs;
            cout << "Consolidated pay: "; cin >> this -> consPay;
        }

        // getter methods
        float get_basic(){
            return this -> basic;
        }
        float get_hra(){
            return this -> hra;
        }
        float get_da(){
            return this -> da;
        }
        float get_wagesPerHr(){
            return this -> wagesPerHr;
        }
        float get_hrs(){
            return this -> hrs;
        }
        float get_consPay(){
            return this -> consPay;
        }

        // overloaded salary method
        float salary(float basic, float hra, float da){
            return basic + hra + da;
        }
        float salary(float wagesPerHr, float hrs){
            return wagesPerHr * hrs;
        }
        float salary(float consPay){
            return consPay;
        }
};


int main(void){
    Employee newemployee;

    newemployee.set_details();
    if (newemployee.get_hra() > 0.5*newemployee.get_basic()){
        cout << "\nInvalid pay scale";
        return 1;
    }

    cout << "\nRegular employees: " << newemployee.salary(newemployee.get_basic(), newemployee.get_hra(), newemployee.get_da()) << endl;

    cout << "Daily wages: " << newemployee.salary(newemployee.get_wagesPerHr(), newemployee.get_hrs()) << endl;

    cout << "Consolidated pay: " << newemployee.salary(newemployee.get_consPay()) << endl;
    return 0;
}