#include <stdio.h>
#include <stdlib.h>

//Exo 1
typedef struct noeud
{
    int val;
    struct noued* fgauche;
    struct noued* fdroite;
}noued;

noued cree_arbre(int val, noued gauche, noued droite){
    noued res = {val,&gauche,&droite};
    return res;
}

noued cree_feuille(int f){
    noued res = {f,NULL,NULL};
    return res;
}


int main(int argc, char const *argv[])
{
    //feuilles
    noued f1 = cree_feuille(4);
    noued f2 = cree_feuille(5);
    noued f3 = cree_feuille(6);
    noued f4 = cree_feuille(7);

    //sous arbres
    noued ar1 = cree_arbre(2,f1,f2);
    noued ar2 = cree_arbre(3,f3,f4);

    //racine
    noued* arRac = (noued*)malloc(sizeof(noued));
    //arRac = cree_arbre(1,ar1,ar2);
    arRac->val=1;
    arRac->fgauche=&ar1;
    arRac->fdroite=&ar2;

    
    int arbre[] = {arRac.val,ar1.val,ar2.val,f1.val,f2.val,f3.val,f4.val};
    for (int i = 0; i < 7; i++)
    {
        printf("%d ",arbre[i]);
    }
    

   //printTree(arRac);
    
    return 0;
}
