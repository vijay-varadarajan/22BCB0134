#include <iostream>

using namespace std;

class sum{
    private:
    int value, increment, element[20];

    public:
        sum(int size, int x){
            for (int i = 0; i < size; i++)
                element[i] = 1;
            int value = element[0];
            
            for(increment = 1; increment <= size - 1; increment++)
                {
                    value = x*value + element[increment];
                    cout << value << endl;
                }

            cout << value;
        }
};

int main(){
    sum obj(10,2);
    return 0;
}