#include <iostream>

using namespace std;

class TimeConverter {
public:
    int hoursToMinutes(int hours) {
        return hours * 60;
    }

    int hoursToSeconds(int hours) {
        return hours * 3600;
    }

    int minutesToSeconds(int minutes) {
        return minutes * 60;
    }
};

int main() {
    TimeConverter converter;

    // Convert hours to minutes
    int hours = 2;
    int minutes = converter.hoursToMinutes(hours);
    cout << hours << " hours is equivalent to " << minutes << " minutes." << endl;

    // Convert hours to seconds
    int seconds = converter.hoursToSeconds(hours);
    cout << hours << " hours is equivalent to " << seconds << " seconds." << endl;

    // Convert minutes to seconds
    int minutesInput = 30;
    int secondsOutput = converter.minutesToSeconds(minutesInput);
    cout << minutesInput << " minutes is equivalent to " << secondsOutput << " seconds." << endl;

    return 0;
}
