#include <stdio.h>
#include <stdlib.h>

// D�finition de la structure du n�ud
typedef struct Noeud{
    int valeur; // Valeur enti�re du n�ud
    struct Noeud* filsGauche; // Pointeur vers le n�ud fils gauche
    struct Noeud* filsDroite; // Pointeur vers le n�ud fils droit
}Noeud;


// Fonction pour cr�er un nouvel arbre avec une valeur donn�e et deux sous-arbres
Noeud cree_arbre(int valeur, Noeud *sousArbreGauche, Noeud *sousArbreDroite) {
    Noeud nouvelArbre; // Cr�e un nouvel arbre
    nouvelArbre.valeur = valeur; // Assignation de la valeur du n�ud racine
    nouvelArbre.filsGauche = sousArbreGauche; // Assignation du sous-arbre gauche
    nouvelArbre.filsDroite = sousArbreDroite; // Assignation du sous-arbre droit
    return nouvelArbre; // Renvoie le nouvel arbre cr��
}

int main() {
    // Exemple d'utilisation de la fonction cree_arbre()
    
    // Cr�ation de deux sous-arbres simples
    Noeud* sousArbreGauche = malloc(sizeof(Noeud));
    sousArbreGauche->valeur = 5;
    sousArbreGauche->filsGauche = NULL;
    sousArbreGauche->filsDroite = NULL;
    
    Noeud* sousArbreDroite = malloc(sizeof(Noeud));
    sousArbreDroite->valeur = 15;
    sousArbreDroite->filsGauche = NULL;
    sousArbreDroite->filsDroite = NULL;
    



    // Cr�ation de l'arbre principal avec la valeur 10 et les deux sous-arbres cr��s
    Noeud arbrePrincipal = cree_arbre(10, sousArbreGauche, sousArbreDroite);
    
    // Lib�ration de la m�moire allou�e pour les sous-arbres
    free(sousArbreGauche);
    free(sousArbreDroite);

    return 0;
}

