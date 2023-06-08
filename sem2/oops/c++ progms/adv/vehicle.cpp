#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Vehicle {
protected:
    string vehicleNumber;
    string type;
    double rentPerHour;
    bool available;

public:
    Vehicle(string number, string vehicleType, double rent)
        : vehicleNumber(number), type(vehicleType), rentPerHour(rent), available(true) {}

    string getVehicleNumber() const {
        return vehicleNumber;
    }

    string getType() const {
        return type;
    }

    double getRentPerHour() const {
        return rentPerHour;
    }

    bool isAvailable() const {
        return available;
    }

    void rent() {
        if (available) {
            available = false;
            cout << "Vehicle " << vehicleNumber << " rented successfully." << endl;
        } else {
            cout << "Sorry, the vehicle is not available for rent." << endl;
        }
    }

    void returnVehicle() {
        if (available) {
            cout << "The vehicle " << vehicleNumber << " is already available." << endl;
        } else {
            available = true;
            cout << "Vehicle " << vehicleNumber << " returned successfully." << endl;
        }
    }

    virtual double calculateRentalCharges(int hours) const {
        return rentPerHour * hours;
    }

    virtual void display() const {
        cout << "Vehicle Number: " << vehicleNumber << endl;
        cout << "Type: " << type << endl;
        cout << "Rent per Hour: $" << rentPerHour << endl;
        cout << "Availability: " << (available ? "Available" : "Not Available") << endl;
    }
};

class Car : public Vehicle {
private:
    int seatingCapacity;

public:
    Car(string number, double rent, int capacity)
        : Vehicle(number, "Car", rent), seatingCapacity(capacity) {}

    int getSeatingCapacity() const {
        return seatingCapacity;
    }

    void display() const override {
        Vehicle::display();
        cout << "Seating Capacity: " << seatingCapacity << " persons" << endl;
    }
};

class Bike : public Vehicle {
public:
    Bike(string number, double rent)
        : Vehicle(number, "Bike", rent) {}

    void display() const override {
        Vehicle::display();
    }
};

int main() {
    vector<Vehicle*> vehicles;

    // Creating car objects
    Car car1("CAR001", 10.0, 4);
    Car car2("CAR002", 12.5, 6);
    Car car3("CAR003", 15.0, 2);

    // Creating bike objects
    Bike bike1("BIKE001", 5.0);
    Bike bike2("BIKE002", 6.0);

    // Adding vehicles to the vector
    vehicles.push_back(&car1);
    vehicles.push_back(&car2);
    vehicles.push_back(&car3);
    vehicles.push_back(&bike1);
    vehicles.push_back(&bike2);

    // Displaying vehicle details
    for (const auto& vehicle : vehicles) {
        vehicle->display();
        cout << endl;
    }

    // Renting a vehicle
    car1.rent();

    // Returning a vehicle
    bike2.returnVehicle();

    // Calculating rental charges
    int rentalHours = 3;
    cout << "Rental Charges for car1 ("
         << car1.getVehicleNumber() << ") for " << rentalHours << " hours: $"
         << car1.calculateRentalCharges(rentalHours) << endl;

    return 0;
}
