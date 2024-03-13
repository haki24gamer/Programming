#include <stdio.h>
#include <stdlib.h>

// D�finition de la structure de l'arbre binaire
typedef struct Noeud {
    int valeur;
    struct Noeud *gauche;
    struct Noeud *droit;
} Arbre_B;

Arbre_B* creerArbre(int val, Arbre_B* fgauche, Arbre_B* fdroite){
    struct Noeud* nouveauNoeud = (struct Noeud*)malloc(sizeof(struct Noeud));
    nouveauNoeud->valeur=val;
    nouveauNoeud->droit=fdroite;
    nouveauNoeud->gauche=fgauche;
    return nouveauNoeud;
}

// Fonction pour d�terminer la racine de l'arbre
Arbre_B *racine(Arbre_B *arbre) {
    return arbre;
}

// Proc�dure pour lister toutes les feuilles de l'arbre
void lister_feuilles(Arbre_B *arbre) {
    if (arbre == NULL) return;

    if (arbre->gauche == NULL && arbre->droit == NULL) {
        printf("%d ", arbre->valeur);
    }

    lister_feuilles(arbre->gauche);
    lister_feuilles(arbre->droit);
}

// Fonction pour calculer la taille de l'arbre
int taille(Arbre_B *arbre) {
    if (arbre == NULL) return 0;

    return 1 + taille(arbre->gauche) + taille(arbre->droit);
}

// Fonction pour renvoyer le sous-arbre gauche
Arbre_B *sous_arbre_gauche(Arbre_B *arbre) {
    return arbre->gauche;
}

// Fonction pour renvoyer le sous-arbre droit
Arbre_B *sous_arbre_droit(Arbre_B *arbre) {
    return arbre->droit;
}

// Proc�dure pour afficher l'arbre (parcours en ordre infix� )
void afficher_arbre(Arbre_B *arbre) {
    if (arbre == NULL) {
    	return;
	}
	
	else {
		afficher_arbre(arbre->gauche);
		printf("%d ", arbre->valeur);
    	afficher_arbre(arbre->droit);
	}
    
}

// Parcours en ordre infixe
void parcours_infixe(Arbre_B *arbre) {
    if (arbre == NULL) return;

    parcours_infixe(arbre->gauche);
    printf("%d ", arbre->valeur);
    parcours_infixe(arbre->droit);
}

// Parcours en ordre pr�fixe
void parcours_prefixe(Arbre_B *arbre) {
    if (arbre == NULL) return;

    printf("%d ", arbre->valeur);
    parcours_prefixe(arbre->gauche);
    parcours_prefixe(arbre->droit);
}

// Parcours en ordre postfixe
void parcours_postfixe(Arbre_B *arbre) {
    if (arbre == NULL) return;

    parcours_postfixe(arbre->gauche);
    parcours_postfixe(arbre->droit);
    printf("%d ", arbre->valeur);
}

// Proc�dure pour afficher la racine de l'arbre
void afficher_racine(Arbre_B *arbre) {
    if (arbre == NULL) {
        printf("L'arbre est vide.\n");
        return;
    }
    printf("La racine de l'arbre est : %d\n", arbre->valeur);
}

