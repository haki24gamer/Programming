#include <stdio.h>
#include <stdlib.h>

// Structure représentant un nœud de l'arbre binaire
struct Noeud {
    int donnee;
    struct Noeud* gauche;
    struct Noeud* droite;
};

// Fonction pour créer un nouveau nœud
struct Noeud* creerNoeud(int valeur) {
    struct Noeud* nouveauNoeud = (struct Noeud*)malloc(sizeof(struct Noeud));
    if (nouveauNoeud == NULL) {
        printf("Allocation de mémoire échouée.\n");
        exit(EXIT_FAILURE);
    }

    nouveauNoeud->donnee = valeur;
    nouveauNoeud->gauche = NULL;
    nouveauNoeud->droite = NULL;

    return nouveauNoeud;
}

// Fonction pour déterminer la racine de l'arbre
struct Noeud* determinerRacine(struct Noeud* arbre) {
    return arbre;
}

// Procédure pour lister toutes les feuilles de l'arbre
void listerFeuilles(struct Noeud* arbre) {
    if (arbre == NULL) {
        return;
    }

    if (arbre->gauche == NULL && arbre->droite == NULL) {
        printf("%d est une feuille.\n", arbre->donnee);
    } else {
        listerFeuilles(arbre->gauche);
        listerFeuilles(arbre->droite);
    }
}

// Fonction pour calculer la taille de l'arbre (nombre total de nœuds)
int tailleArbre(struct Noeud* arbre) {
    if (arbre == NULL) {
        return 0;
    } else {
        // Taille de l'arbre = 1 (racine) + taille de l'arbre gauche + taille de l'arbre droit
        return 1 + tailleArbre(arbre->gauche) + tailleArbre(arbre->droite);
    }
}

// Fonction renvoyant le sous-arbre gauche d'un nœud donné
struct Noeud* sousArbreGauche(struct Noeud* noeud) {
    if (noeud == NULL) {
        return NULL;
    }
    return noeud->gauche;
}

// Fonction renvoyant le sous-arbre droit d'un nœud donné
struct Noeud* sousArbreDroite(struct Noeud* noeud) {
    if (noeud == NULL) {
        return NULL;
    }
    return noeud->droite;
}

// Procédure pour afficher l'arbre de manière inordre (parcours symétrique)
void parcoursInordre(struct Noeud* arbre) {
    if (arbre != NULL) {
        parcoursInordre(arbre->gauche);
        printf("%d ", arbre->donnee);
        parcoursInordre(arbre->droite);
    }
}

// Procédure pour afficher l'arbre de manière préfixe (parcours NLR)
void parcoursPrefixe(struct Noeud* arbre) {
    if (arbre != NULL) {
        printf("%d ", arbre->donnee);
        parcoursPrefixe(arbre->gauche);
        parcoursPrefixe(arbre->droite);
    }
}

// Procédure pour afficher l'arbre de manière suffixe (parcours LRN)
void parcoursSuffixe(struct Noeud* arbre) {
    if (arbre != NULL) {
        parcoursSuffixe(arbre->gauche);
        parcoursSuffixe(arbre->droite);
        printf("%d ", arbre->donnee);
    }
}

// Procédure pour afficher l'arbre de manière textuelle avec des tirets
void afficherArbreTextuel(struct Noeud* arbre, int niveau) {
    if (arbre != NULL) {
        afficherArbreTextuel(arbre->droite, niveau + 1);
        
        for (int i = 0; i < niveau; i++) {
            printf("|--"); // Ajoute des tirets pour l'indentation
        }

        printf("%d\n", arbre->donnee);
        
        afficherArbreTextuel(arbre->gauche, niveau + 1);
    }
}


int main() {
    // Déclaration d'un arbre binaire simple
    struct Noeud* racine = creerNoeud(37);
    racine->gauche = creerNoeud(41);
    racine->gauche->gauche = creerNoeud(13);
    racine->gauche->gauche->droite = creerNoeud(3);
    racine->gauche->gauche->droite->gauche = creerNoeud(5);
    racine->gauche->gauche->droite->droite = creerNoeud(23);
    racine->droite = creerNoeud(2);
    racine->droite->droite = creerNoeud(11);
    racine->droite->gauche = creerNoeud(7);
    racine->droite->droite->gauche = creerNoeud(19);

    // Utilisation de la fonction pour déterminer la racine de l'arbre
    struct Noeud* racineDeLArbre = determinerRacine(racine);
    printf("La racine de l'arbre est : %d\n", racineDeLArbre->donnee);

    // Utilisation de la procédure pour lister toutes les feuilles de l'arbre
    printf("Liste des feuilles de l'arbre :\n");
    listerFeuilles(racine);

    // Utilisation de la fonction pour calculer la taille de l'arbre
    printf("Taille de l'arbre : %d\n", tailleArbre(racine));

    // Utilisation des fonctions pour obtenir les sous-arbres gauche et droit
    struct Noeud* sousArbreG = sousArbreGauche(racine);
    struct Noeud* sousArbreD = sousArbreDroite(racine);

    // Utilisation des procédures pour afficher l'arbre dans différents ordres
    printf("Affichage de l'arbre en ordre infixe :\n");
    parcoursInordre(racine);
    printf("\n");

    printf("Affichage de l'arbre en ordre préfixe :\n");
    parcoursPrefixe(racine);
    printf("\n");

    printf("Affichage de l'arbre en ordre suffixe :\n");
    parcoursSuffixe(racine);
    printf("\n");

    // Utilisation de la procédure pour afficher l'arbre de manière textuelle avec des tirets
    printf("Affichage de l'arbre de manière textuelle avec des tirets :\n");
    afficherArbreTextuel(racine, 0);

    

    return 0;
}
