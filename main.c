#include <math.h>
#include <stdio.h> // pour les input et output (littéralement obligatoire en C)
#include <stdlib.h> // pour le random
#include <time.h>  // pour avoir une valeur impredictible pour la seed du random

int main() {
    int size;
    int c;
    int grid[35][35] = {};
    srand(time(NULL));


    do{printf("Quel est la taille de la grille [5-35] : ");

        if (scanf("%d", &size) != 1) {
            printf("Erreur, mettez un nombre entier.\n");
            while ((c = getchar()) != '\n' && c != EOF);
            size=0;
            continue;
        }

        printf("Taille de la grille = %d \n ", size);
        printf("La taille est invalide, cela doit etre compris entre 5 et 35. \n\n");

    }while (size>35 || size<5);


    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            grid[i][j] = 0;
        }
    }

    printf("   ");
    for (int i = 0; i < size; i++){
        printf("%2d ",i+1);
    }
        printf("\n");
    for (int i = 0; i < size; i++) {

        printf("%2d ",i+1);

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