#include <stdio.h>

int Comp(int t1[], int t2[],int n)
{
    if (n==0)
    {
        return 0;
    }
    else
    {
        if (t1[n]==t2[n])
        {
            return Comp(t1,t2,n-1);
        }
        else
        {
            return 1;
        }
    }
}

int main(int argc, char const *argv[])
{
    //0 identique, 1 non identique
    int t1[]={1,2,3,4,5};
    int t2[]={1,2,3,4,5};
    if (Comp(t1,t2,5))
    {
        printf("non Identique");
    }
    else
    {
        printf("Identique");
    }
    
    return 0;
}
