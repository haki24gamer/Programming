#include <stdio.h>
#include <unistd.h>
#include <time.h>
#include <stdlib.h>

//@haki24gamer 

int main()
{
    //Variables
    int nl1, nc1, nl2, nc2,i, j, k;


    printf("Entrer le nombres des lignes et colonnes du M1:\n");
    scanf("%d %d",&nl1,&nc1);

    printf("Entrer le nombres des lignes et colonnes du M2:\n");
    scanf("%d %d",&nl2,&nc2);

    int M1[nl1][nc1];
    int M2[nl2][nc2];
    int M3[nl1][nc2];


    printf("Entrer les elements du M1: ");
    for (int i = 0; i < nl1; i++)
    {
        for (int j = 0; j < nc1; j++)
        {
            scanf("%d",&M1[i][j]);
        }
        
    }


    printf("Entrer les elements du M2: ");
    for (int i = 0; i < nl2; i++)
    {
        for (int j = 0; j < nc2; j++)
        {
            scanf("%d",&M2[i][j]);
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
            printf("%d ", M3[i][j]);
        }
        printf("\n");
        
    }
}