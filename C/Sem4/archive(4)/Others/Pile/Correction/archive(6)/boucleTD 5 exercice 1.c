
#include <stdio.h>
#include <stdbool.h>

// D�finition des constantes et types
#define N 7 // Taille maximale de la pile
typedef int Type_C; // Type des donn�es enregistr�es dans la pile

typedef struct {
    Type_C T[N]; // Tableau de donn�es
    int Sommet; // Indice du sommet de la pile
} Pile;

// Initialisation de la pile
void Init_Pile(Pile *P) {
    P->Sommet = 0; // Initialiser le sommet de la pile � 0 pour indiquer qu'elle est vide
}

// V�rifier si la pile est vide
bool Pile_vide(Pile P) {
    if (P.Sommet == 0) {
        return 1;
    } else {
        return 0;
    }
}

// V�rifier si la pile est pleine
bool Pile_pleine(Pile P) {
    if (P.Sommet == N) {
        return 1;
    } else {
        return 0; 
    }
}

// Ajouter une valeur � la pile (empiler)
void Empiler(Pile *P, Type_C X) {
    if (!Pile_pleine(*P)) {
        P->T[P->Sommet] = X;
        P->Sommet++;
    } else {
        printf("Erreur : la pile est pleine.\n");
    }
}

// Supprimer une valeur de la pile (d�piler)
void Depiler(Pile *P, Type_C *X) {
    if (!Pile_vide(*P)) {
        P->Sommet--;
        *X = P->T[P->Sommet];
    } else {
        printf("Erreur : la pile est vide.\n");
    }
}

int main() {
    Pile maPile;
    Init_Pile(&maPile);

    // Tester les op�rations de la pile
    if (Pile_vide(maPile)) {
        printf("La pile est vide \n");
    } else {
        printf("La pile n'est pas vide \n");
    }
    int i ,temp;
    
	for (i=0;i < N;i++){
        printf("veuillez saisir la valeur %d a ajouter : ",i);
		scanf("%d",&temp);
		Empiler(&maPile, temp);
	}
    int sommet;
    
    if (Pile_pleine(maPile)) {
        printf("La pile est pleine \n");
    } else {
        printf("La pile n'est pas pleine \n");
    }

    printf("piler vider : \n");
    for (i=0;i<N;i++){
		Depiler(&maPile, &sommet);
		printf("%d \n",sommet);
	}

    if (Pile_pleine(maPile)) {
        printf("La pile est pleine \n");
    } else {
        printf("La pile n'est pas pleine \n");
    }
      if (Pile_vide(maPile)) {
        printf("La pile est vide \n");
    } else {
        printf("La pile n'est pas vide \n");
    }

    return 0;
}

