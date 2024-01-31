#include <stdio.h>

void mention(int note){
    switch (note)
    {
    case 17 ... 20 :
        printf("tres bien");
        break;

    case 15 ... 16:
        printf("bien");
        break;

    case 13 ... 14:
        printf("assez bien");
        break;
    
    case 11 ... 12:
        printf("passable");
        break;
    
    default:
        printf("ajournee");
        break;
    }
}


int main(){
    mention(15);
    return 0;
}

