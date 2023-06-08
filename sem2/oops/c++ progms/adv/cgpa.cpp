#include <iostream>
#include <string>
using namespace std;

class Student {
private:
    string name;
    int rNum;

public:
    void details() {
        cout << "Enter name: ";
        cin >> name;
        cout << "Enter roll number: ";
        cin >> rNum;
    }

    void dispdetails() {
        cout << "Name: " << name << endl;
        cout << "Roll Number: " << rNum << endl;
    }
};

class CGPACalculator : public Student {
private:
    int subs;
    float* gpts;

public:
    void grades() {
        cout << "Enter the number of subjects: ";
        cin >> subs;
        gpts = new float[subs];
        for (int i = 0; i < subs; i++) {
            cout << "Enter grade point for subject " << i+1 << ": ";
            cin >> gpts[i];
        }
    }

    float calc() {
        float totalgpts = 0;
        for (int i = 0; i < subs; i++) {
            totalgpts += gpts[i];
        }
        float cgpa = (float)totalgpts / subs;
        return cgpa;
    }

    void disp() {
        float cgpa = calc();
        cout << "CGPA: " << cgpa << endl;
    }
};

int main() {
    CGPACalculator student1;
    CGPACalculator student2;

    student1.details();
    student1.grades();
    student1.dispdetails();

    student2.details();
    student2.grades();
    student2.dispdetails();
    
    student1.disp();
    student2.disp();

    return 0;
}
