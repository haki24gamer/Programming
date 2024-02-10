#include <stdio.h>

int factFor(int n)
{
    int res=1;
    for (int i = 1; i <= n; i++)
    {
        res*=i;
    }
    return res;
}

int factWhile(int n)
{
    int i=1;
    int res=1;
    while (i<=n)
    {
        res*=i;
        i++;
    }
    return res;
}

int main(int argc, char const *argv[])
{
    printf("%d\n",factFor(5));
    printf("%d\n",factWhile(5));
    return 0;
}
