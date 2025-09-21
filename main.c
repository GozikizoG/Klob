#include <stdio.h>   // pour les input et output
#include <stdlib.h>  // pour le random
#include <time.h>    // pour la seed du random
#include <stdbool.h> // pour bool, true, false

int cube(int x, int y, bool grid[35][35], int size) {
    x--; y--;
    if (x < 0 || y < 0 || x+1 > size || y+1 > size || x > size || y > size) {
        printf("Coordonnees hors limites.\n");
        return 1;
    }

    if (grid[x][y] == false &&
        grid[x+1][y] == false &&
        grid[x][y+1] == false &&
        grid[x+1][y+1] == false) {

        grid[x][y] = true;
        grid[x+1][y] = true;
        grid[x][y+1] = true;
        grid[x+1][y+1] = true;
    } else {
        printf("Emplacement non valide.\n");
        return 1;
    }
    return 0;
}

void drawGrid(bool grid[35][35], int size) {
    printf("   ");
    for (int i = 0; i < size; i++) {
        printf("%2d ", i+1);
    }
    printf("\n");

    for (int i = 0; i < size; i++) {
        printf("%2d ", i+1);
        for (int j = 0; j < size; j++) {
            if (grid[i][j] == false) {
                printf("[ ]");
            } else {
                printf("[X]");
            }
        }
        printf("\n");
    }
}

int main() {
    int size;
    int c;
    bool grid[35][35] = {}; // tableau rempli de false par défaut
    srand(time(NULL));

    do {
        printf("Quel est la taille de la grille [5-35] : ");
        if (scanf("%d", &size) != 1) {
            printf("Erreur, mettez un nombre entier.\n");
            while ((c = getchar()) != '\n' && c != EOF);
            size = 0;
            continue;
        }
        if (size > 35 || size < 5) {
            printf("La taille est invalide, cela doit être compris entre 5 et 35.\n\n");
        }
    } while (size > 35 || size < 5);

    // initialisation explicite optionnelle
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            grid[i][j] = false;
        }
    }

    drawGrid(grid, size);

    int x = 6, y = 6;
    if (cube(x, y, grid, size)==1) {
        printf("donne moi un x : ");
        scanf("%d", &x);
        printf("donne moi un y : ");
        scanf("%d", &y);
        cube(x, y, grid, size);
    };

    drawGrid(grid, size);

    return 0;
}