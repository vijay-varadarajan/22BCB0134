#include <iostream>
#include <cmath>

using namespace std;

class Distance {
public:
    double calculateDistance(double x1, double y1, double x2, double y2) {
        double distance = sqrt(pow((x2 - x1), 2) + pow((y2 - y1), 2));
        return distance;
    }

    double calculateDistance(double x1, double y1, double z1, double x2, double y2, double z2) {
        double distance = sqrt(pow((x2 - x1), 2) + pow((y2 - y1), 2) + pow((z2 - z1), 2));
        return distance;
    }
};

int main() {
    Distance distanceCalculator;

    // 2D distance calculation
    double x1_2D = 2.0, y1_2D = 3.0;
    double x2_2D = 5.0, y2_2D = 7.0;
    double distance_2D = distanceCalculator.calculateDistance(x1_2D, y1_2D, x2_2D, y2_2D);
    cout << "Distance in 2D space: " << distance_2D << endl;

    // 3D distance calculation
    double x1_3D = 1.0, y1_3D = 2.0, z1_3D = 3.0;
    double x2_3D = 4.0, y2_3D = 5.0, z2_3D = 6.0;
    double distance_3D = distanceCalculator.calculateDistance(x1_3D, y1_3D, z1_3D, x2_3D, y2_3D, z2_3D);
    cout << "Distance in 3D space: " << distance_3D << endl;

    return 0;
}
