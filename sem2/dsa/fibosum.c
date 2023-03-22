#include <stdio.h>
#define N 2

int stack[2], top = -1;

void push(int n);
void pop();
int peek();
void display();
int calcsum(int n);
int nthterm(int n);

int main(void)
{
    int len, sum, nterm;
    printf("Enter length of fibonacci series to calculate sum: ");
    scanf("%d", &len);

    sum = calcsum(len); nterm = nthterm(len);
    printf("\n%dth term of fibonacci series is: %d\n", len, nterm);
    printf("Sum of %d terms: %d\n", len, sum);
}

int nthterm(int n)
{
    int one = peek(); pop();
    int two = peek(); pop();
    return (two - one);
}

int calcsum(int n)
{
    push(1); push(0);

    int sum = 0, one, two;
    for (int i = 0; i < n; i++)
    {
        one = peek(); pop();
        two = peek(); pop();
        sum += one;
        push(one + two);
        push(two);
    }
    return sum;
}

void push(int n)
{
    if (top >= N)
        printf("Stack Overflow"); // if top is at N, stack is full, unable to push
    else
    {
        top++; // otherwise increment top
        stack[top] = n; // assign the input value (n) to the stack's topmost index
    }
}

void pop()
{
    if (top <= -1)
        printf("Nothing to pop"); // if top is less than 0 nothing to print
    else
        top--; // Otherwise decrement top by 1
}

int peek()
{
    if (top <= -1)
        printf("Nothing to peek"); // if top is less than 0, no elements in the array
    else
        return stack[top]; // else return the value stored in the topmost index of stack
}   

void display()
{
    if (top <= -1)
        printf("No elements in stack to display."); // if top less than 0, no elements in the array
    else
    {
        printf("Elements in stack: \n");
        for(int i = top; i >= 0; i--) // otherwise, loop thro the stack and print each element
        {
            printf("%d ", stack[i]);
        }
    }
}
