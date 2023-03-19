/*

    INFIX TO POSTFIX
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

    EVALUATE POSTFIX
parse thro post[]
    if post[i] is a digit
        push to stack
    else
        temp_ans = perform operation on top two elements (as ints) of stack
        pop twice
        push temp_ans (as char) to stack
return stack[0] as int
    
*/


#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>
#define N 50


int top = -1;
char stack[N];


void push(char val);
void pop();
int peek();
int precedence(char oper);
int oper(int a, int b, char op);
char* topost(char* expr, int n);
int evalpost(char* post, int n);


int main(int argc, char* argv[])
{
    char* expr = "5-3+(6-2/2)*5";

    char* post = topost(expr, strlen(expr));
    // printf("%s", post);

    int ans = evalpost(post, strlen(post));

    printf("\nAns: %d\n", ans);

    free(post);
}


int evalpost(char* post, int n)
{
    int sub = 0;
    for (int i = 0; i < n; i++)
    {
        if (isdigit(post[i]) != 0)
            push(post[i]);
        else
        {
            sub = oper(stack[top - 1] - '0', stack[top] - '0', post[i]);
            pop(); pop();
            push(sub + '0');
        }
    }
    return stack[0] - '0';
}


char* topost(char* expr, int n)
{
    int j = -1; 
    char* post = malloc(n*sizeof(char));
    for (int i = 0; i < n; i++)
    {
        if(isdigit(expr[i]) != 0)
            post[++j] = expr[i];
        
        else if (expr[i] == '(')
            push(expr[i]);
        
        else if (expr[i] == ')')
        {
            while (stack[top] != '(')
            {
                post[++j] = peek();
                pop();
            }
            pop();
        }
        else
        {
            if (top == -1)
                push(expr[i]);

            else
            {
                if (precedence(stack[top]) >= precedence(expr[i]))
                {    
                    post[++j] = peek();
                    pop();
                    push(expr[i]);
                }
                else
                    push(expr[i]);
            }
        }
    }

    while(top > -1)
    {
        post[++j] = peek();
        pop();
    }
    post[++j] = '\0';
    return post;
}


void push(char val)
{
    if (top >= N-1)
        return;
    else
    {
        ++top;
        stack[top] = val;
    }
}


void pop()
{
    if (top <= -1)
        return;
    
    else
        --top;
}


int peek()
{
    if (top <= -1)
        return -1;
    
    else
        return stack[top];
}


int oper(int a, int b, char op)
{
    switch (op)
    {
        case '+':
            return a + b;
        
        case '-':
            return a - b;

        case '*':
            return a * b;

        case '/':
            return a / b;

        default:
            break;
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
