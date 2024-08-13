// c program to find all the roots of given quadratic equation

#include <stdio.h>
#include <math.h>

int main()
{
    float a, b, c, d, root1, root2, realPart, imaginaryPart;

    printf("Equation of the form ax^2 + bx + c. Enter coefficients a, b and c: ");
    scanf("%f %f %f", &a, &b, &c);

    d = b * b - 4 * a * c;

    if (d > 0)
    {
        root1 = (-b + sqrt(d)) / (2 * a);
        root2 = (-b - sqrt(d)) / (2 * a);
        printf("root1 = %.2f and root2 = %.2f", root1, root2);
    }
    else if (d == 0)
    {
        root1 = root2 = -b / (2 * a);
        printf("root1 = root2 = %.2f;", root1);
    }
    else
    {
        realPart = -b / (2 * a);
        imaginaryPart = sqrt(-d) / (2 * a);
        printf("root1 = %.2f+%.2fi and root2 = %.2f-%.2fi", realPart, imaginaryPart, realPart, imaginaryPart);
    }

    return 0;
}