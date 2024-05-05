#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


#define TAILLE_MAX 5

typedef struct file {
    int tete;
    int queue;
    int tab[TAILLE_MAX];
} File;

File fle; // D�claration de la file globale

void init_file() {
    fle.tete = 0;
    fle.queue = 0;
}

bool file_vide() {
    return fle.tete == fle.queue;
}

bool file_pleine() {
    return fle.queue == TAILLE_MAX;
}

int taille_file() {
    if (file_vide())
        return 0;
    if (fle.queue >= fle.tete)
        return fle.queue - fle.tete;
}

void enfiler(int x) {
    if (file_pleine()) {
        printf("Erreur : la file est pleine.\n");
        exit(EXIT_FAILURE);
    }
    fle.tab[fle.queue] = x;
    fle.queue++;
}

int defiler() {
    if (file_vide()) {
        printf("Erreur : la file est vide.\n");
        exit(EXIT_FAILURE);
    }
    int valeur = fle.tab[fle.tete];
    fle.tete++;
    return valeur;
}

void afficher() {
    if (file_vide()) {
        printf("La file est vide.\n");
        return;
    }
    printf("Contenu de la file :\n");
    int i;
    for (i = fle.tete; i < fle.queue; i++) {
        printf("%d\n", fle.tab[i]);
    }
}

int main() {
    init_file();
    int item, choice;
    int option = 1;
    printf("\n\tImpl�mentation d'une file");
    while (option) {
        printf("\nMenu principal");
        printf("\n1.Enfiler \n2.D�filer \n3.Afficher \n4.Exit");
        printf("\nEntrez votre choix: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("\nEnter L'element � enfiler: ");
                scanf("%d", &item);
                enfiler(item);
                break;
            case 2:
                if (!file_vide()) {
                    int x = defiler();
                    printf("\nL'�l�ment d�filer est %d", x);
                } else {
                    printf("\nErreur : la file est vide.");
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


