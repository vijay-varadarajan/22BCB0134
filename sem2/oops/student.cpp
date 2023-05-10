#include <iostream>

using namespace std;

class Student{
    public: 
        int regno;
        string name;
        string address;
};

class Exam: public Student{
    public:
        int marks[5];
};

class Sports{
    public:
        string sport_name;
        int score;
};

class Result: public Sports, public Exam{
    public:
        string eligibility(int avg, int score){
            if (avg > 80 && score > 80){
                return "Eligible";
            }
            else{
                return "Not eligible";
            }
        }
};

float calcavg(int marks[]){
    float avg;
    for (int i = 0; i < 5; i++)
        avg += marks[i];

    avg /= 5;
    return avg;
}

int main(void){
    Result students[5];
    for (int i = 0; i < 5; i++){
        cout << "Enter student " << i+1 << " marks: " << endl;
        for (int j = 0; j < 5; j++){
            cout << "Enter mark " << j+1 << " : ";
            cin >> students[i].marks[j];
        }
        cout << "Enter sports score: ";
        cin >> students[i].score;
        
        float avg = calcavg(students[i].marks);

        cout << students[i].eligibility(avg, students[i].score) << endl;
    }
}
