#include <stdio.h>
#include <strings.h>

int main()
{
    char *nom;
    char *prenom;
    char adress[50];
    

    scanf("%s ",&nom);
    scanf("%s ",&prenom);

    //gets(adress); //3/10
    //scanf("%[^\n]s", &adress); //10/10
    fgets(adress,sizeof(adress),stdin); //8/10

    printf("%s",&nom);
    printf("\n");
    printf("%s",&prenom);
    printf("\n");
    printf("%s",adress);
    return 0;
}