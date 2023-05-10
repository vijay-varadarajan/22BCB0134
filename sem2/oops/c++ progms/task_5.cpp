#include <iostream>

using namespace std;

class Week{         // class Week
    private:        // declare private variable
        int day_num; 

    public:         // public methods
        Week(int num){          // constructor, takes day number as argument
            day_num = num;      // sets private variable to argument value
        }

        string find_day(){      // class method to find day for given day number
            switch(day_num){
                case 1:
                    return "Sunday";
                    break;
                case 2:
                    return "Monday";
                    break;
                case 3: 
                    return "Tuesday";
                    break;
                case 4:
                    return "Wednesday";
                    break;
                case 5:
                    return "Thursday";
                    break;
                case 6:
                    return "Friday";
                    break;
                case 7:
                    return "Saturday";
                    break;
                default:
                    return "Invalid day number";
            }
        }
};

int main(void)
{
    int num;
    cout << "Enter day number of the week: "; 
    cin >> num;

    Week day(num);         // call constructor with input number as parameter to initialize object
    cout << "Day: " << day.find_day();      // call method to find the day
}