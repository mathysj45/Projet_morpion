#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include "tic-tac-toe.h"

// Initialise le tableau du morpion avec des espaces vides
void inittab(char tab[3][3])
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++) 
        {
           tab[i][j] = ' ';
        }
    }
}