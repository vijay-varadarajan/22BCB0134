#include <stdio.h>
#include <string.h>

int main(void)
{
    // declare char array of size 8 to store dob and initialize required variables.
    char dob[8]; int len, res = 0, even_sum = 0, odd_sum = 0;

    // get the dob
    printf("DOB: ");
    scanf("%s", dob);
    len = strlen(dob);
    
    // if length of input is not 8, exit
    if (len != 8)
    {
        printf("invalid input");
        return 1;
    }

    // calculate sums of odd and even places
    for(int i = 0, j = 1; i < 8; i+=2, j+=2)
    {
        even_sum += dob[i] - '0';
        odd_sum += dob[j] - '0';
    }
    
    // print output in the given format
    printf("You have entered ");
    for(int i = 0; i < 8; i++)
    {
        printf("%d", dob[i] - '0');
    }
    printf(", ");
    
    // print if lucky or not based on given condition
    if (((odd_sum * 3) + even_sum) % 10 == 0)
    {
        printf("\"Lucky number\"");
    }
    else
    {
        printf("\"Not a lucky number\"");
    }
}