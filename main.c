#include <stdio.h>   // pour les input et output
#include <stdlib.h>  // pour le random
#include <time.h>    // pour la seed du random
#include <stdbool.h> // pour bool, true, false

int cube(int x, int y, bool grid[35][35], int size) {
    x--; y--;
    if (x < 0 || y < 0 || x >= size-1 || y >= size-1) {
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
int pieceO(int x, int y, bool grid[35][35], int size) {
    x--; y--;
    if (x < 0 || y < 0 || x+1 >= size || y+1 >= size) return 1;
    if (!grid[y][x] && !grid[y][x+1] && !grid[y+1][x] && !grid[y+1][x+1]) {
        grid[y][x] = grid[y][x+1] = grid[y+1][x] = grid[y+1][x+1] = true;
        return 0;
    }
    return 1;
}
int pieceI(int x, int y, int rotate, bool grid[35][35], int size) {
    x--; y--;
    switch (rotate % 4) {
        case 0:
        case 2: // horizontal
            if (x < 0 || y < 0 || x+3 >= size) return 1;
            if (!grid[y][x] && !grid[y][x+1] && !grid[y][x+2] && !grid[y][x+3]) {
                grid[y][x] = grid[y][x+1] = grid[y][x+2] = grid[y][x+3] = true;
                return 0;
            }
            break;
        case 1:
        case 3: // vertical
            if (x < 0 || y < 0 || y+3 >= size) return 1;
            if (!grid[y][x] && !grid[y+1][x] && !grid[y+2][x] && !grid[y+3][x]) {
                grid[y][x] = grid[y+1][x] = grid[y+2][x] = grid[y+3][x] = true;
                return 0;
            }
            break;
    }
    return 1;
}
int pieceT(int x, int y, int rotate, bool grid[35][35], int size) {
    x--; y--;
    switch (rotate % 4) {
        case 0: // ┴
            if (x < 0 || y < 0 || x+2 >= size || y+1 >= size) return 1;
            if (!grid[y][x] && !grid[y][x+1] && !grid[y][x+2] && !grid[y+1][x+1]) {
                grid[y][x] = grid[y][x+1] = grid[y][x+2] = grid[y+1][x+1] = true;
                return 0;
            }
            break;
        case 1: // ┤
            if (x < 0 || y < 0 || x+1 >= size || y+2 >= size) return 1;
            if (!grid[y][x+1] && !grid[y+1][x+1] && !grid[y+2][x+1] && !grid[y+1][x]) {
                grid[y][x+1] = grid[y+1][x+1] = grid[y+2][x+1] = grid[y+1][x] = true;
                return 0;
            }
            break;
        case 2: // ┬
            if (x < 0 || y < 0 || x+2 >= size || y+1 >= size) return 1;
            if (!grid[y+1][x] && !grid[y+1][x+1] && !grid[y+1][x+2] && !grid[y][x+1]) {
                grid[y+1][x] = grid[y+1][x+1] = grid[y+1][x+2] = grid[y][x+1] = true;
                return 0;
            }
            break;
        case 3: // ├
            if (x < 0 || y < 0 || x+1 >= size || y+2 >= size) return 1;
            if (!grid[y][x] && !grid[y+1][x] && !grid[y+2][x] && !grid[y+1][x+1]) {
                grid[y][x] = grid[y+1][x] = grid[y+2][x] = grid[y+1][x+1] = true;
                return 0;
            }
            break;
    }
    return 1;
}
int pieceL(int x, int y, int rotate, bool grid[35][35], int size) {
    x--; y--;
    switch (rotate % 4) {
        case 0:
            if (x < 0 || y < 0 || x+1 >= size || y+2 >= size) return 1;
            if (!grid[y][x] && !grid[y+1][x] && !grid[y+2][x] && !grid[y+2][x+1]) {
                grid[y][x] = grid[y+1][x] = grid[y+2][x] = grid[y+2][x+1] = true;
                return 0;
            }
            break;
        case 1:
            if (x < 0 || y < 0 || x+2 >= size || y+1 >= size) return 1;
            if (!grid[y][x] && !grid[y][x+1] && !grid[y][x+2] && !grid[y+1][x+2]) {
                grid[y][x] = grid[y][x+1] = grid[y][x+2] = grid[y+1][x+2] = true;
                return 0;
            }
            break;
        case 2:
            if (x < 0 || y < 0 || x+1 >= size || y+2 >= size) return 1;
            if (!grid[y][x+1] && !grid[y+1][x+1] && !grid[y+2][x+1] && !grid[y][x]) {
                grid[y][x+1] = grid[y+1][x+1] = grid[y+2][x+1] = grid[y][x] = true;
                return 0;
            }
            break;
        case 3:
            if (x < 0 || y < 0 || x+2 >= size || y+1 >= size) return 1;
            if (!grid[y+1][x] && !grid[y+1][x+1] && !grid[y+1][x+2] && !grid[y][x]) {
                grid[y+1][x] = grid[y+1][x+1] = grid[y+1][x+2] = grid[y][x] = true;
                return 0;
            }
            break;
    }
    return 1;
}
int pieceJ(int x, int y, int rotate, bool grid[35][35], int size) {
    x--; y--;
    switch (rotate % 4) {
        case 0:
            if (x < 0 || y < 0 || x+1 >= size || y+2 >= size) return 1;
            if (!grid[y][x+1] && !grid[y+1][x+1] && !grid[y+2][x+1] && !grid[y+2][x]) {
                grid[y][x+1] = grid[y+1][x+1] = grid[y+2][x+1] = grid[y+2][x] = true;
                return 0;
            }
            break;
        case 1:
            if (x < 0 || y < 0 || x+2 >= size || y+1 >= size) return 1;
            if (!grid[y][x] && !grid[y+1][x] && !grid[y+1][x+1] && !grid[y+1][x+2]) {
                grid[y][x] = grid[y+1][x] = grid[y+1][x+1] = grid[y+1][x+2] = true;
                return 0;
            }
            break;
        case 2:
            if (x < 0 || y < 0 || x+1 >= size || y+2 >= size) return 1;
            if (!grid[y][x] && !grid[y+1][x] && !grid[y+2][x] && !grid[y][x+1]) {
                grid[y][x] = grid[y+1][x] = grid[y+2][x] = grid[y][x+1] = true;
                return 0;
            }
            break;
        case 3:
            if (x < 0 || y < 0 || x+2 >= size || y+1 >= size) return 1;
            if (!grid[y][x] && !grid[y][x+1] && !grid[y][x+2] && !grid[y+1][x]) {
                grid[y][x] = grid[y][x+1] = grid[y][x+2] = grid[y+1][x] = true;
                return 0;
            }
            break;
    }
    return 1;
}
int pieceS(int x, int y, int rotate, bool grid[35][35], int size) {
    x--; y--;
    switch (rotate % 4) {
        case 0:
        case 2:
            if (x < 0 || y < 0 || x+2 >= size || y+1 >= size) return 1;
            if (!grid[y][x+1] && !grid[y][x+2] && !grid[y+1][x] && !grid[y+1][x+1]) {
                grid[y][x+1] = grid[y][x+2] = grid[y+1][x] = grid[y+1][x+1] = true;
                return 0;
            }
            break;
        case 1:
        case 3:
            if (x < 0 || y < 0 || x+1 >= size || y+2 >= size) return 1;
            if (!grid[y][x] && !grid[y+1][x] && !grid[y+1][x+1] && !grid[y+2][x+1]) {
                grid[y][x] = grid[y+1][x] = grid[y+1][x+1] = grid[y+2][x+1] = true;
                return 0;
            }
            break;
    }
    return 1;
}

int pieceZ(int x, int y, int rotate, bool grid[35][35], int size) {
    x--; y--;
    switch (rotate % 4) {
        case 0:
        case 2:
            if (x < 0 || y < 0 || x+2 >= size || y+1 >= size) return 1;
            if (!grid[y][x] && !grid[y][x+1] && !grid[y+1][x+1] && !grid[y+1][x+2]) {
                grid[y][x] = grid[y][x+1] = grid[y+1][x+1] = grid[y+1][x+2] = true;
                return 0;
            }
            break;
        case 1:
        case 3:
            if (x < 0 || y < 0 || x+1 >= size || y+2 >= size) return 1;
            if (!grid[y+1][x] && !grid[y][x+1] && !grid[y+1][x+1] && !grid[y+2][x]) {
                grid[y+1][x] = grid[y][x+1] = grid[y+1][x+1] = grid[y+2][x] = true;
                return 0;
            }
            break;
    }
    return 1;
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

    int x = 6, y = 6, rotate = 0;
    if (pieceL(x, y,rotate, grid, size)==1) {
        printf("donne moi un x : ");
        scanf("%d", &x);
        printf("donne moi un y : ");
        scanf("%d", &y);
        printf("donne moi un rotate : ");
        scanf("%d", &rotate);
        pieceL(x, y,rotate, grid, size);
    };

    drawGrid(grid, size);
    return 0;
}