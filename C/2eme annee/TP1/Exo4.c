#include <stdio.h>

void Operation(int nb1, int nb2, char Op)
{
    switch (Op)
    {
    case '+':
        printf("%d + %d = %d \n", nb1, nb2, nb1+nb2);
        break;
    case '-':
        printf("%d - %d = %d \n", nb1, nb2, nb1-nb2);
        break;
     case '*':
        printf("%d * %d = %d \n", nb1, nb2, nb1*nb2);
        break;
     case '/':
        if (nb2==0)
        {
            printf("Operation indeterminee \n");
        }
        else
        {
            printf("%d / %d = %d \n", nb1, nb2, nb1/nb2);
        }
        break;
    
    default:
        printf("Operation inexistante \n");
        break;
    }
}

int main()
{
    Operation(15, 5, '/');


}