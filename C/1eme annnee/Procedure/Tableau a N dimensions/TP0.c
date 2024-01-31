#include <stdio.h>

int main()
{
    //Varibales
    int L,C,i,j,Somme;

    //Creation du tableau
    printf("Entrer le nombres des lignes et colonnes:\n");
    scanf("%d %d",&L,&C);
    int tab[L][C];

    //Remplir le tableau
    printf("Remplir le tableau!\n");
    for (i = 0; i < L; i++)
    {
        printf("Entrer les elments de la ligne %d:\n",i+1);
        for (j = 0; j < C; j++)
        {
            scanf("%d",&tab[i][j]);
        }
    }

    //Addition des elements
    Somme = 0;
    for (i = 0; i < L; i++)
    {
        for (j = 0; j < C; j++)
        {
            Somme+=tab[i][j];
        }
    }
    
    //Affichage
    printf("La somme des elements du tableau est egale a %d",Somme);
}