#include <stdio.h>   // pour les input et output
#include <stdlib.h>  // pour le random
#include <time.h>    // pour la seed du random
#include <stdbool.h> // pour bool, true, false

int pieceO(int x, int y, bool grid[35][35], int sizeX, int sizeY) {
    if (x < 0 || y < 0 || x+1 > sizeX || y+1 > sizeY) return 1;
    if (!grid[y][x] && !grid[y][x+1] && !grid[y+1][x] && !grid[y+1][x+1]) {
        grid[y][x] = grid[y][x+1] = grid[y+1][x] = grid[y+1][x+1] = true;
        return 0;
    }
    return 1;
}
int pieceI(int x, int y, int rotate, bool grid[35][35], int sizeX, int sizeY) {
    switch (rotate % 4) {
        case 0:
        case 2: // horizontal
            if (x < 0 || y < 0 || x+3 >= sizeX) return 1;
            if (!grid[y][x] && !grid[y][x+1] && !grid[y][x+2] && !grid[y][x+3]) {
                grid[y][x] = grid[y][x+1] = grid[y][x+2] = grid[y][x+3] = true;
                return 0;
            }
            break;
        case 1:
        case 3: // vertical
            if (x < 0 || y < 0 || y+3 >= sizeY) return 1;
            if (!grid[y][x] && !grid[y+1][x] && !grid[y+2][x] && !grid[y+3][x]) {
                grid[y][x] = grid[y+1][x] = grid[y+2][x] = grid[y+3][x] = true;
                return 0;
            }
            break;
    }
    return 1;
}
int pieceT(int x, int y, int rotate, bool grid[35][35], int sizeX, int sizeY) {
    switch (rotate % 4) {
        case 0: // ┴
            if (x < 0 || y < 0 || x+2 >= sizeX || y+1 >= sizeY) return 1;
            if (!grid[y][x] && !grid[y][x+1] && !grid[y][x+2] && !grid[y+1][x+1]) {
                grid[y][x] = grid[y][x+1] = grid[y][x+2] = grid[y+1][x+1] = true;
                return 0;
            }
            break;
        case 1: // ┤
            if (x < 0 || y < 0 || x+1 >= sizeX || y+2 >= sizeY) return 1;
            if (!grid[y][x+1] && !grid[y+1][x+1] && !grid[y+2][x+1] && !grid[y+1][x]) {
                grid[y][x+1] = grid[y+1][x+1] = grid[y+2][x+1] = grid[y+1][x] = true;
                return 0;
            }
            break;
        case 2: // ┬
            if (x < 0 || y < 0 || x+2 >= sizeX || y+1 >= sizeY) return 1;
            if (!grid[y+1][x] && !grid[y+1][x+1] && !grid[y+1][x+2] && !grid[y][x+1]) {
                grid[y+1][x] = grid[y+1][x+1] = grid[y+1][x+2] = grid[y][x+1] = true;
                return 0;
            }
            break;
        case 3: // ├
            if (x < 0 || y < 0 || x+1 >= sizeX || y+2 >= sizeY) return 1;
            if (!grid[y][x] && !grid[y+1][x] && !grid[y+2][x] && !grid[y+1][x+1]) {
                grid[y][x] = grid[y+1][x] = grid[y+2][x] = grid[y+1][x+1] = true;
                return 0;
            }
            break;
    }
    return 1;
}
int pieceL(int x, int y, int rotate, bool grid[35][35], int sizeX, int sizeY) {
    switch (rotate % 4) {
        case 0:
            if (x < 0 || y < 0 || x+1 >= sizeX || y+2 >= sizeY) return 1;
            if (!grid[y][x] && !grid[y+1][x] && !grid[y+2][x] && !grid[y+2][x+1]) {
                grid[y][x] = grid[y+1][x] = grid[y+2][x] = grid[y+2][x+1] = true;
                return 0;
            }
            break;
        case 1:
            if (x < 0 || y < 0 || x+2 >= sizeX || y+1 >= sizeY) return 1;
            if (!grid[y][x] && !grid[y][x+1] && !grid[y][x+2] && !grid[y+1][x+2]) {
                grid[y][x] = grid[y][x+1] = grid[y][x+2] = grid[y+1][x+2] = true;
                return 0;
            }
            break;
        case 2:
            if (x < 0 || y < 0 || x+1 >= sizeX || y+2 >= sizeY) return 1;
            if (!grid[y][x+1] && !grid[y+1][x+1] && !grid[y+2][x+1] && !grid[y][x]) {
                grid[y][x+1] = grid[y+1][x+1] = grid[y+2][x+1] = grid[y][x] = true;
                return 0;
            }
            break;
        case 3:
            if (x < 0 || y < 0 || x+2 >= sizeX || y+1 >= sizeY) return 1;
            if (!grid[y+1][x] && !grid[y+1][x+1] && !grid[y+1][x+2] && !grid[y][x]) {
                grid[y+1][x] = grid[y+1][x+1] = grid[y+1][x+2] = grid[y][x] = true;
                return 0;
            }
            break;
    }
    return 1;
}
int pieceJ(int x, int y, int rotate, bool grid[35][35], int sizeX, int sizeY) {

    switch (rotate % 4) {
        case 0:
            if (x < 0 || y < 0 || x+1 >= sizeX || y+2 >= sizeY) return 1;
            if (!grid[y][x+1] && !grid[y+1][x+1] && !grid[y+2][x+1] && !grid[y+2][x]) {
                grid[y][x+1] = grid[y+1][x+1] = grid[y+2][x+1] = grid[y+2][x] = true;
                return 0;
            }
            break;
        case 1:
            if (x < 0 || y < 0 || x+2 >= sizeX || y+1 >= sizeY) return 1;
            if (!grid[y][x] && !grid[y+1][x] && !grid[y+1][x+1] && !grid[y+1][x+2]) {
                grid[y][x] = grid[y+1][x] = grid[y+1][x+1] = grid[y+1][x+2] = true;
                return 0;
            }
            break;
        case 2:
            if (x < 0 || y < 0 || x+1 >= sizeX || y+2 >= sizeY) return 1;
            if (!grid[y][x] && !grid[y+1][x] && !grid[y+2][x] && !grid[y][x+1]) {
                grid[y][x] = grid[y+1][x] = grid[y+2][x] = grid[y][x+1] = true;
                return 0;
            }
            break;
        case 3:
            if (x < 0 || y < 0 || x+2 >= sizeX || y+1 >= sizeY) return 1;
            if (!grid[y][x] && !grid[y][x+1] && !grid[y][x+2] && !grid[y+1][x]) {
                grid[y][x] = grid[y][x+1] = grid[y][x+2] = grid[y+1][x] = true;
                return 0;
            }
            break;
    }
    return 1;
}
int pieceS(int x, int y, int rotate, bool grid[35][35], int sizeX, int sizeY) {

    switch (rotate % 4) {
        case 0:
        case 2:
            if (x < 0 || y < 0 || x+2 >= sizeX || y+1 >= sizeY) return 1;
            if (!grid[y][x+1] && !grid[y][x+2] && !grid[y+1][x] && !grid[y+1][x+1]) {
                grid[y][x+1] = grid[y][x+2] = grid[y+1][x] = grid[y+1][x+1] = true;
                return 0;
            }
            break;
        case 1:
        case 3:
            if (x < 0 || y < 0 || x+1 >= sizeX || y+2 >= sizeY) return 1;
            if (!grid[y][x] && !grid[y+1][x] && !grid[y+1][x+1] && !grid[y+2][x+1]) {
                grid[y][x] = grid[y+1][x] = grid[y+1][x+1] = grid[y+2][x+1] = true;
                return 0;
            }
            break;
    }
    return 1;
}
int pieceZ(int x, int y, int rotate, bool grid[35][35], int sizeX, int sizeY) {
    switch (rotate % 4) {
        case 0:
        case 2:
            if (x < 0 || y < 0 || x+2 >= sizeX || y+1 >= sizeY) return 1;
            if (!grid[y][x] && !grid[y][x+1] && !grid[y+1][x+1] && !grid[y+1][x+2]) {
                grid[y][x] = grid[y][x+1] = grid[y+1][x+1] = grid[y+1][x+2] = true;
                return 0;
            }
            break;
        case 1:
        case 3:
            if (x < 0 || y < 0 || x+1 >= sizeX || y+2 >= sizeY) return 1;
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

void drawBoard(bool grid[35][35], int board[3], int rotate) {
    int xoff = 0;
    // 1. Réinitialiser
    for (int i = 0; i < 4; i++)
        for (int j = 0; j < 16; j++)
            grid[i][j] = false;

    // Placer les pièces
    for (int i = 0; i < 3; i++, xoff+=5) {
        switch (board[i]) {
            default: pieceO(xoff, 0, grid, 16, 4); printf("%d // ",xoff); break;
            // case 1: pieceI(i, 0, rotate, grid, 16, 4); printf("I "); break;
            // case 2: pieceT(i, 0, rotate, grid, 16, 4); printf("T "); break;
            // case 3: pieceL(i, 0, rotate, grid, 16, 4); printf("L "); break;
            // case 4: pieceJ(i, 0, rotate, grid, 16, 4); printf("J "); break;
            // case 5: pieceS(i, 0, rotate, grid, 16, 4); printf("S%d // ",i); break;
            // case 6: pieceZ(i, 0, rotate, grid, 16, 4); printf("Z "); break;
        }
    }
    // Dessiner la grille
    printf("\n    1              2              3 \n");
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 16; j++) {

            if (grid[i][j] == true) {
                printf("[X]");
            } else {
                printf("[ ]");
            };
        }
        printf("\n");
    }
}

int main() {
    srand(time(NULL));
    int size,c,x,y,rotate = 0;
    int board[3];
    bool boardDraw[35][35];
    bool grid[35][35] = {};




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
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            grid[i][j] = false;
        }
    }
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 16; j++) {
            boardDraw[i][j] = false;
        }
    }

    drawGrid(grid, size);
    printf("\n\n\n");

    for (int i = 0; i < 3; i++){board[i] = rand() % 1;}


    drawBoard(boardDraw,board,rotate);

    pieceT(1,1,1,grid,size,size);
    drawGrid(grid, size);

    return 0;
}