// c program to multiply two floating point numbers

#include <stdio.h>

int main()
{
    float num1, num2, product;
    printf("Enter two numbers: ");
    scanf("%f %f", &num1, &num2);
    product = num1 * num2;
    printf("Product: %f", product);
    return 0;
}
