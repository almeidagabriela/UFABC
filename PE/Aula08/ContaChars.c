#include <stdio.h>
#include "meugetch.h" //Buscando dentro da raiz do font

int contaChars();

int main(){
    printf("%d\n", contaChars());

    return 0;
}

int contaChars(){
    char letra;
    letra = getche();

    if(letra == 10){
        return 0;
    }

    return contaChars() + 1;
}