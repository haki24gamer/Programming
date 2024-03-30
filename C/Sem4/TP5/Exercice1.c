#include <stdio.h>
#include <stdlib.h>

//Q1
typedef struct Node{
    int val;
    struct Node* fgauche;
    struct Node* fdroite;
};

struct Node* creerArbre(int valeurs, struct Node* gauche, struct Node* droite){
    struct Node* rac = (struct Node*)(malloc(sizeof(struct Node)));
    rac->val=valeurs;
    rac->fgauche=gauche;
    rac->fdroite=droite;
    return rac;
}

int max(struct Node* arbre){
    if (arbre->fdroite==NULL)
    {
        return arbre->val;
    }
    return max(arbre->fdroite);
    
}
int min(struct Node* arbre){
    if (arbre->fgauche==NULL)
    {
        return arbre->val;
    }
    return min(arbre->fgauche);
    
}

int main(int argc, char const *argv[])
{
    
    struct Node* D = creerArbre(8,creerArbre(5,NULL,NULL),NULL);
    struct Node* B = creerArbre(4,creerArbre(3,NULL,NULL),D);
    struct Node* C = creerArbre(20,creerArbre(15,NULL,NULL),NULL);
    struct Node* rac = creerArbre(10,B,C);

    printf("%d",min(rac));
    return 0;
}
