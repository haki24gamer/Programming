#include <stdio.h>

int main(int argc, char const *argv[])
{
    //Declaration d un tableau
    int taille = 5;
    int tabInt[taille];
    char tabChar[taille];

    //Initialize les elements du tableau a 0
    //int tabInt[5]={0};


    //Affectation manuelle d un element
    tabChar[0] = 'H';
    
    //Affectation d un ensemble des elements avec une boucle
    // for (int i = 0; i < taille; i++)
    // {
    //     printf("Entrer l elements num %d:", i);
    //     scanf("%d", &tabInt[i]);
    // }
    
    // Afficher un tableau
    // for (int i = 0; i < taille; i++)
    // {
    //     printf("%d ", tabInt[i]);
    // }

    return 0;
}
