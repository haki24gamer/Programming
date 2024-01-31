#include <stdio.h>
#include <string.h>

typedef struct
{
    int CC;
    int CF;
} note;
//enregistrement
typedef struct {
    int ID;
    char nom[50];
    char prenom[50];
    note Note;
} etu;


int main(int argc, char const *argv[]){
    
    //declaration Manuel
    etu ET1 = {50, "Hassan", "Houssein"}; 
    scanf("%d %d", &ET1.Note.CC, &ET1.Note.CF);
    printf(" %d %s %s %d %d",ET1.ID, ET1.prenom, ET1.nom, ET1.Note.CC, ET1.Note.CF);
    
    strcpy()
    //Saisie d enregistrement
    /*
    etu ET2;
    scanf("%d %s %s", &ET2.ID, &ET2.prenom, &ET2.nom);
    printf("%d %s %s", ET2.ID, ET2.prenom, ET2.nom);
    */
   /*
    etu ET[3];
    for (int i = 0; i < 3; i++)
    {
        scanf("%d %s %s", &ET[i].ID, &ET[i].prenom, &ET[i].nom);
        
    }
    for (int i = 0; i < 3; i++)
    {
        printf("%d %s %s\n", ET[i].ID, ET[i].prenom, ET[i].nom);
    }
    */

    return 0;
}

