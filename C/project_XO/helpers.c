#include <stdio.h>
#include "helpers.h"

// Create game board
void creategame(char game[3][3]){
    for(int i=0; i<3; i++)
    {
        for(int j=0; j<3; j++)
        {
            game[i][j] = '-';
        }
    }
}


// Get and store y in y coordinate
void storeO(char game[3][3]){
    int check, a, b;
    do{
        check = 1;
        printf("Enter o coord: ");
        scanf("%d %d", &a, &b);
        if (a >= 3 || b >= 3)
        {
            check = 0;
        }
        else if (game[a][b] == '-')
        {
            game[a][b] = 'O';
            check = 1;
        }
        else
        {
            check = 0;
        }
    }while(check == 0);
}


// Get and store x in x coordinate
void storeX(char game[3][3]){
    int check, a, b;
    do{
        check = 1;
        printf("Enter x coord: ");
        scanf("%d %d", &a, &b);
        if (a >= 3 || b >= 3)
        {
            check = 0;
        }
        else if (game[a][b] == '-')
        {
            game[a][b] = 'X';
            check = 1;
        }
        else
        {
            check = 0;
        }
    }while(check == 0);
}


// Evaluate the matrix for each input
int checker(char game[3][3]){
    int win;
    for(int p=0; p<3; p++)
    {
        win = rowchecker(game, p);
        if (win == 1){
            break;
        }

        // Check a column of matching inputs
        win = colchecker(game, p);
        if (win == 1){
            break;
        }

        // Check left to right diagonal for matching inputs
        win = lrdiagchecker(game);
        if (win == 1){
            break;
        }

        // Check right to left diagonal for matching inputs
        win = rldiagchecker(game);
        if (win == 1){
            break;
        }
    }
    return win;
}


// Function to display the game progression
void dispgame(char game[3][3]){
    printf("\n");
    for(int i=0; i<3; i++){
        for(int j=0; j<3; j++){
            printf(" %c ", game[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}


// Function to check a row of matching inputs
int rowchecker(char game[3][3], int p){
    int counter = 0, win = 0;
    char checkval, curval;
    for(int q=0; q<3; q++)
    {
        curval = game[p][q];
        if(curval != '-'){
            if (q == 0)
            {
                checkval = game[p][0];
            }
            if (curval == checkval)
            {
                counter++;
            }
            if (counter == 3)
            {
                if(checkval == 'X'){
                    win = 1;
                    printf("Player X wins\n");
                    break;
                }
                else if(checkval == 'O'){
                    win = 1;
                    printf("Player O wins\n");
                    break;
                }
            }
        }
        else{
            break;
        }
    }
    return win;
}


// Function to check a column of matching inputs
int colchecker(char game[3][3], int p){
    int counter = 0, win = 0;
    char checkval, curval;
    for(int q=0; q<3; q++)
    {
        curval = game[q][p];
        if(curval != '-'){
            if (q == 0)
            {
                checkval = game[0][p];
            }
            if (curval == checkval)
            {
                counter++;
            }
            if (counter == 3)
            {
                if(checkval == 'X'){
                    win = 1;
                    printf("Player X wins\n");
                    break;
                }
                else if(checkval == 'O'){
                    win = 1;
                    printf("Player O wins\n");
                    break;
                }
            }
        }
        else{
            break;
        }
    }
    return win;
}


// Function to check Left to right diagonal
int lrdiagchecker(char game[3][3]){
    int counter = 0, win = 0;
    char checkval, curval;

    for (int lrdiag = 0; lrdiag < 3; lrdiag++){
        curval = game[lrdiag][lrdiag];
        if (curval != '-'){
            if (lrdiag == 0){
                checkval = curval;
            }
            if (checkval == curval){
                counter++;
            }
            if (counter == 3){
                if(checkval == 'X'){
                    win = 1;
                    printf("Player X wins\n");
                    break;
                }
                else if(checkval == 'O'){
                    win = 1;
                    printf("Player O wins\n");
                    break;
                }
            }
            if (win == 1){
                break;
            }
        }
        else{
            break;
        }
    }
    return win;
}


// Function to check right to left diagonal
int rldiagchecker(char game[3][3]){
    int counter = 0, win = 0;
    char curval, checkval;

    for (int rldiag = 0; rldiag < 3; rldiag++){
        curval = game[rldiag][2 - rldiag];
        if (curval != '-'){
            if (rldiag == 0){
                checkval = curval;
            }
            if (checkval == curval){
                counter++;
            }
            if (counter == 3){
                if(checkval == 'X'){
                    win = 1;
                    printf("Player X wins\n");
                    break;
                }
                else if(checkval == 'O'){
                    win = 1;
                    printf("Player O wins\n");
                    break;
                }
            }
            if (win == 1){
                break;
            }
        }
        else{
            break;
        }
    }
    return win;
}
