#include <stdio.h>

int main()
{
    int N,i;
    char temp;

    printf("Lignes");
    scanf("%d",&N);

    char T[N];

    printf("Entrer les lettres:\n");
    for ( i = 0; i < N; i++)
    {
        scanf(" %c",&T[i]);
    }

    temp=T[0];
    
    for ( i = 0; i < N-1; i++)
    {
        T[i]=T[i+1];
    }

    for ( i = 0; i < N; i++)
    {
        printf("%c",T[i]);
    }

    T[N]=temp;

    return 0;
}