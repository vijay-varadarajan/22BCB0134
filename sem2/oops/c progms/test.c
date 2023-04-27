#include <stdio.h>

int main(void)
{
    int rows, cols;
    scanf("%d %d", &rows, &cols);
    
    // Create a matrix with given rows and columns
    int elems[rows][cols];

    // Initialize variables to calculate the row sum, column sums and sum of row sums
    int row_sum, col_sum[cols], sum_row_sum = 0;
    
    // Get all elements of the matrix as user input and initialize column sum array to 0s.
    for(int i = 0; i < rows; i++)
    {
        for(int j = 0; j < cols; j++)
        {
            scanf("%d", &elems[i][j]);
            col_sum[j] = 0;
        }
    }

    // Iterate through the 2 d array
    for (int i = 0; i < rows; i++)
    {
        // Set row sum to zero for each row
        row_sum = 0;
        for (int j = 0; j < cols; j++)
        {
            // Print the elements of the matrix
            printf("%d ", elems[i][j]);

            // Add the current row element to the row sum
            row_sum += elems[i][j];

            // Add the current column element to the appropriate column in column sum
            col_sum[j] += elems[i][j];
        }
        // Update sum of row sums with the current rowsum
        sum_row_sum += row_sum;

        // print the row sum
        printf("%d\n", row_sum);
    }

    // In the final line print the column sums
    for(int i = 0; i < cols; i++)
    {
        printf("%d ", col_sum[i]);
    }
    // Followed by the sum of row sums
    printf("%d", sum_row_sum);
}
