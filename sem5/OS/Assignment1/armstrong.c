// c program to check if given number is armstrong number or not

#include <stdio.h>

int main()
{
    int num, originalNum, remainder, result = 0;

    // Input an integer from user
    printf("Enter an integer: ");
    scanf("%d", &num);

    originalNum = num;

    // Check if the number is armstrong number or not
    while (originalNum != 0)
    {
        // remainder contains the last digit
        remainder = originalNum % 10;

        result += remainder * remainder * remainder;

        // removing last digit from the orignal number
        originalNum /= 10;
    }

    // Print the result
    if (result == num)
        printf("%d is an Armstrong number.\n", num);
    else
        printf("%d is not an Armstrong number.\n", num);

    return 0;
}