int main() {
    // Cr�ation classique de l'arbre binaire T 
    Arbre_B *arbre = (Arbre_B*)malloc(sizeof(Arbre_B));
    arbre->valeur = 37;
    arbre->gauche = (Arbre_B*)malloc(sizeof(Arbre_B));
    arbre->gauche->valeur = 41;
    arbre->gauche->droit = NULL;
    arbre->gauche->gauche = (Arbre_B*)malloc(sizeof(Arbre_B));
    arbre->gauche->gauche->valeur = 13;
    arbre->gauche->gauche->gauche = NULL;
    arbre->gauche->gauche->droit = (Arbre_B*)malloc(sizeof(Arbre_B));
    arbre->gauche->gauche->droit->valeur = 3;
    arbre->gauche->gauche->droit->gauche = (Arbre_B*)malloc(sizeof(Arbre_B));
    arbre->gauche->gauche->droit->gauche->valeur = 5;
    arbre->gauche->gauche->droit->gauche->gauche = NULL;
    arbre->gauche->gauche->droit->gauche->droit = NULL;
    arbre->gauche->gauche->droit->droit = (Arbre_B*)malloc(sizeof(Arbre_B));
    arbre->gauche->gauche->droit->droit->valeur = 23;
    arbre->gauche->gauche->droit->droit->gauche = NULL;
    arbre->gauche->gauche->droit->droit->droit = NULL;
    arbre->gauche->droit = NULL;
    
	
	arbre->droit = (Arbre_B*)malloc(sizeof(Arbre_B));
    arbre->droit->valeur = 2;
    arbre->droit->gauche = (Arbre_B*)malloc(sizeof(Arbre_B));
    arbre->droit->gauche->valeur = 7;
    arbre->droit->gauche->gauche = NULL;
    arbre->droit->gauche->droit = NULL;
    arbre->droit->droit = (Arbre_B*)malloc(sizeof(Arbre_B));
    arbre->droit->droit->valeur = 11;
    arbre->droit->droit->gauche = (Arbre_B*)malloc(sizeof(Arbre_B));
    arbre->droit->droit->gauche->valeur = 19;
    arbre->droit->droit->gauche->gauche = NULL;
    arbre->droit->droit->gauche->droit = NULL;
    arbre->droit->droit->droit = NULL;

    //Creation avec la fonction creerArbre
    Arbre_B* A = creerArbre(3,creerArbre(5,NULL,NULL),creerArbre(23,NULL,NULL));
    Arbre_B* B = creerArbre(13,NULL,A);
    Arbre_B* C = creerArbre(41,B,NULL);
    Arbre_B* D = creerArbre(11,creerArbre(19,NULL,NULL),NULL);
    Arbre_B* E = creerArbre(2,creerArbre(7,NULL,NULL),D);
    
    Arbre_B* racine = creerArbre(37,C,E);
   
   
   // 
    parcours_infixe(racine); 

    // Affichage de l'arbre
    printf("Affichage de l'arbre en ordre infix�:\n");
    afficher_arbre(arbre);
    printf("\n");

    // Affichage de la racine de l'arbre
    afficher_racine(arbre);

    // Affichage de toutes les feuilles de l'arbre
    printf("Feuilles de l'arbre : ");
    lister_feuilles(arbre);
    printf("\n");

    // Calcul de la taille de l'arbre
    printf("Taille de l'arbre : %d\n", taille(arbre));

    // Affichage du sous-arbre gauche de l'arbre
    printf("Sous-arbre gauche de l'arbre : ");
    afficher_arbre(sous_arbre_gauche(arbre));
    printf("\n");

    // Affichage du sous-arbre droit de l'arbre
    printf("Sous-arbre droit de l'arbre : ");
    afficher_arbre(sous_arbre_droit(arbre));
    printf("\n");

    // Parcours en ordre infixe de l'arbre
    printf("Parcours en ordre infixe de l'arbre : ");
    parcours_infixe(arbre);
    printf("\n");

    // Parcours en ordre pr�fixe de l'arbre
    printf("Parcours en ordre pr�fixe de l'arbre : ");
    parcours_prefixe(arbre);
    printf("\n");

    // Parcours en ordre postfixe de l'arbre
    printf("Parcours en ordre postfixe de l'arbre : ");
    parcours_postfixe(arbre);
    printf("\n");

    // Lib�ration de la m�moire allou�e pour l'arbre
    free(arbre->gauche->droit->droit->gauche->droit);
    free(arbre->gauche->droit->droit->gauche);
    free(arbre->gauche->droit->droit->droit);
    free(arbre->gauche->droit->droit);
    free(arbre->gauche->droit);
    free(arbre->gauche);
    free(arbre->droit->gauche);
    free(arbre->droit->droit->gauche);
    free(arbre->droit->droit);
    free(arbre->droit);
    free(arbre);

    return 0;
    printf("tu vas jamais me voire !!!!!!!!!");

}

