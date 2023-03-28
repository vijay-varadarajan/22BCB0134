#include <stdio.h>

int main(void)
{
    int num, k, odd_sum = 0, even_sum = 0;
    printf("Enter a number: ");
    scanf("%d", &num);

    while (num > 0)
    {
        k = num % 10;
        
        if (k % 2 == 0)
            even_sum += k;
        else
            odd_sum += k;

        num = (num - (num % 10)) / 10;
    }

    if (even_sum == odd_sum)
        printf("Matching");
    else
        printf("Not matching");
}