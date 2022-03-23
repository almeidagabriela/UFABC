#include "qtd_digitos.h"

int quantidade_digitos(int numero) {
    int contador = 0;

    if(numero == 0){
        contador = 1;
    }else{
        while(numero != 0){
            contador++;
            numero = numero / 10;
        }
    }

    return contador;
}