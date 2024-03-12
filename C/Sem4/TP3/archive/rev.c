#include <stdio.h>

typedef struct Node
{
    int val;
    struct Node* left;
    struct Node* right;
} Node;


int main(int argc, char const *argv[])
{
    Node* rac = (Node*)malloc(sizeof(Node));
    rac->val=37;
    rac->left = (Node*)malloc(sizeof(Node));
    rac->left=41;
    rac->left->left = (Node*)malloc(sizeof(Node));
    rac->left->left=13;
    rac->left->left->left=NULL;
    rac->left->left->right = (Node*)malloc(sizeof(Node));
    rac->left->left->right=3;
    rac->left->left->right->left = (Node*)malloc(sizeof(Node));
    rac->left->left->right->left=5;
    rac->left->left->right->left->left = NULL;
    rac->left->left->right->left->right = NULL;
    rac->left->left->right->right = (Node*)malloc(sizeof(Node));
    rac->left->left->right->right=23;
    rac->left->left->right->right->left = NULL;
    rac->left->left->right->right->right = NULL;
    rac->right=(Node*)malloc(sizeof(Node));
    rac->right=2;
    rac->right->left=(Node*)malloc(sizeof(Node));
    rac->right->left=7;
    rac->right->left->left=NULL;
    rac->right->left->right=NULL;
    rac->right->right=(Node*)malloc(sizeof(Node));
    rac->right->right=11;
    rac->right->right->left=(Node*)malloc(sizeof(Node));
    rac->right->right->left=19;
    rac->right->right->left->left=NULL;
    rac->right->right->left->right=NULL;
    rac->right->right->right=NULL;


    return 0;
}
