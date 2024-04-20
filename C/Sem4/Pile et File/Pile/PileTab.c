#include <stdio.h> 
#define N 5

typedef int Type_C;

typedef struct
{
    Pile tab[N];
    int sommet;
} Pile;

//Initialisation d une pile
Pile init_Pile(Pile P){
    P.sommet = -1;

}

//Verification si la pile est vide
int Pile_vide(Pile P){
    if (P.sommet==-1)
    {
        return 0;
    }
    else
    {
        return 1;
    }
}

//Verification si la pile est pleine
int Pile_pleine(Pile P){
    // if (Pile_vide(P)==1 && (sizeof(P.tab)/sizeof(P.tab[0]))==N)
    // {
    //     return 0;
    // }
    if (P.sommet>=N-1)
    {
        return 0;
    }
    else
    {
        return 1;
    }
    
}

//Empiler
Pile Empiler(Pile P,Type_C X){
    if (Pile_pleine(P)==0)
    {
        /* code */
    }
    
}



int main(int argc, char const *argv[])
{
    
    return 0;
}
