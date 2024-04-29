#include <stdio.h>
#include <stdlib.h> // Pour malloc et free
#include <stdbool.h>

#define N 100 // Taille maximale de la file

// type des éléments
typedef int Type_C; 
// type File
typedef struct {
    Type_C T[N];
    int debut;
    int queue;
} File;

// Initialisation de la file
void Init_File(File *file) {
    file->debut = 0;
    file->queue = 0;
}

// Vérifier si la file est vide
bool File_vide(File file) {
    return file.debut == file.queue;
}

// Vérifier si la file est pleine
bool File_pleine(File file) {
    return file.queue == N;
}

// Ajouter une valeur à la file (enfiler)
void Enfiler(File *file, Type_C valeur) {
    if (File_pleine(*file)) {
        fprintf(stderr, "Erreur : la file est pleine.\n");
        exit(EXIT_FAILURE);
    }
    file->T[file->queue] = valeur;
    file->queue++;
}

// Supprimer une valeur de la file (défiler)
void Defiler(File *file, Type_C *valeur) {
    if (File_vide(*file)) {
        fprintf(stderr, "Erreur : la file est vide.\n");
        exit(EXIT_FAILURE);
    }
    *valeur = file->T[file->debut];
    file->debut++;
}

int main() {
    File maFile;
    Init_File(&maFile);

    // Tester les opérations de la file
    if (File_vide(maFile)) {
        printf("La file est vide.\n");
    } else {
        printf("La file n'est pas vide.\n");
    }

    Enfiler(&maFile, 10);
    Enfiler(&maFile, 20);
    Enfiler(&maFile, 30);
    Enfiler(&maFile, 40);

    if (File_vide(maFile)) {
        printf("La file est vide.\n");
    } else {
        printf("La file n'est pas vide.\n");
    }

    Type_C valeur;
    Defiler(&maFile, &valeur);
    printf("Valeur défiler : %d\n", valeur);
    Defiler(&maFile, &valeur);
    printf("Valeur défiler : %d\n", valeur);

    if (File_vide(maFile)) {
        printf("La file est vide.\n");
    } else {
        printf("La file n'est pas vide.\n");
    }

    return 0;
}

