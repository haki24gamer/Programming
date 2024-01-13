#include <stdio.h>
#include <string.h>

void inverser(char tableau[]){
    int n = strlen(tableau);
    char tableauInv[n];
    for (int i = 0; i < n; i++)
    {
        tableauInv[i]=tableau[n-i-1];
    }
    printf("%s",tableauInv);
}

void afficher(char tableau[]){
    printf("%s",tableau);
}

void palindrome(char tableau[]){
    int res=0;
    int n = strlen(tableau);
    for (int i = 0; i < n; i++)
    {
        if (tableau[i]!=tableau[n-1-i])
        {
            res++;
        }
    }

    if (res==0)
    {
        printf("%s est un palindrome",tableau);
    }
    else
    {
        printf("%s n est pas un palindrome", tableau);
    }
}


int main(int argc, char const *argv[])
{
    char tab[50];
    scanf("%s",tab);
    // printf("%s \n",tab);

    // inverser(tab);
    // afficher(tab);
    //palindrome(tab);
    
    return 0;
}
