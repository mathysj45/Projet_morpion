#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include "tic-tac-toe.h"

int main() 
{
    int i;
    int j;
    char tab[2][2];
    inittab(tab);
    printf("Affichage du tableau de morpion.\n");
    printtab(tab);
    printf("%d", tab[i][j]);
    exit(0);
}
