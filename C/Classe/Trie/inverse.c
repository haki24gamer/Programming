#include <stdio.h>

int main()
{
    int i, n, temp;

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
    
    printf("\n");
    for (i=0;i<n/2;i++)
    {
        temp=T[i];
        T[i]=T[n-1-i];
        T[n-1-i]=temp;
    }

    for (i=0;i<n;i++)
    {
        printf("%4d",T[i]);
    }
    return 0;
    
}