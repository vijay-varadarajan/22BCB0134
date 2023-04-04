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
    if (front == -1)
        printf("Nothing to display.\n");
    else
    {
        for (int i = front; i <= rear; i++)
            printf("%d ", queue[i]);
        printf("\n");
    }
}

void enqueue(int num)
{
    if (rear >= N-1)
    {
        printf("Queue overflow.\n");
    }
    else
    {
        if (front == -1)
            front++;
        rear++;
        queue[rear] = num;
    }
}

void dequeue()
{
    if (front <= -1)
        printf("Queue underflow.\n");
    else
    {
        if (rear == front)
        {
            front = -1; rear = -1;
        }
        else
            front++;
    }
}
