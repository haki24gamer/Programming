#include <stdio.h>
#include <stdlib.h>
/*
Parcours en ordre (infixe) de l'arbre :
1 3 5 6 8 10 12 15 20
*/

// Définition de la structure du nœud
typedef struct Node {
    int key; // Clé du nœud
    struct Node* left; // Pointeur vers le nœud fils gauche
    struct Node* right; // Pointeur vers le nœud fils droit
} Node;

// Fonction pour imprimer un arbre binaire en ordre croissant des clés
void printTree(Node *tree) {
    if (!tree) return; // Si l'arbre est vide, retourne
    if (tree->left) printTree(tree->left); // Imprime le sous-arbre gauche
    printf("Cle = %d\n", tree->key); // Imprime la clé du nœud actuel
    if (tree->right) printTree(tree->right); // Imprime le sous-arbre droit
}

int main() {
    // Création de l'arbre binaire
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

    // Libération de la mémoire allouée pour l'arbre
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

