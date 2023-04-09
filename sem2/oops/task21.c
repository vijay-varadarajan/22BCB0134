#include <stdio.h>
#define n 100

int fact(int);
// Functions accepting pointers to arrays as input parameters
void storeinput(int *input, int i, int value);
void getoutput(int *output, int *input);

int main(void)
{
    int N, value;
    printf("Enter number of inputs: "); scanf("%d", &N);
    
    static int input[n], output[n]; // Static input and output arrays

    for (int i = 0; i < N; i++)
    {
        printf("Enter number %d: ", i+1);
        scanf("%d", &value);
        storeinput(&input[0], i, value); // Address of input array passed in as argument with index to store input values
    }

    // Address of both input and output arrays passed to store the factorials of the input values
    getoutput(&output[0], &input[0]);
    
    for (int i = 0; i < N; i++)
    {        
        // Output array printed for corresponding inputs
        printf("%d! = %d\n", input[i], output[i]);
    }
}

// Function to calculate the factorial
int fact(int a)
{
    if (a <= 1)
        return 1;
    return a * fact(a - 1);
}

// Function to store input value in input array at specific index
void storeinput(int *input, int i, int value)
{
    input[i] = value;
}

// Function to store factorials of input values in output array
void getoutput(int *output, int *input)
{
    for (int i = 0; i < n; i++)
    {
        output[i] = fact(input[i]);
    }
}
