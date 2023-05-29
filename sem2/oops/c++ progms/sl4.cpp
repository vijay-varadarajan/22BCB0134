#include <iostream>
#define MAX 100

using namespace std;

class ArraySum{
    int n;
    int arr1[MAX], arr2[MAX], sumarr[MAX];

    public: 
        void getArr(){
            cout << "Enter the size of arrays: "; cin >> n;
            for (int i = 0; i < n; i++){
                cout << "arr1[" << i << "] = " ; cin >> arr1[i];
            }
            for (int i = 0; i < n; i++){
                cout << "arr2[" << i << "] = " ; cin >> arr2[i];
            }
        }

        void arrSum(){
            for (int i = 0; i < n; i++) {
                sumarr[i] = arr1[i] + arr2[i];
            }
            for (int i = 0; i < n; i++) {
                cout << sumarr[i] << " ";
            }
        }
};

int main(void){
    ArraySum calc;
    calc.getArr();
    cout << "Sum of arrays: " << endl;
    calc.arrSum();
}
