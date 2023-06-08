#include <iostream>
#include <string>

using namespace std;

class Car {
private:
    int carNum;
    bool avail;

public:
    Car(int number) {
        carNum = number;
        avail = true;
    }

    int getCarNum() {
        return carNum;
    }

    bool isAvail() {
        return avail;
    }

    void bookCar() {
        if (avail) {
            avail = false;
            cout << "Car " << carNum << " has been booked." << endl;
        } else {
            cout << "Car " << carNum << " is not available for booking." << endl;
        }
    }

    void returnCar() {
        if (!avail) {
            avail = true;
            cout << "Car " << carNum << " has been returned." << endl;
        } else {
            cout << "Car " << carNum << " is already available." << endl;
        }
    }
};

class Customer {
private:
    int id;
    string name;
    Car* bookedCars[10];
    int bookedCount;

public:
    Customer(int id, const string& name) {
        this -> id = id;
        this -> name = name;
        bookedCount = 0;
    }

    int getid() {
        return id;
    }

    string getName() {
        return name;
    }

    void bookCar(Car* car) {
        if (car->isAvail()) {
            bookedCars[bookedCount] = car;
            bookedCount++;
            car->bookCar();
        } else {
            cout << "Car " << car->getCarNum() << " is not available for booking." << endl;
        }
    }

    void returnCar(Car* car) {
        if (car->isAvail()) {
            cout << "Car " << car->getCarNum() << " is already available." << endl;
        } else {
            for (int i = 0; i < bookedCount; i++) {
                if (bookedCars[i] == car) {
                    bookedCars[i] = bookedCars[bookedCount-1];
                    bookedCount--;
                    car->returnCar();
                    return;
                }
            }
            cout << "Car " << car->getCarNum() << " was not booked by customer " << id << "." << endl;
        }
    }

    void displayBookingDetails() {
        cout << "Booking details for Customer " << id << " - " << name << ":" << endl;
        if (bookedCount == 0) {
            cout << "No cars booked." << endl;
        } else {
            cout << "Booked Cars:" << endl;
            for (int i = 0; i < bookedCount; i++) {
                cout << "Car Number: " << bookedCars[i]->getCarNum() << endl;
            }
        }
    }
};

int main() {
    // Create car objects
    Car car1(1);
    Car car2(2);
    Car car3(3);

    // Create customer objects
    Customer customer1(101, "John");
    Customer customer2(102, "Emma");

    // Book cars
    customer1.bookCar(&car1);
    customer1.bookCar(&car2);
    customer2.bookCar(&car3);
    cout << endl;

    // Return cars
    customer1.returnCar(&car1);
    customer2.returnCar(&car3);
    cout << endl;

    // Display booking details
    customer1.displayBookingDetails();
    cout << endl;
    customer2.displayBookingDetails();

    return 0;
}
