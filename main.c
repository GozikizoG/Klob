#include <stdio.h> // pour les input et output (littéralement obligatoire en C)
#include <stdlib.h> // pour le random
#include <time.h>  // pour avoir une valeur impredictible pour la seed du random

int main() {
    int size;
    int grid[35][35] = {};
    srand(time(NULL));

    printf("Quel est la taille de la grille ? (MAX 35)"); // dire max 100
    scanf("%d", &size); //verif plus tard

    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            grid[i][j] = 0;
        }
    }

    printf("    ");
    for (int i = 0; i < size; i++){
        if (i+1<9){printf("%d  ",i+1);}else{printf("%d ",i+1);}
    }
        printf("\n");
    for (int i = 0; i < size; i++) {

        printf("%2d ",i+1);
        //if (i<=10){printf(" ");}

        for (int j = 0; j < size; j++) {

            if (grid[i][j] == 0) {
                printf("[ ]");
            }else if(grid[i][j] == 1){
                printf("[X]");
            }

        }
        printf("\n");
    }

    return 0;
}