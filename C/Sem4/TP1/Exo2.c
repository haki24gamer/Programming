#include <stdio.h>

int factRecur(int n)
{
    int res;
    if (n==1)
    {
        res=1;
    }
    else
    {
        res=factRecur(n-1)*n;
    }
    return res;
}


int main(int argc, char const *argv[])
{
    printf("%d",factRecur(4));
    return 0;
}
