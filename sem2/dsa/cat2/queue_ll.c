#include <stdio.h>
#include <stdlib.h>

typedef struct sllnode{
    int value;
    struct sllnode* next;
} sllnode;

sllnode* create (int value);
sllnode* dequeue(sllnode* front);
int peek(sllnode* front);
sllnode* enqueue(sllnode* rear, int value);

int main(void)
{
    sllnode* front = create(1);
    sllnode* rear = front;
    printf("%d\n", peek(front));

    rear = enqueue(rear, 2);
    printf("%d\n", peek(front));
    
    rear = enqueue(rear, 3);
    printf("%d\n", peek(front));

    front = dequeue(front);
    printf("%d\n", peek(front));
    
    front = dequeue(front);
    printf("%d\n", peek(front));
    
    front = dequeue(front);
    printf("%d\n", peek(front));

    front = dequeue(front);
}

sllnode* create (int value)
{
    sllnode* front = (sllnode*) malloc (sizeof(sllnode));
    if (front == NULL)
        exit(1);

    front -> value = value;
    front -> next = NULL;

    return front;
}

sllnode* enqueue(sllnode* rear, int value)
{
    sllnode* newNode = (sllnode*) malloc (sizeof(sllnode));
    if (newNode == NULL)
        exit(1);

    newNode -> value = value;
    newNode -> next = NULL;

    rear -> next = newNode;
    rear = newNode;

    return rear;
}

sllnode* dequeue(sllnode* front)
{
    if (front == NULL)
    {
        printf("Queue underflow\n");
        return front;
    }

    if (front -> next != NULL)
    {
        sllnode* temp = front;   
        front = front -> next;
        free(temp);
        temp = NULL;
    }
    else
    {
        free(front);
        front = NULL;
    }

    return front;
}

int peek(sllnode* front)
{
    if (front == NULL)
    {
        printf("Queue underflow\n");
        return -1;
    }

    return front -> value;
}
