#include <stdio.h>
#include <stdlib.h>

// D�claration de la structure de donn�es pour l'arbre binaire
typedef struct Noeud {
    int valeur;
    struct Noeud *gauche;
    struct Noeud *droit;
} Noeud;

// Fonction pour cr�er un nouveau noeud
Noeud* creerNoeud(int valeur) {
    Noeud* nouveauNoeud = (Noeud*)malloc(sizeof(Noeud));
    nouveauNoeud->valeur = valeur;
    nouveauNoeud->gauche = NULL;
    nouveauNoeud->droit = NULL;
    return nouveauNoeud;
}

// Fonction pour ins�rer un noeud dans l'arbre
Noeud* inserer(Noeud* racine, int valeur) {
    if (racine == NULL)
        return creerNoeud(valeur);

    if (valeur < racine->valeur)
        racine->gauche = inserer(racine->gauche, valeur);
    else if (valeur > racine->valeur)
        racine->droit = inserer(racine->droit, valeur);

    return racine;
}

// Fonction pour retrouver le maximum dans l'arbre
int trouverMaximum(Noeud* racine) {
    if (racine == NULL)
        return -1; // Retourne -1 si l'arbre est vide
    
    while (racine->droit != NULL)
        racine = racine->droit;

    return racine->valeur;
}

// Fonction pour retrouver le minimum dans l'arbre
int trouverMinimum(Noeud* racine) {
    if (racine == NULL)
        return -1; // Retourne -1 si l'arbre est vide
    
    while (racine->gauche != NULL)
        racine = racine->gauche;

    return racine->valeur;
}

// Fonction pour tester si l'arbre est vide ou non
int estVide(Noeud* racine) {
    return (racine == NULL);
}

// Proc�dure pour parcourir l'arbre en postfixe
void postfixe(Noeud* racine) {
    if (racine == NULL)
        return;
    postfixe(racine->gauche);
    postfixe(racine->droit);
    printf("%d ", racine->valeur);
}

// Fonction pour retourner la taille de l'arbre
int tailleArbre(Noeud* racine) {
    if (racine == NULL)
        return 0;
    return 1 + tailleArbre(racine->gauche) + tailleArbre(racine->droit);
}

// Fonction pour retourner la valeur de la racine
int racine(Noeud* racine) {
    if (racine == NULL)
        return -1; // Retourne -1 si l'arbre est vide
    return racine->valeur;
}



//Rechercher
Noeud* Recherche(Noeud* racine, int v){
    if (racine==NULL)
    {
        return 1;
    }
    else
    {
        if (racine->valeur==v)
        {
            return racine;
        }
        else
        {
            if (racine->valeur>=v)
            {
                return Recherche(racine->gauche,v);
            }
            else
            {
                return Recherche(racine->droit,v);
            }
        }
    }
}


//Supprimer
Noeud* Supprimer(Noeud* racine, int e){
    if (racine->valeur>e)
    {
        return Supprimer(racine->gauche,e);
    }
    else if (racine->valeur<e)
    {
        return Supprimer(racine->droit,e);
    }
    else if(racine->valeur==e)
    {
        if ((racine->droit==NULL)&&(racine->gauche==NULL))
        {
            racine=NULL;
        }
        else if ((racine->droit==NULL))
        {
            racine=racine->gauche;
        }
        else if((racine->gauche==NULL))
        {
            racine=racine->droit;
        }
        else
        {
            /* code */
        }
        
        
        
        
    }
    
    
}




// Programme principal
int main() {
    Noeud* racin = NULL;
    int elements[] = {10, 4, 3, 8, 5, 20, 15};
    int i;

    // Insertion des �l�ments dans l'arbre
    for (i = 0; i < sizeof(elements) / sizeof(elements[0]); i++)
        racin = inserer(racin, elements[i]);

    // Affichage du maximum
    printf("Le maximum dans l'arbre est : %d\n", trouverMaximum(racin));

    // Affichage du minimum
    printf("Le minimum dans l'arbre est : %d\n", trouverMinimum(racin));

    // Test si l'arbre est vide
    if (estVide(racin))
        printf("L'arbre est vide.\n");
    else
        printf("L'arbre n'est pas vide.\n");

    // Parcours en postfixe
    printf("Parcours en postfixe : ");
    postfixe(racin);
    printf("\n");

    // Taille de l'arbre
    printf("La taille de l'arbre est : %d\n", tailleArbre(racin));

    // Valeur de la racine
    printf("La valeur de la racine est : %d\n", racine(racin));



    return 0;
}

