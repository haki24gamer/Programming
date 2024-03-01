#include <stdio.h>
#include <stdlib.h>

// Définition de la structure du nœud
typedef struct Noeud{
    int valeur; // Valeur entière du nœud
    struct Noeud* filsGauche; // Pointeur vers le nœud fils gauche
    struct Noeud* filsDroite; // Pointeur vers le nœud fils droit
}Noeud;


// Fonction pour créer un nouvel arbre avec une valeur donnée et deux sous-arbres
Noeud cree_arbre(int valeur, Noeud *sousArbreGauche, Noeud *sousArbreDroite) {
    Noeud nouvelArbre; // Crée un nouvel arbre
    nouvelArbre.valeur = valeur; // Assignation de la valeur du nœud racine
    nouvelArbre.filsGauche = sousArbreGauche; // Assignation du sous-arbre gauche
    nouvelArbre.filsDroite = sousArbreDroite; // Assignation du sous-arbre droit
    return nouvelArbre; // Renvoie le nouvel arbre créé
}

int main() {
    // Exemple d'utilisation de la fonction cree_arbre()
    
    // Création de deux sous-arbres simples
    Noeud* sousArbreGauche = malloc(sizeof(Noeud));
    sousArbreGauche->valeur = 5;
    sousArbreGauche->filsGauche = NULL;
    sousArbreGauche->filsDroite = NULL;
    
    Noeud* sousArbreDroite = malloc(sizeof(Noeud));
    sousArbreDroite->valeur = 15;
    sousArbreDroite->filsGauche = NULL;
    sousArbreDroite->filsDroite = NULL;
    



    // Création de l'arbre principal avec la valeur 10 et les deux sous-arbres créés
    Noeud arbrePrincipal = cree_arbre(10, sousArbreGauche, sousArbreDroite);
    
    // Libération de la mémoire allouée pour les sous-arbres
    free(sousArbreGauche);
    free(sousArbreDroite);

    return 0;
}

