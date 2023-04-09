#include <stdio.h>
#include <stdlib.h>
#define MAX_ACCOUNTS 100

struct Customer {
    // customer details variables declared locally
    int accNo;
    char name[50];
    float balance;
};

// accounts and number of accounts declared as static variables
static struct Customer accs[MAX_ACCOUNTS];
static int numAccs = 0;

void addAcc(struct Customer *newAcc); 
int searchAcc(int accNo, struct Customer **acc); 
void updateBalance(int accNo, float amount); 
void printAccs();


int main() {
    int choice;

    while (1) 
    {
        printf("\nWelcome to MY banking system\nChoose the option to perform the corresponding task: \n");
        printf("1. Add a new customer account\n");
        printf("2. Search for a customer account\n");
        printf("3. Update the account balance for a customer account\n");
        printf("4. Print out all customer account information\n");
        printf("5. Exit\nEnter your choice (1-5): ");
        scanf("%d", &choice);

        switch (choice) 
        {
            case 1: 
            {
                struct Customer newAcc;
                addAcc(&newAcc);
                break;
            }

            case 2: 
            {
                int accNo;
                struct Customer *acc;

                printf("\nEnter the account number: ");
                scanf("%d", &accNo);

                if (searchAcc(accNo, &acc)) 
                {
                    printf("\nCustomer name: %s\n", acc->name);
                    printf("Account balance: %.2f\n", acc->balance);
                } 
                
                else 
                {
                    printf("\nAccount not found.\n");
                }
            }
            break;

            case 3: 
            {
                int accNo;
                float amount;

                printf("\nEnter the account number: ");
                scanf("%d", &accNo);

                printf("Enter the amount to update the balance: ");
                scanf("%f", &amount);

                updateBalance(accNo, amount);
            }
            break;

            case 4:
                printAccs();
            break;

            case 5:
                printf("\nExiting.\n");
            exit(0);

        default:
            printf("\nInvalid choice. Please enter a number from 1 to 5.\n");
        }
    }
    return 0;
}



// Function to add a new customer account to the system
void addAcc(struct Customer *newAcc) 
{
    if (numAccs >= MAX_ACCOUNTS) 
    {
        printf("\nMaximum number of accs reached.\n");
        return;
    }

    printf("\nEnter the customer name: ");
    scanf("%s", newAcc->name);

    printf("Enter the account number: ");
    scanf("%d", &newAcc->accNo);

    printf("Enter the account balance: ");
    scanf("%f", &newAcc->balance);

    accs[numAccs++] = *newAcc;

    printf("\nAccount added successfully.\n");
}

// Function to search for a customer account using the account number 
int searchAcc(int accNo, struct Customer **acc) 
{
    for (int i = 0; i < numAccs; i++) 
    {
        if (accs[i].accNo == accNo) 
        {
            *acc = &accs[i];
            return 1;
        }
    }
    return 0;
}

// Function to update the account balance for a customer account
void updateBalance(int accNo, float amount) 
{
    struct Customer *acc;
    if (searchAcc(accNo, &acc)) 
    {
        acc->balance += amount;
        printf("\nBalance updated successfully.\n");
    }  
    else 
    {
        printf("\nAccount not found.\n");
    }
}

// Function to print out all customer account information
void printAccs() {
    printf("\nCustomer Accounts:\n");
    for (int i = 0; i < numAccs; i++) 
    {
        printf("\nCustomer name: %s\n", accs[i].name);
        printf("Account number: %d\n", accs[i].accNo);
        printf("Account balance: %.2f\n", accs[i].balance);
    }
}
