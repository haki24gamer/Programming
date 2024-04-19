#include <stdio.h>

typedef int Element;

typedef struct{
    Element valeur;
    cellule *suivant;
} cellule;

typedef cellule *Pile;

Pile pile_vide(cellule p, Element val){
    p.valeur=val;
    p.suivant=NULL;
}

int Pile_vide(){

}

int Pile_pleine(){

}


Pile Empiler(){

}

int main(int argc, char const *argv[])
{
    
    return 0;
}
