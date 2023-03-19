#include <stdio.h>
#include <float.h>
int main(void)
{
    printf("%d ", sizeof(int));
    printf("%d ", sizeof(short int));
    printf("%d ", sizeof(long int));
    printf("%d ", sizeof(unsigned int));
    printf("\n%E ", sizeof(float));
    printf("\n%d ", sizeof(double));
    printf("%d ", sizeof(long double));
    printf("\n%d \?", sizeof(void));
    printf("\n%d ", sizeof(char));
    printf("\n%d ", sizeof(wchar_t));
    
}