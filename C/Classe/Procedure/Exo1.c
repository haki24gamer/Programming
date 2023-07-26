#include <stdio.h>

void multi(int L, int C, int A[L][C] ,int X)
{
    int A2[L][C];
    for (int i = 0; i < L; i++)
    {
        for (int j = 0; j < C; j++)
        {
            A2[i][j]=A[i][j]*X;
        }
        
    }

    for (int i = 0; i < L; i++)
    {
        for (int j = 0; j < C; j++)
        {
            printf("%4d",A2[i][j]);
        }
        printf("\n");
    }
}

int main()
{
    int NL,NC, Y;
    printf("Entrer le NL NC du matrice:\n");
    scanf("%d %d",&NL,&NC);
    int M[NL][NC];
    printf("Entrer les elements du tableau:\n");
    for (int i = 0; i < NL; i++)
    {
        for (int j = 0; j < NC; j++)
        {
            scanf("%d",&M[i][j]);
        }
    }


    printf("Entrer l element a multiplier avec:\n");
    scanf("%d",&Y);

    multi(NL, NC, M,Y);

    return 0;
}