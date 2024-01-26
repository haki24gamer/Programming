#include <stdio.h>

int main(){
    int Tab[100];

    for (int i = 0; i < 100; i++)
    {
        Tab[i]=i;
    }

    for (int i = 0; i < 100; i++)
    {

        if ((i+1)%10==0)
        {
            printf("%d", Tab[i]);
            printf("\n");
            
        }
        else{
                printf("%2d,", Tab[i]);
        }
    }
    
}