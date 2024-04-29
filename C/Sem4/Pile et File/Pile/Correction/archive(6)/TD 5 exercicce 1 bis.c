#include <stdio.h>
#include <stdlib.h> // Pour malloc et free
#include <stdbool.h>

// type des �l�ments
typedef int Type_C; 
// type Cellule
typedef struct cellule {
    Type_C valeur;
    struct cellule *suivant;
} Cellule;

// type Pile
typedef Cellule *Pile;

// Initialisation de la pile
void Init_Pile(Pile *pile) {
    *pile = NULL;
}

// V�rifier si la pile est vide
bool Pile_vide(Pile pile) {
    return pile == NULL;
}

// V�rifier si la pile est pleine
bool Pile_pleine() {
    return false; // Une liste cha�n�e ne peut pas �tre pleine
}

// Ajouter une valeur � la pile (empiler)
void Empiler(Pile *pile, Type_C valeur) {
    Cellule *nouvelle_cellule = malloc(sizeof(Cellule));
    if (nouvelle_cellule == NULL) {
        fprintf(stderr, "Erreur : impossible d'allouer de la m�moire.\n");
        exit(EXIT_FAILURE);
    }
    nouvelle_cellule->valeur = valeur;
    nouvelle_cellule->suivant = *pile;
    *pile = nouvelle_cellule;
}

// Supprimer une valeur de la pile (d�piler)
void Depiler(Pile *pile, Type_C *valeur) {
    if (Pile_vide(*pile)) {
        fprintf(stderr, "Erreur : la pile est vide.\n");
        exit(EXIT_FAILURE);
    }
    *valeur = (*pile)->valeur;
    Cellule *tmp = *pile;
    *pile = (*pile)->suivant;
    free(tmp);
}

int main() {
    Pile maPile;
    Init_Pile(&maPile);

    // Tester les op�rations de la pile
    if (Pile_vide(maPile)) {
        printf("La pile est vide \n");
    } else {
        printf("La pile n'est pas vide \n");
    }

    Empiler(&maPile, 10);
    Empiler(&maPile, 20);

    Type_C sommet;
    Depiler(&maPile, &sommet);
    printf("Valeur d�pil�e : %d\n", sommet);

        // Tester les op�rations de la pile
    if (Pile_vide(maPile)) {
        printf("La pile est vide \n");
    } else {
        printf("La pile n'est pas vide \n");
    }

    return 0;
}

