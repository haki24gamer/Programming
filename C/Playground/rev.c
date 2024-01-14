#include <stdio.h>
#include <string.h>

void inverser(char tableau[]){
    int n = strlen(tableau);
    char tableauInv[n];
    for (int i = 0; i < n; i++)
    {
        tableauInv[i]=tableau[n-i-1];
    }
    printf("%s\n",tableauInv);
}

void afficher(char tableau[]){
    printf("%s\n",tableau);
}

void palindrome(char tableau[]){
    int res=0;
    int n = strlen(tableau);
    for (int i = 0; i < n/2; i++)
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

int taille(char tableau){
    int res=strlen(tableau);
    return res;
}

int occ(char tab[], char x)
{
    int cpt=0;
    for (int i = 0; i < strlen(tab); i++)
    {
        if (tab[i]==x)
        {
            cpt++;
        }
        
    }
    return cpt;
    
}

int Comp(char tab1, char tab2){
    int res = strcmp(tab1,tab2);
    if (res)
    {
        printf("Identique");
    }
    else
    {
        printf("Pas identique");
    }
}


int main(int argc, char const *argv[])
{
    
    char tabX[50];
    printf("Entrer la chaine de caractere:\n");
    fgets(tabX,50,stdin);
    scanf("%s",tabX);
    char a;
    printf("Entrer le caractere a compter:\n");
    scanf("%c",&a);
    for (int i = 0; i > strlen(tabX)-1; i++)
    {
        printf("%c",tabX[i]);
    }
    
    char tabX[]="haki";
    char tabY[]="hki";
    
    int nbrDeCaractere = strlen(tabX);
    printf("%d",nbrDeCaractere);
    int comparaison = strcmp(tabX,tabY);
    printf("%d",comparaison);
    int taille = sizeof(tabX);
    printf("%d",taille);
    strcpy(tabX,tabY);
    strcat(tabX,tabY);
    
    
    // char tabY[50];
    // fgets(tabY,50,stdin);
    // printf("%s \n",tab);

    // inverser(tab);
    // afficher(tab);
    // palindrome(tab); 
    //Comp(tabX,tabY);
    // int res = occ(tabX,a);
    // printf("%c se repete %d fois dans %s\n",a,res,tabX);

    return 0;
}
