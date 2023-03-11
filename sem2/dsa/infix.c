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
#include <ctype.h>
#define N 5

int top = -1; char stack[N];

void push(char stack[], int top, int N, char val);

int main(void)
{
    char exp[5] = "2*3+5";
    for (int i = 0; i < 5; i++)
    {
        if(isdigit(exp[i]) != 0)
        {
            printf("%d", exp[i]);
        }
        else
        {
            if(top == -1)
            {
                push(stack[], top, N, exp[i])
            }

        }
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
        top++;
        stack[top] = val;
    }
}