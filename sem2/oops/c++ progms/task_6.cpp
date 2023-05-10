#include <iostream>

using namespace std;

class Child // class for a child
{
    public: // variables for child class - name, marks, rank
        string name;
        int marks;
        int rank;
};

void calcRank(Child children[]){
    for (int i = 0; i < 6; i++){    // set all ranks to one
        children[i].rank = 1;
    }

    // loop through and compare each mark with others and increment rank if mark is lower
    for(int i = 0; i < 6; i++) {
        for(int j = i + 1; j < 6; j++) {
            if(children[i].marks < children[j].marks) {
                children[i].rank++;
            } else if(children[i].marks > children[j].marks) {
                children[j].rank++;
            }
        }
    }

}

int main(void)
{
    Child children[6];

    // get name and marks as input
    for (int i = 0; i < 6; i++){
        cout << "Enter student " << i+1 << " name: "; cin >> children[i].name;
        cout << "Enter student " << i+1 << " mark: "; cin >> children[i].marks;
    }

    calcRank(children); // calculate ranks

    cout << endl;
    for (int i = 0; i < 6; i++){    // print rank with names
        cout << children[i].name << ": Rank - " << children[i].rank << endl;
    }
}