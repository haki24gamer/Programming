#include <stdio.h>
#include <stdlib.h> // Pour malloc et free
#include <stdbool.h>

// type des éléments
typedef int Type_C;

// Structure d'un nœud de la liste chaînée
typedef struct Element {
    Type_C valeur;
    struct Element *suivant;
} Element;

// Structure de la file basée sur une liste chaînée
typedef struct {
    Element *tete;
    Element *queue;
} File;

// Initialisation de la file
void Init_File(File *file) {
    file->tete = NULL;
    file->queue = NULL;
}

// Vérifier si la file est vide
bool File_vide(File file) {
    return file.tete == NULL;
}

// Ajouter une valeur à la file (enfiler)
void Enfiler(File *file, Type_C valeur) {
    Element *nouveau_element = malloc(sizeof(Element));
    if (nouveau_element == NULL) {
        fprintf(stderr, "Erreur : impossible d'allouer de la mémoire.\n");
        exit(EXIT_FAILURE);
    }
    nouveau_element->valeur = valeur;
    nouveau_element->suivant = NULL;

    if (File_vide(*file)) {
        file->tete = nouveau_element;
        file->queue = nouveau_element;
    } else {
        file->queue->suivant = nouveau_element;
        file->queue = nouveau_element;
    }
}

// Supprimer une valeur de la file (défiler)
void Defiler(File *file, Type_C *valeur) {
    if (File_vide(*file)) {
        fprintf(stderr, "Erreur : la file est vide.\n");
        exit(EXIT_FAILURE);
    }
    *valeur = file->tete->valeur;
    Element *tmp = file->tete;
    file->tete = file->tete->suivant;
    free(tmp);
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
    
  	printf("vider la file \n");
	while(!File_vide(maFile)){
    Type_C valeur;
    Defiler(&maFile, &valeur);
    printf("Valeur défiler : %d\n", valeur);
	}


    if (File_vide(maFile)) {
        printf("La file est vide.\n");
    } else {
        printf("La file n'est pas vide.\n");
    }

    return 0;
}

