#include <iostream>

using namespace std;

class Courier{
    public:
        int courierID;
        string name;

        void printBill(int base_fare)
        {
            cout << "\nCourierID: " << courierID << endl;
            cout << "Name of Courier: " << name << endl;
            cout << "Shipping cost: " << base_fare + 30 << endl;
        }
};

class International_services: public Courier{
    public:
        string destination;
        int weight;
        int total_cost;

        void FinalBill(){
            cout << "\nCourierID: " << courierID << endl;
            cout << "Name of Courier: " << name << endl;
            cout << "Destination: " << destination << endl; 
            cout << "Weight: " << weight << endl;
        }

        void FinalBill(int base_fare){
            total_cost = base_fare * weight;
            cout << "Total Shipping cost: " << total_cost << endl;

            if (total_cost > 100)
                cout << "More sale" << endl;
            else
                cout << "Less sale" << endl;
        }
};


int main(void)
{
    International_services courier1; 
    int base_fare;

    cout << "Enter the Courier ID: "; cin >> courier1.courierID;
    cout << "Enter the Name of the courier: "; cin >> courier1.name;
    cout << "Enter base fare: "; cin >> base_fare;
    cout << "Enter the weight in KG: "; cin >> courier1.weight;

    courier1.printBill(base_fare);
    courier1.FinalBill(base_fare);
}

