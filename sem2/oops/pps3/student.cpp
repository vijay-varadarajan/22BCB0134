#include <iostream>

using namespace std;

class Student {     // parent class 'Student'
    public:
        string name; int id; int age;   // declaration of public variables 

        Student() {                     // constructor to set default values
            name = "XYZ"; 
            id = 0;
            age = 0;
        }

        void Getstu() {                 // Method to get student details
            cout << "Enter the name: " ; cin >> name;
            cout << "Enter the ID: " ; cin >> id;
            cout << "Enter the age: "; cin >> age;
        }

        void Putstu() {                 // Method to print student details
            cout << "\nName: " << name << endl;
            cout << "ID: " << id << endl;
            cout << "Age: " << age << endl;
        }
};

class Undergraduate: public Student {   // child class 'Undergradute' derived from parent class 'Student'
    public: 
        int UGCourses;                  //declaration of public variable 'UGCourses'

        Undergraduate() {               // constructor to set default values
            UGCourses = 0;
        }

        void GetUGCourses() {           // Method to get UGCourses value
            cout << "Enter the number of UG courses offered: "; cin >> UGCourses;
        }

        void PutUGCourses() {           // Method to display the number of 'UGCourses'
            cout << "Number of UG courses offered: " << UGCourses << endl;
        }
};

class Postgraduate: public Student {    // child class 'Postgraduate' derived from parent class 'Student'
    public: 
        int PGCourses;                  //declaration of public variable 'PGCourses'

        Postgraduate() {                // constructor to set default values
            PGCourses = 0;
        }

        void GetPGCourses() {           // Method to get PGCourses value
            cout << "Enter the number of PG courses offered: "; cin >> PGCourses;
        }

        void PutPGCourses() {           // Method to display the number of 'PGCourses'
            cout << "Number of PG courses offered: " << PGCourses << endl;
        }
};

int main(void)
{   
    Undergraduate student1;

    student1.Getstu();
    student1.GetUGCourses();

    Postgraduate student2;

    student2.GetPGCourses();

    student1.Putstu();
    student1.PutUGCourses();
    student2.PutPGCourses();

    return 0;
}
