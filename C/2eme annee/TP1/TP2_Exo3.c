#include <stdio.h>

int main()
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
    return 0;
}