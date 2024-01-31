#include <stdio.h>
int main()
{
    int x;
    printf("Entrer un nombre positive: ");
    scanf("%d", &x);

    for (int i = 0; i < x; i+=2)
    {
        printf("%d ",i);
    }
    
    return 0;
}