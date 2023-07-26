#include <stdio.h>

int main()
{
    int i,j,NC,NL,nbr0;

    printf("Lignes et colonnes:\n");
    scanf("%d %d",&NC,&NL);
    int T[NL][NC];
    printf("Les elements:\n");
    for (int i = 0; i < NL; i++)
    {
        for (int j = 0; j < NC; j++)
        {
            scanf("%d",&T[i][j]);
        }
        
    }
    nbr0=0;
    for (int i = 0; i < NL; i++)
    {
        for (int j = 0; j < NC; j++)
        {
            if (T[i][j]==0)
            {
                nbr0++;
            }
            
        }
        
    }

    int max=NC*NL/2;

    if (max<=nbr0)
    {
        printf("Creuse");
    }
    else
    {
        printf("Pas creuse");
    }
    
    

    return 0;
}