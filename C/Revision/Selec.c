#include <stdio.h>
void Zizi(int N, int T[N])
{
    int i,j,temp,pp;
    for (i = 0;i < N-1; i++)
    {
        pp=i;
        for (j = i+1; j < N; j++)
        {
            if (T[j]>T[pp])
            {
                pp=j;
            }
        }
        temp=T[i];
        T[i]=T[pp];
        T[pp]=temp;
    }
    for (i=0;i<N;i++)
    {
        printf("%d",T[i]);
    }
}

int main()
{
    int i,n;

    //Remplir le tableau
    printf("Entrer la taille du tableau: ");
    scanf("%d",&n);
    int T[n];
    for (i=0;i<n;i++)
    {
        scanf("%d",&T[i]);
    }

    Zizi(n,T);

    return 0;
}

