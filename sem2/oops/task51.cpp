#include <iostream>

using namespace std;

class MenuItem{             // parent class
    public: 
        string name;        // public parent class variables
        float calories; 
        
        void print(){       // print method defined in parent class
            cout << name <<  " (" << calories << " cal)" << endl;
        }
};

class Beverage: public MenuItem{    // Beverage class - child of MenuItem class
    public:
        float ounces;               // child class variables

        float cal_per_ounce()       // child class method
        {
            return calories / ounces;
        }
};

int main(void)
{
    MenuItem Noodles;               // object of parent class
    Noodles.name = "Egg Chow Mein"; 
    Noodles.calories = 300;

    Noodles.print();

    Beverage Soda;                  // object of child class 
    Soda.name = "Pepsi";            // Soda has access to variables name and calories in MenuItem class
    Soda.calories = 100;            
    Soda.ounces = 10;

    Soda.print();                   // It also has access to print method along with cal_per_ounce method
    cout << "Calories per ounce: " << Soda.cal_per_ounce() << endl;

    return 0;
}
