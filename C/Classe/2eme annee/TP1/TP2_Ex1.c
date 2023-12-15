#include <stdio.h>

int main()
{
    int a,b,c;

    printf("Entrer deux nombres:");
    scanf("%d %d", &a, &b);
    c=a*b;

    printf("%d*%d=%d",a,b,c);
    return 0;
}