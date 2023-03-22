#include <stdio.h>

/*
Repeat n-1 times
For i from 0 to n–2
    If numbers[i] and numbers[i+1] out of order
        Swap them
*/

int main(void)
{
    int nums[] = {1,4,5,2,7,6,3,4,9};
    int n = 9;

    for(int i = 0; i < n-1; i++)
    {
        for (int j = 0; j < n-2; j++)
        {
            if(nums[j] > nums[j+1])
            {
                int tmp = nums[j];
                nums[j] = nums[j+1];
                nums[j+1] = tmp;
            }
        }
    }

    for(int i = 0; i < n; i++)
    {
        printf("%d", nums[i]);
    }
    printf("\n");
}

