#include <stdio.h>

void Exo1()
{
    int a,b,c;

    printf("Entrer deux nombres:");
    scanf("%d %d", &a, &b);
    c=a*b;

    printf("%d*%d=%d",a,b,c);
}

void Exo2()
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
}

void Exo3()
{
    int x;
    printf("Entrer un nombre:");
    scanf("%d", &x);

    if (x%2==0)
    {
        printf("Ce nombre est pair");
    }
    else
    {
        printf("Ce nombre est impair");
    }
}

void Exo4()
{

    int x;
    printf("Entrer un nombre positive: ");
    scanf("%d", &x);

    for (int i = 0; i <= x; i+=2)
    {
        printf("%d ",i);
    }
}

int main()
{
    int rep;
    int exo;
    
    do
    {
        printf("Entrer le nombre de l exercice (1-4):");
        scanf("%d", &exo);

        switch (exo)
        {
        case 1:
            printf("Exo1:\n");
            Exo1();
            printf("\n");
            break;

        case 2:
            printf("Exo2:\n");
            Exo2();
            printf("\n");
            break;

        case 3:
            printf("Exo3:\n");
            Exo3();
            printf("\n");
            break;

        case 4:
            printf("Exo4:\n");
            Exo4();
            printf("\n");
            break;
        
        default:
            printf("\nEntrer un numero valable!\n");
            break;
        }

        printf("\nSouhaitez vous recommencer le programme? (O=0/N=1) ");
        scanf("%d",&rep);
    }while(rep!=0);

    return 0;
}