#include <stdio.h>
#include <stdlib.h> 
#include <stdbool.h>

typedef int Type_C; 

typedef struct cellule {
    Type_C valeur;
    struct cellule *suivant;
} Cellule;

typedef Cellule *Pile;


void Init_Pile(Pile *pile) {
    *pile = NULL;
}

bool Pile_vide(Pile pile) {
    return pile == NULL;
}

bool Pile_pleine() {
    return false;
}


void Empiler(Pile *pile, Type_C valeur) {
    Cellule *nouvelle_cellule = malloc(sizeof(Cellule));
    if (nouvelle_cellule == NULL) {
        printf("Erreur : impossible d'allouer de la memoire.");
        exit(EXIT_FAILURE);
    }
    nouvelle_cellule->valeur = valeur;
    nouvelle_cellule->suivant = *pile;
    *pile = nouvelle_cellule;
}


void Depiler(Pile *pile, Type_C *valeur) {
    if (Pile_vide(*pile)) {
        printf("Erreur : la pile est vide.");
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

    
    if (Pile_vide(maPile)) {
        printf("La pile est vide \n");
    } else {
        printf("La pile n'est pas vide \n");
    }

    Empiler(&maPile, 10);
    Empiler(&maPile, 20);

    Type_C sommet;
    Depiler(&maPile, &sommet);
    printf("Valeur depilee : %d\n", sommet);

    
    if (Pile_vide(maPile)) {
        printf("La pile est vide \n");
    } else {
        printf("La pile n'est pas vide \n");
    }

    return 0;
}

