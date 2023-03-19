/*

infix exprression in char expr[]
parse thro expr[] using i
    if expr[i] is a number:
        print
    elif ( :
        store in stack
    elif ):
        keep popping and printing from stack
            if '(' is reached in stack:
                pop (not print) '('
                break
    else (operator1):
        if stack is empty 
            push to stack
        if another operator (operator0) in stack
            if precedence(oper0 >= oper1):
                pop and print oper0
                push oper1 in place of oper0
            else
                push oper1 above oper0
end of expr is reached:
    keep popping and printing from stack
    
*/

#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>
#define N 50

int top = -1;
char stack[N];
char expr[N] = "1/2+(3-4)*5"; 
char post[N];

void push(char val);
void pop();
int peek();
int precedence(char oper);

int main(void)
{
    int j = 0;
    for (int i = 0; i < N; i++)
    {
        if(isdigit(expr[i]) != 0)
        {
            printf("%c", expr[i]);
        }
        else if (expr[i] == '(')
        {
            push(expr[i]);
        }
        else if (expr[i] == ')')
        {
            while (stack[top] != '(')
            {
                printf("%c", peek());
                pop();
            }
            pop();
        }
        else
        {
            if (top == -1)
            {
                push(expr[i]);
            }
            else
            {
                if (precedence(stack[top]) >= precedence(expr[i]))
                {    
                    printf("%c", peek());
                    pop();
                    push(expr[i]);
                }
                else
                {
                    push(expr[i]);
                }
            }
        }
    }

    while(top > -1)
    {
        printf("%c", peek());
        pop();
    }
}

int precedence(char oper)
{
    switch (oper)
    {
    case '(':
        return 0;

    case '+':
        return 1;
    
    case '-':
        return 1;

    case '*':
        return 2;

    case '/':
        return 3;
    
    default:
        break;
    }
}

void push(char val)
{
    if (top >= N-1)
    {
        return;
    }
    else
    {
        ++top;
        stack[top] = val;
    }
}

void pop()
{
    if (top <= -1)
    {
        return;
    }
    else
    {
        --top;
    }
}

int peek()
{
    if (top <= -1)
    {
        return -1;
    }
    else
    {
        return stack[top];
    }
}