/*

infix expression in char exp[]
parse thro exp[] using i
    if exp[i] is a number:
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
end of exp is reached:
    keep popping and printing from stack
    
*/

#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>

void push(char stack[], int top, int N, char val);
void pop(char stack[], int top);
int precedence(char oper);

int main(void)
{
    int top = -1, N = 11;
    char stack[N], exp[11] = "2*5+3"; 

    for (int i = 0; i < N; i++)
    {

        if(isdigit(exp[i]) != 0)
        {
            printf("%c", exp[i]);
        }
        else
        {
            if (top == -1)
            {
                top++;
                push(stack, top, N, exp[i]);
            }
            else
            {
                if (precedence(stack[top]) >= precedence(exp[i]))
                {    
                    pop(stack, top);
                    top--;
                    top++;
                    push(stack, top, N, exp[i]);
                }
                else
                {
                    top++;
                    push(stack, top, N, exp[i]);
                }
            }
        }

        //printf("%d\n", top);
    }

    while(top > -1)
    {
        pop(stack, top);
        top--;
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

void push(char stack[], int top, int N, char val)
{
    if (top == N-1)
    {
        return;
    }
    else
    {
        stack[top] = val;
    }
}

void pop(char stack[], int top)
{
    if (top == -1)
    {
        return;
    }
    else
    {
        printf("%c", stack[top]);
    }
}
