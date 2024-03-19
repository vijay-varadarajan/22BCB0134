#include <stdbool.h>
#include <stdio.h> 

bool isCorrectSquare(int N, int board[N][N], int row, int col)
{
    int i, j;
 
    // Check row 
    for (i = 0; i < col; i++)
        if (board[row][i])
            return false;
 
    // Check upper diagonal
    for (i = row, j = col; i >= 0 && j >= 0; i--, j--)
        if (board[i][j])
            return false;
 
    // Check lower diagonal
    for (i = row, j = col; j >= 0 && i < N; i++, j--)
        if (board[i][j])
            return false;
 
    return true;
}
 

bool NQueens(int N, int board[N][N], int col)
{
    if (col >= N)
        return true;
 
    for (int i = 0; i < N; i++) {

        if (isCorrectSquare(N, board, i, col)) {
             
            board[i][col] = 1;
 
            if (NQueens(N, board, col + 1))
                return true;

            board[i][col] = 0; // BACKTRACK
        }
    }
 
    return false;
}


// Driver program to test above function
int main()
{
    int N;
    printf("Enter the number of queens: ");
    scanf("%d", &N);

    int board[N][N];
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            board[i][j] = 0;
        }
    }
 
    if (NQueens(N, board, 0) == false) {
        printf("Solution does not exist");
        return false;
    }
 
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if(board[i][j])
                printf("Q ");
            else
                printf(". ");
        }
        printf("\n");
    }

    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            if(board[i][j]) printf("%d ", j+1);
        }
    }
    return 0;
}
 