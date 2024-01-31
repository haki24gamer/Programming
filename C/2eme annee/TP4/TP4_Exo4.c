#include <stdio.h>

int main(){
    int min,max;
    int Tab[10];
    printf("Entrer 10 valeurs: ");

    for (int i = 0; i < 10; i++)
    {
        scanf("%d", &Tab[i]);
    }
    
    min = Tab[0];
    max = Tab[0];
    for (int i = 1; i < 10; i++)
    {
        if (min>Tab[i])
        {
            min=Tab[i];
        }
        if (max<Tab[i])
        {
            max=Tab[i];
        }
        
    }
    
    printf("max = %d \n", max);
    printf("min = %d \n", min);

    printf("Tab = ");
    for (int i = 0; i < 10; i++)
    {
        printf("%d ", Tab[i]);
    }
    
    
}