#include <stdio.h>
#include <stdlib.h>

typedef struct slllist
{
    int value;
    struct slllist* next;
} sllnode;


void insert_end(sllnode* head, int value);
int find(sllnode* head, int value);
void delete_mid(sllnode* head, int value);
void print(sllnode* head);
void delete_end(sllnode* head);
sllnode* destroy(sllnode* head);
sllnode* delete_front(sllnode* head);
sllnode* insert_sorted(sllnode* head, int value);
sllnode* insert_front(sllnode* head, int value);
sllnode* create (int value);

int main(void)
{
    sllnode* head = create(1);
    // 1
    print(head);
    printf("\n");
    
    head = insert_front(head, 0);
    // 0 1
    print(head);
    printf("\n");
    
    insert_end(head, 4);
    // 0 1 4
    print(head);
    printf("\n");
    
    head = insert_sorted(head, 2);
    // 0 1 2 4
    print(head);
    printf("\n");

    head = insert_sorted(head, -3);
    // -3 0 1 2 4
    print(head);
    printf("\n");

    head = insert_sorted(head, 6);
    // -3 0 1 2 4 6
    print(head);
    printf("\n");

    head = insert_front(head, -12);
    // -12 -3 0 1 2 4 6
    print(head);
    printf("\n");

    insert_end(head, 12);
    // -12 -3 0 1 2 4 6 12
    print(head);
    printf("\n");

    int index = find(head, 2);
    printf("Position of 2: %d\n", index); // 5

    head = delete_front(head);
    // -3 0 1 2 4 6 12
    print(head);
    printf("\n");

    delete_end(head);
    // -3 0 1 2 4 6
    print(head);
    printf("\n");

    delete_mid(head, 1);
    // -3 0 2 4 6
    print(head);
    printf("\n");

    head = destroy(head);
    //    
    if (head)
        print(head);
    else
        printf("NULL");
}

sllnode* create (int value)
{
    sllnode* head = (sllnode*) malloc(sizeof(sllnode));
    if (head == NULL)
        exit(1);
    
    head -> value = value;
    head -> next = NULL;
    return head;
}

sllnode* insert_front(sllnode* head, int value)
{
    sllnode* new = (sllnode*) malloc(sizeof(sllnode));
    if (new == NULL)
        exit(1);

    new -> value = value;
    new -> next = head;
    head = new;

    return head;
}

void insert_end(sllnode* head, int value)
{
    sllnode* new = (sllnode*) malloc(sizeof(sllnode));
    if (new == NULL)
        exit(1);
    new -> value = value;
    new -> next = NULL;
    
    sllnode* temp = head;
    while(temp -> next != NULL)
        temp = temp -> next;
    temp -> next = new;
}

sllnode* insert_sorted(sllnode* head, int value)
{
    sllnode* new = (sllnode*) malloc(sizeof(sllnode));
    if (new == NULL)
        exit(1);
    new -> value = value;
    new -> next = NULL;

    sllnode* temp = head;
    if (temp -> value > value)
    {
        head = insert_front(head, value);
        return head;
    }   
    
    if (temp -> next == NULL)
    {
       if (temp -> value > value)
            head = insert_front(head, value);

        else
            insert_end(head, value);

        return head;
    }

    while (temp -> next -> value < value)
    {
        temp = temp -> next;
        if (temp -> next == NULL)
        {
            temp -> next = new;
            return head;
        }
    }

    new -> next = temp -> next;
    temp -> next = new;
    return head;
}

int find(sllnode* head, int value)
{
    sllnode* temp = head;
    int count = 0;
    while(temp != NULL)
    {
        count++;
        if (temp -> value == value)
            return count;
        temp = temp -> next;
    }
    return 0;
}

sllnode* delete_front(sllnode* head)
{
    sllnode* temp = head;
    head = head -> next;
    
    free(temp);
    temp = NULL;

    return head;
}

void delete_mid(sllnode* head, int value)
{   
    int index = find(head, value);
    sllnode* p = head; sllnode* q = head;
    for (int i = 0; i < index - 1; i++)
    {
        q = p;
        p = p -> next;
    }
    q -> next = p -> next;
    free(p);
    p = NULL;
}

void delete_end(sllnode* head)
{
    sllnode* temp;
    for (temp = head; temp -> next -> next != NULL; temp = temp -> next)
    {
        continue;
    }
    
    free(temp -> next);
    temp -> next = NULL;
    temp = NULL;
}

void print(sllnode* head)
{
    if (head == NULL)
    {
        exit(1);
    }
    sllnode* temp = head;
    while (temp != NULL)
    {
        printf("%d ", temp -> value);
        temp = temp -> next;
    }
}

sllnode* destroy(sllnode* head)
{
    sllnode* temp = head;
    if (temp == NULL)
    {
        return head;
    }
    head = destroy(temp -> next);
    free(temp);
    head = NULL;

    return head;
}
