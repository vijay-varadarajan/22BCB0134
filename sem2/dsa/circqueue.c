#include <stdio.h>
#define N 5

int queue[N], front = -1, rear = -1;

void enqueue(int num);
void dequeue();
void disp();

int main(void)
{
    int num;
    int choice;
    while (1)
    {
        printf("Front %d Rear %d\n", front, rear);
        printf("Choice \n(1) to enqueue\n(2) to dequeue\n(3) to display\n:");
        scanf("%d", &choice);
        switch (choice)
        {
            case 1:
                printf("Enter number to enqueue: ");
                scanf("%d", &num);  
                enqueue(num);
                break;
            
            case 2:
                dequeue();
                break;

            case 3:
                disp();
                break;

            default:
                return 1;
        }
    }
}

void disp()
{
    if (rear == -1)
        printf("Nothing to display.\n");
    else
    {
        for (int i = front; i != rear; i = (i+1) % N)
            printf("%d ", queue[i]);
        printf("%d \n", queue[rear]);
    }
}

void enqueue(int num)
{
    if ((rear + 1) % N == front)
        printf("Queue overflow");
    else
    {
        if (front == -1)
            front++;
        rear = (rear + 1) % N;
        queue[rear] = num;
    }
}

void dequeue()
{
    if (front == -1)
        printf("Queue underflow");
    else
    {
        if (front == rear)
        {   
            front = -1; rear = -1;
        }    
        else
            front = (front + 1) % N;
    }
}
