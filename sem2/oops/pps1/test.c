#include <stdio.h>

int main(void)
{
    int n = 3;
    char salary[n][10];

    for(int i = 0; i < n; i++)
    {
        printf("%d: ", i);
        scanf("%s", salary[i]);
    }

    for (int i = 0; i < n; i++)
    {
        // check if salary is valid, exit if invalid
        for(int j = 0; j < 10; j++) 
        {
            if(salary[i][j] == '\0')
                break;
            if(salary[i][j] < '0' || salary[i][j] > '9')
            {
                printf("Invalid\n");
                return 1;
            }
        }
    }
}