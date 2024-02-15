#include <stdio.h>
#include <string.h>

//Q1
typedef struct fi
{
    char Nom[50];
    char Niveau[50];
}Filiere;

typedef struct et
{
    char UserName[50];
    char LastName[50];
    char FirstName[50];
    Filiere fi;
}Etudiant;

void saisirNouveau(Etudiant * Tab, Etudiant Etu, int *taille){
    Tab[(*taille)++]=Etu;
}

int Test(Etudiant Et1, Etudiant Et2){
    int res = strcmp(Et1.FirstName,Et2.FirstName);
    return res;
}

int main(int argc, char const *argv[])
{
    //Q4

    //Q2
    Filiere Fi3 = {
        "Maths",
        "L1"
    };

    Filiere Filiere1 = {
        "Infor2",
        "L2"
    };
    //Q3
    Etudiant et3 = {
        "Hass",
        "Hassan",
        "Houssein",
        Fi3
    };
    Etudiant et1 = {
        "Ali",
        "Ahmed",
        "Ibiro",
        Filiere1
    };
    Etudiant et2 = {
        "Goumati",
        "Ali",
        "Gona",
        Filiere1
    };
    
    
    //Q5
    int N = 0;
    Etudiant TabEtu[3];
    saisirNouveau(TabEtu,et1,&N);
    saisirNouveau(TabEtu,et2,&N);
    saisirNouveau(TabEtu,et3,&N);

    
    for (int i = 0; i < 3; i++)
    {
        printf("%s\n",TabEtu[i].FirstName);
    }
    
    
    
    return 0;
}
