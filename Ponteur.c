#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	int wal = 500;
	
	//int* p = &wal;
	//printf("%d \n",wal); //valeur de wal
	//printf("%d \n", &wal ); //adresse de wal
	//printf("%d \n", p); //adress de wal
	//printf("%X \n", *p); //valeur de wal
	//printf("%d \n", &p); //adresse de p
	//printf("%d \n", &(*p)); //adresse de wal
	
	int tab[]={12,32,5,2,1,8,55,4,7};
	int *p = &tab;
	
		printf("%d", *p+2); //premiere valeur plus 2
	printf("%d", *(p+2)); // la valeur du 3eme element
	printf("%d\n", p); //adresse de p
	printf("%d\n", &p+1); // adresses suivant
	printf("%d\n", &tab[4]-3); //adresse de l element 2 du tableau
	printf("%d", tab+3);//adresse du 4eme element
	printf("%d", &tab[7]-p); //l adresse de dernier element - l adresse de premier element
	printf("%d", *(p+*(p+8)-tab[7]));
	
	return 0;
}

