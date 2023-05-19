#include <iostream>
using namespace std;

class Shape {
    protected:      // protected variables for shape edges, corners and diagonals
        int edge_count;
        int corner_count;
        int diagonal_count;

    public:
        Shape() {   // constructor
            edge_count = 0;
            corner_count = 0;
            diagonal_count = 0;
        }

        // public setter methods
        void setEdges(int e) {
            edge_count = e;
        }

        void setCorners(int c) {
            corner_count = c;
        }

        void setDiagonals(int d) {
            diagonal_count = d;
        }
};

class Color {
    protected:      // protected variables to store RGB values
        int red_val;
        int green_val;
        int blue_val;

    public:
        Color() {   // constructor
            red_val = 0;
            green_val = 0;
            blue_val = 0;
        }

        // public setter methods
        void setRed(int r) {
            red_val = r;
        }

        void setGreen(int g) {
            green_val = g;
        }

        void setBlue(int b) {
            blue_val = b;
        }
};

// inherited class through multiple inheritance
class Square : public Shape, public Color {
    
    // all public setter methods of parent classes are inherited

    public:
        void display() {
            cout << "Square characteristics" << endl;
            cout << "Edges: " << edge_count << endl;
            cout << "Corners: " << corner_count << endl;
            cout << "Diagonals: " << diagonal_count << endl;
            cout << "Red: " << red_val << endl;
            cout << "Green: " << green_val << endl;
            cout << "Blue: " << blue_val << endl;
        }
};

int main() {
    // object created for child class
    Square square;

    // set square values through the methods of parent classes
    square.setEdges(4);
    square.setCorners(4);
    square.setDiagonals(2);
    square.setRed(200);
    square.setGreen(155);
    square.setBlue(40);

    // display through child class method
    square.display();

    return 0;
}