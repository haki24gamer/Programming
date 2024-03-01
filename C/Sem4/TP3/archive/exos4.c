#include <stdio.h>
#include <stdlib.h>

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
    // Création d'un arbre binaire simple
    Node* root = (Node*)malloc(sizeof(Node));
    root->key = 10;
    root->left = (Node*)malloc(sizeof(Node));
    root->left->key = 5;
    root->left->left = NULL;
    root->left->right = NULL;
    root->right = (Node*)malloc(sizeof(Node));
    root->right->key = 15;
    root->right->left = NULL;
    root->right->right = NULL;

    // Appel de la fonction pour imprimer l'arbre
    printf("Impression de l'arbre :\n");
    printTree(root);

    // Libération de la mémoire allouée pour l'arbre
    free(root->left);
    free(root->right);
    free(root);

    return 0;
}

