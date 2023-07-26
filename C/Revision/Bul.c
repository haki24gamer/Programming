#include <stdio.h>
void Zizi(int N, int T[N])
{
    int i,j,pp,temp;
    
    int cpt=0;

    while (cpt==0)
    {
        cpt=1;
        for ( i = 0; i < N-1; i++)
        {
            if (T[i]<T[i+1])
            {
                temp=T[i];
                T[i]=T[i+1];
                T[i+1]=temp;
                cpt=0;
            }
        }
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

}
