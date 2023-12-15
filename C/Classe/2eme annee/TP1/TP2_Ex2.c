#include <stdio.h>

int main()
{
    int a,b,c;

    printf("Entrer deux nombres:");
    scanf("%d %d", &a, &b);

    if (b!=0)
    {
        c=a/b;
        printf("%d/%d=%d",a,b,c);
    }
    else
    {
        printf("le deuxieme nombre ne peut pas etre negative");
    }
    
    return 0;
    
}