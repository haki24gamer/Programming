#include <stdio.h>

int main()
{
    int i, n, temp,del;

    printf("Entrer la taille du tableau: ");
    scanf("%d",&n);

    int T[n];

    for (i=0;i<n;i++)
    {
        scanf("%d",&T[i]);
    }

    for (i=0;i<n;i++)
    {
        printf("%4d",T[i]);
    }
    
    printf("\nEntrer l indice a supprimer: ");
    
    scanf("%d",&del);

    for (i=0;i<n-1;i++)
    {
        if (i>=del)
        {
            T[i]=T[i+1];
        }
    }

    T[n-1];

    for (i=0;i<n-1;i++)
    {
        printf("%4d",T[i]);
    }

    return 0;
}