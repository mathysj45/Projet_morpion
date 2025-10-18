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
        printf("Bienvenue cher joueur ! Que dirais-tu d'une partie de morpion ?\n");
        printf("Voici le tableau de jeu :\n");
        printtab(tab);

        // Vérifie si le joueur entre une valeur correcte
        printf("Choisi un nombre entre 0 et 8 : ");
        while (scanf("%d", &choix) != 1)
        {
            printf("J'ai dit un nombre petit chenapan ! Allez choisi un nombre cette fois-ci :\n");
            while (getchar() != '\n');
            sleep(1);
        }

        // Vérifie si le choix est dans les limites
        if (choix < 0 || choix > 8)
        {
            printf("Que ne comprends-tu pas <<entre 0 et 8>> ??\n");
            sleep(1);
            continue;
        }

        // Convertit le choix en coordonnées de la grille
        int ligne = choix / 3;
        int colonne = choix % 3;

        // Vérifie si la case est déjà occupée
        if (tab[ligne][colonne] != ' ')
        {
            printf("Tu essais de triché ? Choisis une case VIDE !\n");
            sleep(1);
            continue;
        }

        // Place le 'X' du joueur
        tab[ligne][colonne] = 'X';

        system("clear");
        printtab(tab);

        // Vérification de la fin de la partie
        if (endgame(tab))   
        {                   
            char winner = checkWinner(tab);
            printf("Game Over!\n");
            if (winner != ' ')
                printf("Le joueur %c a gagné! Tu es maginifique !\n", winner);
                break;
        }

        sleep(1);

        // Vérification des cases vides pour un match nul
        int cases_vides = 0;
        for (int a = 0; a < 3; a++)
            for (int b = 0; b < 3; b++)
                if (tab[a][b] == ' ')
                    cases_vides++;
        if (cases_vides == 0)
        {
            printf("Match nul!\n");
            break;
        }

        // Tour de l'ordinateur
        int ligneIA, colonneIA;
        do 
        {
            ligneIA = rand() % 3;
            colonneIA = rand() % 3;
        }

        // Assure que l'IA choisit une case vide
        while (tab[ligneIA][colonneIA] != ' ');

        // Place le 'O' de l'ordinateur
        tab[ligneIA][colonneIA] = 'O';

        // Affiche le tableau après le tour de l'ordinateur
        system("clear");
        printf("Après le tour de l'ordinateur :\n");
        printtab(tab);

        if (endgame(tab))
        {
            char winner = checkWinner(tab);
            printf("Game Over!\n");
            if (winner != ' ')
                printf("Le joueur %c a gagné! Tu es mauvais cher joueur !\n", winner);

                break;
        }
    }

    exit(0);
}