#include <iostream>

using namespace std;

class Vehicle{
    public:
        float weight;
        float length, breadth, height;

        Vehicle(float weight, float length, float breadth, float height){
            this -> weight = weight;
            this -> length = length;
            this -> breadth = breadth;
            this -> height = height;
        }

        void printvehicleInfo(){
            cout << "Vehicle's weight: " << this->weight << endl;
            cout << "Dimensions: " << this->length << "x" << this->breadth << "x" << this -> height << endl;
        }
};

class Car: public Vehicle {
    public: 
        string model;

        Car(string model, float weight, float length, float breadth, float height):Vehicle(weight, length, breadth, height){
            this->model = model;
            this->weight = weight;
            this->length = length;
            this->breadth = breadth;
            this->height = height;
        }

        void printInfo(){
            cout << "Model: " << this->model << endl;
        }
};

int main(void){
    Car car1("Audi", 200.35, 3.5, 1.57, 1.25);
    car1.printvehicleInfo();
    car1.printInfo();
    return 0;
}
