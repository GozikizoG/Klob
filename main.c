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
    switch ((rotate % 4 + 4) % 4) {
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
    switch ((rotate % 4 + 4) % 4) {
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
    switch ((rotate % 4 + 4) % 4) {
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

    switch ((rotate % 4 + 4) % 4) {
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

    switch ((rotate % 4 + 4) % 4) {
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
    switch ((rotate % 4 + 4) % 4) {
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
    for (int i = 0; i < 4; i++)
        for (int j = 0; j < 16; j++)
            grid[i][j] = false;

    for (int i = 0; i < 3; i++, xoff+=5) {
        switch (board[i]) {
            case 0: pieceO(xoff, 0, grid, 16, 4); break;
            case 1: pieceI(xoff, 0, rotate, grid, 16, 4); break;
            case 2: pieceT(xoff, 0, rotate, grid, 16, 4); break;
            case 3: pieceL(xoff, 0, rotate, grid, 16, 4); break;
            case 4: pieceJ(xoff, 0, rotate, grid, 16, 4); break;
            case 5: pieceS(xoff, 0, rotate, grid, 16, 4); break;
            case 6: pieceZ(xoff, 0, rotate, grid, 16, 4); break;
        }
    }
    printf("    1              2              3 \n");
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

int menu(int score,int *rotate) {
    int answer = 0;
    printf("Ton score est de %d\n1. Jouer une piece\n2. Tourner les pieces (90° horraire)\n3. Tourner les pieces (90° anti-horraire)\n4. Abandonner\n",score);
    scanf("%d", &answer);
    switch (answer) {
        default:
            printf("Erreur\n");
            break;
        case 1:
            printf("Parmis les 3 pieces, laquel veux tu jouer ?");
            scanf("%d", answer);
            if (answer==1||answer==2||answer==3){return answer;}
            printf("Erreur\n");
            return 0;
        case 2:
            (*rotate) = (*rotate % 4 + 3) % 4;
            return 0;
        case 3:
            (*rotate) = (*rotate % 4 + 5) % 4;
            return 0;
        case 4:

            return 9;
    }
    return 0;
}

int main() {
    srand(time(NULL));
    int size,c,x,y,score = 0;
    int rotate = 2;
    int board[3];
    bool end = false;
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
            printf("La taille est invalide, cela doit etre compris entre 5 et 35.\n\n");
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

    do {
        drawGrid(grid, size);
        printf("\n\n\n");
        for (int i = 0; i < 3; i++){board[i] = rand() % 7;} // ce sera à déplacer à l'endroit ou on confirme qu'ona jouer
        drawBoard(boardDraw,board,rotate);
        switch (menu(score,&rotate)) {
            default:
                break;
            case 1:
                printf("Tu veux jouer la 1");
                break;
            case 2:
                printf("Tu veux jouer la 2");
                break;
            case 3:
                printf("Tu veux jouer la 3");
                break;
            case 9:
                printf("Tu as abandonne.");
                end = true;
                break;

        }
    } while (end != true);




    return 0;
}