#include <stdio.h>
#include <stdlib.h>

//Exo 1
typedef struct Node
{
    int val;
    struct Node* fgauche;
    struct Node* fdroite;
}Node;

Node cree_feuille(int f){
    Node res = {f,NULL,NULL};
    return res;
}

Node cree_arbre(int val, Node gauche, Node droite){
    Node res = {val,&gauche,&droite};
    return res;
}

/*
void afficher(Node* arbre){
    if (arbre)
    {
        return;
    }
    if (arbre->fgauche)
    {
        afficher(arbre.fgauche);
    }
    if (arbre.fgauche)
    {
        afficher(arbre.fdroite);
    }
    printf("%d",arbre.val);
}
*/
int main(int argc, char const *argv[])
{
    //feuilles
    Node f1 = cree_feuille(8);
    Node f2 = cree_feuille(9);
    Node f3 = cree_feuille(10);
    Node f4 = cree_feuille(11);
    Node f5 = cree_feuille(12);
    Node f6 = cree_feuille(13);
    Node f7 = cree_feuille(14);
    Node f8 = cree_feuille(15);

    //sous arbres niv 3
    Node ArV3_1 = cree_arbre(4,f1,f2);
    Node ArV3_2 = cree_arbre(5,f3,f4);
    Node ArV3_3 = cree_arbre(6,f5,f6);
    Node ArV3_4 = cree_arbre(7,f7,f8);

    //sous arbres nic 2
    Node ArV2_1 = cree_arbre(2,ArV3_1,ArV3_2);
    Node ArV2_2 = cree_arbre(3,ArV3_3,ArV3_4);

    //racine
    Node rac = cree_arbre(1,ArV2_1,ArV2_2);

    //arRac = cree_arbre(1,ar1,ar2);

    printf("                %d\n",rac.val);
    printf("             /    \\\n");
    printf("           %d       %d\n",ArV2_1.val,ArV2_2.val);
    printf("          /  \\    /  \\\n");
    printf("        %d    %d    %d   %d\n",ArV3_1.val,ArV3_2.val,ArV3_3.val,ArV3_4.val);
    printf("       / \\  / \\  / \\ / \\\n");
    printf("      %d  %d %d %d  \n",f1.val,f1.val,f1.val,f1.val);
   //printTree(arRac);
    
    return 0;
}
