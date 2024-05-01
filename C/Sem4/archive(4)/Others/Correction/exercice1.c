#include <stdio.h>
#include <stdbool.h>

#define TAILLE_MAX 5

typedef struct pile {
    int sommet;
    int tab[TAILLE_MAX];
} Pile;

Pile p;

void init_pile() {
    p.sommet = 0;
}

int pile_vide() {
    return p.sommet == 0;
}

int pile_pleine() {
    return p.sommet == TAILLE_MAX;
}

int taille_pile() {
    return p.sommet;
}

void empiler(int x) {
    if (pile_pleine()) {
        printf("Erreur : la pile est pleine.\n");
        return;
    }
    p.tab[p.sommet] = x;
    p.sommet++;
}

void afficher() {
    if (pile_vide()) {
        printf("La pile est vide.\n");
        return;
    }
    printf("Contenu de la pile :\n");
    int i;
    for (i = p.sommet - 1; i >= 0; i--) {
        printf("%d\n", p.tab[i]);
    }
}

int depiler() {

    if (pile_vide()) {
        printf("Erreur : la pile est vide.\n");
        return -1;
    }
    p.sommet--;
    return p.tab[p.sommet];
}


int main() {
    init_pile();

    int item, choice;
    int option = 1;
    printf("\n\tImplémentation d'une pile");
    while (option) {
        printf("\nMenu principal");
        printf("\n1.Empiler \n2.Dépiler \n3.Afficher \n4.Exit");
        printf("\nEntrez votre choix: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("\nEnter L'élément à empiler: ");
                scanf("%d", &item);
                empiler(item);
                break;
            case 2:
                if (!pile_vide()) {
                    int x = depiler();
                    printf("\nL'élément dépilé est %d", x);
                } else {
                    printf("\nErreur : la pile est vide.");
                }
                break;
            case 3:
                afficher();
                break;
            case 4:
                exit(0);
        }
        printf("\nVoulez-vous continuer (Tapez 0(Non) ou 1(Oui))? : ");
        scanf("%d", &option);
    }
    return 0;
}

