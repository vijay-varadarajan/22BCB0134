#include <stdio.h>

float fact (int a);

int main(void)
{
    int n; double ans = 0.0;
    printf("Enter n: ");
    scanf("%d", &n);

    for (int i = 1; i <= n; i++)
    {   
        ans += (1/fact(i));
        printf("ans");
    }

    printf("%.3lf", ans);
}

float fact (int a)
{
    if (a <= 1)
        return 1;
    else
        return a*fact(a-1);
}