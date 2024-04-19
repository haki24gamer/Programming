#include <stdio.h>
#include <stdlib.h> // Pour malloc et free
#include <stdbool.h>

// type des éléments
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

// Vérifier si la pile est vide
bool Pile_vide(Pile pile) {
    return pile == NULL;
}

// Vérifier si la pile est pleine
bool Pile_pleine() {
    return false; // Une liste chaînée ne peut pas être pleine
}

// Ajouter une valeur à la pile (empiler)
void Empiler(Pile *pile, Type_C valeur) {
    Cellule *nouvelle_cellule = malloc(sizeof(Cellule));
    if (nouvelle_cellule == NULL) {
        fprintf(stderr, "Erreur : impossible d'allouer de la mémoire.\n");
        exit(EXIT_FAILURE);
    }
    nouvelle_cellule->valeur = valeur;
    nouvelle_cellule->suivant = *pile;
    *pile = nouvelle_cellule;
}

// Supprimer une valeur de la pile (dépiler)
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

    // Tester les opérations de la pile
    if (Pile_vide(maPile)) {
        printf("La pile est vide \n");
    } else {
        printf("La pile n'est pas vide \n");
    }

    Empiler(&maPile, 10);
    Empiler(&maPile, 20);

    Type_C sommet;
    Depiler(&maPile, &sommet);
    printf("Valeur dépilée : %d\n", sommet);

        // Tester les opérations de la pile
    if (Pile_vide(maPile)) {
        printf("La pile est vide \n");
    } else {
        printf("La pile n'est pas vide \n");
    }

    return 0;
}

