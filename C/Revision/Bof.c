#include <stdio.h>

int main()
{
    int N,i,imin,imax;

    printf("Lignes");
    scanf("%d",&N);

    int T[N];

    printf("Entrer les lettres:\n");
    for ( i = 0; i < N; i++)
    {
        scanf("%d",&T[i]);
    }


    int max=T[0];
    int min=T[0];

    for ( i = 0; i < N; i++)
    {
        if (max<T[i])
        {
            max=T[i];
            imax=i;
        }
        if (min>T[i])
        {
            min=T[i];
            imin=i;
        }
    }

    int max2=T[0];
    int min2=T[0];

    for ( i = 0; i < N; i++)
    {
        if (i!=imax||i!=imin)
        {
            
            if (max2<T[i])
            {
                max2=T[i];
            }
            if (min2>T[i])
            {
                min2=T[i];
            }
        }
        
    }

    printf("Le 2max est %d\n Le 2min est %d",max2,min2);

    return 0;
}