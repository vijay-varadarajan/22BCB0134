#include <iostream>

using namespace std;

class Matrix{
        int rows;
        int cols;
        int **matrix;   // declare double pointer variable matrix for 2d array
        
    public: 
        Matrix(int rows, int cols){ // constructor to initialize row and column values and allocate memory for matrix
            this -> rows = rows;
            this -> cols = cols;

            // allocate memory for a matrix object based on number of rows and columns
            matrix = new int *[rows];
            for (int i = 0; i < rows; i++) {
                matrix[i] = new int[cols];
            };
        }

        // get user inputs for matrix elements
        void read(){
            for (int i = 0; i < rows; i++){
                for (int j = 0; j < cols; j++){
                    cout << "Enter element [" << i+1 << "," << j+1 << "] : ";
                    cin >> this -> matrix[i][j];
                }
            }
        }

        // display the matrix elements
        void display() {
            for (int i = 0; i < rows; i++) {
                for (int j = 0; j < cols; j++) {
                    cout << this -> matrix[i][j] << " ";
                }
                cout << endl;
            }
        }

        // overload + operator
        Matrix operator+(Matrix matrix2){
            Matrix sum(rows, cols);
            for(int i = 0; i < rows; i++){
                for (int j = 0; j < cols; j++){
                    sum.matrix[i][j] = this -> matrix[i][j] + matrix2.matrix[i][j];
                }
            }
            return sum;
        }

        // overload '-' operator
        Matrix operator-(Matrix matrix2){
            Matrix diff(rows, cols);
            for(int i = 0; i < rows; i++){
                for (int j = 0; j < cols; j++){
                    diff.matrix[i][j] = this -> matrix[i][j] - matrix2.matrix[i][j];
                }
            }
            return diff;
        }
};

int main(void){
    int rows, cols;
    char oper;

    cout << "Enter number of rows: "; cin >> rows;
    cout << "Enter number of columns: "; cin >> cols;
    Matrix matrix1(rows, cols);
    Matrix matrix2(rows, cols);
    Matrix summ(rows, cols);
    Matrix diff(rows, cols);
    
    cout << "Enter elements for matrix 1: " << endl;
    matrix1.read();

    cout << "Enter elements for matrix 2: " << endl;
    matrix2.read();

    cout << "Enter operator to perform operation [+/-]: "; cin >> oper;
    
    // perform operation based on user's choice
    if (oper == '+'){
        summ = matrix1 + matrix2;
        cout << "Sum: " << endl;
        summ.display();
    } else if (oper == '-') {
        diff = matrix1 - matrix2;
        cout << "Difference: " << endl;
        diff.display();
    } else {
        cout << "Wrong operator" << endl;
    }
}
