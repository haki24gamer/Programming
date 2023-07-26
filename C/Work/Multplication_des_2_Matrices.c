#include <stdio.h>

int main()
{
    //Variables
    int nl1, nc1, nl2, nc2,i, j, k;


    printf("Entrer les dimensions du 1ere matrice:\n");
    scanf("%d %d",&nl1,&nc1);
    printf("Entrer les dimensions du 2ere matrice:\n");
    scanf("%d %d",&nl2,&nc2);

    int M1[nl1][nc1];
    int M2[nl2][nc2];
    int M3[nl1][nc2];


    if (nc1==nl2)
    {
        
        printf("Entrer les elements du 1ere matrice:\n");
        for (int i = 0; i < nl1; i++)
        {
            for (int j = 0; j < nc1; j++)
            {
                scanf(" %d ",&M1[i][j]);
            }
        }
        printf("Entrer les elements du 2nd matrice:\n");
        for (int i = 0; i < nl2; i++)
        {
            for (int j = 0; j < nc2; j++)
            {
                scanf(" %d ",&M2[i][j]);
            }
        }


        for (int i = 0; i < nl1; i++)
        {
            for (int j = 0; j < nc2; j++)
            {
                M3[i][j]=0;
            }
        }
        for (int i = 0; i < nl1; i++)
        {
            for (int j = 0; j < nc2; j++)
            {
                for (int k = 0; k < nc1; k++)
                {
                    M3[i][j]+=M1[i][k]*M2[k][j];
                }
                
            }
        }
        
        for (int i = 0; i < nl1; i++)
        {
            for (int j = 0; j < nc2; j++)
            {
                printf("%4d ", M3[i][j]);
            }
            printf("\n");
            
        }
    }
    else
    {
        printf("Le nombre du colonne du 1ere matrice doit etre egale a la nombre des lignes du 2nd matrice");
    }
}