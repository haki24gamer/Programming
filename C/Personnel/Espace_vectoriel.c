#include <stdio.h>

#define ROWS 3
#define COLS 3

int main() {
    int matrix[ROWS][COLS];
    int i, j, k, temp;
    int n = ROWS * COLS;
    
    // Remplir la matrice
    printf("Entrez les elements de la matrice (%d x %d) : \n", ROWS, COLS);
    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            printf("Element [%d][%d] : ", i, j);
            scanf("%d", &matrix[i][j]);
        }
    }

    // Transformer la matrice en tableau à une dimension
    int array[n];
    k = 0;
    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            array[k++] = matrix[i][j];
        }
    }

    // Supprimer les doublons
    for (i = 0; i < n; i++) {
        for (j = i+1; j < n;) {
            if (array[j] == array[i]) {
                for (k = j; k < n; k++) {
                    array[k] = array[k+1];
                }
                n--;
            } else {
                j++;
            }
        }
    }

    // Trier le tableau en ordre croissant
    for (i = 0; i < n-1; i++) {
        for (j = i+1; j < n; j++) {
            if (array[j] < array[i]) {
                temp = array[i];
                array[i] = array[j];
                array[j] = temp;
            }
        }
    }

    // Afficher le tableau trié
    printf("Tableau trié en ordre croissant : \n");
    for (i = 0; i < n; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");

    return 0;
}
