#include <stdio.h>
#include <stdlib.h>

// Définition de la structure du nœud
typedef struct Noeud {
    int valeur; // Valeur entière du nœud
    struct Noeud* filsGauche; // Pointeur vers le nœud fils gauche
    struct Noeud* filsDroite; // Pointeur vers le nœud fils droit
} Noeud;

// Fonction pour créer une feuille avec une valeur donnée
Noeud cree_feuille(int valeur) {
    Noeud feuille; // Crée une feuille
    feuille.valeur = valeur; // Assignation de la valeur du nœud feuille
    feuille.filsGauche = NULL; // Aucun fils gauche
    feuille.filsDroite = NULL; // Aucun fils droit
    return feuille; // Renvoie la feuille créée
}

int main() {
    // Exemple d'utilisation de la fonction cree_feuille()
    Noeud feuille = cree_feuille(42); // Crée une feuille avec la valeur 42

    // Affichage de la valeur de la feuille créée
    printf("Valeur de la feuille : %d\n", feuille.valeur);

    return 0;
}

