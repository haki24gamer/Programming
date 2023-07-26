#include <stdio.h>

int main()
{
    int i,n,p;
    printf("entrer la taille du tablea \n ");
    scanf("%d",&n);
    int tab[n];
    printf("remplissez le tableau");
    for (i=0;i<=n-1;i++){
        scanf("%d",&tab[i]);
    }
    printf("entrer la position \n");
    scanf("%d",&p);
     
    for (i=1;i<=n;i++){
        if(i==p)
        {
            printf(" ");
        }
          printf("%d",tab[i]);
          printf(" ");6
    }
      return 0;
    }