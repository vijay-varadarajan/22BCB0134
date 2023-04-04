#include <stdio.h>

int main(void)
{
    int a[] = {20, 6, 18, 11, 14, 17, 15, 12}, n = 8;
    printf("%d\n", a[n-1]);

    int cp = a[n-1];
    for(int i = n-2; i >= 0; i--)
    {
        if (a[i] > cp)
        {
            printf("%d\n", a[i]);
            cp = a[i];
        }
    }
}