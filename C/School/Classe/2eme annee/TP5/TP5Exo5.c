#include <stdio.h>
#include <string.h>

int main(){
    char str[]="string";
    compter(str);
}

void afficher(char str[]){
    printf(str);
}

void compter(char str[]){
    int cpt=0;
    while (str[cpt]!='\0')
    {
        cpt++;
    }
    printf("%d",cpt);
}
