#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include "tic-tac-toe.h"

// Affiche le tableau du morpion
void printtab(char tab[3][3]) 
{
    printf("\n");
    printf(" %c | %c | %c\n", tab[0][0],tab[0][1], tab[0][2]);
    printf(" ---------\n");
    printf(" %c | %c | %c\n", tab[1][0], tab[1][1], tab[1][2]);
    printf(" ---------\n");
    printf(" %c | %c | %c\n", tab[2][0], tab[2][1], tab[2][2]);
}