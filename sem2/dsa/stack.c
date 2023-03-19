#include <stdio.h>

int N = 5;
int top = -1;
int stack[5]; // declare stack array of size 5 

void push(int n);
void pop();
int peek();
void display();

int main(void)
{
    int choice, value;
    printf("Enter your choice: ");
    scanf("%d", &choice);
    
    switch(choice)
    {
        case 1:
            printf("Enter value: ");
            scanf("%d", value);
            push(value);
            break;
        case 2:
            pop();
            break;
        case 3:
            display();
            break;
        default:
            printf("Invalid choice.");
    }
}

void push(int n)
{
    if (top >= N)
        printf("Stack Overflow"); // if top is at N, stack is full, unable to push
    else
    {
        top++; // otherwise increment top
        stack[top] = n; // assign the input value (n) to the stack's topmost index
        printf("Value pushed");
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