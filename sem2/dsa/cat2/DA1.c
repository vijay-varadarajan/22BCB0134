#include <stdio.h>

// queue functions used
void enqueue(int num);
void dequeue();
int queue_peek();

// stack functions used
void pop();
int stack_peek();

const int N = 6;    // N = number of customers = number of pastas
int top = 0;    // first element of pasta stack is the topmost
int front = 0, rear = N - 1;    // initialize front and rear of queue

// customer queue and pasta stack initialized 
int customers[] = {1,1,1,0,0,0,0,1,0,1}, pastas[] = {1,0,1,0,1,1,0,1,0,1};


int main(void)
{
    int left = N, front_customer; // 'left' keeps track of number of customers left
    int rotation_count = 0;     // initializing a variable to count the number of customer rotations

    // repeat until number of elements in customers reaches 0
    while(left > 0)
    {
        // if customer preference matches pasta stack
        if (stack_peek() == queue_peek())
        {
            dequeue();          // remove customer from queue
            pop();              // remove pasta from stack
            left--;                   // decrement customer count by 1
            rotation_count = 0;     // reset rotation count to 0
        }

        // if customer preference does not match pasta stack
        else
        {
            if (left == 1) // exit loop if only one customer is left
                break;

            front_customer = queue_peek();      
            dequeue();                  // remove the customer from front of the queue
            enqueue(front_customer);    // add the customer removed to the back of the queue
            rotation_count++;           // increment rotation count
        }

        // exit if the all customers in the queue have been checked against pasta stack
        if (rotation_count == left)       
            break;                      
    }

    // print number of customers left unserved
    printf("\nCustomers unserved: %d\n", left);
}


void enqueue(int num)
{
    if ((rear + 1) % N == front) // check if queue is full
        printf("Queue overflow");
    else
    {
        if (front == -1)
            front++;    // if there are no elements in queue, increment front
        rear = (rear + 1) % N;  // always increment rear with circular conditions
        customers[rear] = num;  // insert value into rear index
    }
}

void dequeue()
{
    if (front == -1)    // check if queue is empty
        printf("Queue underflow");
    else
    {
        if (front == rear) // if only one element left in queue, reset queue parameters
        {   
            front = -1; rear = -1;
        }    
        front = (front + 1) % N; // increment front to show element deletion
    }
}

int queue_peek()
{
    if (front == -1)
        printf("Empty queue"); // if front is -1, no elements in queue
    else
        return customers[front];    // otherwise return element in front index 
}

void pop()
{
    if (top >= N)
        printf("Nothing to pop"); // if top is less than 0 nothing to print
    else
        top++; // Otherwise increment top by 1
}

int stack_peek()
{
    if (top >= N)
        printf("Nothing to peek"); // if top is less than 0, no elements in the array
    else
        return pastas[top]; // else return the value stored in the topmost index of pastas
}   
