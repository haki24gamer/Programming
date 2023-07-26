#include <stdio.h>

int main()
{
    int i, j, n, temp,ins,cpt=0;

    //Remplir le tableau
    printf("Entrer la taille du tableau: ");
    scanf("%d",&n);
    int T[n];
    for (i=0;i<n;i++)
    {
        scanf("%d",&T[i]);
    }

    printf("Entrer l element a inserer");
    scanf("%d",&ins);

    //inserer
    T[n+1];
    for(i = 0; i < n-1; i++)
    {
        if (T[i]>ins)
        {
            if (cpt==0)
            {
                temp=T[i];
                T[i]=ins;
                T[i+1]=temp;
                cpt++;
            }
            else
            {
                temp=T[i+1];
                T[i+1]=T[i];
            }
        }
    }
    
    for (i=0;i<n+1;i++)
    {
        printf("%4d",T[i]);
    }


}