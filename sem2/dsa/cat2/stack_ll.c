#include <stdio.h>
#include <stdlib.h>

typedef struct sllnode{
    int value;
    struct sllnode* next;
}sllnode;

sllnode* create (int value);
sllnode* pop (sllnode* top);
char peek (sllnode* top, int* a);
sllnode* push (sllnode* top, int value);

int main(void)
{
    sllnode* head = create(1);
    int num = 0;

    head = push(head, 2);
    
    head = push(head, 3);
    
    head = push(head, 4);
    
    head = push(head, 5);

    head = pop(head);
    head = pop(head);
    head = pop(head);
    head = pop(head);
    head = pop(head);
    head = pop(head);
    
}

sllnode* create (int value)
{
    sllnode* top = (sllnode*) malloc(sizeof(sllnode));
    if (top == NULL)
        exit(1);

    top -> value = value;
    top -> next = NULL;

    return top;
}

sllnode* push (sllnode* top, int value)
{
    sllnode* newNode = (sllnode*) malloc(sizeof(sllnode));
    if (newNode == NULL)
        exit(1);

    newNode -> value = value;
    newNode -> next = top;
    top = newNode;

    return top; 
}

sllnode* pop (sllnode* top)
{
    if (top == NULL)
        printf("Stack underflow.\n");
    
    sllnode* temp = top;
    
    if (top != NULL)
    {
        if (top->next == NULL)
        {
            printf("%d", top->value);
            free(top);
            top = NULL;
        }
        else
        {
            printf("%d", top -> value);
            top = top -> next;
        }
    }
    
    free(temp);
    temp = NULL;

    return top;
}

char peek (sllnode* top, int* num)
{
    if (top == NULL)
    {
        printf("Stack underflow");
        return 'n';
    }
    *num = top -> value;
    return 'y';
}
