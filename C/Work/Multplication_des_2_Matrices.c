#include <stdio.h>
#include <unistd.h>
#include <time.h>
#include <stdlib.h>

int main()
{
    //Variables
    int nl1, nc1, nl2, nc2,i, j, k;

    nl1 = 2;
    nc1 = 3;

    nl2 = 3;
    nc2 = 2;

    int M1[nl1][nc1];
    int M2[nl2][nc2];
    int M3[nl1][nc2];

    for (int i = 0; i < nl1; i++)
    {
        for (int j = 0; j < nc1; j++)
        {
            scanf(" %d ",&M1[i][j]);
        }
        
    }
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
            printf("%d ", M3[i][j]);
        }
        printf("\n");
        
    }

    scanf("%d ", &i);
    
}