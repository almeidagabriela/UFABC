#include <stdio.h>

void inverteNumeros();

int main(){
    inverteNumeros();

    return 0;
}
/*
void inverteNumeros(){
    int num, resto = -1, inverte = -1;

    scanf("%d", &num);

    while(num != 0){
        inverte = num;

        while(inverte != 0){
            resto = inverte % 10;

            printf("%d", resto);

            inverte = inverte - resto;
            inverte = inverte / 10;
        }
        printf("\n");
        num = 0;
        inverteNumeros();
    }
}
*/
void inverteNumeros(){
    int num;

    scanf("%d", &num);

    while(num != 0){
        int aux = num;

        while(aux != 0){
		    int varR = aux % 10;

           	printf("%d", varR);

            aux = (aux - varR) / 10;
        }
        printf("\n");
        num = 0;
        inverteNumeros();
    }
}