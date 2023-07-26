#include <stdio.h>

int main()
{
    int i,j,NC,NL;

    printf("Lignes et colonnes:\n");
    scanf("%d %d",&NC,&NL);
    int T[NL][NC];
    if (NL==NC)
    {
        printf("Les elements:\n");
        for (int i = 0; i < NL; i++)
        {
            for (int j = 0; j < NC; j++)
            {
                scanf("%d",&T[i][j]);
            }
            
        }

            
        for (int i = 0; i < NL; i++)
        {
            for (int j = 0; j < NC; j++)
            {
                    if (i==j)
                    {
                        T[i][j]=0;
                    }
                    if (NL-1-i==j)
                    {
                        T[i][j]=0;
                    }
            }
            
        }
        
        for (int i = 0; i < NL; i++)
        {
            for (int j = 0; j < NC; j++)
            {
                printf("%4d",T[i][j]);
            }
            printf("\n");

        
        }

    }
    
    return 0;
}