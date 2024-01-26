#include <stdio.h>
#include <string.h>

struct Etudiant
{
    int ID;
    char nom[50];
    char prenom[50];
};


int main(int argc, char const *argv[])
{
    int N = 1;
    int i;
    struct Etudiant Et[N];

    for (int i = 0; i < N; i++)
    {
        scanf("%d", &Et[i].ID);
        scanf("%s", &Et[i].nom);
        scanf("%s", &Et[i].prenom);
    }
    for (int i = 0; i < N; i++)
    {
        printf("%d", Et[i].ID);
        printf("%s", Et[i].nom);
        printf("%s", Et[i].prenom);
    }
    
    
    return 0;
}