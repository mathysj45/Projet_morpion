#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <time.h>
#include "tic-tac-toe.h"

int main()
{
    int choix;
    char tab[3][3];
    srand(time(NULL));

    inittab(tab);

    while (1)
    {
        system("clear");
        printtab(tab);

        printf("Entrez un nombre entre 0 et 8 : ");
        while (scanf("%d", &choix) != 1)
        {
            printf("Entrée incorrecte. Réessayez.\n");
            while (getchar() != '\n');
        }

        if (choix < 0 || choix > 8)
        {
            printf("Valeur hors limites. Réessayez.\n");
            sleep(1);
            continue;
        }

        int ligne = choix / 3;
        int colonne = choix % 3;

        if (tab[ligne][colonne] != ' ')
        {
            printf("Case déjà occupée. Réessayez.\n");
            sleep(1);
            continue;
        }

        tab[ligne][colonne] = 'X';

        system("clear");
        printtab(tab);

        if (endgame(tab))
        {
            char winner = checkWinner(tab);
            printf("Game Over!\n");
            if (winner != ' ')
                printf("Le joueur %c a gagné!\n", winner);
            else
                printf("Match nul!\n");
            break;
        }

        sleep(1);

        int ligneIA, colonneIA;
        do 
        {
            ligneIA = rand() % 3;
            colonneIA = rand() % 3;
        } 
        while (tab[ligneIA][colonneIA] != ' ');

        tab[ligneIA][colonneIA] = 'O';

        system("clear");
        printf("Après le tour de l'ordinateur :\n");
        printtab(tab);

        if (endgame(tab))
        {
            char winner = checkWinner(tab);
            printf("Game Over!\n");
            if (winner != ' ')
                printf("Le joueur %c a gagné!\n", winner);
            else
                printf("Match nul!\n");
            break;
        }
    }

    exit(0);
}
