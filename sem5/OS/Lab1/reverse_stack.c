// write a c program to reverse a given stack using recursion

#include <stdio.h>

#define MAX 10

int stack[MAX];

int top = -1;

void push(int data)
{
    if (top == MAX - 1)
    {
        printf("Stack is full\n");
        return;
    }
    stack[++top] = data;
}

int pop()
{
    if (top == -1)
    {
        printf("Stack is empty\n");
        return -1;
    }
    return stack[top--];
}

void display()
{
    if (top == -1)
    {
        printf("Stack is empty\n");
        return;
    }
    for (int i = 0; i <= top; i++)
        printf("%d ", stack[i]);
    printf("\n");
}

void insertAtBottom(int data)
{
    if (top == -1)
    {
        push(data);
        return;
    }
    int temp = pop();
    insertAtBottom(data);
    push(temp);
}

void reverse()
{
    if (top == -1)
        return;
    int temp = pop();
    reverse();
    insertAtBottom(temp);
}

int main()
{
    int n;
    printf("Enter the number of elements in the stack: ");
    scanf("%d", &n);

    printf("Enter the elements of the stack: ");
    for (int i = 0; i < n; i++)
    {
        int data;
        scanf("%d", &data);
        push(data);
    }

    printf("Stack before reversing: ");
    display();

    reverse();

    printf("Stack after reversing: ");
    display();

    return 0;
}