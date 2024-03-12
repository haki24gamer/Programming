#include <stdio.h>
#include <stdlib.h>
/*
Parcours en ordre (infixe) de l'arbre :
1 3 5 6 8 10 12 15 20
*/

// D�finition de la structure du n�ud
typedef struct Node {
    int key; // Cl� du n�ud
    struct Node* left; // Pointeur vers le n�ud fils gauche
    struct Node* right; // Pointeur vers le n�ud fils droit
} Node;

// Fonction pour imprimer un arbre binaire en ordre croissant des cl�s
void printTree(Node *tree) {
    if (!tree) return; // Si l'arbre est vide, retourne
    if (tree->left) printTree(tree->left); // Imprime le sous-arbre gauche
    printf("Cle = %d\n", tree->key); // Imprime la cl� du n�ud actuel
    if (tree->right) printTree(tree->right); // Imprime le sous-arbre droit
}

int main() {
    // Cr�ation de l'arbre binaire
    Node* root = (Node*)malloc(sizeof(Node));
    root->key = 10;

    root->left = (Node*)malloc(sizeof(Node));
    root->left->key = 5;
    root->left->left = (Node*)malloc(sizeof(Node));
    root->left->left->key = 3;
    root->left->left->left = (Node*)malloc(sizeof(Node));
    root->left->left->left->key = 1;
    root->left->left->left->left = NULL;
    root->left->left->left->right = NULL;
    root->left->left->right = NULL;

    root->left->right = (Node*)malloc(sizeof(Node));
    root->left->right->key = 8;
    root->left->right->left = (Node*)malloc(sizeof(Node));
    root->left->right->left->key = 6;
    root->left->right->left->left = NULL;
    root->left->right->left->right = NULL;
    root->left->right->right = NULL;

    root->right = (Node*)malloc(sizeof(Node));
    root->right->key = 15;
    root->right->left = (Node*)malloc(sizeof(Node));
    root->right->left->key = 12;
    root->right->left->left = NULL;
    root->right->left->right = NULL;
    root->right->right = (Node*)malloc(sizeof(Node));
    root->right->right->key = 20;
    root->right->right->left = NULL;
    root->right->right->right = NULL;

    // Appel de la fonction pour imprimer l'arbre
    printf("Impression de l'arbre :\n");
    printTree(root);

    // Lib�ration de la m�moire allou�e pour l'arbre
    free(root->left->left->left);
    free(root->left->left);
    free(root->left->right->left);
    free(root->left->right);
    free(root->left);
    free(root->right->left);
    free(root->right->right);
    free(root->right);
    free(root);

    return 0;
}

