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


    j=1;

    while(j<n)
    {
        i=j-1;
        temp=T[j];
        while ((i>-1)&&(T[i]>temp))
        {
            T[i+1]=T[i];
            i=i-1;
        }
        T[i+1]=temp;
        j++;
    }
    
    for (i=0;i<n;i++)
    {
        printf("%4d",T[i]);
    }

    return 0;
}