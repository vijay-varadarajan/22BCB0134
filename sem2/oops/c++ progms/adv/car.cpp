#include <iostream>
#include <string>

using namespace std;

class Car {
private:
    int carNumber;
    string model;
    double rentalRate;
    bool availability;

public:
    Car(int number, const string& carModel, double rate) {
        carNumber = number;
        model = carModel;
        rentalRate = rate;
        availability = true;
    }

    void rentCar() {
        if (availability) {
            availability = false;
            cout << "Car " << carNumber << " has been rented." << endl;
        } else {
            cout << "Car " << carNumber << " is not available for rent." << endl;
        }
    }

    void returnCar() {
        if (!availability) {
            availability = true;
            cout << "Car " << carNumber << " has been returned." << endl;
        } else {
            cout << "Car " << carNumber << " is already available." << endl;
        }
    }

    double calculateRentalCharges(int numberOfDays) {
        return rentalRate * numberOfDays;
    }

    void displayCarDetails() {
        cout << "Car Number: " << carNumber << endl;
        cout << "Model: " << model << endl;
        cout << "Rental Rate per Day: $" << rentalRate << endl;
        cout << "Availability: " << (availability ? "Available" : "Not Available") << endl;
    }
};

int main() {
    // Create car objects
    Car car1(1, "Sedan", 50.0);
    Car car2(2, "SUV", 80.0);
    Car car3(3, "Hatchback", 40.0);

    // Display car details
    cout << "Car Details:" << endl;
    car1.displayCarDetails();
    cout << endl;
    car2.displayCarDetails();
    cout << endl;
    car3.displayCarDetails();
    cout << endl;

    // Rent a car
    car1.rentCar();
    cout << endl;
    car2.rentCar();
    cout << endl;
    car3.rentCar();
    cout << endl;

    // Return a car
    car1.returnCar();
    cout << endl;
    car2.returnCar();
    cout << endl;
    car3.returnCar();
    cout << endl;

    // Calculate rental charges
    int numberOfDays = 5;
    double charges = car1.calculateRentalCharges(numberOfDays);
    cout << "Rental Charges for Car 1: $" << charges << endl;

    return 0;
}
