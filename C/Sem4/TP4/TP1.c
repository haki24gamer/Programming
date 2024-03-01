#include <stdio.h>
#include <stdlib.h>

//1
typedef struct Node {
    int key;
    struct Node* left;
    struct Node* right;
} Node;



//2
void infix(Node *arbre){
    if (!arbre)
    {
        return;
    }
    if (arbre->left)
    {
        infix(arbre->left);
    }
    printf("%d ",arbre->key);
    if (arbre->right)
    {
        infix(arbre->right);
    }
}
//3
void postfix(Node *arbre){
    if (!arbre)
    {
        return;
    }
    if (arbre->left)
    {
        infix(arbre->left);
    }
    if (arbre->right)
    {
        infix(arbre->right);
    }
    printf("%d ",arbre->key);
}
//4
void prefix(Node *arbre){
    if (!arbre)
    {
        return;
    }
    if (arbre->right)
    {
        infix(arbre->right);
    }
    if (arbre->left)
    {
        infix(arbre->left);
    }
    printf("%d ",arbre->key);
}
//5
int ArbTaille(Node* arbre){
    if (!arbre)
    {
        return 0;
    }
    return 1+ArbTaille(arbre->left)+ArbTaille(arbre->right);
}

int main() {
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
    /*
    printf("Impression de l'arbre :\n");
    printTree(root);
    */

   infix(root);
   printf("\n");
   postfix(root);
   printf("\n");
   prefix(root);
   printf("\n");
   printf("%d",ArbTaille(root));
   

    return 0;
}

