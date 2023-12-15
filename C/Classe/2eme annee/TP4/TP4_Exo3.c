#include <stdio.h>
#include <string.h>

int main(){
    int tSource[10]={-2,3,-5,-6,5,8,9,-4,9,-1};
    int tDestination[10];

    
    

    for (int i = 0; i < 10; i++)
    {
        if (tSource[i]>0)
        {
            tDestination[i]=tSource[i];
        }
        else
        {
            tDestination[i]=0;
        }
        
    }
    

    printf("\n");

    for (int i = 0; i < 10; i++)
    {
        if (i!=9)
        {
            printf("%2d, ",tSource[i]);
        }
        else
        {
            printf("%2d",tSource[i]);
        }
    }

        printf("\n");
    for (int i = 0; i < 10; i++)
    {
        if (i!=9)
        {
            printf("%2d, ",tDestination[i]);
        }
        else
        {
            printf("%2d",tDestination[i]);
        }
    }

    /**

    for (int i = 0; i < 10; i++)
    {
        for (int j = i; j < 10; j++)
        {
            if (Tab[j]>Tab[i])
            {
                n=Tab[i];
                Tab[i]=Tab[j];
                Tab[j]=n;
            }
        }
    }
    **/
    return 0;
    
}