#include <stdio.h>

int main()
{
    int i, j, n, temp,mark;

    printf("Entrer la taille du tableau: ");
    scanf("%d",&n);

    int T[n];

    for (i=0;i<n;i++)
    {
        scanf("%d",&T[i]);
    }

    mark=0;
    int cpt=2;
    

    while (mark==0)
    {
        mark=1;
        for (i=0;i<n;i++)
        {
            if (T[i]<T[i+1])
            {
                temp=T[i];
                T[i]=T[i+1];
                T[i+1]=temp;
                mark=0;
                cpt++;
            }
        }
    }
    
    for (i=0;i<n;i++)
    {
        printf("%4d",T[i]);
    }

    printf("\n%d",cpt);

    return 0;
}