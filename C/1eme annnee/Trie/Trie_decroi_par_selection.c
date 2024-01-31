#include <stdio.h>

int main()
{
    int i, j, n, temp;

    printf("Entrer la taille du tableau: ");
    scanf("%d",&n);

    int T[n];

    for (i=0;i<n;i++)
    {
        scanf("%d",&T[i]);
    }

    for (i=0;i<n;i++)
    {
        for (j = i+1; j < n; j++)
        {
            if (T[i]<T[j])
            {
                temp=T[i];
                T[i]=T[j];
                T[j]=temp;
            }
            
        }
    }

    for (i=0;i<n;i++)
    {
        printf("%4d",T[i]);
    }


    return 0;
}