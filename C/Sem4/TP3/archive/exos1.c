#include <stdio.h>
#include <stdlib.h>

// Définition de la structure du nœud
typedef struct Noeud {
    int valeur; // Valeur entière du nœud
    struct Noeud *filsGauche; // Pointeur vers le nœud fils gauche
    struct Noeud *filsDroite; // Pointeur vers le nœud fils droit
}Noeud;


int main() {
    // Exemple d'utilisation de la structure
    Noeud racine; 
    racine.valeur = 10; // Assignation d'une valeur à la racine
    racine.filsGauche = NULL; // Initialisation du fils gauche à NULL (pas de fils pour l'instant)
    racine.filsDroite = NULL; // Initialisation du fils droit à NULL (pas de fils pour l'instant)
    
    // Libération de la mémoire allouée
    //free(racine);

    return 0;
}

