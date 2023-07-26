#include <stdio.h>

int main()
{
    //Variables
    int L,C;

    //Creation du tableau
    printf("Entrer le nombres des lignes et colonnes N:\n");
    scanf("%d %d",&L,&C);
    int tab[L][C];

    if (C!=L)
    {
        printf("le nombres des lignes et colonnes ne sont pas egales!");
    }
    else
    {
        
        //Remplir le tableau et mettre des 0s aux diagonales
        for (int i = 0; i < L; i++)
        {
            printf("Veuillez entrer les elements de la ligne %d", i+1);
            for (int j = 0; j < C; j++)
            {
                if (i!=j)
                {
                    scanf("%d",&tab[i][j]);
                }
                else
                {
                    tab[i][j]=0;
                }
            }
        }

        //Afficher le tableaux
        printf("Tableaux:\n");
        for (int i = 0; i < L; i++)
        {
            for (int j = 0; j < C; j++)
            {
                printf("%5d",tab[i][j]);
            }
            printf("\n");
        }
        
    }
    
    
    
}