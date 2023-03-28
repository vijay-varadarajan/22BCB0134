#include <stdio.h>
#include <stdlib.h>


int sparse(int **matrix, int m, int n);
int ** allocate(int h, int w);


int main(void)
{
    int **matrix, m, n;

    printf("Enter m and n: ");
    scanf("%d %d", &m, &n);

    matrix = allocate(m, n);
    
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("matrix [%d][%d]: " , i, j);
            scanf("%d", &matrix[i][j]);
        }
    }

    if (sparse(matrix, m, n) == 1)
        printf("Sparse");
    else
        printf("Not sparse");
}


int ** allocate(int h, int w)
{
    int **p; int i, j;
    p = (int **) calloc(h, sizeof(int));
    for (int i = 0; i < h; i++)
    {
        p[i] = (int *)calloc(w, sizeof(int));
    }
    return p;
}


int sparse(int **matrix, int m, int n)
{
    int count = 0, elements = m*n;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (matrix[i][j] == 0)
                count ++;
            if (count > elements/2)
                return 1;
        }
    }
    return 0;
}
