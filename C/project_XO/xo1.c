#include<stdio.h>
#include <getopt.h>
#include <stdlib.h>

#include "helpers.h"

int main()
{
    char game[3][3];
    int win;

    creategame(game);

    dispgame(game);

    storeX(game);

    dispgame(game);

    for (int n=0; n<4; n++)
    {
        // Get input coords and check for invalid inputs
        storeO(game);

        dispgame(game);

        // Evaluate the matrix each time to check if pattern matches
        win = checker(game);
        if (win == 1){
            break;
        }

        storeX(game);

        dispgame(game);

        // Evaluate the matrix each time to check if pattern matches
        win = checker(game);
        if (win == 1){
            break;
        }
    }
    if (win == 0){
        printf("Game Drawn\n");
    }

    dispgame(game);
}

