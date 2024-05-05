#include <stdio.h>
#include <stdlib.h>

// D�finition de la structure d'un n�ud d'arbre
typedef struct Noeud {
    int cle;
    struct Noeud *gauche;
    struct Noeud *droite;
} Noeud;

// Fonction pour cr�er un nouveau n�ud
Noeud* creerNoeud(int cle) {
    Noeud* nouveauNoeud = (Noeud*)malloc(sizeof(Noeud));
    nouveauNoeud->cle = cle;
    nouveauNoeud->gauche = nouveauNoeud->droite = NULL;
    return nouveauNoeud;
}

// Fonction pour ins�rer un n�ud dans l'arbre
Noeud* inserer(Noeud* racine, int cle) {
    if (racine == NULL) {
        return creerNoeud(cle);
    }
    if (cle < racine->cle) {
        racine->gauche = inserer(racine->gauche, cle);
    } else if (cle > racine->cle) {
        racine->droite = inserer(racine->droite, cle);
    }
    return racine;
}

// Fonction pour rechercher une cl� dans l'arbre
Noeud* rechercher(Noeud* racine, int cle) {
    if (racine == NULL || racine->cle == cle) {
        return racine;
    }
    if (cle < racine->cle) {
        return rechercher(racine->gauche, cle);
    }
    return rechercher(racine->droite, cle);
}

// Fonction pour trouver le n�ud avec la plus grande cl�
Noeud* trouverMax(Noeud* racine) {
    if (racine == NULL || racine->droite == NULL) {
        return racine;
    }
    return trouverMax(racine->droite);
}

// Fonction pour trouver le n�ud avec la plus petite cl�
Noeud* trouverMin(Noeud* racine) {
    if (racine == NULL || racine->gauche == NULL) {
        return racine;
    }
    return trouverMin(racine->gauche);
}

// Fonction pour supprimer un n�ud dans l'arbre
Noeud* supprimerNoeud(Noeud* racine, int cle) {
    if (racine == NULL) {
        return racine;
    }
    if (cle < racine->cle) {
        racine->gauche = supprimerNoeud(racine->gauche, cle);
    } else if (cle > racine->cle) {
        racine->droite = supprimerNoeud(racine->droite, cle);
    } else {
        // N�ud � supprimer trouv�
        if (racine->gauche == NULL) {
            Noeud* temp = racine->droite;
            free(racine);
            return temp;
        } else if (racine->droite == NULL) {
            Noeud* temp = racine->gauche;
            free(racine);
            return temp;
        }
        // N�ud avec deux enfants, trouver le successeur (minimum du sous-arbre droit)
        Noeud* temp = trouverMin(racine->droite);
        // Copier la cl� du successeur
        racine->cle = temp->cle;
        // Supprimer le successeur
        racine->droite = supprimerNoeud(racine->droite, temp->cle);
    }
    return racine;
}

// Fonction pour afficher le parcours pr�fixe de l'arbre
void parcoursPrefixe(Noeud* racine) {
    if (racine != NULL) {
        printf("%d ", racine->cle);
        parcoursPrefixe(racine->gauche);
        parcoursPrefixe(racine->droite);
    }
}

int main() {
    Noeud* racine = NULL;
    int cles[] = {10, 4, 3, 8, 5, 20, 15};
    int i;
    
    // Insertion des cl�s dans l'arbre
    for (i = 0; i < sizeof(cles) / sizeof(cles[0]); i++) {
        racine = inserer(racine, cles[i]);
    }
    
    printf("Parcours prefixe de l'arbre apres insertion: ");
    parcoursPrefixe(racine);
    printf("\n");
    
    // Recherche d'une cl�
    int cleRecherchee = 8;
    Noeud* noeudTrouve = rechercher(racine, cleRecherchee);
    if (noeudTrouve != NULL) {
        printf("La cle %d est trouvee dans l'arbre.\n", cleRecherchee);
    } else {
        printf("La cle %d n'est pas trouvee dans l'arbre.\n", cleRecherchee);
    }
    
    // Recherche du maximum
    Noeud* noeudMax = trouverMax(racine);
    printf("La cle maximale dans l'arbre est: %d\n", noeudMax->cle);
    
    // Recherche du minimum
    Noeud* noeudMin = trouverMin(racine);
    printf("La cle minimale dans l'arbre est: %d\n", noeudMin->cle);
    
    // Suppression d'une cl�
    int cleSupprimer = 20;
    racine = supprimerNoeud(racine, cleSupprimer);
    printf("Parcours prefixe de l'arbre apres suppression de la cle %d: ", cleSupprimer);
    parcoursPrefixe(racine);
    printf("\n");

    return 0;
}

