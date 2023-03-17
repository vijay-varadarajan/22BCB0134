#include <stdio.h>

int main(void)
{
    int code; float amount, disc_amount;

    // get product code snd amount from user
    printf("Product code: ");
    scanf("%d", &code);
    printf("Order amount: ");
    scanf("%f", &amount);

    // check if amount is valid
    if(amount < 0)
    {
        printf("Invalid input\n");
        return 1;
    }

    // set discounted amount to the original amount
    disc_amount = amount;

    // change discounted amount based on the conditions
    switch(code)
    {
        case 1:
            if (amount > 1000)
                disc_amount -= (0.1)*disc_amount;
            break;
        
        case 2:
            if (amount > 750)
                disc_amount -= (0.05)*disc_amount;
            break;

        case 3:
            if (amount > 500)
                disc_amount -= (0.1)*disc_amount;
            break;

        // exit if product code is invalid
        default:
            printf("Invalid option.");
            return 1;
    }

    // print final discounted amount
    printf("Thanks, your discounted amount: %.2f", disc_amount);
    return 0;
}